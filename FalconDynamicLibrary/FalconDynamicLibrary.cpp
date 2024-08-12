// FalconDynamicLibrary.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "FalconDynamicLibrary.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//Create "extern" variables to export DLL methods for EXE.
//-----------------------------------------------------------------------------------------------
extern "C" _declspec(dllexport) int CalculateScoreBasedOnExtracurriculars(const int HoursOfExtracurricular);
extern "C" _declspec(dllexport) int CalculateScoreBasedOnWorkHours(const int WorkHours);
extern "C" _declspec(dllexport) int CalculateScoreBasedOnUniversityCredits(const int UniversityCredits);

//Implement the methods declared here
//-----------------------------------------------------------------------------------------------
//Calculate the productivity score based on the hours of relevant extra-curricular activity.
int CalculateScoreBasedOnExtracurriculars(const int HoursOfRelevantExtracurricular) {
	/*
	* Productivity Score Table for Extracurriculars
	* ------------------------------------------
	* If no extracurricular spend -> 0 Points
	* Less than 7 hours -> 5 Points
	* Between 7 to 10 hours -> 10 Points
	* Between 10 to 15 hours -> 15 Points
	* Between 15 to 24 hours -> 20 Points
	* More than 24 hours -> 25 Points
	*/
	if (HoursOfRelevantExtracurricular <= 0) {
		return 0;
	}
	else if (HoursOfRelevantExtracurricular < 7) {
		return 5;
	}
	else if (HoursOfRelevantExtracurricular >= 7 && HoursOfRelevantExtracurricular < 10) {
		return 10;
	}
	else if (HoursOfRelevantExtracurricular >= 10 && HoursOfRelevantExtracurricular < 15) {
		return 15;
	}
	else if (HoursOfRelevantExtracurricular >= 15 && HoursOfRelevantExtracurricular < 24) {
		return 20;
	}
	else if (HoursOfRelevantExtracurricular >= 24) {
		return 25;
	}
	return 0;
}

//Calculate the productivity score based on the hours of work if there is an internship or full time work.
int CalculateScoreBasedOnWorkHours(const int WorkHours) {
	/*
	* Productivity Score Table for Work Hours
	* ------------------------------------------
	* No work -> 0 Points
	* Less than 10 -> 50 Points
	* Between 10 to 20 hours -> 55 Points
	* Between 20 to 30 hours -> 60 Points
	* Between 30 to 40 hours -> 65 Points
	* Between 40 to 45 hours -> 70 Points
	* 45 Hours and More -> 75 Points
	*/
	if (WorkHours <= 0) {
		return 0;
	}
	else if (WorkHours < 10) {
		return 50;
	}
	else if (WorkHours >= 10 && WorkHours < 20) {
		return 55;
	}
	else if (WorkHours >= 20 && WorkHours < 30) {
		return 60;
	}
	else if (WorkHours >= 30 && WorkHours < 40) {
		return 65;
	}
	else if (WorkHours >= 40 && WorkHours < 45) {
		return 70;
	}
	else if (WorkHours >= 45) {
		return 75;
	}
}

//Calculate the productivity score based on the number of credits completed in a university.
int CalculateScoreBasedOnUniversityCredits(const int UniversityCredits) {
    /*
	* Productivity Score Table for University Credits
	* ------------------------------------------
	* No university course -> 0 Points
	* Between 3 to 4 Credits -> 50 Points
	* Between 4 to 6 Credits -> 55 Points
	* Between 6 to 8 Credits -> 60 Points
	* Between 9 to 12 Credits -> 65 Points
	* 12 or More Credits -> 75 Points
	*/
	if (UniversityCredits <= 0) {
		return 0;
	}
	else if (UniversityCredits >= 3 && UniversityCredits <= 4) {
		return 50;
	}
	else if (UniversityCredits > 4 && UniversityCredits < 6) {
		return 55;
	}
	else if (UniversityCredits >= 6 && UniversityCredits <= 8) {
		return 60;
	}
	else if (UniversityCredits >= 9 && UniversityCredits < 12) {
		return 65;
	}
	else if (UniversityCredits >= 12) {
		return 75;
	}
}

// CFalconDynamicLibraryApp
BEGIN_MESSAGE_MAP(CFalconDynamicLibraryApp, CWinApp)
END_MESSAGE_MAP()


// CFalconDynamicLibraryApp construction

CFalconDynamicLibraryApp::CFalconDynamicLibraryApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CFalconDynamicLibraryApp object

CFalconDynamicLibraryApp theApp;


// CFalconDynamicLibraryApp initialization

BOOL CFalconDynamicLibraryApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
