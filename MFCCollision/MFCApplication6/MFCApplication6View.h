
// MFCApplication6View.h : CMFCApplication6View 类的接口
//

#pragma once


class CMFCApplication6View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication6View();
	DECLARE_DYNCREATE(CMFCApplication6View)

// 特性
public:
	CMFCApplication6Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32774();
	afx_msg void On32773();
};

#ifndef _DEBUG  // MFCApplication6View.cpp 中的调试版本
inline CMFCApplication6Doc* CMFCApplication6View::GetDocument() const
   { return reinterpret_cast<CMFCApplication6Doc*>(m_pDocument); }
#endif

