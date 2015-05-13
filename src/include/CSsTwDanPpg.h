#if !defined(AFX_CSSTWDANPPG_H__81F47389_106F_432A_86DD_32A080E0663B__INCLUDED_)
#define AFX_CSSTWDANPPG_H__81F47389_106F_432A_86DD_32A080E0663B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// CSsTwDanPpg.h : Declaration of the CCSsTwDanPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CCSsTwDanPropPage : See CSsTwDanPpg.cpp.cpp for implementation.

class CCSsTwDanPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCSsTwDanPropPage)
	DECLARE_OLECREATE_EX(CCSsTwDanPropPage)

// Constructor
public:
	CCSsTwDanPropPage();

// Dialog Data
	//{{AFX_DATA(CCSsTwDanPropPage)
	enum { IDD = IDD_PROPPAGE_CSSTWDAN };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CCSsTwDanPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSSTWDANPPG_H__81F47389_106F_432A_86DD_32A080E0663B__INCLUDED)
