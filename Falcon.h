
// Falcon.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFalconApp:
// See Falcon.cpp for the implementation of this class
//

class CFalconApp : public CWinApp
{
public:
	CFalconApp();

// Overrides
public:
	virtual BOOL InitInstance();
	HACCEL m_hAccelTable_File_Menu;
	HACCEL m_hAccelTable_Help_Menu;
	HACCEL m_hAccelTable_Tools_Menu;

// Implementation

	DECLARE_MESSAGE_MAP()
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
};

extern CFalconApp theApp;
