#pragma once
#define MAX_POINT 100

// CDlgImage 대화 상자입니다.

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	CImage m_image;
	CWnd* m_pParent;
	int m_nDataCount = 0; // 몇개를 그릴 것인지
	CPoint m_ptData[MAX_POINT]; // 배열(좌표값)

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif
private:
	void datwData(CDC* pDC);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnUpParent();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

	void initImage();
};
