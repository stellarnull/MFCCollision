#pragma once
#include "afxwin.h"


// CSelDlg 对话框

class CSelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelDlg)

public:
	CSelDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelDlg();

// 对话框数据
	enum { IDD = IDD_SELECTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString text;
	CEdit m_edit;
	afx_msg void OnBnClickedOk();
};
