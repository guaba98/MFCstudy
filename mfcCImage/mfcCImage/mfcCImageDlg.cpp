
// mfcCImageDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcCImage.h"
#include "mfcCImageDlg.h"
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


// CmfcCImageDlg 대화 상자



CmfcCImageDlg::CmfcCImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCIMAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcCImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcCImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_IMAGE, &CmfcCImageDlg::OnBnClickedBtnImage)
	ON_BN_CLICKED(IDC_BUTTON2, &CmfcCImageDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CmfcCImageDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CmfcCImageDlg::OnBnClickedBtnAction)
END_MESSAGE_MAP()


// CmfcCImageDlg 메시지 처리기

BOOL CmfcCImageDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcCImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcCImageDlg::OnPaint()
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
HCURSOR CmfcCImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcCImageDlg::OnBnClickedBtnImage()
{
	// 클래스에서 사용하는 변수(n이 붙는다)
	// 멤버변수 지역변수
	int nWidth = 640; // 가로폭 픽셀
	int nHeight = 480; // 세로폭 픽셀
	int nBpp = 8; // gray level

	// 이미지 생성
	m_image.Create(nWidth, -nHeight, nBpp); // 모든 변수를 만들때는 파라마터 값에 숫자를 안 주는게 중요하다. -> 위에서 설정한 변수를 사용해 준다.
	BOOL vaildImgPos(int x, int y);

	// 조건 작성
	// 흑백을 기준으로 display 하게 되어있기 때문에 컬러로 할려면 설정을 따로 해줘야 한다.

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits(); // 내가 만든 이미지의 첫번째 포인터의 값을 가져오겠다.
	
	// fm은 이미지 데이터의 시작 포인터를 가리킨다. 이미지 데이터는 메모리에 연속적으로 배열된 행으로 구성된다.
	// 각 행의 끝과 다음 행의 시작 사이에는 간격(nPitch)가 있을 수 있다.


	memset(fm, 0xff, nWidth * nHeight); // 메모리를 어떠한 값으로 연결할 것인지
	
	//for (int j = 0; j < nHeight; j++) {
	//	for (int i = 0; i < nWidth; i++) {
	//		// 2d 이미지 좌표 (i, j)를 1D메모리 주소로 변환한다. 
	//		// 255는 해당 픽셀의 값에 할당된다. 255를 할당하면 흰색으로 표시된다.
	//		// nBpp=8이 그레이스케일이미지므로 0(검은색) 부터 255(흰색)까지 값이 할당된다.
	//		fm[j * nPitch + i] = (j*60)%255; 
	//		
	//	}
	//}

	

	// 이미지 그리기
	UpdateDisplay(); // 이미지 업데이트 하는 함수 호출

}

// 전역변수로 선언
CString g_strFileImage = _T("c:\\image\\save.bmp");
void CmfcCImageDlg::OnBnClickedButton2()
{
	// 이미지 저장하기
	m_image.Save(g_strFileImage);
}


void CmfcCImageDlg::OnBnClickedButton3()
{
	// 이미지가 없으면 제거
	if (m_image != NULL) {
		m_image.Destroy();
	}
	// 이미지 로드하기
	m_image.Load(g_strFileImage);

	UpdateDisplay();
}

// 이미지 업데이트 하는 함수 생성
void CmfcCImageDlg::UpdateDisplay() 
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CmfcCImageDlg::moveCircle()
{
	static int nSttX = 0;
	static int nSttY = 0;
	int nGray = 80;
	int nWidth = m_image.GetWidth(); // 가로폭 픽셀
	int nHeight = m_image.GetHeight(); // 세로폭 픽셀
	unsigned char* fm = (unsigned char*)m_image.GetBits(); // 내가 만든 이미지의 첫번째 포인터의 값을 가져오겠다.
	int nPitch = m_image.GetPitch();
	
	// 전체 이미지를 흰색으로 초기화한다.
	memset(fm, 0xff, nWidth * nHeight); // 메모리를 어떠한 값으로 연결할 것인지

	// 원의 반지름을 설정한다.
	int r = 24;

	for (int j = nSttY - r; j < nSttY + r; j++) {
		for (int i = nSttX - r; i < nSttX + r; i++) {
			int dx = i - nSttX;
			int dy = j - nSttY;
			if (vaildImgPos(i, j) && (dx * dx + dy * dy <= r * r)) {
				// 픽셀이 이미지 내에 있고, 원의 내부에 있는 경우에만 그레이로 채웁니다.
				fm[j * nPitch + i] = nGray;
			}
		}
	}
	nSttX++;
	nSttY++;
	UpdateDisplay();
}

void CmfcCImageDlg::OnBnClickedBtnAction()
{
	for (int i = 0;i < 640; i++) {
		moveCircle();
		Sleep(1);
	}
	
}

BOOL CmfcCImageDlg::vaildImgPos(int x, int y) 
{
	int nWidth = m_image.GetWidth(); // 가로폭 픽셀
	int nHeight = m_image.GetHeight(); // 세로폭 픽셀

	CRect rect(0, 0, nWidth, nHeight);
	// 주어진 x, y 에 대해서 영역 안에 들어가면 그 값을 리턴해 준다.
	return rect.PtInRect(CPoint(x, y)); // Cpoint값으로 바꿔 준다.

}
