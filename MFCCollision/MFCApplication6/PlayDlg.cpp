// PlayDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "PlayDlg.h"
#include "afxdialogex.h"


// CPlayDlg 对话框

IMPLEMENT_DYNAMIC(CPlayDlg, CDialogEx)

CPlayDlg::CPlayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlayDlg::IDD, pParent)
{

}

CPlayDlg::~CPlayDlg()
{
}

void CPlayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OCX1, m_player);//绑定播放器控件 
	DDX_Control(pDX, IDC_BUTTON1, m_open);
}


BEGIN_MESSAGE_MAP(CPlayDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPlayDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPlayDlg 消息处理程序


void CPlayDlg::OnBnClickedButton1()
{
	CString filename;//保存路径
	CFileDialog dlg(TRUE,NULL,NULL,NULL,
		_T("媒体文件(*.wmv,*.mp3,*.avi,,*.rm,*.rmvb,*.mkv,*.mp4)|*.wmv;*.mp3;*.avi;*.rm;*.rmvb;*.mkv;*.mp4|"),this);
	if(dlg.DoModal() == IDOK)
		filename = dlg.GetPathName();
	if(filename != "")
	{
		m_player.put_URL(filename);
	}
}
