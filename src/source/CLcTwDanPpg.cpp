// CLcTwDanPpg.cpp : Implementation of the CCLcTwDanPropPage property page class.

#include "stdafx.h"
#include "../include/CTwDan.h"
#include "../include/CLcTwDanPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CCLcTwDanPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CCLcTwDanPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CCLcTwDanPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CCLcTwDanPropPage, "CTWDAN.CLcTwDanPropPage.1",
	0xcc774727, 0x4940, 0x45d5, 0xab, 0x30, 0x56, 0x62, 0x58, 0xae, 0x7e, 0x73)


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanPropPage::CCLcTwDanPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CCLcTwDanPropPage

BOOL CCLcTwDanPropPage::CCLcTwDanPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CLCTWDAN_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanPropPage::CCLcTwDanPropPage - Constructor

CCLcTwDanPropPage::CCLcTwDanPropPage() :
	COlePropertyPage(IDD, IDS_CLCTWDAN_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CCLcTwDanPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanPropPage::DoDataExchange - Moves data between page and properties

void CCLcTwDanPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CCLcTwDanPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanPropPage message handlers
