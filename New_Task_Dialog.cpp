// New_Task_Dialog.cpp : implementation file
//

#include "pch.h"
#include "Falcon.h"
#include "afxdialogex.h"
#include "New_Task_Dialog.h"
#include "GlobalsManager.h"


// New_Task_Dialog dialog

IMPLEMENT_DYNAMIC(New_Task_Dialog, CDialogEx)

New_Task_Dialog::New_Task_Dialog(CFalconDlg* pParentDlg, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NEW_TASK, pParent), m_pFalconDlg(pParentDlg)
{

}

New_Task_Dialog::~New_Task_Dialog()
{
}

void New_Task_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_BRANCH_CATEGORY, Category_Box);
	DDX_Control(pDX, IDC_EDIT_BRANCH_CATEGORY2, Description_Box);
	DDX_Control(pDX, IDC_EDIT_BRANCH_DUE_DATE, Due_Date_Box);
	DDX_Control(pDX, IDC_EDIT_BRANCH_NAME, Branch_Name_TaskDlg_Box);
}


BEGIN_MESSAGE_MAP(New_Task_Dialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &New_Task_Dialog::OnBnClickedOk)
END_MESSAGE_MAP()


// New_Task_Dialog message handlers

//Perform action when the user clicks "OK".
void New_Task_Dialog::OnBnClickedOk()
{
	//Update this function further to help user to do operations.
	UpdateData(TRUE);

	//Declare a pointer of "GlobalsManager.cpp".
	GlobalsManager* pGlobal = GlobalsManager::Instance();

	//Declare variables to store the values from control files
	CString Branch_Name;
	CString Category;
	CString Description;
	CString Due_Date;
	time_t dueTime;

	//Retrieve variables from control variables
	Branch_Name_TaskDlg_Box.GetWindowTextW(Branch_Name);
	Category_Box.GetWindowTextW(Category);
	Description_Box.GetWindowTextW(Description);
	Due_Date_Box.GetWindowTextW(Due_Date);

	//Convert CString to time_t to add the due date.
	// Variables to hold the parsed date components
	int year, month, day;

	//Create the task.
	Task task;
	task.description = Description;

	// Parse the CString into the year, month, and day components
	if (_stscanf_s(Due_Date, _T("%d-%d-%d"), &year, &month, &day) == 3)
	{
		// Construct a CTime object from the parsed components
		CTime dueDate(year, month, day, 0, 0, 0);  // Hours, minutes, seconds set to 0

		// Convert the CTime object to a time_t variable
		time_t dueTime = dueDate.GetTime();

		// Now dueTime is a time_t variable representing the due date
		// You can use dueTime as needed in your application
		task.dueDate = dueTime;
	}
	else
	{
		// Handle error if the string could not be parsed
		AfxMessageBox(_T("Invalid date format"));
	}

	//Add task to the daily bulletin.
	pGlobal->globalVariablesInstance.bulletin.addTaskToBranch(Branch_Name, Category, task);

	//Save the result to the Bulletin_Display variable
	m_pFalconDlg->Bulletin_Display = pGlobal->globalVariablesInstance.bulletin.printBulletin();

	// Save the bulletin to a file
	m_pFalconDlg->C_Bulletin_Display.SetWindowTextW(m_pFalconDlg->Bulletin_Display);

	CDialogEx::OnOK();
}
