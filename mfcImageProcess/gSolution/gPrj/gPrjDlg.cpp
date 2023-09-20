
// gPrjDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "gPrj.h"
#include "gPrjDlg.h"
#include "afxdialogex.h"

#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CgPrjDlg ��ȭ ����



CgPrjDlg::CgPrjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GPRJ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgPrjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CIRCLE, mEdit);
}

BEGIN_MESSAGE_MAP(CgPrjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
//	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_TEST, &CgPrjDlg::OnBnClickedBtnTest)
	ON_BN_CLICKED(IDC_BTN_PROCESS, &CgPrjDlg::OnBnClickedBtnProcess)
	ON_BN_CLICKED(IDC_BTN_MAKE_PATTERN, &CgPrjDlg::OnBnClickedBtnMakePattern)
	ON_BN_CLICKED(IDC_BTN_GET_DATA, &CgPrjDlg::OnBnClickedBtnGetData)
	ON_BN_CLICKED(IDC_BTN_THREAD, &CgPrjDlg::OnBnClickedBtnThread)
END_MESSAGE_MAP()


// CgPrjDlg �޽��� ó����

BOOL CgPrjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//ShowWindow(SW_SHOWMAXIMIZED);
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);

	m_pDlgImgResult = new CDlgImage;
	m_pDlgImgResult->Create(IDD_DLGIMAGE, this);
	m_pDlgImgResult->ShowWindow(SW_SHOW);
	m_pDlgImgResult->MoveWindow(640, 0, 640, 480);

	

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CgPrjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CgPrjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CgPrjDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if(m_pDlgImage)		delete m_pDlgImage;
	if(m_pDlgImgResult)	delete m_pDlgImgResult;
}

void CgPrjDlg::callFunc(int n)
{
	// std::cout << n << std::endl;
}

void CgPrjDlg::OnBnClickedBtnTest()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, 0, nWidth*nHeight);

	for (int k = 0; k < MAX_POINT; k++) {
		int x = rand() % nWidth;
		int y = rand() % nHeight;
		fm[y * nPitch + x] = rand()%0xff;
		//m_pDlgImgResult->m_nDataCount = k;
		//m_pDlgImgResult->m_ptData[k].x = x;
		//m_pDlgImgResult->m_ptData[k].y = y;
	}

	int nIndex = 0;
	int nTh = 100;
	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (fm[j*nPitch + i] > nTh) {
				if (m_pDlgImgResult->m_nDataCount < MAX_POINT) {
					//cout << nIndex << ":" << i << "," << j << endl;
					m_pDlgImgResult->m_ptData[nIndex].x = i;
					m_pDlgImgResult->m_ptData[nIndex].y = j;
					m_pDlgImgResult->m_nDataCount = ++nIndex;
				}
			}
		}
	}

	m_pDlgImage->Invalidate();
	m_pDlgImgResult->Invalidate();

}

#include "Process.h" // 1. ���μ��� ������ �����´�.
#include <chrono> // ũ�γ� �Լ� 
#include <thread>
using namespace std; // std::�� ����� �ش�.
using namespace chrono; // std::chrono::�� ����� �ش�.

void CgPrjDlg::OnBnClickedBtnProcess()
{
	// ���� �ð��� start ������ �����Ѵ�. ���� �ð��� ���¸� auto�� �����´ٴ� ���� ������ �ʰڴٴ� �ǹ��̴�.
	// ������ �� �� ���¸� ����� ��� �Ѵ�.
	auto start = system_clock::now(); 

	// ��Ŭ��� �� Process�� ��ü�� �����Ѵ�.
	CProcess process; 
	int nTh = 0;

	// �̹����� �ּ�, nTh ���� �Ѱ��ش�. nTh�� �� �ָ� ������ ���µ�, nTH
	int nRet = process.getStarInfo(&m_pDlgImage->m_image, nTh); // ���� DlgImage�� m_image�� ����Ʈ �ּҸ� �����´�.(& ���)
//	Sleep(1000);
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	// ����ð��� ���ϱ� ���� ��� ���μ����� ���� �� ���� ���Ѵ�.
	auto end = system_clock::now();
	auto millisec = duration_cast<milliseconds>(end - start); // ������ �ð� - ó���ð��� �ؼ� ����ð��� ���Ѵ�.
	
	// ����ϱ�
	/*cout << nRet << "\t"<< millisec.count()*0.001 << "sec" <<endl;*/
}

