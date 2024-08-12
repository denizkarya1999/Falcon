
// FalconDlg.h : header file
//

#pragma once


// CFalconDlg dialog
class CFalconDlg : public CDialogEx
{
// Construction
public:
	CFalconDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FALCON_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//Variables
	CString filePath;
	CString Bulletin_Display;
	CEdit C_Bulletin_Display;
	CFont m_BulletinFont;
	CStatic Bulletin_Indicator;
	CFont toolsDisplayFont;
	CStatic tools_Display;

	//Controller Helper Methods
	afx_msg void OnFileNewbulletin();
	afx_msg void OnFileOpen32772();
	afx_msg void OnFileSave32790();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileDelete();
	afx_msg void OnFileClose32775();
	afx_msg void OnHelpX();
	afx_msg void OnHelpAboutfalcon();
	afx_msg void OnBnClickedButtonNewBranch();
	afx_msg void OnBnClickedButtonNewTask();
	afx_msg void OnBnClickedButtonNewSubtask();
	afx_msg void OnBnClickedButtonNewBranchWarning();
	afx_msg void OnBnClickedButtonClearScreen();
	afx_msg void OnToolsProductivityScoreCalculatorClick();

	// Accelerator Helper Methods
	afx_msg void OnAcceleratorOpen();
	afx_msg void OnAcceleratorClose();
	afx_msg void OnAcceleratorSaveAs();
	afx_msg void OnAcceleratorDelete();
	afx_msg void OnAcceleratorNewBulletin();
	afx_msg void OnAcceleratorAbout();
	afx_msg void OnAcceleratorWebsite();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnAccelerator32792();
	afx_msg void OnAcceleratorProductivityScore();

	//Helper methods for the handlers
	bool Open();
	bool Save(CString FileLocation);
	void Delete(CString FileLocation);

	//Creates a "Weekly Bulletin"
	void CreateBulletin();
};
