// SelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "SelDlg.h"
#include "afxdialogex.h"


// CSelDlg �Ի���

IMPLEMENT_DYNAMIC(CSelDlg, CDialogEx)

CSelDlg::CSelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelDlg::IDD, pParent)
	, text(_T(""))
{

}

CSelDlg::~CSelDlg()
{
}

void CSelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CSelDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSelDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelDlg ��Ϣ�������


void CSelDlg::OnBnClickedOk()
{
	m_edit.GetWindowTextW(text);
	CDialogEx::OnOK();
}
