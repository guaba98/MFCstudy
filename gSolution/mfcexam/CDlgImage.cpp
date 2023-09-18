// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "mfcexam.h"
#include "afxdialogex.h"
#include "CDlgImage.h"


// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
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
	ON_BN_CLICKED(IDC_BTN_PARENT, &CDlgImage::OnBnClickedBtnParent)
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기

#include "mfcexamDlg.h"
void CDlgImage::OnBnClickedBtnParent()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static int n = 100;
	CmfcexamDlg* pDlg = (CmfcexamDlg*)m_pParent;
	pDlg->callFunc(n++);
}

