#pragma once
#include "afxwin.h"


// CSelDlg �Ի���

class CSelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelDlg)

public:
	CSelDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelDlg();

// �Ի�������
	enum { IDD = IDD_SELECTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString text;
	CEdit m_edit;
	afx_msg void OnBnClickedOk();
};