// ���� ��ư�� Ŭ������ ��
#define YELLOW RGB(255, 255, 0)
void CgPrjDlg::OnBnClickedBtnMakePattern()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();

	// �� ����, ����, ��ġ ���� ��������
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	int nIndex = 0;
	int x = rand() % nWidth;
	int y = rand() % nHeight;
	int penWidth = 20; // ���� �׵θ� �β�

	CString str;
	mEdit.GetWindowText(str);
	int r = _wtoi(str.GetBuffer()); // int������ ��ȯ(������)
	str.ReleaseBuffer();

	memset(fm, 30, nWidth * nHeight * 3);

	// �� �׸���
	for (int j = y - r; j < y + r; j++) {
		for (int i = x - r; i < x + r; i++) {
			if (!vaildImgPos(i, j)) {
				continue; // �ش� ��ġ�� �̹��� ��踦 ����ٸ� ���� ��ġ�� �Ѿ��.
			}

			int dx = i - x;
			int dy = j - y;
			int distanceSquared = dx * dx + dy * dy; // �� ���� �ȿ� ��ġ ����
			int index = (j * nPitch + i * 3);

			if (distanceSquared <= r * r) { // ������
				fm[index] = 255;     // Red
				fm[index + 1] = 255; // Green
				fm[index + 2] = 255; // Blue
			}

			// ���� �߽ɿ� ���� ǥ��
			if ((i == x || j == y) && distanceSquared <= r * r) {
				fm[index + 2] = 0;     // Red
				fm[index + 1] = 0; // Green
				fm[index] = 0; // Blue
			}
			// ���� ���ΰ� �ƴ� �׵θ� �κи� ��ĥ�ϱ� ���� ����
			if (distanceSquared <= r * r && distanceSquared >= (r - 4) * (r - 4)) {
				//fm[index + 2] = GetRValue(YELLOW);     // Red
				//fm[index + 1] = GetGValue(YELLOW); // Green
				//fm[index] = GetBValue(YELLOW); // Blue
				fm[index + 2] = 255;     // Red
				fm[index + 1] = 234; // Green
				fm[index] = 0; // Blue
			}

		}
	}

	// ȭ�鿡 ǥ���ϱ�
	m_pDlgImage->Invalidate();
}

BOOL CgPrjDlg::vaildImgPos(int x, int y) {
	int nWidth = m_pDlgImage->m_image.GetWidth(); // ������ �ȼ�
	int nHeight = m_pDlgImage->m_image.GetHeight(); // ������ �ȼ�

	CRect rect(0, 0, nWidth, nHeight);
	// �־��� x, y �� ���ؼ� ���� �ȿ� ���� �� ���� ������ �ش�.
	return rect.PtInRect(CPoint(x, y)); // Cpoint������ �ٲ� �ش�.
}




// �����߽� �� ���ϱ�(�߽ɰ�)
void CgPrjDlg::OnBnClickedBtnGetData()
{

	// ���� �ڵ�� �����ϰ� �̹����� ���� ����
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	// ���� ����
	int nTh = 0x80; // �߰� ��
	int nSumX = 0; // X��
	int nSumY = 0; // Y��
	int nCount = 0;

	// ��� ������ �ش��ϰ� �ϱ� ���� �Ʒ��� ���� 0, 0, nWidth, nHeight�� ������
	CRect rect(0, 0, nWidth, nHeight);

	// �����͸� �̿��ؼ� ���� ����
	// �� �ȼ��� ��ǥ�� Ư�� ������ ũ��(nTh)
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j*nPitch + i] > nTh) {
				// ���Ͱ��� ���ϱ� ���� X��ǥ�� 1�� �߰�, Y��ǥ�� 1�� �߰�����
				nSumX += i; // ��ǥ�� ���ϱ�
				nSumY += j;
				nCount++; // �� �� ����Ǿ����� �˱� ���ؼ� �ϳ��� ������Ű��
			}
		}
	}

	// ��� ���� ��� (�� �� ī��Ʈ �Ǿ����� �˱� ���ؼ�)
	// ���� ������ ����������, int / int�̱⶧���� ���� int�� �� -> �� �߿� �ϳ��� ����ȯ�� ����� ��
	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	// ���
	cout << dCenterX << "\t" << dCenterY << endl;

	// ȭ�鿡 ������Ʈ
	m_pDlgImage->Invalidate();
}

void threadProcess(CWnd* pParent, CRect rect, int *nRet)
{
	CgPrjDlg *pWnd = (CgPrjDlg*)pParent;
	*nRet = pWnd->processImg(rect);
}

void CgPrjDlg::OnBnClickedBtnThread()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	auto start = system_clock::now();

	int nImgSize = 4096 * 4;
	CRect rect(0, 0, nImgSize, nImgSize);
	CRect rt[4];
	int nRet[4];
	for (int k = 0; k < 4; k++) {
		rt[k] = rect;
		rt[k].OffsetRect(nImgSize*(k % 2), nImgSize*int(k / 2));
	}
	thread _thread0(threadProcess, this, rt[0], &nRet[0]);
	thread _thread1(threadProcess, this, rt[1], &nRet[1]);
	thread _thread2(threadProcess, this, rt[2], &nRet[2]);
	thread _thread3(threadProcess, this, rt[3], &nRet[3]);

	_thread0.join();
	_thread1.join();
	_thread2.join();
	_thread3.join();

	int nSum;
	for (int k = 0; k < 4; k++)
		nSum += nRet[k];

	auto end = system_clock::now();
	auto millisec = duration_cast<milliseconds>(end - start);

	cout << nSum << "\t" << millisec.count()*0.001 << "sec" << endl;

}

int CgPrjDlg::processImg(CRect rect)
{
	auto start = system_clock::now();

	CProcess process;
	int nTh = 0;
	int nRet = process.getStarInfo(&m_pDlgImage->m_image, nTh, rect);

	auto end = system_clock::now();
	auto millisec = duration_cast<milliseconds>(end - start);

	cout << nRet << "\t" << millisec.count()*0.001 << "sec" << endl;
	return nRet;
}


