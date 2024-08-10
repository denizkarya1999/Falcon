// New_Branch_Dialog.cpp : implementation file
//

#include "pch.h"
#include "Falcon.h"
#include "afxdialogex.h"
#include "New_Branch_Dialog.h"
#include "GlobalsManager.h"
#include "Weekly_Bulletin.h"

// New_Branch_Dialog dialog

IMPLEMENT_DYNAMIC(New_Branch_Dialog, CDialogEx)

New_Branch_Dialog::New_Branch_Dialog(CFalconDlg* pParentDlg, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BRANCH, pParent), m_pFalconDlg(pParentDlg)
{

}

New_Branch_Dialog::~New_Branch_Dialog()
{
}

void New_Branch_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_BRANCH_NAME, Branch_Name_Box);
	DDX_Control(pDX, IDC_EDIT_BRANCH_LOAD, Branch_Load_Box);
}


BEGIN_MESSAGE_MAP(New_Branch_Dialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &New_Branch_Dialog::OnBnClickedOk)
END_MESSAGE_MAP()


// New_Branch_Dialog message handlers

//Perform action when the user clicks "OK".
void New_Branch_Dialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CreateBulletinBranch();

	CDialogEx::OnOK();
}

//Creates a branch for bulletin.
void New_Branch_Dialog::CreateBulletinBranch()
{
	//Update this function further to help user to do operations.
	UpdateData(TRUE);

	//Declare a pointer of "GlobalsManager.cpp".
	GlobalsManager *pGlobal = GlobalsManager::Instance();

	//Declare variables to store the values from control files
	CString Branch_Name;
	CString Branch_Load;
	Load SelectedLoad;

	//Retrieve variables from control variables
	Branch_Name_Box.GetWindowTextW(Branch_Name);
	Branch_Load_Box.GetWindowTextW(Branch_Load);

	//Determine the load based on the users answer (Available values: NoLoad, LessLoad, NormalLoad and HighLoad)
	if (Branch_Load == "No Load") {
		SelectedLoad = NoLoad;
	} else if (Branch_Load == "Less Load") {
		SelectedLoad = LessLoad;
	} else if (Branch_Load == "Normal Load") {
		SelectedLoad = NormalLoad;
	}
	else if (Branch_Load == "High Load") {
		SelectedLoad = HighLoad;
	}

	//Create a branch based on instances
	pGlobal->globalVariablesInstance.bulletin.addBranch(Branch_Name, SelectedLoad);

	//Save the result to the Bulletin_Display variable
	m_pFalconDlg->Bulletin_Display = pGlobal->globalVariablesInstance.bulletin.printBulletin();

	// Save the bulletin to a file
	m_pFalconDlg->C_Bulletin_Display.SetWindowTextW(m_pFalconDlg->Bulletin_Display);
}