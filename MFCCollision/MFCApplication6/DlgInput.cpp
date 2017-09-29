// DlgInput.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "DlgInput.h"
#include <iostream>
#include <math.h>
#include "afxdialogex.h"
using namespace std;
const double pi=3.141592654;
// CDlgInput 对话框

IMPLEMENT_DYNAMIC(CDlgInput, CDialogEx)

	CDlgInput::CDlgInput(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgInput::IDD, pParent)
	, dialog1(0)
{

}

CDlgInput::~CDlgInput()
{

}

void CDlgInput::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, m1_rad1);
	DDX_Control(pDX, IDC_RADIO2, m1_rad2);
	DDX_Control(pDX, IDC_RADIO3, m1_rad3);
	DDX_Control(pDX, IDC_RADIO4, m1_rad4);
	DDX_Control(pDX, IDC_RADIO5, m2_rad1);
	DDX_Control(pDX, IDC_RADIO6, m2_rad2);
	DDX_Control(pDX, IDC_RADIO7, m2_rad3);
	DDX_Control(pDX, IDC_RADIO8, m2_rad4);
	DDX_Control(pDX, IDC_SLIDER1, m1_slider);
	DDX_Control(pDX, IDC_EDIT5, m1_angle_edit);
	DDX_Control(pDX, IDC_EDIT6, m2_angle_edit);
	DDX_Control(pDX, IDC_SLIDER2, m2_slider);
	DDX_Control(pDX, IDC_COMBO1, m1_cb);
	DDX_Control(pDX, IDC_COMBO2, m2_cb);
	DDX_Control(pDX, IDC_EDIT1, m1_radius_edit);
	DDX_Control(pDX, IDC_EDIT2, m2_radius_edit);
	DDX_Control(pDX, IDC_BUTTON2, m1_radius_sure);
	DDX_Control(pDX, IDC_BUTTON3, m2_radius_sure);
	DDX_Control(pDX, IDC_DRAW, m_pic);
	DDX_Control(pDX, IDC_BUTTON1, m_button_go);
}


BEGIN_MESSAGE_MAP(CDlgInput, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgInput::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgInput::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgInput::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDlgInput::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CDlgInput::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CDlgInput::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CDlgInput::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CDlgInput::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CDlgInput::OnBnClickedRadio8)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgInput::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgInput::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgInput::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CDlgInput::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// CDlgInput 消息处理程序


void CDlgInput::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	//#1015

	// TODO:  在此添加控件通知处理程序代码
}


void CDlgInput::OnCbnSelchangeCombo1()
{
	CString value;
	m1_cb.GetLBText(m1_cb.GetCurSel(), value);
	b1.mass = _ttoi(value);
}


void CDlgInput::OnBnClickedRadio1()
{
	m1_rad1.SetCheck(1);
	m1_rad2.SetCheck(0);
	m1_rad3.SetCheck(0);
	m1_rad4.SetCheck(0);
	b1.speed = 5;
}


void CDlgInput::OnBnClickedRadio2()
{
	m1_rad1.SetCheck(0);
	m1_rad2.SetCheck(1);
	m1_rad3.SetCheck(0);
	m1_rad4.SetCheck(0);
	b1.speed = 10;
}


void CDlgInput::OnBnClickedRadio3()
{
	m1_rad1.SetCheck(0);
	m1_rad2.SetCheck(0);
	m1_rad3.SetCheck(1);
	m1_rad4.SetCheck(0);
	b1.speed = 15;
}


void CDlgInput::OnBnClickedRadio4()
{
	m1_rad1.SetCheck(0);
	m1_rad2.SetCheck(0);
	m1_rad3.SetCheck(0);
	m1_rad4.SetCheck(1);
	b1.speed = 20;
}


void CDlgInput::OnBnClickedRadio5()
{
	m2_rad1.SetCheck(1);
	m2_rad2.SetCheck(0);
	m2_rad3.SetCheck(0);
	m2_rad4.SetCheck(0);
	b2.speed = 5;
}


void CDlgInput::OnBnClickedRadio6()
{
	m2_rad1.SetCheck(0);
	m2_rad2.SetCheck(1);
	m2_rad3.SetCheck(0);
	m2_rad4.SetCheck(0);
	b2.speed = 10;
}


void CDlgInput::OnBnClickedRadio7()
{
	m2_rad1.SetCheck(0);
	m2_rad2.SetCheck(0);
	m2_rad3.SetCheck(1);
	m2_rad4.SetCheck(0);
	b2.speed = 15;
}


void CDlgInput::OnBnClickedRadio8()
{
	m2_rad1.SetCheck(0);
	m2_rad2.SetCheck(0);
	m2_rad3.SetCheck(0);
	m2_rad4.SetCheck(1);
	b2.speed = 20;
}


