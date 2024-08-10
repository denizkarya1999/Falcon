#pragma once
#include "afxdialogex.h"
#include "FalconDlg.h"


// New_Subtask_Dialog dialog

class New_Subtask_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(New_Subtask_Dialog)

public:
	New_Subtask_Dialog(CFalconDlg* pParentDlg, CWnd* pParent = nullptr);   // standard constructor
	virtual ~New_Subtask_Dialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW_SUBTASK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//Variables
	CEdit Branch_Name_Control;
	CEdit Branch_Category_Control;
	CEdit Subtask_Description_Control;
	CEdit Subtask_Due_Date_Control;
	CEdit Task_ID_Control;

	// Pointer to the parent dialog
	CFalconDlg* m_pFalconDlg;

	//Handlers
	afx_msg void OnBnClickedOk();

};
