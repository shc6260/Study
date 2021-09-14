
// 3_201707080_신희찬View.cpp: CMy3201707080신희찬View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "3_201707080_신희찬.h"
#include "MainFrm.h"
#endif

#include "3_201707080_신희찬Doc.h"
#include "3_201707080_신희찬View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3201707080신희찬View

IMPLEMENT_DYNCREATE(CMy3201707080신희찬View, CView)

BEGIN_MESSAGE_MAP(CMy3201707080신희찬View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_LINE, &CMy3201707080신희찬View::OnLine)
	ON_COMMAND(ID_CIRCLE, &CMy3201707080신희찬View::OnCircle)
	ON_COMMAND(ID_POLYGON, &CMy3201707080신희찬View::OnPolygon)
	ON_COMMAND(ID_RED, &CMy3201707080신희찬View::OnRed)
	ON_COMMAND(ID_BLUE, &CMy3201707080신희찬View::OnBlue)
	ON_COMMAND(ID_CROSS, &CMy3201707080신희찬View::OnCross)
	ON_COMMAND(ID_RECT, &CMy3201707080신희찬View::OnRect)
	ON_COMMAND(ID_BLACK, &CMy3201707080신희찬View::OnBlack)
	ON_COMMAND(ID_YELLOW, &CMy3201707080신희찬View::OnYellow)
	ON_COMMAND(ID_BDIAGONAL, &CMy3201707080신희찬View::OnBdiagonal)
	ON_COMMAND(ID_Vertical, &CMy3201707080신희찬View::OnVertical)
	ON_COMMAND(ID_Horizon, &CMy3201707080신희찬View::OnHorizon)
	ON_COMMAND(ID_FDIAGONAL, &CMy3201707080신희찬View::OnFdiagonal)
	ON_COMMAND(ID_HS_DIAGCROSS, &CMy3201707080신희찬View::OnHsDiagcross)
	ON_COMMAND(ID_CAR, &CMy3201707080신희찬View::OnCar)
	ON_COMMAND(ID_CANDY, &CMy3201707080신희찬View::OnCandy)
	ON_COMMAND(ID_YOUTUBE, &CMy3201707080신희찬View::OnYoutube)
	ON_COMMAND(ID_CLEAR, &CMy3201707080신희찬View::OnClear)
END_MESSAGE_MAP()

// CMy3201707080신희찬View 생성/소멸

CMy3201707080신희찬View::CMy3201707080신희찬View() noexcept
	: m_ptstart(0), 
	m_ptpre(0) , 
	m_bfirst(false),
	m_blbuttondown(false),
	m_bhatch(false),
	m_ncount(0),
	m_ndrawmode(0)
{
	m_bfirst = true;
	m_blbuttondown = true;
	
	for (int i = 0; i < 50; i++) {
		m_ptdata[i] = 0;
	}
	m_ncount = 0;

	m_nhatchstyle = HS_CROSS;
	m_bhatch = false;
	m_colorpen = RGB(0,0,0);
	m_colorbrush = RGB(0, 0, 0);

}

CMy3201707080신희찬View::~CMy3201707080신희찬View()
{
}

BOOL CMy3201707080신희찬View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy3201707080신희찬View 그리기

void CMy3201707080신희찬View::OnDraw(CDC* pDC)
{
	CMy3201707080신희찬Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	CPen pen, * oldpen;
	pen.CreatePen(PS_SOLID, 3 , m_colorpen);
	oldpen = pDC->SelectObject(&pen);
	pDC->SetROP2(R2_COPYPEN);

	CBrush brush, * oldbrush;
	
	if (m_Bitmapi) {
		brush.CreatePatternBrush(&m_Bitmap);
		m_Bitmap.DeleteObject();
		m_Bitmapi = false;
	}

	else if (m_bhatch) {
		brush.CreateHatchBrush(m_nhatchstyle, m_colorbrush);
	}

	else
		brush.CreateSolidBrush(m_colorbrush);


	oldbrush = pDC->SelectObject(&brush);

	switch(m_ndrawmode){
	case 0:
		pDC->MoveTo(m_ptstart);
		pDC->LineTo(m_ptpre);
		break;

	case 1:
		pDC->Ellipse(m_ptstart.x, m_ptstart.y, m_ptpre.x, m_ptpre.y);
		break;

	case 2:
		pDC->Polygon(m_ptdata, m_ncount);
		break;
	case 3:
		pDC->Rectangle(m_ptstart.x, m_ptstart.y, m_ptpre.x, m_ptpre.y);
		break;
	}
	

	pDC->SelectObject(oldpen);
	pDC->SelectObject(oldbrush);
	pen.DeleteObject();
	brush.DeleteObject();
}


