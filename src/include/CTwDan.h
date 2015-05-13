#if !defined(AFX_CTWDAN_H__9B5B1774_5F86_48B1_9735_3E8881B11F37__INCLUDED_)
#define AFX_CTWDAN_H__9B5B1774_5F86_48B1_9735_3E8881B11F37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// CTwDan.h : main header file for CTWDAN.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "../make/Resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCTwDanApp : See CTwDan.cpp for implementation.

class CCTwDanApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTWDAN_H__9B5B1774_5F86_48B1_9735_3E8881B11F37__INCLUDED)
