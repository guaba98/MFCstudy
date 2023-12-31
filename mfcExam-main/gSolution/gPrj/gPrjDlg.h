
// gPrjDlg.h : 헤더 파일
//
#include "DlgImage.h" // 헤더파일에 추가한다.

#pragma once


// CgPrjDlg 대화 상자
class CgPrjDlg : public CDialogEx
{
// 생성입니다.
public:
	CgPrjDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	CDlgImage *m_pDlgImage; // 이미지 그릴 창 변수 생성
	CDlgImage *m_pDlgImgResult; // 복사할 창 변수 생성

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GPRJ_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedBtnDlg();
	afx_msg void OnDestroy();
	
	void callFunc(int n);
	afx_msg void OnBnClickedBtnTest();
};
