
// MFCstartDlg.cpp: 구현 파일
//

// 헤더(파일 선언)
#include "pch.h"
#include "framework.h"
#include "MFCstart.h"
#include "MFCstartDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

// 열거형 자료형을 사용해서 사용자가 어떤 연산자 버튼을 눌렀는지 구분하기
enum FourOP {
	PLUS = 1001,
	MINUS,
	MULTIPLY,
	DIVIDE,
	NONE
};

CString m_strDisplay;   // 화면에 표시될 문자열
int m_nSecondOperand;  // 두 번째 입력한 피 연산자

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
	
END_MESSAGE_MAP()





// CMFCstartDlg 대화 상자


// CMFstartDIg에 있는 부분을 상속받아 -> CMFstartDIg를 생성한다.(상속 개념)

CMFCstartDlg::CMFCstartDlg(CWnd* pParent /*=nullptr*/) // CWnd 의 Parent(부모)는 Null 값이다.
	: CDialogEx(IDD_MFCSTART_DIALOG, pParent)
	, m_EditDisplay(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCstartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, m_strDisplay);  // IDC_EDIT5는 표시용 Edit Control의 ID입니다.

}

// 실행되는 이벤트들 모음
BEGIN_MESSAGE_MAP(CMFCstartDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON_1, &CMFCstartDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CMFCstartDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CMFCstartDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CMFCstartDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CMFCstartDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CMFCstartDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CMFCstartDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CMFCstartDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CMFCstartDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &CMFCstartDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_RESULT2, &CMFCstartDlg::OnBnClickedButtonResult2)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCstartDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CMFCstartDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CMFCstartDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CMFCstartDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CMFCstartDlg::OnBnClickedButtonResult)
END_MESSAGE_MAP()




// CMFCstartDlg 메시지 처리기
// CMFCstartDlg 밑에 OnInitDialog가 있다고 이해하기
// 초기화 할 때 수행되는 함수이다.
BOOL CMFCstartDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	m_selectedOP = NONE;
	m_nFirstOperand = 0;
	m_nSecondOperand = 0;
	m_nResult = 0;
	m_strDisplay = _T("");

	UpdateData(FALSE); // 초기값 ui에 전송


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCstartDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCstartDlg::OnPaint()
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
HCURSOR CMFCstartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#include <iostream>
using namespace std;
void CMFCstartDlg::OnBnClickedTest()
{
	UpdateData(TRUE);
	

	UpdateData(false);

}



void CMFCstartDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("1");  // "1"을 m_strDisplay에 추가합니다.
	UpdateData(FALSE);
	
}


void CMFCstartDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("2");  
	UpdateData(FALSE);

}


void CMFCstartDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("3");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("4");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("5");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("6");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("7");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("8");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("9");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButton0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_strDisplay = m_strDisplay + _T("0");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButtonResult2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selectedOP = NONE;
	m_nFirstOperand = 0;
	m_nSecondOperand = 0;
	m_nResult = 0;
	m_strDisplay = _T("");
	UpdateData(FALSE);
}



void CMFCstartDlg::OnBnClickedButtonAdd()
{
	
	UpdateData(TRUE);
	m_nFirstOperand = _ttoi(m_strDisplay);
	m_selectedOP = PLUS;
	m_strDisplay = _T("");
	UpdateData(FALSE);
}



void CMFCstartDlg::OnBnClickedButtonMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nFirstOperand = _ttoi(m_strDisplay);
	m_selectedOP = MINUS;
	m_strDisplay = _T("");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButtonMul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nFirstOperand = _ttoi(m_strDisplay);
	m_selectedOP = MULTIPLY;
	m_strDisplay = _T("");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButtonDiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nFirstOperand = _ttoi(m_strDisplay);
	m_selectedOP = DIVIDE;
	m_strDisplay = _T("");
	UpdateData(FALSE);
}


void CMFCstartDlg::OnBnClickedButtonResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nSecondOperand = _ttoi(m_strDisplay);

	switch (m_selectedOP) {
	case PLUS:
		m_nResult = m_nFirstOperand + m_nSecondOperand;
		break;
	case MINUS:
		m_nResult = m_nFirstOperand - m_nSecondOperand;
		break;
	case MULTIPLY:
		m_nResult = m_nFirstOperand * m_nSecondOperand;
		break;
	case DIVIDE:
		if (m_nSecondOperand != 0)
			m_nResult = m_nFirstOperand / m_nSecondOperand;
		else
			m_strDisplay = _T("Error");  // 0으로 나눌 때 오류 메시지 표시
		break;
	}

	m_strDisplay.Format(_T("%d"), m_nResult);
	UpdateData(FALSE);
}
