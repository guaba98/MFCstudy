
// gPrjDlg.h : ��� ����
//
#include "DlgImage.h" // ������Ͽ� �߰��Ѵ�.

#pragma once


// CgPrjDlg ��ȭ ����
class CgPrjDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CgPrjDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	CDlgImage *m_pDlgImage; // �̹��� �׸� â ���� ����
	CDlgImage *m_pDlgImgResult; // ������ â ���� ����

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GPRJ_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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