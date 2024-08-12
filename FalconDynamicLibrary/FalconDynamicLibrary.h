// FalconDynamicLibrary.h : main header file for the FalconDynamicLibrary DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFalconDynamicLibraryApp
// See FalconDynamicLibrary.cpp for the implementation of this class
//

class CFalconDynamicLibraryApp : public CWinApp
{
public:
	CFalconDynamicLibraryApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
