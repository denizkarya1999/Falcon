#pragma once
#include "afxdialogex.h"
#include "FalconDlg.h"


// New_Task_Dialog dialog

class New_Task_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(New_Task_Dialog)

public:
	New_Task_Dialog(CFalconDlg* pParentDlg, CWnd* pParent = nullptr);   // standard constructor
	virtual ~New_Task_Dialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW_TASK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
public:
	//Variables
	CEdit Branch_Name_TaskDlg_Box;
	CEdit Category_Box;
	CEdit Description_Box;
	CEdit Due_Date_Box;

	//Handlers 
	afx_msg void OnBnClickedOk();

	// Pointer to the parent dialog
	CFalconDlg* m_pFalconDlg;
};
