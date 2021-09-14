
// 3_201707080_신희찬View.h: CMy3201707080신희찬View 클래스의 인터페이스
//

#pragma once


class CMy3201707080신희찬View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy3201707080신희찬View() noexcept;
	DECLARE_DYNCREATE(CMy3201707080신희찬View)

// 특성입니다.
public:
	CMy3201707080신희찬Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMy3201707080신희찬View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CPoint m_ptstart;
	CPoint m_ptpre;
	bool m_bfirst;
	bool m_blbuttondown;
	bool m_bhatch;
	CPoint m_ptdata[50];

	int m_ncount;
	COLORREF m_colorpen;
	COLORREF m_colorbrush;
	int m_ndrawmode;
	int m_nhatchstyle;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLine();
	afx_msg void OnCircle();
	afx_msg void OnPolygon();
	afx_msg void OnRed();
	afx_msg void OnBlue();
	afx_msg void OnCross();
	afx_msg void OnRect();
	afx_msg void OnBlack();
	afx_msg void OnYellow();
	afx_msg void OnBdiagonal();
	afx_msg void OnVertical();
	afx_msg void OnHorizon();
	afx_msg void OnFdiagonal();
	afx_msg void OnHsDiagcross();
	afx_msg void OnCar();
	afx_msg void OnCandy();
	CBitmap m_Bitmap;
//	int m_Bitmapi;
	bool m_Bitmapi = false;
	afx_msg void OnYoutube();
	afx_msg void OnClear();
};

#ifndef _DEBUG  // 3_201707080_신희찬View.cpp의 디버그 버전
inline CMy3201707080신희찬Doc* CMy3201707080신희찬View::GetDocument() const
   { return reinterpret_cast<CMy3201707080신희찬Doc*>(m_pDocument); }
#endif

