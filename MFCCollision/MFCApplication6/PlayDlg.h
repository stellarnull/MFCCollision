#pragma once
#include "ocx1.h"
#include "windows Media Player\CWMPPlayer4.h"
#include "afxwin.h"

// CPlayDlg 对话框

class CPlayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayDlg)

public:
	CPlayDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlayDlg();

// 对话框数据
	enum { IDD = IDD_PLAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	COcx1 m_player;
	CWMPPlayer4 m_player;
	CButton m_open;
};
