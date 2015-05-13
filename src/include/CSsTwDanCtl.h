#if !defined(AFX_CSSTWDANCTL_H__6030DE0E_6D3B_4B44_A6BF_B87FCA698E6B__INCLUDED_)
#define AFX_CSSTWDANCTL_H__6030DE0E_6D3B_4B44_A6BF_B87FCA698E6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define SCREEN_HIGHT	720
#define SCREEN_WIGTH	668

// CSsTwDanCtl.h : Declaration of the CCSsTwDanCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanCtrl : See CSsTwDanCtl.cpp for implementation.

class CCSsTwDanCtrl : public COleControl
{
	DECLARE_DYNCREATE(CCSsTwDanCtrl)

// Constructor
public:
	CCSsTwDanCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSsTwDanCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CCSsTwDanCtrl();

	DECLARE_OLECREATE_EX(CCSsTwDanCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CCSsTwDanCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CCSsTwDanCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CCSsTwDanCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CCSsTwDanCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CCSsTwDanCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CCSsTwDanCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CCSsTwDanCtrl)
		// NOTE: ClassWizard will add and remove enumeration elements here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSSTWDANCTL_H__6030DE0E_6D3B_4B44_A6BF_B87FCA698E6B__INCLUDED)
