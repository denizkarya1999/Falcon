// New_Branch_Warning_Dialog.cpp : implementation file
//

#include "pch.h"
#include "Falcon.h"
#include "afxdialogex.h"
#include "New_Branch_Warning_Dialog.h"
#include "GlobalsManager.h"


// New_Branch_Warning_Dialog dialog

IMPLEMENT_DYNAMIC(New_Branch_Warning_Dialog, CDialogEx)

New_Branch_Warning_Dialog::New_Branch_Warning_Dialog(CFalconDlg* pParentDlg, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NEW_BRANCH_WARNING, pParent), m_pFalconDlg(pParentDlg)
{

}

New_Branch_Warning_Dialog::~New_Branch_Warning_Dialog()
{
}

void New_Branch_Warning_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_BRANCH_NAME_FOR_WARNING, Branch_Name_Box);
	DDX_Control(pDX, IDC_EDIT_BRANCH_WARNING, Warning_Message_Box);
}


BEGIN_MESSAGE_MAP(New_Branch_Warning_Dialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &New_Branch_Warning_Dialog::OnBnClickedOk)
END_MESSAGE_MAP()


// New_Branch_Warning_Dialog message handlers


void New_Branch_Warning_Dialog::OnBnClickedOk()
{
	CreateBulletinBranchWarning();
	CDialogEx::OnOK();
}

void New_Branch_Warning_Dialog::CreateBulletinBranchWarning()
{
	//Update this function further to help user to do operations.
	UpdateData(TRUE);

	//Declare a pointer of "GlobalsManager.cpp".
	GlobalsManager *pGlobal = GlobalsManager::Instance();

	//Declare variables to store the values from control files
	CString Branch_Name;
	CString Branch_Warning;

	//Retrieve variables from control variables
	Branch_Name_Box.GetWindowTextW(Branch_Name);
	Warning_Message_Box.GetWindowTextW(Branch_Warning);
	
	//Add warnings to the branch based on instances
	pGlobal->globalVariablesInstance.bulletin.addWarningToBranch(Branch_Name, Branch_Warning);

	//Save the result to the Bulletin_Display variable
	m_pFalconDlg->Bulletin_Display = pGlobal->globalVariablesInstance.bulletin.printBulletin();

	// Save the bulletin to a file
	m_pFalconDlg->C_Bulletin_Display.SetWindowTextW(m_pFalconDlg->Bulletin_Display);
}