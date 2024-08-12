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
extern "C" _declspec(dllexport) int CalculateScoreBasedOnExtracurriculars(const int HoursOfExtracurricular);
extern "C" _declspec(dllexport) int CalculateScoreBasedOnWorkHours(const int WorkHours);
extern "C" _declspec(dllexport) int CalculateScoreBasedOnUniversityCredits(const int UniversityCredits);

// ProductivityCalculatorDialog dialog

IMPLEMENT_DYNAMIC(ProductivityCalculatorDialog, CDialogEx)

ProductivityCalculatorDialog::ProductivityCalculatorDialog(CFalconDlg* pParentDlg, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PRODUCTIVITY_CALCULATOR, pParent), m_pFalconDlg(pParentDlg)
{
}

ProductivityCalculatorDialog::~ProductivityCalculatorDialog()
{
}

void ProductivityCalculatorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ProductivityCalculatorDialog, CDialogEx)
END_MESSAGE_MAP()


// ProductivityCalculatorDialog message handlers
