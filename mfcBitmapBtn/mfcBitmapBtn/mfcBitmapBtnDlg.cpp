
// mfcBitmapBtnDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcBitmapBtn.h"
#include "mfcBitmapBtnDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
//	afx_msg void OnDestroy();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CmfcBitmapBtnDlg 대화 상자



CmfcBitmapBtnDlg::CmfcBitmapBtnDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCBITMAPBTN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcBitmapBtnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcBitmapBtnDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_ON_OFF, &CmfcBitmapBtnDlg::OnBnClickedBtnOnOff)
END_MESSAGE_MAP()


// CmfcBitmapBtnDlg 메시지 처리기

BOOL CmfcBitmapBtnDlg::OnInitDialog()
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
	initButtons(); // 버튼 기본 작업 설정

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcBitmapBtnDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcBitmapBtnDlg::OnPaint()
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
HCURSOR CmfcBitmapBtnDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 다이얼로그 박스의 배경을 특정 png로 채우기
BOOL CmfcBitmapBtnDlg::OnEraseBkgnd(CDC* pDC)
{	
	CPngImage image; // 이미지 객체 생성
	image.Load(IDB_BASE, nullptr); // 설정한 id 값을 통해 이미지를 가져옴

	CDC dc; // pDC와 호환되는 메모리 DC를 생성
	dc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = dc.SelectObject(&image);

	pDC->BitBlt(0, 0, 640, 480, &dc, 0, 0, SRCCOPY); // dc에서 pDC로 비트맵의 내용을 복사하는 데 사용됨
	dc.SelectObject(pOldBitmap); // 메모리 DC에서 원래의 비트맵 객체를 다시 선택함. 
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}

void CmfcBitmapBtnDlg::initButtons()
{
	CRect rect(0, 0, 100, 50); // (x, y) 위치와 (가로, 세로) 폭을 지정 
	GetDlgItem(IDC_BTN_ON_OFF)->GetWindowRect(&rect); // 버튼의 위치를 가져온다.
	// GetDlgItem(IDC_BTN_ON_OFF)->GetClientRect(&rect);
	m_pBtnOnOff = new CBitmapButton; // m_pBtnOnOff라는 포인터에 CBitmapButton을 동작으로 생성하고 할당한다.
	m_pBtnOnOff->Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rect, this, IDC_BTN_ON_OFF); // 버튼에 해당된 속성 지정
	m_pBtnOnOff->LoadBitmaps(IDB_ON, IDB_OFF); // 디폴트, 셀렉트, 포커스, 사용하지 않을 때 이미지를 로드할 수 있다. 
	m_pBtnOnOff->SizeToContent(); //크기에 맞게 사이즈 조정


}



// 메모리 누수가 발생하지 않게 버튼 생성을 처리해줌

void CmfcBitmapBtnDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_pBtnOnOff) delete m_pBtnOnOff;
}


void CmfcBitmapBtnDlg::OnBnClickedBtnOnOff()
{
	static bool bOn = false;
	if (bOn) {
		m_pBtnOnOff->LoadBitmaps(IDB_ON);
	}
	else {
		m_pBtnOnOff->LoadBitmaps(IDB_OFF);
	}
	bOn = !bOn;
}
