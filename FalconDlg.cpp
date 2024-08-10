// FalconDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include <ctime>
#include "Falcon.h"
#include "FalconDlg.h"
#include "Weekly_Bulletin.h"
#include "GlobalsManager.h"
#include "Weekly_Bulletin.h"
#include "New_Branch_Dialog.h"
#include "New_Task_Dialog.h"
#include "New_Branch_Warning_Dialog.h"
#include "New_Subtask_Dialog.h"
#include "afxdialogex.h"
#include <Shellapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFalconDlg dialog



CFalconDlg::CFalconDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FALCON_DIALOG, pParent)
	, Bulletin_Display(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDD_FALCON_ICON);
}

void CFalconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BULLETIN_DISPLAY, Bulletin_Display);
	DDX_Control(pDX, IDC_BULLETIN_DISPLAY, C_Bulletin_Display);
	DDX_Control(pDX, IDC_STATIC_INDICATOR, Bulletin_Indicator);
	DDX_Control(pDX, IDC_STATIC_TOOLS_DISPLAY, tools_Display);
}

BEGIN_MESSAGE_MAP(CFalconDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_COMMAND(ID_FILE_NEWBULLETIN, &CFalconDlg::OnFileNewbulletin)
	ON_COMMAND(ID_FILE_SAVE32790, &CFalconDlg::OnFileSave32790)
	ON_COMMAND(ID_FILE_OPEN32772, &CFalconDlg::OnFileOpen32772)
	ON_COMMAND(ID_FILE_SAVE_COPY_AS, &CFalconDlg::OnFileSaveAs)
	ON_COMMAND(ID_FILE_DELETE, &CFalconDlg::OnFileDelete)
	ON_COMMAND(ID_FILE_CLOSE32775, &CFalconDlg::OnFileClose32775)
	ON_COMMAND(ID_HELP_X, &CFalconDlg::OnHelpX)
	ON_COMMAND(ID_HELP_ABOUTFALCON, &CFalconDlg::OnHelpAboutfalcon)
	ON_COMMAND(ID_ACCELERATOR_OPEN, &CFalconDlg::OnAcceleratorOpen)
	ON_COMMAND(ID_ACCELERATOR_CLOSE, &CFalconDlg::OnAcceleratorClose)
	ON_COMMAND(ID_ACCELERATOR_SAVE, &CFalconDlg::OnAcceleratorSaveAs)
	ON_COMMAND(ID_ACCELERATOR_DELETE, &CFalconDlg::OnAcceleratorDelete)
	ON_COMMAND(ID_ACCELERATOR_NEW_BULLETIN, &CFalconDlg::OnAcceleratorNewBulletin)
	ON_COMMAND(ID_ACCELERATOR_ABOUT, &CFalconDlg::OnAcceleratorAbout)
	ON_COMMAND(ID_ACCELERATOR_WEBSITE, &CFalconDlg::OnAcceleratorWebsite)
	ON_COMMAND(ID_ACCELERATOR32792, &CFalconDlg::OnAccelerator32792)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CFalconDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CFalconDlg::OnBnClickedButtonDelete)

	ON_BN_CLICKED(IDC_BUTTON_NEW_BRANCH, &CFalconDlg::OnBnClickedButtonNewBranch)
	ON_BN_CLICKED(IDC_BUTTON_NEW_TASK, &CFalconDlg::OnBnClickedButtonNewTask)
	ON_BN_CLICKED(IDC_BUTTON_NEW_SUBTASK, &CFalconDlg::OnBnClickedButtonNewSubtask)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_SCREEN, &CFalconDlg::OnBnClickedButtonClearScreen)
	ON_BN_CLICKED(IDC_BUTTON_NEW_BRANCH_WARNING, &CFalconDlg::OnBnClickedButtonNewBranchWarning)
END_MESSAGE_MAP()


// CFalconDlg message handlers

BOOL CFalconDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.


	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Set the necessary styles for multiline, autoscroll, and scrollbars
	C_Bulletin_Display.ModifyStyle(0, ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_WANTRETURN | WS_VSCROLL | WS_HSCROLL);

	// Initialize fonts and other controls
	toolsDisplayFont.CreatePointFont(120, _T("Segoe UI")); // Font size 20
	tools_Display.SetFont(&toolsDisplayFont);

	m_BulletinFont.CreatePointFont(160, _T("Segoe UI")); // Font size 16
	Bulletin_Indicator.SetFont(&m_BulletinFont);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFalconDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFalconDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFalconDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Menu Command Handlers for "Weekly Bulletin"
