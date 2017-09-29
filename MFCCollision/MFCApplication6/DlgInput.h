#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgInput 对话框

class CDlgInput : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgInput)

public:
	CDlgInput(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgInput();
	struct ball{
		int mass;
		int radius;
		int speed;
		int angle;
	};
	ball b1;
	ball b2;
// 对话框数据
	enum { IDD = IDD_SIMULATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CEdit m_input;
	afx_msg void OnCbnSelchangeCombo1();
	CButton m1_rad1;
	CButton m1_rad2;
	CButton m1_rad3;
	CButton m1_rad4;
	CButton m2_rad1;
	CButton m2_rad2;
	CButton m2_rad3;
	CButton m2_rad4;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
//	void ChangeDisplayInfo(int pos);
	CSliderCtrl m1_slider;
	CEdit m1_angle_edit;
	CEdit m2_angle_edit;
	virtual BOOL OnInitDialog();
	CSliderCtrl m2_slider;
	int ChangeAngle1Display(int pos);
	int ChangeAngle2Display(int pos);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
//	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox m1_cb;
	CComboBox m2_cb;
	CEdit m1_radius_edit;
	CEdit m2_radius_edit;
	CButton m1_radius_sure;
	CButton m2_radius_sure;
	afx_msg void OnBnClickedButton2();
	int dialog1;
	CStatic m_picDraw;
	CStatic m_pic;
	virtual INT_PTR DoModal();
	afx_msg void OnBnClickedButton3();
//	afx_msg void OnStnEnableDraw();
	afx_msg void OnBnClickedButton1();
	CButton m_button_go;
	afx_msg void OnCbnSelchangeCombo2();
};
