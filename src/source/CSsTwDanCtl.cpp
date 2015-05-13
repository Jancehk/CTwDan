// CSsTwDanCtl.cpp : Implementation of the CCSsTwDanCtrl ActiveX Control class.

#include "stdafx.h"
#include "..\include\CTwDan.h"
#include "..\include\CSsTwDanCtl.h"
#include "..\include\CSsTwDanPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CCSsTwDanCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CCSsTwDanCtrl, COleControl)
	//{{AFX_MSG_MAP(CCSsTwDanCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CCSsTwDanCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CCSsTwDanCtrl)
	// NOTE - ClassWizard will add and remove dispatch map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CCSsTwDanCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CCSsTwDanCtrl, COleControl)
	//{{AFX_EVENT_MAP(CCSsTwDanCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CCSsTwDanCtrl, 1)
	PROPPAGEID(CCSsTwDanPropPage::guid)
END_PROPPAGEIDS(CCSsTwDanCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CCSsTwDanCtrl, "CTWDAN.CSsTwDanCtrl.1",
	0x712ecd25, 0x6f8a, 0x4d4d, 0xa9, 0x47, 0x91, 0x5c, 0x33, 0x85, 0xaa, 0xbf)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CCSsTwDanCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DCSsTwDan =
		{ 0xe2a89ff, 0xe548, 0x4731, { 0x82, 0xf3, 0xf4, 0xd6, 0xce, 0x84, 0x73, 0x75 } };
const IID BASED_CODE IID_DCSsTwDanEvents =
		{ 0x71f4ef0e, 0x422d, 0x4d65, { 0xb5, 0x8f, 0x3a, 0xc6, 0xd1, 0x48, 0x7d, 0x29 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwCSsTwDanOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CCSsTwDanCtrl, IDS_CSSTWDAN, _dwCSsTwDanOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanCtrl::CCSsTwDanCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CCSsTwDanCtrl

BOOL CCSsTwDanCtrl::CCSsTwDanCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_CSSTWDAN,
			IDB_CSSTWDAN,
			afxRegApartmentThreading,
			_dwCSsTwDanOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanCtrl::CCSsTwDanCtrl - Constructor

CCSsTwDanCtrl::CCSsTwDanCtrl()
{
	InitializeIIDs(&IID_DCSsTwDan, &IID_DCSsTwDanEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanCtrl::~CCSsTwDanCtrl - Destructor

CCSsTwDanCtrl::~CCSsTwDanCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanCtrl::OnDraw - Drawing function

void CCSsTwDanCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanCtrl::DoPropExchange - Persistence support

void CCSsTwDanCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanCtrl::OnResetState - Reset control to default state

void CCSsTwDanCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanCtrl::AboutBox - Display an "About" box to the user

void CCSsTwDanCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_CSSTWDAN);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanCtrl message handlers


