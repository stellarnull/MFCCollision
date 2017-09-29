// SortDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "SortDlg.h"
#include "afxdialogex.h"
#include <afxoledb.h>
#include "SelDlg.h"
//#import "c:\program files\common files\system\ado\msado15.dll" \no_namespace\rename ("EOF", "adoEOF")

static int CALLBACK MyCompareProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CString &lp1 = *((CString *)lParam1);
	CString &lp2 = *((CString *)lParam2);
	int &sort = *(int *)lParamSort;
	if (sort == 0)
	{
		return lp1.CompareNoCase(lp2);
	}
	else
	{
		return lp2.CompareNoCase(lp1);
	}
}
// CSortDlg �Ի���

IMPLEMENT_DYNAMIC(CSortDlg, CDialogEx)

	CSortDlg::CSortDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSortDlg::IDD, pParent)
{

}

CSortDlg::~CSortDlg()
{
}

void CSortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_accesslist);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_BUTTON3, m_button3);
}


BEGIN_MESSAGE_MAP(CSortDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSortDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSortDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSortDlg::OnBnClickedButton3)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &CSortDlg::OnLvnColumnclickList1)
END_MESSAGE_MAP()


// CSortDlg ��Ϣ�������


void CSortDlg::OnBnClickedButton1()
{
	BOOL result = TRUE;
	LV_COLUMN lvcolumn;  
	LV_ITEM lvitem;  
	LPCTSTR lpszConnect = _T("Driver={Microsoft Access Driver (*.mdb)};DBQ=test.mdb;");
	try
	{
		result = m_database.OpenEx(lpszConnect, NULL);	
		MessageBox(_T("�����ݿ�test.mdb�ɹ���"));
	}
	catch(CDBException * e){

		MessageBox(_T("���ݿ�����ʧ�ܣ���ȷ�����ݿ�test.mdb�Ƿ��ڵ�ǰ·����!\n s%"), e->m_strError);
	}
	LPCTSTR query =_T("SELECT Info.[ID], Info.[����],Info.[��ѧ���], Info.[��������], Info.[�Ƿ�Ϊ��Ա] FROM Info ORDER BY Info.[ID] ASC;");
	CRecordset rs(&m_database);
	result = rs.Open(CRecordset::dynaset, query, CRecordset::none);
	if(result)
	{

		//CODBCFieldInfo fInfo;
		short sFieldCount = rs.GetODBCFieldCount(); 
		CString test;
		//test.Format(_T("%d"),sFieldCount);

		/*
		//ɾ���б�ؼ�ԭ��������  
		m_accesslist.DeleteAllItems();  
		//ɾ���б�ؼ�ԭ��������  
		while(m_accesslist.GetHeaderCtrl()->GetItemCount()>0){  
		m_accesslist.DeleteColumn(m_accesslist.GetHeaderCtrl()->GetItemCount()-1);  
		}  
		m_accesslist.SetRedraw(TRUE);  
		m_accesslist.Invalidate();  
		m_accesslist.UpdateWindow();  */
		CRect rect;
		m_accesslist.GetWindowRect(&rect);

		if (sFieldCount > 0)  
		{  
			for (short column = 0; column < sFieldCount; column++)  
			{  
				CODBCFieldInfo fInfo;  
				rs.GetODBCFieldInfo(column, fInfo);  
				//MessageBox(fInfo.m_strName);  
				lvcolumn.mask = LVCF_FMT|LVCF_TEXT|LVCF_WIDTH;  
				lvcolumn.fmt = LVCFMT_LEFT;  
				lvcolumn.pszText = fInfo.m_strName.GetBuffer(fInfo.m_strName.GetLength());  
				lvcolumn.iSubItem = column;  
				lvcolumn.cx = rect.Width()/sFieldCount;  
				fInfo.m_strName.ReleaseBuffer();  
				m_accesslist.InsertColumn(column,&lvcolumn); 
				//test.Format(_T("%d  %s"),column,lvcolumn.pszText);
				//MessageBox(test);
			}  
		}  
		CDBVariant var;  
		CString value;  
		int rowCount = 0;  
		int iactualitem;  
		//��ȡ���ݿ��б�����Ϣ  
		while (!rs.IsEOF())  
		{  
			for (short column = 0; column < sFieldCount; column++)  
			{  
				rs.GetFieldValue(column, var); 
				switch (var.m_dwType)  
				{  
				case DBVT_STRING:  
					value.Format(_T("%s"), var.m_pstring->GetBuffer(var.m_pstring->GetLength()));  
					break;  
				case DBVT_ASTRING:  
					value.Format(_T("%s"), var.m_pstringA->GetBuffer(var.m_pstringA->GetLength()));  
					break;  
				case DBVT_WSTRING:  
					value.Format(_T("%s"), var.m_pstringW->GetBuffer(var.m_pstringW->GetLength()));  
					break;  
				case DBVT_LONG:  
					value.Format(_T("%ld"), var.m_lVal);  
					break;  
				case DBVT_SHORT:  
					value.Format(_T("%d"), var.m_iVal);  
					break;
				case DBVT_BOOL:
					if(var.m_boolVal)
						value.Format(_T("��"));
					else
						value.Format(_T("��"));
					break;
				default:  
					value = _T("");  
				}  
				if(column == 0){  
					lvitem.mask = LVIF_TEXT;  
					lvitem.iItem = rowCount;  
					lvitem.iSubItem = column;  
					lvitem.pszText = value.GetBuffer(value.GetLength());  
					value.ReleaseBuffer();  
					lvitem.cchTextMax = value.GetLength();  
					m_accesslist.GetItem(&lvitem);  
					lvitem.iItem = m_accesslist.GetItemCount();  
					iactualitem = m_accesslist.InsertItem(&lvitem);  
				}else{  
					lvitem.mask = LVIF_TEXT;  
					lvitem.iItem = rowCount;  
					lvitem.iSubItem = column;  
					lvitem.pszText = value.GetBuffer(value.GetLength());  
					value.ReleaseBuffer();  
					lvitem.cchTextMax = value.GetLength();  
					lvitem.iItem = iactualitem;  
					m_accesslist.SetItem(&lvitem);  
				}  
			}  
			rowCount++;  
			rs.MoveNext();  
		}  
		m_button1.EnableWindow(FALSE);
		m_button2.EnableWindow(TRUE);
		m_button3.EnableWindow(TRUE);
		sort = false;
	}  
}