// CMy3201707080신희찬View 진단

#ifdef _DEBUG
void CMy3201707080신희찬View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3201707080신희찬View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3201707080신희찬Doc* CMy3201707080신희찬View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3201707080신희찬Doc)));
	return (CMy3201707080신희찬Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3201707080신희찬View 메시지 처리기


void CMy3201707080신희찬View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (m_bfirst) {//처음 그리는 것을 체크
		m_ptstart = 0;
		m_ptpre = 0;
		m_bfirst = true;
		m_ncount = 0;

		for (int i = 0; i < 50; i++) {
			m_ptdata[i] = 0;
		}
		Invalidate(true);
	}
	switch (m_ndrawmode)
	{
		case 0:
		case 1:
		case 3:
			m_blbuttondown = true;
			m_ptstart = point;
			m_ptpre = point;
			m_bfirst = false;
			break;
		case 2:
			if (m_bfirst) {
				m_bfirst = false;
			}
			m_ptstart = point;
			m_ptpre = point;
			m_ptdata[m_ncount] = point;
			m_ncount++;
			break;
			
	}
	RECT rectclient;
	//마우스캡쳐
	SetCapture();
	//클라이언트 영역
	GetClientRect(&rectclient);
	//스크린 좌표계 변환
	ClientToScreen(&rectclient);
	//마우스 이동 제한
	::ClipCursor(&rectclient);
		
	CView::OnLButtonDown(nFlags, point);
}


void CMy3201707080신희찬View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//pen설정
	CClientDC dc(this);
	CPen pen, * oldpen;
	pen.CreatePen(PS_SOLID,3,RGB(0,0,250));
	oldpen = dc.SelectObject(&pen);
	dc.SetROP2(R2_XORPEN);

	//burush
	CBrush brush, * oldbrush;
	if (m_bhatch) {//패턴으로 채움 
		brush.CreateHatchBrush(m_nhatchstyle, m_colorbrush);
	}
	else {
		brush.CreateSolidBrush(m_colorbrush);
	}

	//brush 객체 등록
	oldbrush = dc.SelectObject(&brush);
	switch(m_ndrawmode) {
		case 0:
			if (m_blbuttondown) {
				dc.MoveTo(m_ptstart);
				dc.LineTo(m_ptpre);
				dc.MoveTo(m_ptstart);
				dc.LineTo(point);
				m_ptpre = point;
			}
			break;

		case 1:
			if (m_blbuttondown) {
				dc.Ellipse(m_ptstart.x, m_ptstart.y, m_ptpre.x, m_ptpre.y);
				dc.Ellipse(m_ptstart.x, m_ptstart.y, point.x, point.y);
				m_ptpre = point;
			}
			break;
		case 2:
			if (!m_bfirst) {
				dc.MoveTo(m_ptstart);
				dc.LineTo(m_ptpre);
				dc.MoveTo(m_ptstart);
				dc.LineTo(point);
				m_ptpre = point;
			}
			break;

		case 3:
			if (m_blbuttondown) {
				dc.Rectangle(m_ptstart.x, m_ptstart.y, m_ptpre.x, m_ptpre.y);
				dc.Rectangle(m_ptstart.x, m_ptstart.y, point.x, point.y);
				m_ptpre = point;
			}
			break;
	}

	dc.SelectObject(oldpen);
	dc.SelectObject(oldbrush);
	pen.DeleteObject();
	brush.DeleteObject();
	//메인프레임 포인터 얻어오기
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CString strPoint;
	strPoint.Format(_T("마우스 위치 X :d, Y : %d"),point.x, point.y);

	pFrame->m_wndStatusBar.SetPaneText(1,strPoint);



	CView::OnMouseMove(nFlags, point);
}


