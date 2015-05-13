// CSsTwDanPpg.cpp : Implementation of the CCSsTwDanPropPage property page class.

#include "stdafx.h"
#include "..\include\CTwDan.h"
#include "..\include\CSsTwDanPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CCSsTwDanPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CCSsTwDanPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CCSsTwDanPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CCSsTwDanPropPage, "CTWDAN.CSsTwDanPropPage.1",
	0x86e7a416, 0xf8b7, 0x427d, 0x98, 0xa7, 0xb6, 0x5c, 0x6f, 0xe8, 0x36, 0x8e)


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanPropPage::CCSsTwDanPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CCSsTwDanPropPage

BOOL CCSsTwDanPropPage::CCSsTwDanPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CSSTWDAN_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanPropPage::CCSsTwDanPropPage - Constructor

CCSsTwDanPropPage::CCSsTwDanPropPage() :
	COlePropertyPage(IDD, IDS_CSSTWDAN_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CCSsTwDanPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanPropPage::DoDataExchange - Moves data between page and properties

void CCSsTwDanPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CCSsTwDanPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CCSsTwDanPropPage message handlers
