
// MFCstartDlg.h: 헤더 파일
//

#pragma once


// CMFCstartDlg 대화 상자
class CMFCstartDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCstartDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.


	enum FourOP m_selectedOP; // 사칙연산 선택자
	CString m_strDisplay; // 화면에 표시될 문자열
	int m_nFirstOperand; // 첫 번째 입력한 피 연산자
	int m_nSecondOperand; // 두 번째 입력한 피 연산자
	int m_nResult; // 결과값 저장


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSTART_DIALOG };
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
	afx_msg void OnBnClickedTest();
	int m_nNum;
	CString m_EditDisplay;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonResult2();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonResult();
};
