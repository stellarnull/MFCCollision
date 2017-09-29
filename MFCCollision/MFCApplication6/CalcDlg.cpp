// CalcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "CalcDlg.h"
#include "afxdialogex.h"
#include <math.h>


// CCalcDlg �Ի���

IMPLEMENT_DYNAMIC(CCalcDlg, CDialogEx)

	CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalcDlg::IDD, pParent)
	, data1(0)
	, data2(0)
	, data3(0)
{

}

CCalcDlg::~CCalcDlg()
{
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_sb1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_sb2);
	DDX_Control(pDX, IDC_SLIDER3, m_slider);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//  DDX_Control(pDX, IDC_EDIT3, m_edit2);
	//  DDX_Control(pDX, IDC_EDIT4, m_edit3);
	//  DDX_Control(pDX, IDC_EDIT2, m_edit4);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_BUTTON3, m_button3);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
}


BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalcDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCalcDlg ��Ϣ�������


void CCalcDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if( pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR1 )
	{
		int iNowPos;
		switch(nSBCode)
		{
		case SB_THUMBTRACK:
			m_sb1.SetScrollPos(nPos);//ȡ�õ�ǰλ��ֵ  
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		case SB_LINEDOWN://�������������µļ�ͷ
			iNowPos = m_sb1.GetScrollPos();
			iNowPos ++;
			if(iNowPos>100)           
				iNowPos = 100;
			m_sb1.SetScrollPos(iNowPos);
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		case SB_LINEUP://�������������ϵļ�ͷ
			iNowPos = m_sb1.GetScrollPos();
			iNowPos --;
			if(iNowPos<0)
				iNowPos = 0;
			m_sb1.SetScrollPos(iNowPos);
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		case SB_PAGEDOWN://��������������ļ�ͷ�������֮������
			iNowPos = m_sb1.GetScrollPos();
			iNowPos += 10;
			if(iNowPos > 100)
				iNowPos = 100;
			m_sb1.SetScrollPos(iNowPos);
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		case SB_PAGEUP://��������������ļ�ͷ�������֮�������
			iNowPos = m_sb1.GetScrollPos();
			iNowPos -= 10;
			if(iNowPos<0)
				iNowPos = 0;
			m_sb1.SetScrollPos(iNowPos);
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		}
	}
	else if( pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR2)
	{
		int iNowPos;
		switch(nSBCode)
		{
		case SB_THUMBTRACK:
			m_sb2.SetScrollPos(nPos);//ȡ�õ�ǰλ��ֵ  
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		case SB_LINEDOWN://�������������µļ�ͷ
			iNowPos = m_sb2.GetScrollPos();
			iNowPos ++;
			if(iNowPos>100)           
				iNowPos = 100;
			m_sb2.SetScrollPos(iNowPos);
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		case SB_LINEUP://�������������ϵļ�ͷ
			iNowPos = m_sb2.GetScrollPos();
			iNowPos --;
			if(iNowPos<0)
				iNowPos = 0;
			m_sb2.SetScrollPos(iNowPos);
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		case SB_PAGEDOWN://��������������ļ�ͷ�������֮������
			iNowPos = m_sb2.GetScrollPos();
			iNowPos += 10;
			if(iNowPos > 100)
				iNowPos = 100;
			m_sb2.SetScrollPos(iNowPos);
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		case SB_PAGEUP://��������������ļ�ͷ�������֮�������
			iNowPos = m_sb2.GetScrollPos();
			iNowPos -= 10;
			if(iNowPos<0)
				iNowPos = 0;
			m_sb2.SetScrollPos(iNowPos);
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		}
	}
	else if( pScrollBar->GetDlgCtrlID() == IDC_SLIDER3)
	{
		CSliderCtrl *pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER3);
		int m_int = pSlidCtrl->GetPos();//ȡ�õ�ǰλ��ֵ  
		ChangeData3Display(m_int);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CCalcDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if( pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR1 )
	{
		int iNowPos;
		switch(nSBCode)
		{
		case SB_THUMBTRACK:
			m_sb1.SetScrollPos(nPos);//ȡ�õ�ǰλ��ֵ  
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		case SB_LINEDOWN://�������������µļ�ͷ
			iNowPos = m_sb1.GetScrollPos();
			iNowPos ++;
			if(iNowPos>100)           
				iNowPos = 100;
			m_sb1.SetScrollPos(iNowPos);
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		case SB_LINEUP://�������������ϵļ�ͷ
			iNowPos = m_sb1.GetScrollPos();
			iNowPos --;
			if(iNowPos<0)
				iNowPos = 0;
			m_sb1.SetScrollPos(iNowPos);
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		case SB_PAGEDOWN://��������������ļ�ͷ�������֮������
			iNowPos = m_sb1.GetScrollPos();
			iNowPos += 10;
			if(iNowPos > 100)
				iNowPos = 100;
			m_sb1.SetScrollPos(iNowPos);
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		case SB_PAGEUP://��������������ļ�ͷ�������֮�������
			iNowPos = m_sb1.GetScrollPos();
			iNowPos -= 10;
			if(iNowPos<0)
				iNowPos = 0;
			m_sb1.SetScrollPos(iNowPos);
			ChangeData1Display(m_sb1.GetScrollPos());
			break;
		}
	}
	else if( pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR2)
	{
		int iNowPos;
		switch(nSBCode)
		{
		case SB_THUMBTRACK:
			m_sb2.SetScrollPos(nPos);//ȡ�õ�ǰλ��ֵ  
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		case SB_LINEDOWN://�������������µļ�ͷ
			iNowPos = m_sb2.GetScrollPos();
			iNowPos ++;
			if(iNowPos>100)           
				iNowPos = 100;
			m_sb2.SetScrollPos(iNowPos);
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		case SB_LINEUP://�������������ϵļ�ͷ
			iNowPos = m_sb2.GetScrollPos();
			iNowPos --;
			if(iNowPos<0)
				iNowPos = 0;
			m_sb2.SetScrollPos(iNowPos);
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		case SB_PAGEDOWN://��������������ļ�ͷ�������֮������
			iNowPos = m_sb2.GetScrollPos();
			iNowPos += 10;
			if(iNowPos > 100)
				iNowPos = 100;
			m_sb2.SetScrollPos(iNowPos);
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		case SB_PAGEUP://��������������ļ�ͷ�������֮�������
			iNowPos = m_sb2.GetScrollPos();
			iNowPos -= 10;
			if(iNowPos<0)
				iNowPos = 0;
			m_sb2.SetScrollPos(iNowPos);
			ChangeData2Display(m_sb2.GetScrollPos());
			break;
		}
	}
	else if( pScrollBar->GetDlgCtrlID() == IDC_SLIDER3)
	{
		CSliderCtrl *pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER3);
		int m_int = pSlidCtrl->GetPos();//ȡ�õ�ǰλ��ֵ  
		ChangeData3Display(m_int);
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//��ʼ��������
	m_sb1.SetScrollRange(0,100);
	m_sb1.SetScrollPos(50);
	ChangeData1Display(m_sb1.GetScrollPos());
	data1 = 50;

	m_sb2.SetScrollRange(0,100);
	m_sb2.SetScrollPos(50);
	ChangeData2Display(m_sb2.GetScrollPos());
	data2 = 50;

	m_slider.SetRange(0,100);
	m_slider.SetPos(50);
	ChangeData3Display(m_slider.GetPos());
	data3 = 50;

	return TRUE;
}


