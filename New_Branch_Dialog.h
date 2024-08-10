#pragma once
#include "afxdialogex.h"
#include "FalconDlg.h"

// New_Branch_Dialog dialog

class New_Branch_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(New_Branch_Dialog)

public:
	New_Branch_Dialog(CFalconDlg* pParentDlg, CWnd* pParent = nullptr);
	virtual ~New_Branch_Dialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BRANCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//Handlers
	afx_msg void OnBnClickedOk();

	//Variables
	CEdit Branch_Name_Box;
	CEdit Branch_Load_Box;

	// Pointer to the parent dialog
	CFalconDlg* m_pFalconDlg; 

	//Helper Methods
	void CreateBulletinBranch();
};
