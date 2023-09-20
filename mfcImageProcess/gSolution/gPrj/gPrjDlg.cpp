
// gPrjDlg.cpp : 구현 파일
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
	ON_WM_PAINT()
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
	//ShowWindow(SW_SHOWMAXIMIZED);
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);

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


// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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

#include "Process.h" // 1. 프로세스 정보를 가져온다.
#include <chrono> // 크로노 함수 
#include <thread>
using namespace std; // std::를 축약해 준다.
using namespace chrono; // std::chrono::를 축약해 준다.

void CgPrjDlg::OnBnClickedBtnProcess()
{
	// 현재 시간을 start 변수에 저장한다. 현재 시간의 형태를 auto로 가져온다는 것은 정하지 않겠다는 의미이다.
	// 선언할 때 꼭 형태를 만들어 줘야 한다.
	auto start = system_clock::now(); 

	// 인클루드 한 Process의 객체를 생성한다.
	CProcess process; 
	int nTh = 0;

	// 이미지의 주소, nTh 값을 넘겨준다. nTh를 안 주면 에러가 나는데, nTH
	int nRet = process.getStarInfo(&m_pDlgImage->m_image, nTh); // 현재 DlgImage의 m_image의 포인트 주소만 가져온다.(& 사용)
//	Sleep(1000);
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	// 경과시간을 구하기 위해 모든 프로세스가 끝난 후 값을 구한다.
	auto end = system_clock::now();
	auto millisec = duration_cast<milliseconds>(end - start); // 마지막 시간 - 처음시간을 해서 경과시간을 구한다.
	
	// 출력하기
	/*cout << nRet << "\t"<< millisec.count()*0.001 << "sec" <<endl;*/
}

// 패턴 버튼을 클릭했을 때
#define YELLOW RGB(255, 255, 0)
void CgPrjDlg::OnBnClickedBtnMakePattern()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();

	// 각 가로, 세로, 피치 값을 가져오기
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	int nIndex = 0;
	int x = rand() % nWidth;
	int y = rand() % nHeight;
	int penWidth = 20; // 원의 테두리 두께

	CString str;
	mEdit.GetWindowText(str);
	int r = _wtoi(str.GetBuffer()); // int형으로 변환(반지름)
	str.ReleaseBuffer();

	memset(fm, 30, nWidth * nHeight * 3);

	// 원 그리기
	for (int j = y - r; j < y + r; j++) {
		for (int i = x - r; i < x + r; i++) {
			if (!vaildImgPos(i, j)) {
				continue; // 해당 위치가 이미지 경계를 벗어났다면 다음 위치로 넘어간다.
			}

			int dx = i - x;
			int dy = j - y;
			int distanceSquared = dx * dx + dy * dy; // 원 범위 안에 위치 변수
			int index = (j * nPitch + i * 3);

			if (distanceSquared <= r * r) { // 검은색
				fm[index] = 255;     // Red
				fm[index + 1] = 255; // Green
				fm[index + 2] = 255; // Blue
			}

			// 원의 중심에 십자 표시
			if ((i == x || j == y) && distanceSquared <= r * r) {
				fm[index + 2] = 0;     // Red
				fm[index + 1] = 0; // Green
				fm[index] = 0; // Blue
			}
			// 원의 내부가 아닌 테두리 부분만 색칠하기 위한 조건
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

	// 화면에 표시하기
	m_pDlgImage->Invalidate();
}

BOOL CgPrjDlg::vaildImgPos(int x, int y) {
	int nWidth = m_pDlgImage->m_image.GetWidth(); // 가로폭 픽셀
	int nHeight = m_pDlgImage->m_image.GetHeight(); // 세로폭 픽셀

	CRect rect(0, 0, nWidth, nHeight);
	// 주어진 x, y 에 대해서 영역 안에 들어가면 그 값을 리턴해 준다.
	return rect.PtInRect(CPoint(x, y)); // Cpoint값으로 바꿔 준다.
}




// 무게중심 값 구하기(중심값)
void CgPrjDlg::OnBnClickedBtnGetData()
{

	// 위의 코드와 동일하게 이미지의 값을 얻어옴
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	// 변수 선언
	int nTh = 0x80; // 중간 값
	int nSumX = 0; // X값
	int nSumY = 0; // Y값
	int nCount = 0;

	// 모든 영역에 해당하게 하기 위해 아래와 같이 0, 0, nWidth, nHeight로 설정함
	CRect rect(0, 0, nWidth, nHeight);

	// 데이터를 이용해서 얻어내가 위해
	// 각 픽셀의 좌표가 특정 값보다 크면(nTh)
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j*nPitch + i] > nTh) {
				// 센터값을 구하기 위해 X좌표에 1씩 추가, Y좌표에 1씩 추가해줌
				nSumX += i; // 좌표값 더하기
				nSumY += j;
				nCount++; // 몇 번 실행되었는지 알기 위해서 하나씩 증가시키기
			}
		}
	}

	// 출력 위해 계산 (몇 번 카운트 되었는지 알기 위해서)
	// 더블 형으로 선언했지만, int / int이기때문에 값은 int가 됨 -> 둘 중에 하나는 형변환을 해줘야 함
	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	// 출력
	cout << dCenterX << "\t" << dCenterY << endl;

	// 화면에 업데이트
	m_pDlgImage->Invalidate();
}

void threadProcess(CWnd* pParent, CRect rect, int *nRet)
{
	CgPrjDlg *pWnd = (CgPrjDlg*)pParent;
	*nRet = pWnd->processImg(rect);
}

void CgPrjDlg::OnBnClickedBtnThread()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


