// New_Subtask_Dialog.cpp : implementation file
//

#include "pch.h"
#include "Falcon.h"
#include "afxdialogex.h"
#include "New_Subtask_Dialog.h"
#include "GlobalsManager.h"


// New_Subtask_Dialog dialog

IMPLEMENT_DYNAMIC(New_Subtask_Dialog, CDialogEx)

New_Subtask_Dialog::New_Subtask_Dialog(CFalconDlg* pParentDlg, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NEW_SUBTASK, pParent), m_pFalconDlg(pParentDlg)
{

}

New_Subtask_Dialog::~New_Subtask_Dialog()
{
}

void New_Subtask_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_BRANCH_NAME_SUBTASK, Branch_Name_Control);
	DDX_Control(pDX, IDC_EDIT_BRANCH_CATEGORY_SUBTASK, Branch_Category_Control);
	DDX_Control(pDX, IDC_EDIT_SUBTASK_DESCRIPTION, Subtask_Description_Control);
	DDX_Control(pDX, IDC_EDIT_SUBTASK_DUE_DATE, Subtask_Due_Date_Control);
	DDX_Control(pDX, IDC_EDIT_TASK_ID, Task_ID_Control);
}


BEGIN_MESSAGE_MAP(New_Subtask_Dialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &New_Subtask_Dialog::OnBnClickedOk)
END_MESSAGE_MAP()


// New_Subtask_Dialog message handlers


void New_Subtask_Dialog::OnBnClickedOk()
{
	//Update this function further to help user to do operations.
	UpdateData(TRUE);

	//Declare a pointer of "GlobalsManager.cpp".
	GlobalsManager* pGlobal = GlobalsManager::Instance();

	//Declare variables to store the values from control files
	CString Branch_Name;
	CString Category;
	CString TaskId;
	CString Description;
	CString Due_Date;
	time_t dueTime;

	//Retrieve variables from control variables
	Branch_Name_Control.GetWindowTextW(Branch_Name);
	Branch_Category_Control.GetWindowTextW(Category);
	Task_ID_Control.GetWindowTextW(TaskId);
	Subtask_Description_Control.GetWindowTextW(Description);
	Subtask_Due_Date_Control.GetWindowTextW(Due_Date);

	//Convert CString to time_t to add the due date.
	// Variables to hold the parsed date components
	int year, month, day;
	
	//Create the subtask
	SubTask subtask;
	subtask.description = Description;
	
	// Parse the CString into the year, month, and day components
	if (_stscanf_s(Due_Date, _T("%d-%d-%d"), &year, &month, &day) == 3)
	{
		// Construct a CTime object from the parsed components
		CTime dueDate(year, month, day, 0, 0, 0);  // Hours, minutes, seconds set to 0

		// Convert the CTime object to a time_t variable
		time_t dueTime = dueDate.GetTime();

		// Now dueTime is a time_t variable representing the due date
		// You can use dueTime as needed in your application
		subtask.dueDate = dueTime;
	}
	else
	{
		// Handle error if the string could not be parsed
		AfxMessageBox(_T("Invalid date format"));
	}

	//Add task to the daily bulletin.
	pGlobal->globalVariablesInstance.bulletin.addSubTaskToTask(Branch_Name, Category, _ttoi(TaskId), subtask);

	//Save the result to the Bulletin_Display variable
	m_pFalconDlg->Bulletin_Display = pGlobal->globalVariablesInstance.bulletin.printBulletin();

	// Save the bulletin to a file
	m_pFalconDlg->C_Bulletin_Display.SetWindowTextW(m_pFalconDlg->Bulletin_Display);

	CDialogEx::OnOK();
}
