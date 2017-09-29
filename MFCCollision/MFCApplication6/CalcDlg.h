#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CCalcDlg 对话框

class CCalcDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCalcDlg)

public:
	CCalcDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCalcDlg();

// 对话框数据
	enum { IDD = IDD_CALC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32772();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
//	CScrollBar m_sb;
	CScrollBar m_sb1;
	CScrollBar m_sb2;
	CSliderCtrl m_slider;
	CEdit m_edit1;
//	CEdit m_edit2;
//	CEdit m_edit3;
//	CEdit m_edit4;
	CButton m_button1;
	CButton m_button2;
	CButton m_button3;
	void ChangeData1Display(int pos);
	void ChangeData2Display(int pos);
	void ChangeData3Display(int pos);
	int data1;
	int data2;
	int data3;
	double GetMean(void);
	double GetVariance(void);
	double GetRMS(void);
	CEdit m_edit2;
	CEdit m_edit3;
	CEdit m_edit4;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
