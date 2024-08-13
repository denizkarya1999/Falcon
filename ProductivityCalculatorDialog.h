#pragma once
#include "afxdialogex.h"
#include "FalconDlg.h"


// ProductivityCalculatorDialog dialog

class ProductivityCalculatorDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ProductivityCalculatorDialog)

public:
	ProductivityCalculatorDialog(CFalconDlg* pParentDlg, CWnd* pParent = nullptr);    // standard constructor
	virtual ~ProductivityCalculatorDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PRODUCTIVITY_CALCULATOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	//Local control variables
	CStatic ProductivityScoreBox;
	CEdit Weekly_Work_Hours_Box;
	CEdit Number_Of_Course_Credits_Box;
	CEdit Weekly_Extracurriculars_Box;
	CFont scoreFont;

	//Local value variables
	CString WorkHours;
	CString CourseCredits;
	CString ExtracurricularHours;
	int ProductivityScore;

	//Transformation variables
	CString strScore;

	// Pointer to the parent dialog
	CFalconDlg* m_pFalconDlg;

	//Controller handlers
	afx_msg void OnBnClickedButtonGenerateScore();
};
