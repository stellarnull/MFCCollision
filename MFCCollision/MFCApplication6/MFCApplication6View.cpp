
// MFCApplication6View.cpp : CMFCApplication6View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication6.h"
#endif

#include "MFCApplication6Doc.h"
#include "MFCApplication6View.h"
#include "DlgInput.h"
#include "CalcDlg.h"
#include "PlayDlg.h"
#include "SortDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6View

IMPLEMENT_DYNCREATE(CMFCApplication6View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFCApplication6View::On32771)
	ON_COMMAND(ID_32772, &CMFCApplication6View::On32772)
	ON_COMMAND(ID_32774, &CMFCApplication6View::On32774)
	ON_COMMAND(ID_32773, &CMFCApplication6View::On32773)
END_MESSAGE_MAP()

// CMFCApplication6View ����/����

CMFCApplication6View::CMFCApplication6View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication6View::~CMFCApplication6View()
{
}

BOOL CMFCApplication6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6View ����

void CMFCApplication6View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication6View ��ӡ

BOOL CMFCApplication6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCApplication6View ���

#ifdef _DEBUG
void CMFCApplication6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6Doc* CMFCApplication6View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6Doc)));
	return (CMFCApplication6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6View ��Ϣ�������


void CMFCApplication6View::On32771() //�˵����ײ����ģ��
{
	CDlgInput cdlg;	
	cdlg.DoModal();
}


void CMFCApplication6View::On32772()  //�˵������
{
	CCalcDlg cclg;
	cclg.DoModal();
}


void CMFCApplication6View::On32774()  //�˵������
{
	CPlayDlg cplg;
	cplg.DoModal();
}


void CMFCApplication6View::On32773()  //�˵�����������
{
	CSortDlg cslg;
	cslg.DoModal();
}