void CMy3201707080신희찬View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (m_blbuttondown) {
		if (m_ndrawmode == 0 || m_ndrawmode == 1 || m_ndrawmode == 3) {
			m_blbuttondown = false;
			m_bfirst = true;
			ReleaseCapture();
			::ClipCursor(NULL);
			Invalidate();
		}
	}

	CView::OnLButtonUp(nFlags, point);
}


void CMy3201707080신희찬View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

		if (m_ndrawmode == 2) {
			if (!m_bfirst) {
				m_ptdata[m_ncount] = point;
				m_ncount++;

				m_bfirst = true;
				ReleaseCapture();
				::ClipCursor(NULL);
				Invalidate(TRUE);
			}
		}	
	

	CView::OnRButtonDown(nFlags, point);
}


void CMy3201707080신희찬View::OnLine()
{
	m_ndrawmode = 0;
	Invalidate();
}


void CMy3201707080신희찬View::OnCircle()
{
	m_ndrawmode = 1;
	Invalidate();
}




void CMy3201707080신희찬View::OnPolygon()
{
	m_ndrawmode = 2;
	Invalidate();
}


void CMy3201707080신희찬View::OnRed()
{
	m_colorpen = RGB(255,0,0);
	m_colorbrush = RGB(255, 0, 0);
	
	Invalidate();
}


void CMy3201707080신희찬View::OnBlue()
{
	m_colorpen = RGB(0, 0, 255);
	m_colorbrush = RGB(0, 0, 255);
	
	Invalidate();
}


void CMy3201707080신희찬View::OnCross()
{
	m_nhatchstyle = HS_CROSS;
	m_bhatch = TRUE;
	Invalidate(true);
}


void CMy3201707080신희찬View::OnRect()
{
	m_ndrawmode = 3;
	Invalidate();
}


void CMy3201707080신희찬View::OnBlack()
{
	m_colorpen = RGB(0, 0, 0);
	m_colorbrush = RGB(0, 0, 0);
	Invalidate();
}


void CMy3201707080신희찬View::OnYellow()
{
	m_colorpen = RGB(255, 255, 0);
	m_colorbrush = RGB(255, 255, 0);
	Invalidate();
}


void CMy3201707080신희찬View::OnBdiagonal()
{
	m_nhatchstyle = HS_BDIAGONAL;
	m_bhatch = true;
	Invalidate(true);
}


void CMy3201707080신희찬View::OnVertical()
{
	m_nhatchstyle = HS_VERTICAL;
	m_bhatch = true;
	Invalidate(true);
}


void CMy3201707080신희찬View::OnHorizon()
{
	m_nhatchstyle = HS_HORIZONTAL;
	m_bhatch = true;
	Invalidate(true);
}


void CMy3201707080신희찬View::OnFdiagonal()
{
	m_nhatchstyle = HS_FDIAGONAL;
	m_bhatch = true;
	Invalidate(true);
}


void CMy3201707080신희찬View::OnHsDiagcross()
{
	m_nhatchstyle = HS_DIAGCROSS;
	m_bhatch = true;
	Invalidate(true);
}


void CMy3201707080신희찬View::OnCar()
{
	m_Bitmap.LoadBitmapW(IDB_BITMAP1);
	m_Bitmapi = true;
	Invalidate();
}


void CMy3201707080신희찬View::OnCandy()
{
	m_Bitmap.LoadBitmapW(IDB_BITMAP2);
	m_Bitmapi = true;
	Invalidate();

}


void CMy3201707080신희찬View::OnYoutube()
{
	m_Bitmap.LoadBitmapW(IDB_BITMAP3);
	m_Bitmapi = true;
	Invalidate();
}


void CMy3201707080신희찬View::OnClear()
{
	m_bhatch = false;
	Invalidate();
}
