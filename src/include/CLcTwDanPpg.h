#if !defined(AFX_CLCTWDANPPG_H__615E5AC0_6B51_4EFC_9512_5995BE249F6D__INCLUDED_)
#define AFX_CLCTWDANPPG_H__615E5AC0_6B51_4EFC_9512_5995BE249F6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// CLcTwDanPpg.h : Declaration of the CCLcTwDanPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CCLcTwDanPropPage : See CLcTwDanPpg.cpp.cpp for implementation.

class CCLcTwDanPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCLcTwDanPropPage)
	DECLARE_OLECREATE_EX(CCLcTwDanPropPage)

// Constructor
public:
	CCLcTwDanPropPage();

// Dialog Data
	//{{AFX_DATA(CCLcTwDanPropPage)
	enum { IDD = IDD_PROPPAGE_CLCTWDAN };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CCLcTwDanPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLCTWDANPPG_H__615E5AC0_6B51_4EFC_9512_5995BE249F6D__INCLUDED)
