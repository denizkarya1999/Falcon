#pragma once
#include "afxdialogex.h"
#include "FalconDlg.h"


// New_Branch_Warning_Dialog dialog

class New_Branch_Warning_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(New_Branch_Warning_Dialog)

public:
	New_Branch_Warning_Dialog(CFalconDlg* pParentDlg, CWnd* pParent = nullptr);   // standard constructor
	virtual ~New_Branch_Warning_Dialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW_BRANCH_WARNING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//Handlers
	afx_msg void OnBnClickedOk();

	//Variables
	CEdit Branch_Name_Box;
	CEdit Warning_Message_Box;

	//Helper methods
	void CreateBulletinBranchWarning();

	// Pointer to the parent dialog
	CFalconDlg* m_pFalconDlg;
};