//-------------------------------------------------------------------------------

// This event handler creates a new "Weekly Bulletin" with ".txt" extension when the user clicks on "New Bulletin".
void CFalconDlg::OnFileNewbulletin()
{
	CreateBulletin();
}

// This event handler opens a saved "Weekly Bulletin" with ".txt" extension when the user clicks on "Open".
void CFalconDlg::OnFileOpen32772()
{
	Open();
}

// This event handler saves the current "Weekly Bulletin" when the user clicks on "Save".
void CFalconDlg::OnFileSave32790()
{
	bool result = Save(filePath);

	// Show message box based on the result
	if (result) {
		AfxMessageBox(_T("File saved successfully!"));
	}
	else {
		AfxMessageBox(_T("Failed to save the file."));
	}
}

// This event handler saves the current "Weekly Bulletin" when the user clicks on "Save As".
void CFalconDlg::OnFileSaveAs()
{
	CFileDialog fileDlg(FALSE, _T("txt"), _T("Weekly Bulletin Generated by Falcon.txt"),
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), this);

	if (fileDlg.DoModal() == IDOK) {
		filePath = fileDlg.GetPathName();
		Save(filePath);
	}
}

//When the user clicks on the save button it will trigger save function
void CFalconDlg::OnBnClickedButtonSave()
{
	bool result = Save(filePath);

	// Show message box based on the result
	if (result) {
		AfxMessageBox(_T("File saved successfully!"));
	}
	else {
		AfxMessageBox(_T("Failed to save the file. Please click 'Save As' or press 'CTRL + ALT + S' to create the file"));
	}
}

//When the user clicks delete, trigger delete file operation
void CFalconDlg::OnBnClickedButtonDelete()
{
	Delete(filePath);
}

// This event handler deletes the current "Weekly Bulletin" when the user clicks on "Delete".
void CFalconDlg::OnFileDelete()
{
	Delete(filePath);
}

// This event handler closes the program when the user clicks on "Close".
void CFalconDlg::OnFileClose32775()
{
	// Post a WM_CLOSE message to close the dialog
	PostMessage(WM_CLOSE);
}

// This event handler closes the program when the user "X-27 Portfolio Website".
void CFalconDlg::OnHelpX()
{
	// URL to open
	LPCTSTR url = _T("http://www.denizkaryaacikbas.com");

	// Open the URL in the default web browser
	ShellExecute(0, _T("open"), url, 0, 0, SW_SHOWNORMAL);
}

// This event handler opens the "About" dialog when the user clicks on "About Falcon".
void CFalconDlg::OnHelpAboutfalcon()
{
	// Create and display the About dialog
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// Accelerator Command Handlers for "Weekly Bulletin"
//-------------------------------------------------------------------------------

// This event handler opens a saved "Weekly Bulletin" with ".txt" extension when the user presses on CTRL + O.
void CFalconDlg::OnAcceleratorOpen()
{
	Open();
}

// This event handler closes the program when the user presses on CTRL + C
void CFalconDlg::OnAcceleratorClose()
{
	// Post a WM_CLOSE message to close the dialog
	PostMessage(WM_CLOSE);
}

// This event handler saves the current "Weekly Bulletin" when the user presses on CTRL + S.
void CFalconDlg::OnAccelerator32792()
{
	bool result = Save(filePath);

	// Show message box based on the result
	if (result) {
		AfxMessageBox(_T("File saved successfully!"));
	}
	else {
		AfxMessageBox(_T("Failed to save the file."));
	}
}

// This event handler saves the current "Weekly Bulletin" when the user presses on CTRL + Alt + S.
void CFalconDlg::OnAcceleratorSaveAs()
{
	CFileDialog fileDlg(FALSE, _T("txt"), _T("Weekly Bulletin Generated by Falcon.txt"),
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), this);

	if (fileDlg.DoModal() == IDOK) {
		filePath = fileDlg.GetPathName();
		Save(filePath);
	}
}

// This event handler deletes the current "Weekly Bulletin" when the user presses on CTRL + D.
void CFalconDlg::OnAcceleratorDelete()
{
	Delete(filePath);
}

// This event handler creates a new "Weekly Bulletin" with ".txt" extension when the user presses on CTRL + N.
void CFalconDlg::OnAcceleratorNewBulletin()
{
	CreateBulletin();
}