//void CDlgInput::ChangeDisplayInfo(int pos)
//{
//	TCHAR sPos[10];
//	_itow_s(pos,sPos,10);
//	m1_angle_edit.SetSel(0,-1);
//	m1_angle_edit.ReplaceSel(sPos);
//	UpdateData(FALSE);    //将与控件绑定的变量内容显示到屏幕上
//
//}



BOOL CDlgInput::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//初始化单选框
	m1_rad1.SetCheck(1);
	m2_rad1.SetCheck(1);
	b1.speed = 5;
	b2.speed = 5;

	//初始化滑动条
	m1_slider.SetRange(0,90);
	m1_slider.SetPos(45);
	ChangeAngle1Display(m1_slider.GetPos());
	b1.angle = 45;
	m2_slider.SetRange(0,90);
	m2_slider.SetPos(45);
	ChangeAngle2Display(m2_slider.GetPos());
	b2.angle = 45;

	//初始化下拉菜单
	m1_cb.AddString(_T("1"));
	m1_cb.AddString(_T("5"));
	m1_cb.AddString(_T("10"));
	m1_cb.AddString(_T("20"));
	m1_cb.SetCurSel(1);
	b1.mass = 5;
	m2_cb.AddString(_T("1"));
	m2_cb.AddString(_T("5"));
	m2_cb.AddString(_T("10"));
	m2_cb.AddString(_T("20"));
	m2_cb.SetCurSel(1);
	b2.mass = 5;

	//初始化可编辑文本框
	m1_radius_edit.ReplaceSel(_T("5"));
	m2_radius_edit.ReplaceSel(_T("5"));
	b1.radius = 5;
	b2.radius = 5;

	//初始化画板
	
	return TRUE;  // return TRUE unless you set the focus to a control

}


int CDlgInput::ChangeAngle1Display(int pos)
{
	TCHAR sPos[10];
	_itow_s(pos,sPos,10);
	m1_angle_edit.SetSel(0,-1);
	m1_angle_edit.ReplaceSel(sPos);
	b1.angle = pos;
	UpdateData(FALSE);    //将与控件绑定的变量内容显示到屏幕上
	return 0;
}


int CDlgInput::ChangeAngle2Display(int pos)
{
	TCHAR sPos[10];
	_itow_s(pos,sPos,10);
	m2_angle_edit.SetSel(0,-1);
	m2_angle_edit.ReplaceSel(sPos);
	b2.angle = pos;
	UpdateData(FALSE);    //将与控件绑定的变量内容显示到屏幕上
	return 0;
}


void CDlgInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if( pScrollBar->GetDlgCtrlID() == IDC_SLIDER1 )
	{
		CSliderCtrl *pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
		int m_int = pSlidCtrl->GetPos();//取得当前位置值  
		ChangeAngle1Display(m_int);
	}
	else if( pScrollBar->GetDlgCtrlID() == IDC_SLIDER2)
	{
		CSliderCtrl *pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
		int m_int = pSlidCtrl->GetPos();//取得当前位置值  
		ChangeAngle2Display(m_int);
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDlgInput::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if( pScrollBar->GetDlgCtrlID() == IDC_SLIDER1 )
	{
		CSliderCtrl *pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
		int m_int = pSlidCtrl->GetPos();//取得当前位置值  
		ChangeAngle1Display(m_int);
	}
	else if( pScrollBar->GetDlgCtrlID() == IDC_SLIDER2)
	{
		CSliderCtrl *pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
		int m_int = pSlidCtrl->GetPos();//取得当前位置值  
		ChangeAngle2Display(m_int);
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}



void CDlgInput::OnBnClickedButton2()
{
	CString value;
	m1_radius_edit.GetWindowTextW(value);
	b1.radius = _ttoi(value);
	

	
	//CString strtemp;
	//strtemp.Format(_T("%d"),b1.radius);
	//m1_angle_edit.SetWindowTextW(strtemp);
}


INT_PTR CDlgInput::DoModal()
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialogEx::DoModal();
}


void CDlgInput::OnBnClickedButton3()
{
	CString value;
	m2_radius_edit.GetWindowTextW(value);
	b2.radius = _ttoi(value);
}