void CSortDlg::OnBnClickedButton2() //����ť
{
	MessageBox(_T("��ֱ�ӵ�������ƽ�������:)"));

}


void CSortDlg::OnBnClickedButton3() //���Ұ�ť
{
	CSelDlg csdl;
	if(csdl.DoModal()==IDCANCEL)
		return;
	if(csdl.text == "")
		return;
	int ic = m_accesslist.GetItemCount();
	bool find = false;
	for(int i = 0;i < ic; i++)
		for(int j = 0;j < m_accesslist.GetHeaderCtrl()->GetItemCount();j++)
		{
			if(m_accesslist.GetItemText(i,j) == csdl.text)
			{				
				m_accesslist.SetItemState(i, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);
				find = true;
			}			
		}
	if(find)
		MessageBox(_T("�ҵ��ˣ���O(��_��)O~~"));
	else
		MessageBox(_T("ľ���ҵ�����%>_<%"));
}


void CSortDlg::OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	int Length = m_accesslist.GetItemCount();
	CArray<CString,CString> ItemData;
	ItemData.SetSize(Length);
	for (int i = 0; i < Length; i++)
	{
		ItemData[i] = m_accesslist.GetItemText(i,pNMLV->iSubItem);
		m_accesslist.SetItemData(i,(DWORD_PTR)&ItemData[i]);//��������ؼ���
	}
	static int sort = 0;
	static int SubItem = 0;
	if (SubItem != pNMLV->iSubItem)
	{
		sort = 0;
		SubItem = pNMLV->iSubItem;
	}
	else
	{
		if (sort == 0)
		{
			sort = 1;
		}
		else
		{
			sort = 0;
		}
	}
	m_accesslist.SortItems(MyCompareProc,(DWORD_PTR)&sort);
	*pResult = 0;
}