void CCalcDlg::ChangeData1Display(int pos)
{
	TCHAR sPos[10];
	_itow_s(pos,sPos,10);
	m_edit1.SetSel(0,-1);
	m_edit1.ReplaceSel(sPos);
	data1 = pos;
	UpdateData(FALSE);    //����ؼ��󶨵ı���������ʾ����Ļ��
}


void CCalcDlg::ChangeData2Display(int pos)
{
	TCHAR sPos[10];
	_itow_s(pos,sPos,10);
	m_edit2.SetSel(0,-1);
	m_edit2.ReplaceSel(sPos);
	data2 = pos;
	UpdateData(FALSE);    //����ؼ��󶨵ı���������ʾ����Ļ��
}


void CCalcDlg::ChangeData3Display(int pos)
{
	TCHAR sPos[10];
	_itow_s(pos,sPos,10);
	m_edit3.SetSel(0,-1);
	m_edit3.ReplaceSel(sPos);
	data3 = pos;
	UpdateData(FALSE);    //����ؼ��󶨵ı���������ʾ����Ļ��
}


double CCalcDlg::GetMean(void)
{
	return ((double)data1+data2+data3)/3;
}


double CCalcDlg::GetVariance(void)
{
	double mean = GetMean();
	return ((double)(data1-mean)*(data1-mean)+(data2-mean)*(data2-mean)+(data3-mean)*(data3-mean))/3;
}


double CCalcDlg::GetRMS(void)
{
	return sqrt((double)(data1*data1+data2*data2+data3*data3)/3);
}


void CCalcDlg::OnBnClickedButton1()
{
	CString value;
	value.Format(_T("%f"),GetMean());
	m_edit4.SetSel(0,-1);
	m_edit4.ReplaceSel(value);
}


void CCalcDlg::OnBnClickedButton2()
{
	CString value;
	value.Format(_T("%f"),GetVariance());
	m_edit4.SetSel(0,-1);
	m_edit4.ReplaceSel(value);
}


void CCalcDlg::OnBnClickedButton3()
{
	CString value;
	value.Format(_T("%f"),GetRMS());
	m_edit4.SetSel(0,-1);
	m_edit4.ReplaceSel(value);
}
