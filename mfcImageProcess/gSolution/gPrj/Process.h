#pragma once

// CProcess ��� ����Դϴ�.


class CProcess : public CObject
{
public:
	CProcess();
	virtual ~CProcess();

	// �Լ� �����
	// ���⼭ nTh�� �⺻���� �������ָ� ���� �� �Ѱ��൵ �ȴ�. ��) nTh = 100
	int getStarInfo(CImage* pImage, int nTh);
	int getStarInfo(CImage* pImage, int nTh, CRect rect);
};


