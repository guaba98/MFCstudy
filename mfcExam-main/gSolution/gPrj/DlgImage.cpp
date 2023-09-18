// DlgImage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage 대화 상자입니다.

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


// CDlgImage 메시지 처리기입니다.

#include "gPrjDlg.h"
void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static int n = 100;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++); // 호출한다.
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	/*AfxMessageBox(_T("ready?"));*/

	// 창 크기 조절
	MoveWindow(0, 0, 640, 480); 

	// 이미지 생성 부분
	initImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


// 그리기 메서드
void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	if (m_image) {
		m_image.Draw(dc, 0, 0); //dc에, (0, 0) 에 그릴것이다.
	}

	datwData(&dc);
}

// 이미지 초기화 부분
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
	CPen pen; // 선 객체 생성
	pen.CreatePen(PS_SOLID, 1, RGB(0xff, 0, 0)); // 실선, 두께, 빨간색
	CPen* pOldPen = pDC->SelectObject(&pen); // 현재 펜 저장

	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);  // 좌표값 설정
		rect.InflateRect(5, 10); // 좌로 5만큼, 우로 10만큼 벌린다
		pDC->Ellipse(rect); //원을 그린다

	}

	pDC->SelectObject(pOldPen); // 저장해 둔 펜 가져오기
}