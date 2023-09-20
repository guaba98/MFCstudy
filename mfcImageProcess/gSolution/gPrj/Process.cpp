// Process.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gPrj.h"
#include "Process.h"


// CProcess

CProcess::CProcess()
{
}

CProcess::~CProcess()
{
}


// CProcess 멤버 함수
// 리턴값이 있기 때문에 함수 형태를 int로 바꿔줌
int CProcess::getStarInfo(CImage* pImage, int nTh) // 포인터 형태로 줬기 때문에 p를 붙여줌
{
	unsigned char* fm = (unsigned char*)pImage->GetBits(); 

	// 이미지에 대한 정보를 얻을 수있기 때문에 pImage를 가져온 것
	int nWidth = pImage->GetWidth(); // 가로
	int nHeight = pImage->GetHeight(); // 세로
	int nPitch = pImage->GetPitch(); // 피치

	int nSum = 0;
	// 메모리의 영역까지 모든 값을 다 표현하면서 100보다 큰 값이 있으면 몇개인지 출력하는 모양
	for (int k = 0; k < nWidth*nHeight; k++) { 
		if (fm[k] > nTh)
			nSum++;
	}
	return nSum;
}

int CProcess::getStarInfo(CImage* pImage, int nTh, CRect rect)
{
	unsigned char* fm = (unsigned char*)pImage->GetBits();
	int nWidth = pImage->GetWidth();
	int nHeight = pImage->GetHeight();
	int nPitch = pImage->GetPitch();

	int nSum = 0;
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j*nPitch + i] > nTh) {
				nSum++;
			}
		}
	}
	return nSum;
}

