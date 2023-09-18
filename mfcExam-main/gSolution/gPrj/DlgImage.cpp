// DlgImage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgImage::OnBnClickedBtnUpParent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage �޽��� ó�����Դϴ�.

#include "gPrjDlg.h"
void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	static int n = 100;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++); // ȣ���Ѵ�.
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	/*AfxMessageBox(_T("ready?"));*/

	// â ũ�� ����
	MoveWindow(0, 0, 640, 480); 

	// �̹��� ���� �κ�
	initImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


// �׸��� �޼���
void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	if (m_image) {
		m_image.Draw(dc, 0, 0); //dc��, (0, 0) �� �׸����̴�.
	}

	datwData(&dc);
}

// �̹��� �ʱ�ȭ �κ�
void CDlgImage::initImage() {
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);
}

void CDlgImage::datwData(CDC* pDC) 
{
	CRect rect;
	CPen pen; // �� ��ü ����
	pen.CreatePen(PS_SOLID, 1, RGB(0xff, 0, 0)); // �Ǽ�, �β�, ������
	CPen* pOldPen = pDC->SelectObject(&pen); // ���� �� ����

	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);  // ��ǥ�� ����
		rect.InflateRect(5, 10); // �·� 5��ŭ, ��� 10��ŭ ������
		pDC->Ellipse(rect); //���� �׸���

	}

	pDC->SelectObject(pOldPen); // ������ �� �� ��������
}