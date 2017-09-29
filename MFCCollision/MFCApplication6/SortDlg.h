#pragma once
#include <afxdb.h>
#include "stdafx.h"
#include "stdio.h"
#include "afxcmn.h"
#include "afxwin.h"
// CSortDlg �Ի���

class CSortDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSortDlg)

public:
	CSortDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSortDlg();
	CDatabase m_database;
	bool sort;

// �Ի�������
	enum { IDD = IDD_SORT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl m_accesslist;
	CButton m_button1;
	CButton m_button2;
	CButton m_button3;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
