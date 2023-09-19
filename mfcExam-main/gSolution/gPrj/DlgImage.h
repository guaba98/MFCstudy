#pragma once
#define MAX_POINT 100

// CDlgImage ��ȭ �����Դϴ�.

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgImage();

	CImage m_image;
	CWnd* m_pParent;
	int m_nDataCount = 0; // ��� �׸� ������
	CPoint m_ptData[MAX_POINT]; // �迭(��ǥ��)

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif
private:
	void datwData(CDC* pDC);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnUpParent();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

	void initImage();
};
