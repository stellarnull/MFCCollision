#pragma once
#include "ocx1.h"
#include "windows Media Player\CWMPPlayer4.h"
#include "afxwin.h"

// CPlayDlg �Ի���

class CPlayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayDlg)

public:
	CPlayDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlayDlg();

// �Ի�������
	enum { IDD = IDD_PLAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	COcx1 m_player;
	CWMPPlayer4 m_player;
	CButton m_open;
};