void CDlgInput::OnBnClickedButton1()
{
	m_button_go.EnableWindow(FALSE);
	CRect pic_rect;
	m_pic.GetWindowRect(&pic_rect);
	CString test1,test2;
	//test1.Format(_T("%d %d %d %d"),pic_rect.left,pic_rect.top,pic_rect.Width(),pic_rect.Height());
	//MessageBox(test1);
	ScreenToClient(&pic_rect);
	//test1.Format(_T("%d %d %d %d"),tmp_rect.left,tmp_rect.top,tmp_rect.Width(),tmp_rect.Height());
	//MessageBox(test1);	
	
	//test2.Format(_T("%d %d %d %d"),pic_rect.left,pic_rect.top,pic_rect.right,pic_rect.bottom);
	//MessageBox(test2);
	pic_rect.left += 8;
	pic_rect.right += 8;
	pic_rect.top += 31;
	pic_rect.bottom += 31;
	CDC *pDC = GetWindowDC();
	CBrush *brush = new CBrush(RGB(50,0,50));
	CBrush *old_brush;
	old_brush = pDC->SelectObject(brush);//将画笔选入设备描述表，并保存旧的画笔
	pDC->Rectangle(pic_rect);
	pDC->SelectObject(old_brush);//将以前的画笔选入设备描述表
	delete brush;
	int t=0;
	double b1_left = pic_rect.left + 10;
	double b1_bottom = pic_rect.bottom - 10;
	double b1_right = b1_left + 2*b1.radius*5;
	double b1_top = b1_bottom - 2*b1.radius*5;
	double b2_right = pic_rect.right - 10;
	double b2_bottom = pic_rect.bottom - 10;
	double b2_left = b2_right - 2*b2.radius*5;
	double b2_top = b2_bottom - 2*b2.radius*5;
	double b1_x = (b1_left+b1_right)/2;
	double b1_y = (b1_top+b1_bottom)/2;
	double b2_x = (b2_left+b2_right)/2;
	double b2_y = (b2_top+b2_bottom)/2;
	double b1_rx,b2_rx,b1_ry,b2_ry;

	bool is_collision = false;
	while(b1_left>pic_rect.left && b1_right<pic_rect.right && b1_bottom<pic_rect.bottom && b1_top>pic_rect.top &&
		b2_left>pic_rect.left && b2_right<pic_rect.right && b2_bottom<pic_rect.bottom && b2_top>pic_rect.top)
	{
		brush = new CBrush(RGB(50,0,50));
		old_brush = pDC->SelectObject(brush);
		pDC->Rectangle(pic_rect);
		pDC->SelectObject(old_brush);
		delete brush;

		brush = new CBrush(RGB(t,255-t,255));
		old_brush = pDC->SelectObject(brush);
		b1_left += b1.speed*cos(b1.angle*pi/180)/5;
		b1_bottom -= b1.speed*sin(b1.angle*pi/180)/5;
		b1_right = b1_left + 2*b1.radius*5;
		b1_top = b1_bottom - 2*b1.radius*5;
		b1_rx = (b1_left+b1_right)/2;
		b1_ry = (b1_top+b1_bottom)/2;		
		pDC->Ellipse(b1_left,b1_bottom,b1_right,b1_top);
		
		pDC->SelectObject(old_brush);
		delete brush;

		brush = new CBrush(RGB(t,255,t));
		old_brush = pDC->SelectObject(brush);
		b2_right -= b2.speed*cos(b2.angle*pi/180)/5;
		b2_bottom -= b2.speed*sin(b2.angle*pi/180)/5;
		b2_left = b2_right - 2*b2.radius*5;
		b2_top = b2_bottom - 2*b2.radius*5;
		b2_rx = (b2_left+b2_right)/2;
		b2_ry = (b2_top+b2_bottom)/2;
		pDC->SetDCBrushColor(RGB(0,255,0));
		pDC->Ellipse(b2_left,b2_bottom,b2_right,b2_top);
		
		pDC->SelectObject(old_brush);
		delete brush;

		CPen *pen = new CPen(PS_SOLID,2,RGB(255,255,0));
		CPen *old_pen = pDC->SelectObject(pen);
		pDC->MoveTo(b1_x, b1_y);
		pDC->LineTo(b1_rx,b1_ry);
		pDC->SelectObject(old_pen);
		delete pen;

		pen = new CPen(PS_SOLID,2,RGB(255,0,255));
		old_pen = pDC->SelectObject(pen);
		pDC->MoveTo(b2_x, b2_y);
		pDC->LineTo(b2_rx,b2_ry);
		pDC->SelectObject(old_pen);
		delete pen;

		
		CString test1,test2;
		test1.Format(_T("%f %f %f %f"),b1_rx,b1_ry,b2_rx,b2_ry);
		//MessageBox(test1);
		if(sqrt((b2_rx-b1_rx)*(b2_rx-b1_rx)+(b2_ry-b1_ry)*(b2_ry-b1_ry))<(b1.radius+b2.radius)*5)
		{
			//MessageBox(_T("撞啦！"));
			is_collision = true;
			break;
		}
		t++;
		Sleep(10);
		
	}
	if(!is_collision)
		MessageBox(_T("唉呀妈呀，没撞上呀！"));
	else
	{
		double b1_mx = b1_rx;
		double b1_my = b1_ry;
		double b2_mx = b2_rx;
		double b2_my = b2_ry;

		double beta = asin((b1_ry-b2_ry)/5/(b1.radius+b2.radius));
		double v1_pa = b1.speed * cos((double)b1.angle*pi/180.0-beta);
		double v1_ve = b1.speed * sin((double)b1.angle*pi/180.0-beta);
		double v2_pa = b2.speed * cos((double)b2.angle*pi/180.0+beta);
		double v2_ve = b2.speed * sin((double)b2.angle*pi/180.0+beta);
		

		//圆心连线方向动量守恒
		double v1_pa_n = ((b1.mass-b2.mass)*v1_pa - 2*b2.mass*v2_pa)/(b1.mass+b2.mass);
		double v2_pa_n = ((b2.mass-b1.mass)*v2_pa - 2*b1.mass*v2_pa)/(b1.mass+b2.mass);

		double theta1 = atan(v1_ve/v1_pa_n);
		double v1_f = sqrt(v1_pa_n*v1_pa_n+v1_ve*v1_ve);
		double v1_pa_f = v1_f*cos(pi+theta1+beta);
		double v1_ve_f = fabs(v1_f*sin(pi+theta1+beta));

		double theta2 = atan(v2_ve/v2_pa_n);
		double v2_f = sqrt(v2_pa_n*v2_pa_n+v2_ve*v2_ve);
		double v2_pa_f = v2_f*cos(pi+theta1+beta);
		double v2_ve_f = fabs(v2_f*sin(pi+theta1+beta));
		//CString test1,test2;
		//test1.Format(_T("%f %f %f %f %f"),beta,v1_pa_f,v1_ve_f,v2_pa_f,v2_ve_f);
		//MessageBox(test1);

		while(b1_left>pic_rect.left && b1_right<pic_rect.right && b1_bottom<pic_rect.bottom && b1_top>pic_rect.top &&
		b2_left>pic_rect.left && b2_right<pic_rect.right && b2_bottom<pic_rect.bottom && b2_top>pic_rect.top)
		{
			brush = new CBrush(RGB(50,0,50));
			old_brush = pDC->SelectObject(brush);
			pDC->Rectangle(pic_rect);
			pDC->SelectObject(old_brush);
			delete brush;

			brush = new CBrush(RGB(t,255-t,255));
			old_brush = pDC->SelectObject(brush);
			b1_left += v1_pa_f/5;
			b1_bottom -= v1_ve_f/5;
			b1_right = b1_left + 2*b1.radius*5;
			b1_top = b1_bottom - 2*b1.radius*5;
			b1_rx = (b1_left+b1_right)/2;
			b1_ry = (b1_top+b1_bottom)/2;		
			pDC->Ellipse(b1_left,b1_bottom,b1_right,b1_top);
		
			pDC->SelectObject(old_brush);
			delete brush;

			brush = new CBrush(RGB(t,255,t));
			old_brush = pDC->SelectObject(brush);
			b2_right -= v2_pa_f/5;
			b2_bottom -= v2_ve_f/5;
			b2_left = b2_right - 2*b2.radius*5;
			b2_top = b2_bottom - 2*b2.radius*5;
			b2_rx = (b2_left+b2_right)/2;
			b2_ry = (b2_top+b2_bottom)/2;
			pDC->SetDCBrushColor(RGB(0,255,0));
			pDC->Ellipse(b2_left,b2_bottom,b2_right,b2_top);
		
			pDC->SelectObject(old_brush);
			delete brush;

			CPen *pen = new CPen(PS_SOLID,2,RGB(255,255,0));
			CPen *old_pen = pDC->SelectObject(pen);
			pDC->MoveTo(b1_x, b1_y);
			pDC->LineTo(b1_mx,b1_my);
			pDC->MoveTo(b1_mx, b1_my);
			pDC->LineTo(b1_rx,b1_ry);
			pDC->SelectObject(old_pen);
			delete pen;

			pen = new CPen(PS_SOLID,2,RGB(255,0,255));
			old_pen = pDC->SelectObject(pen);
			pDC->MoveTo(b2_x, b2_y);
			pDC->LineTo(b2_mx,b2_my);
			pDC->MoveTo(b2_mx, b2_my);
			pDC->LineTo(b2_rx,b2_ry);;
			pDC->SelectObject(old_pen);
			delete pen;

		
			
			Sleep(10);
			t++;
		}
	}
	m_button_go.EnableWindow(TRUE);
}


void CDlgInput::OnCbnSelchangeCombo2()
{
	CString value;
	m2_cb.GetLBText(m2_cb.GetCurSel(), value);
	b2.mass = _ttoi(value);
}
