
// gPrjDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "gPrj.h"
#include "gPrjDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgPrjDlg 대화 상자



CgPrjDlg::CgPrjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GPRJ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgPrjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CgPrjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_TEST, &CgPrjDlg::OnBnClickedBtnTest)
END_MESSAGE_MAP()


// CgPrjDlg 메시지 처리기

BOOL CgPrjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	// 클래스 생성
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0, 0, 640, 480);

	m_pDlgImgResult = new CDlgImage;
	m_pDlgImgResult->Create(IDD_DLGIMAGE, this);
	m_pDlgImgResult->ShowWindow(SW_SHOW);
	m_pDlgImgResult->MoveWindow(640, 0, 640, 480);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CgPrjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CgPrjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 메모리 릭을 막기 위해 생성된 
void CgPrjDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if(m_pDlgImage) delete m_pDlgImage;
	if(m_pDlgImgResult) delete m_pDlgImgResult;
}

#include <iostream>
void CgPrjDlg::callFunc(int n)
{
//	int nData = n;
	std::cout << n << std::endl;
}
using namespace std;

void CgPrjDlg::OnBnClickedBtnTest()
{
	// 이미지 가져오기 
	// 화살표(->)는 포인터, 점(.)은 클래스를 의미
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits(); // 리턴값을 unsigned cha로 받는다는 뜻
	
	// 가로 세로 피치 값 가져오기
	int nWidth = m_pDlgImage->m_image.GetWidth(); // 가로
	int nHeight = m_pDlgImage->m_image.GetHeight(); // 세로
	int nPitch = m_pDlgImage->m_image.GetPitch(); // 픽셀마다 행 간격을 나타내는 값

	// 값 리셋
	memset(fm, 0xff, nWidth * nHeight);

	// 점찍기
	for (int k = 0; k < 100; k++) {
		int x = rand() % nWidth;
		int y = rand() % nHeight;
		fm[y * nPitch + x] = 0;
	}

	// 인덱스 값 변수 선언(초기값 0)
	int nIndex = 0; 

	// 찍힌 점의 좌표를 m_ptData 배열에 저장
	// 모든 픽셀을 탐지하기 위한 이중 for문: 너비만큼, 높이만큼 반복: (i, j)는 픽셀의 (x, y)에 해당
	for (int j = 0; j < nHeight;j++) { 
		for (int i = 0; i < nWidth; i++) {
			if (fm[j * nPitch + i] == 0) { // 좌표의 픽셀 값이 0인지(점이 찍혀 있는지) 확인
				// 찍힌 점을 찾았다면, 그 점의 좌표를 m_ptData 배열에 저장함
				if (m_pDlgImgResult->m_nDataCount <= 100) { // 먼저 m_nDataCount가 100 이하인지 확인(배열의 크기가 100이므로)
					m_pDlgImgResult->m_ptData[nIndex].x = i; // 찾은 점의 x 좌표를 배열에 저장
					m_pDlgImgResult->m_ptData[nIndex].y = j; // 찾은 점의 y 좌표를 배열에 저장
					// m_nDataCount 값을 1씩 증가시키며, 동시에 nIndex값을 1 증가시킨다. (++nIndex의 결과는 nIndex 증가 후의 값이므로)
					m_pDlgImgResult->m_nDataCount = ++nIndex; 
				}	
			}
		}
	}

	// 이미지 잘 가져왔는지 테스트
	// 뒤의 숫자는 얼만큼 칠할것인지
	// memset(fm, 0, 640 * 480); // 메모리셋에 fm(이미지포인터), 뒤에오는 것은 값: 

	// 화면에 업데이트
	m_pDlgImage->Invalidate(); // 왼쪽 화면 업데이트
	m_pDlgImgResult->Invalidate(); // 오른쪽 화면 업데이트
}
