#pragma once

// CProcess 명령 대상입니다.


class CProcess : public CObject
{
public:
	CProcess();
	virtual ~CProcess();

	// 함수 선언부
	// 여기서 nTh의 기본값을 설정해주면 값을 안 넘겨줘도 된다. 예) nTh = 100
	int getStarInfo(CImage* pImage, int nTh);
	int getStarInfo(CImage* pImage, int nTh, CRect rect);
};


