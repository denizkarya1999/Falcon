// ProductivityCalculatorDialog.cpp : implementation file
//

#include "pch.h"
#include "Falcon.h"
#include "afxdialogex.h"
#include "ProductivityCalculatorDialog.h"

//Preprecessor operations for DLL.
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//Import the DLL Variables used.
extern "C" _declspec(dllimport) int CalculateScoreBasedOnExtracurriculars(const int HoursOfExtracurricular);
extern "C" _declspec(dllimport) int CalculateScoreBasedOnWorkHours(const int WorkHours);
extern "C" _declspec(dllimport) int CalculateScoreBasedOnUniversityCredits(const int UniversityCredits);

// ProductivityCalculatorDialog dialog

IMPLEMENT_DYNAMIC(ProductivityCalculatorDialog, CDialogEx)

ProductivityCalculatorDialog::ProductivityCalculatorDialog(CFalconDlg* pParentDlg, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PRODUCTIVITY_CALCULATOR, pParent), m_pFalconDlg(pParentDlg)
{
	//Set productivity score to 0
	ProductivityScore = 0;
}

ProductivityCalculatorDialog::~ProductivityCalculatorDialog()
{
}

void ProductivityCalculatorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PRODUCTIVITY_SCORE, ProductivityScoreBox);
	DDX_Control(pDX, IDC_EDIT_HOURS_OF_EXTRACURRICULARS, Weekly_Extracurriculars_Box);
	DDX_Control(pDX, IDC_EDIT_NUMBER_OF_COURSE_CREDITS, Number_Of_Course_Credits_Box);
	DDX_Control(pDX, IDC_EDIT_HOURS_OF_INTERNSHIP, Weekly_Work_Hours_Box);
}


BEGIN_MESSAGE_MAP(ProductivityCalculatorDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GENERATE_SCORE, &ProductivityCalculatorDialog::OnBnClickedButtonGenerateScore)
END_MESSAGE_MAP()


// ProductivityCalculatorDialog message handlers

//Control Handlers
//------------------------------------------------------------------

//When the user clicks on "Calculate Score" button, calculate the score based on values entered on the boxes.
void ProductivityCalculatorDialog::OnBnClickedButtonGenerateScore()
{
	//Update this function further to help user to do operations.
	UpdateData(TRUE);

	// Retrieve the text from the Weekly_Hours_Of_Work_Box CEdit control.
	Weekly_Work_Hours_Box.GetWindowTextW(WorkHours);
	Number_Of_Course_Credits_Box.GetWindowTextW(CourseCredits);
	Weekly_Extracurriculars_Box.GetWindowTextW(ExtracurricularHours);

	// Add the productivity score based on DLL methods.
	ProductivityScore += CalculateScoreBasedOnExtracurriculars(_ttoi(ExtracurricularHours));
	ProductivityScore += CalculateScoreBasedOnWorkHours(_ttoi(WorkHours));
	ProductivityScore += CalculateScoreBasedOnUniversityCredits(_ttoi(CourseCredits));

	//Assign to the score text box.
	strScore.Format(_T("%d"), ProductivityScore);
	ProductivityScoreBox.SetWindowTextW(strScore);

	//Reset the productivity score
	ProductivityScore = 0;
}