// This event handler opens the "About" dialog when the user presses on CTRL + A.
void CFalconDlg::OnAcceleratorAbout()
{
	// Create and display the About dialog
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// This event handler closes the program when the user presses on CTRL + X.
void CFalconDlg::OnAcceleratorWebsite()
{
	// URL to open
	LPCTSTR url = _T("http://www.denizkaryaacikbas.com");

	// Open the URL in the default web browser
	ShellExecute(0, _T("open"), url, 0, 0, SW_SHOWNORMAL);
}

//This event handler opens up a new dialog to create a branch.
void CFalconDlg::OnBnClickedButtonNewBranch()
{
	New_Branch_Dialog branchDlg(this);
	branchDlg.DoModal();
}

//This event handler will create a new task on the branch.
void CFalconDlg::OnBnClickedButtonNewTask()
{
	New_Task_Dialog taskDlg(this);
	taskDlg.DoModal();
}

//This event handler will create a new subtask.
void CFalconDlg::OnBnClickedButtonNewSubtask()
{
	New_Subtask_Dialog subtaskDlg(this);
	subtaskDlg.DoModal();
}

//This event handler will create a new warning for branch.
void CFalconDlg::OnBnClickedButtonNewBranchWarning()
{
	//Create "Warning Creator" dialog.
	New_Branch_Warning_Dialog warningDlg(this);
	warningDlg.DoModal();
}

//This event handler will clear the screen.
void CFalconDlg::OnBnClickedButtonClearScreen()
{
	//Declare a pointer of "GlobalsManager.cpp".
	GlobalsManager* pGlobal = GlobalsManager::Instance();

	//Reset the task incrementer.
	pGlobal->globalVariablesInstance.bulletin.nextTaskId = 0;

	//Reset Bulletin Variable.
	Bulletin_Display = _T("");

	//Reset the screen.
	C_Bulletin_Display.SetWindowTextW(Bulletin_Display);
}

// Helper Methods for Handlers of "Weekly Bulletin"
//-------------------------------------------------------------------------------

//Helps to save the existing file
bool CFalconDlg::Save(CString FileLocation) { 
	// Open the file for writing
	CStdioFile file;
	if (!file.Open(FileLocation, CFile::modeCreate | CFile::modeWrite | CFile::typeText)) {
		return false;
	}

	C_Bulletin_Display.GetWindowText(Bulletin_Display);

	// Write the content of Bulletin_Display to the file
	file.WriteString(Bulletin_Display);

	// Close the file
	file.Close();

	return true;
}

//Helps to open the file
bool CFalconDlg::Open() {
	CFileDialog fileDlg(TRUE, _T("txt"), _T(""),
		OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
		_T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), this);

	if (fileDlg.DoModal() == IDOK) {
		CString filePath = fileDlg.GetPathName();

		// Open the file for reading
		CStdioFile file;
		if (!file.Open(filePath, CFile::modeRead | CFile::typeText)) {
			AfxMessageBox(_T("Unable to open file for reading"));
			return false;
		}

		// Read the file content
		CString fileContent, line;
		while (file.ReadString(line)) {
			fileContent += line;
			fileContent += _T("\r\n");
		}

		// Close the file
		file.Close();

		// Set the file content to the CEdit control
		C_Bulletin_Display.SetWindowTextW(fileContent);

		// Ensure the edit control scrolls to the end
		C_Bulletin_Display.LineScroll(C_Bulletin_Display.GetLineCount());
	}
}

//Helps to delete the file
void CFalconDlg::Delete(CString fileLocation)
{
	C_Bulletin_Display.SetWindowTextW(_T(""));
	filePath.Empty();

	if (DeleteFile(fileLocation)) {
		AfxMessageBox(_T("File deleted successfully"));
	}
	else {
		AfxMessageBox(_T("Failed to delete the file"));
	}
}

//Creates a bulletin.
void CFalconDlg::CreateBulletin()
{
	//Update this function further to help user to do operations.
	UpdateData(TRUE);

	//Declare a pointer of "GlobalsManager.cpp".
	GlobalsManager* pGlobal = GlobalsManager::Instance();

	//Write the head of the bulletin.
	std::time_t now = std::time(nullptr);
	pGlobal->globalVariablesInstance.bulletin.setDates(now, now + 7 * 24 * 60 * 60); // One week late

	//Save the result to the Bulletin_Display variable
	Bulletin_Display = pGlobal->globalVariablesInstance.bulletin.printBulletin();

	// Save the bulletin to a file
	C_Bulletin_Display.SetWindowTextW(Bulletin_Display);
}