// CLcTwDanCtl.cpp : Implementation of the CCLcTwDanCtrl ActiveX Control class.

#include "StdAfx.h"
#include "../include/CTwDan.h"
#include "../include/CLcTwDanCtl.h"
#include "../include/CLcTwDanPpg.h"
#include "../Include/TwDanCommFun.h"
#include "../Include/BalloonTip.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
												\
/*
#define GETMAXNUM(a,b,c) do \
{							\
	if ((a)>=(b)){if ((a)>=(c)){return (a);}}\
	else{if ((b)>=(c)){return (b);}}return (c);				\
} while (0)
#define GETMINNUM(a,b,c) do \
{							\
if ((a)<=(b)){if ((a)<=(c)){return (a);}}\
else{if ((b)<=(c)){return (b);}}return (c);				\
} while (0)
*/

IMPLEMENT_DYNCREATE(CCLcTwDanCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CCLcTwDanCtrl, COleControl)
	//{{AFX_MSG_MAP(CCLcTwDanCtrl)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CHAR()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CCLcTwDanCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CCLcTwDanCtrl)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetHospital", m_SetHospital, OnSetHospitalChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetTitleName", m_SetTitleName, OnSetTitleNameChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetPatientInfo", m_SetPatientInfo, OnSetPatientInfoChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetPatientRyDate", m_SetPatientRyDate, OnSetPatientRyDateChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetFS", m_SetFS, OnSetFSChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetTS", m_SetTS, OnSetTSChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetMinute", m_SetMinute, OnSetMinuteChanged, VT_R8)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetCTwDanInfo", m_SetCTwDanInfo, OnSetCTwDanInfoChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "GetCTwDanInfo", m_GetCTwDanInfo, OnGetCTwDanInfoChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetTwDanFocus", m_SetTwDanFocus, OnSetTwDanFocusChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetRyDayBegin", m_setRyDayBegin, OnSetRyDayBeginChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetHospitalFontName", SetHospitalFontName, OnSetHospitalFontNameChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetHospitalFontSize", m_SetHospitalFontSize, OnSetHospitalFontSizeChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetTitleNameFontName", m_SetTitleNameFontName, OnSetTitleNameFontNameChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetTitleNameFontSize", m_SetTitleNameFontSize, OnSetTitleNameFontSizeChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "PrintInfoVer", PrintInfoVer, OnPrintInfoVerChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetAftDayDisable", m_SetAftDayDisable, OnSetAftDayDisableChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "GetChageList", GetChageListstr, OnGetChageListChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetTipShow", m_SetTipShow, OnSetTipShowChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CCLcTwDanCtrl, "SetShowBeginDays", m_SetShowBeginDays, OnSetShowBeginDaysChanged, VT_I2)
	DISP_FUNCTION(CCLcTwDanCtrl, "PrintInfo", PrintInfo, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CCLcTwDanCtrl, "BefDay", BefDay, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CCLcTwDanCtrl, "AftDay", AftDay, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CCLcTwDanCtrl, "BefWeek", BefWeek, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CCLcTwDanCtrl, "AftWeek", AftWeek, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CCLcTwDanCtrl, "SaveTmpStorage", SaveTmpStorage, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CCLcTwDanCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CCLcTwDanCtrl, COleControl)
	//{{AFX_EVENT_MAP(CCLcTwDanCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CCLcTwDanCtrl, 1)
	PROPPAGEID(CCLcTwDanPropPage::guid)
END_PROPPAGEIDS(CCLcTwDanCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CCLcTwDanCtrl, "CTWDAN.CLcTwDanCtrl.1",
	0xc4cbaf0f, 0xbd05, 0x435d, 0x86, 0xc5, 0xa7, 0x8c, 0x50, 0x4e, 0xbe, 0x8c)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CCLcTwDanCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DCLcTwDan =
		{ 0xe52ca87f, 0xdfe, 0x4fd7, { 0xa3, 0x10, 0x40, 0xd8, 0x42, 0xe1, 0xa8, 0xaf } };
const IID BASED_CODE IID_DCLcTwDanEvents =
		{ 0x509f1ca8, 0x359c, 0x4449, { 0x9e, 0x7a, 0xd1, 0x63, 0xac, 0x31, 0x91, 0x47 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwCLcTwDanOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CCLcTwDanCtrl, IDS_CLCTWDAN, _dwCLcTwDanOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanCtrl::CCLcTwDanCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CCLcTwDanCtrl

BOOL CCLcTwDanCtrl::CCLcTwDanCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_CLCTWDAN,
			IDB_CLCTWDAN,
			afxRegApartmentThreading,
			_dwCLcTwDanOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}

static CTWDANMANAGE g_CtwnDanManage;
/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanCtrl::CCLcTwDanCtrl - Constructor

CCLcTwDanCtrl::CCLcTwDanCtrl()
{
	InitializeIIDs(&IID_DCLcTwDan, &IID_DCLcTwDanEvents);
	m_ScreenSize	=CRect(0,0,SCREEN_WIGTH,SCREEN_HIGHT);
	SetHospitalFontName = _T("华文行楷");
	m_SetHospitalFontSize = 28;
	m_SetHospital	= _T("医院名称");
	m_SetTitleName	=_T("电子体温单");
	PrintInfoVer = _T("ddddddddddddddddddd");
	//memset(&g_CtwnDanManage.Special,0,sizeof(SPECIAL)*PSPACEL_SUM);
	g_CtwnDanManage.bIsPrint = CTWDAN_INIT;
	g_CtwnDanManage.CurrentEndDay =0;
	m_SetTwDanFocus = 0;
	//memset(&g_CtwnDanManage.Special, 0, PSPACEL_SUM*sizeof(SPECIAL));
	memset(&g_CtwnDanManage.stuLcTwDan, 0, PSPACEL_SUM*sizeof(CTWLCDANINFO));
	m_SetFS =0;
	m_setRyDayBegin =0;
	m_SetAftDayDisable =3;
	flg = true;
	m_AnlStr.SetParementValue(this);
	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanCtrl::~CCLcTwDanCtrl - Destructor

CCLcTwDanCtrl::~CCLcTwDanCtrl()
{
	// TODO: Cleanup your control's instance data here.
	pCTWLCDANINFO stuLcTwDanTmp = NULL;
	while(g_CtwnDanManage.m_ptrArray.GetSize() > 0)
	{
		stuLcTwDanTmp = (pCTWLCDANINFO)g_CtwnDanManage.m_ptrArray.GetAt(0);
		g_CtwnDanManage.m_ptrArray.RemoveAt(0);
		if (NULL != stuLcTwDanTmp)
		{
			free(stuLcTwDanTmp);
			stuLcTwDanTmp = NULL;
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanCtrl::OnDraw - Drawing function

void CCLcTwDanCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	//::SetWindowPos(GetSafeHwnd() , HWND_TOPMOST ,  1 ,1 , 100 , 200, SWP_NOSIZE );
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	OnPrintInfo(pdc,rcBounds);
//	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanCtrl::DoPropExchange - Persistence support

void CCLcTwDanCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanCtrl::OnResetState - Reset control to default state

void CCLcTwDanCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanCtrl::AboutBox - Display an "About" box to the user

void CCLcTwDanCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_CLCTWDAN);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanCtrl message handlers

void CCLcTwDanCtrl::OnPrintInfo(CDC *pdc,CRect rcBounds)
{
	CFont font,*oldfont;
	float	m_printLevel;
	CPoint point;
	CRect DrawRect,tempRect;
	CPen pen(12,2,RGB(0,0,0));
	int m_LevHigh=0;
	int m_LevWith=0;
	int m_index=0;
	int m_indextemp1=0;
	int m_indextemp2=0;
	//	GetWindowRect(clientRect);
	m_indextemp2 = sizeof(CTWLCDANINFO);
	g_CtwnDanManage.m_printLevel = m_printLevel = (float)rcBounds.Width()/m_ScreenSize.Width();
	if (CTWDAN_INIT != g_CtwnDanManage.bIsPrint)
	{
		return;
	}
	/************************************************************************/
	/* 画出体温单的界面                                                    */
	/************************************************************************/
	if (1.0==m_printLevel)
	{
		g_CtwnDanManage.bIsPrint = CTWDAN_SELF;
		m_LevHigh=1;
		m_LevWith=1;
	}
	else if (1.0 > m_printLevel)
	{
//		MessageBox(_T("位置不对"),_T("警告"),MB_ICONSTOP);
	}
	else
	{
		g_CtwnDanManage.bIsPrint = CTWDAN_PRINT;
		m_printLevel=float(m_printLevel-0.2);
		m_LevHigh =(int)(rcBounds.Height() - m_ScreenSize.Height()*m_printLevel)/2;
		m_LevWith =(int)(rcBounds.Width() - m_ScreenSize.Width()*m_printLevel )/2;
	}
	g_CtwnDanManage.penRed.DeleteObject();
	g_CtwnDanManage.penRed.CreatePen(PS_SOLID,GetResult(2,m_printLevel),RGB(0,0,255));  //粗红笔
	g_CtwnDanManage.penBule.DeleteObject();
	g_CtwnDanManage.penBule.CreatePen(PS_SOLID,GetResult(2,m_printLevel),RGB(0,0,0));  //粗红笔
	g_CtwnDanManage.penDot.DeleteObject();
	g_CtwnDanManage.penDot.CreatePen(PS_DASH,GetResult(1,m_printLevel*1.8),RGB(255,0,0));  //粗红笔
	
//	MessageBox(_T("1111111111111位置不对"),_T("警告"),MB_ICONSTOP);
	DrawRect.left = rcBounds.left + m_LevWith;
	DrawRect.top  = rcBounds.top +m_LevHigh;
	DrawRect.right = rcBounds.right - m_LevWith;
	DrawRect.bottom = rcBounds.bottom -m_LevHigh;
	if (m_printLevel<1)
	{
		return;
	}
	g_CtwnDanManage.Bounds = DrawRect;
	g_CtwnDanManage.SizeLeve = m_printLevel;
	pdc->SelectObject(&pen);
	pdc->Rectangle(&DrawRect);  //描述一个矩形框
	//set hospital name
	font.CreateFont(-MulDiv(m_SetHospitalFontSize,-pdc->GetDeviceCaps(LOGPIXELSY),72),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,SetHospitalFontName);
	oldfont=pdc->SelectObject(&font);

	pen.DeleteObject();
	pen.CreatePen(12,1,RGB(0,0,0));    //细黑笔
	pdc->SelectObject(&pen);
	tempRect=DrawRect;
	tempRect.InflateRect(0,-GetResult(5,m_printLevel),0,0);
	pdc->DrawText(m_SetHospital,&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);
	pdc->SelectObject(oldfont);
	font.DeleteObject();
	
	//set little title name
	font.CreateFont(-MulDiv(15,-pdc->GetDeviceCaps(LOGPIXELSY),72),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,_T("宋体"));
	oldfont=pdc->SelectObject(&font);
	tempRect.top=DrawRect.top+GetResult(40,m_printLevel);
	pdc->DrawText(m_SetTitleName,&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);
//	tempRect.InflateRect(0,-5,0,0);
	pdc->SelectObject(oldfont);
	font.DeleteObject();
//	ShowLine();
	g_CtwnDanManage.NeiBounds.left   = DrawRect.left+GetResult(80,m_printLevel);
	g_CtwnDanManage.NeiBounds.right   = DrawRect.right;
	g_CtwnDanManage.NeiBounds.top = DrawRect.top+GetResult(185,m_printLevel);
	g_CtwnDanManage.NeiBounds.bottom = DrawRect.top+GetResult(585,m_printLevel);
	for (int tt=0;tt<GetResult(70,m_printLevel);tt=tt+GetResult(20,m_printLevel))//最上的三条线
	{
		pdc->MoveTo(DrawRect.left,DrawRect.top+GetResult(80,m_printLevel)+tt);
		pdc->LineTo(DrawRect.right,DrawRect.top+GetResult(80,m_printLevel)+tt);
	}
	pdc->MoveTo(g_CtwnDanManage.NeiBounds.left,DrawRect.top+GetResult(80,m_printLevel));
	pdc->LineTo(g_CtwnDanManage.NeiBounds.left,DrawRect.bottom);

	pdc->MoveTo(DrawRect.left,DrawRect.top+GetResult(155,m_printLevel));
	pdc->LineTo(DrawRect.right,DrawRect.top+GetResult(155,m_printLevel));

	pdc->MoveTo(g_CtwnDanManage.NeiBounds.left,DrawRect.top+GetResult(165,m_printLevel));
	pdc->LineTo(DrawRect.right,DrawRect.top+GetResult(165,m_printLevel));
	
	pdc->MoveTo(g_CtwnDanManage.NeiBounds.left,DrawRect.top+GetResult(175,m_printLevel));
	pdc->LineTo(DrawRect.right,DrawRect.top+GetResult(175,m_printLevel));
	
	m_index = GetResult(42,m_printLevel);
	m_indextemp1=DrawRect.top+GetResult(140,m_printLevel);
	m_indextemp2=DrawRect.bottom-GetResult(120,m_printLevel);
	for (tt=DrawRect.left+GetResult(94,m_printLevel);tt<DrawRect.right-1;tt=tt+m_index)
	{
		pdc->MoveTo(tt,m_indextemp1);
		pdc->LineTo(tt,m_indextemp2);
		
		pdc->MoveTo(tt+GetResult(14,m_printLevel),m_indextemp1);
		pdc->LineTo(tt+GetResult(14,m_printLevel),m_indextemp2);
	}

	m_index = GetResult(50,m_printLevel);
	m_indextemp1=DrawRect.top+GetResult(185,m_printLevel);
	m_indextemp2=DrawRect.bottom-GetResult(145,m_printLevel);

	for (tt=m_indextemp1;tt<m_indextemp2;tt=tt+m_index)  //细横线
	{
		pdc->MoveTo(g_CtwnDanManage.NeiBounds.left,tt+GetResult(10,m_printLevel));
		pdc->LineTo(DrawRect.right,tt+GetResult(10,m_printLevel));
		pdc->MoveTo(g_CtwnDanManage.NeiBounds.left,tt+GetResult(20,m_printLevel));
		pdc->LineTo(DrawRect.right,tt+GetResult(20,m_printLevel));
		pdc->MoveTo(g_CtwnDanManage.NeiBounds.left,tt+GetResult(30,m_printLevel));
		pdc->LineTo(DrawRect.right,tt+GetResult(30,m_printLevel));
		pdc->MoveTo(g_CtwnDanManage.NeiBounds.left,tt+GetResult(40,m_printLevel));
		pdc->LineTo(DrawRect.right,tt+GetResult(40,m_printLevel));
	}
	
	pdc->MoveTo(DrawRect.left,g_CtwnDanManage.NeiBounds.bottom);
	pdc->LineTo(DrawRect.right,g_CtwnDanManage.NeiBounds.bottom);
	
	m_index = GetResult(20,m_printLevel);
	m_indextemp1=DrawRect.left+GetResult(80,m_printLevel);
	m_indextemp2=DrawRect.right;

	for (tt=20;tt<=120;tt=tt+20)  //细横线
	{
		pdc->MoveTo(m_indextemp1,DrawRect.bottom-GetResult(tt,m_printLevel));
		pdc->LineTo(m_indextemp2,DrawRect.bottom-GetResult(tt,m_printLevel));
	}
	pen.DeleteObject();
	pen.CreatePen(12,(int)(2*m_printLevel),RGB(255,0,0));  //粗红笔
	pdc->SelectObject(&pen);
	
	//星期分割线
	m_index = GetResult(84,m_printLevel);
	m_indextemp1=DrawRect.top+GetResult(80,m_printLevel);
	m_indextemp2=DrawRect.bottom-GetResult(2,m_printLevel);
	
	for (tt=DrawRect.left+GetResult(164,m_printLevel);tt<DrawRect.right-10;tt=tt+m_index)  //中心水平
	{
		pdc->MoveTo(tt,m_indextemp1);
		pdc->LineTo(tt,m_indextemp2);  //下底边
	}
	m_index = GetResult(100,m_printLevel);
	m_indextemp1=DrawRect.left+GetResult(80,m_printLevel);
	m_indextemp2=DrawRect.right-1;
	for (tt=DrawRect.top+GetResult(185,m_printLevel);tt<DrawRect.bottom-GetResult(140,m_printLevel);tt=tt+m_index)  //中心竖线
	{
		pdc->MoveTo(m_indextemp1,tt);
		pdc->LineTo(m_indextemp2,tt);
	}
	pen.DeleteObject();
	pen.CreatePen(12,(int)(2*m_printLevel),RGB(0,0,0));//粗黑笔
	pdc->SelectObject(&pen);
	
	m_index = GetResult(84,m_printLevel);
	m_indextemp1=DrawRect.top+GetResult(140,m_printLevel);
	m_indextemp2=DrawRect.bottom-GetResult(120,m_printLevel);
	
	for (tt=DrawRect.left+GetResult(122,m_printLevel);tt<DrawRect.right-1;tt=tt+m_index)
	{
		pdc->MoveTo(tt,m_indextemp1);
		pdc->LineTo(tt,m_indextemp2);
		
		pdc->MoveTo(tt,DrawRect.top+GetResult(m_printLevel==1?679:681,m_printLevel));
		pdc->LineTo(tt,DrawRect.top+GetResult(m_printLevel==1?698:700,m_printLevel));
	}
	m_index = GetResult(100,m_printLevel);
	m_indextemp1=DrawRect.left+GetResult(80,m_printLevel);
	m_indextemp2=DrawRect.right-1;
	for (tt=DrawRect.top+GetResult(235,m_printLevel);tt<DrawRect.bottom-GetResult(135,m_printLevel);tt+=m_index)
	{
		pdc->MoveTo(m_indextemp1,tt);
		pdc->LineTo(m_indextemp2,tt);
	}
	
	pdc->SelectObject(oldfont);
	font.DeleteObject();

	/************************************************************************/
	/*  左侧篮筐内容                        */
	/************************************************************************/
	font.DeleteObject();
	font.CreateFont(-MulDiv(11,-pdc->GetDeviceCaps(LOGPIXELSY),72),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,_T("宋体"));
	pdc->SelectObject(&font);
	
	pen.DeleteObject();
	pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
	pdc->SelectObject(&pen);
	
	m_index=DrawRect.left+GetResult(8,m_printLevel);
	pdc->TextOut(m_index,DrawRect.top+GetResult(83,m_printLevel),_T("入院日期:"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(103,m_printLevel),_T("住院天数:"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(603,m_printLevel),_T("大便次数:"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(623,m_printLevel),_T("输入液量:"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(643,m_printLevel),_T("尿量(ml):"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(663,m_printLevel),_T("痰量(ml):"));
	//pdc->TextOut(m_index,DrawRect.top+GetResult(683,m_printLevel),_T("高/低压:"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(700,m_printLevel),_T("体重(kg):"));
	

	/***/
	font.DeleteObject();
	font.CreateFont(-MulDiv(7,-pdc->GetDeviceCaps(LOGPIXELSY),55),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,_T("宋体"));
	pdc->SelectObject(&font);
	pdc->TextOut(m_index,DrawRect.top+GetResult(63,m_printLevel),m_SetPatientInfo);
	pdc->TextOut(m_index,DrawRect.top+GetResult(682,m_printLevel),_T("舒张/收缩压:"));
	
	/*****/


	font.DeleteObject();
	font.CreateFont(-MulDiv(9,-pdc->GetDeviceCaps(LOGPIXELSY),70),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,_T("宋体"));
	pdc->SelectObject(&font);
	
	pdc->TextOut(DrawRect.left+GetResult(5,m_printLevel),DrawRect.top+GetResult(125,m_printLevel),_T("术/产后天数:"));
	pdc->TextOut(DrawRect.left+GetResult(15,m_printLevel),DrawRect.top+GetResult(143,m_printLevel),_T("时间:"));
	pdc->TextOut(DrawRect.left+GetResult(20,m_printLevel),DrawRect.top+GetResult(588,m_printLevel),_T("呼吸:"));
	m_index=GetResult(42,m_printLevel);
	m_indextemp1=DrawRect.top+GetResult(143,m_printLevel);
	for (int timea=DrawRect.left+GetResult(84,m_printLevel)+1;timea<DrawRect.right-1;timea+=m_index)
	{
		pdc->TextOut(timea+2,m_indextemp1,_T("4"));
		pdc->TextOut(timea+GetResult(14,m_printLevel),m_indextemp1,_T("8"));
		pdc->TextOut(timea-4+GetResult(28,m_printLevel),m_indextemp1,_T("12"));
	}
	m_index=DrawRect.left+GetResult(8,m_printLevel);
	pdc->TextOut(m_index,DrawRect.top+GetResult(162,m_printLevel),_T("脉搏  体温"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(182,m_printLevel),_T("180   42℃"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(232,m_printLevel),_T("160   41℃"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(282,m_printLevel),_T("140   40℃"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(331,m_printLevel),_T("120   39℃"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(382,m_printLevel),_T("100   38℃"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(432,m_printLevel),_T(" 80   37℃"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(482,m_printLevel),_T(" 60   36℃"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(532,m_printLevel),_T(" 40   35℃"));
	pdc->TextOut(m_index,DrawRect.top+GetResult(570,m_printLevel),_T(" 20   34℃"));
	g_CtwnDanManage.pdc = pdc;
	g_CtwnDanManage.twpointFrom.x=g_CtwnDanManage.twpointFrom.y =0;
	g_CtwnDanManage.mbpointFrom.x=g_CtwnDanManage.mbpointFrom.y=0;
	/************************************************************************/
	/*                           最下面的数据处理                           */
	/************************************************************************/
	ShowValueInfo();
	
	
	/************************************************************************/
	/*                  画出体温线				                            */
	/*                  画特殊内容                                          */
	/************************************************************************/
	ShowTiWenInfo();
	g_CtwnDanManage.bIsPrint = CTWDAN_INIT;
}
void CCLcTwDanCtrl::OnPrintLogInfo(CDC *pdc,CRect rcBounds)
{
	CFont	font;
	CPen	pen;
	float	m_printLevel=0.0;
	CPoint	m_point, m_point2;
	CString m_szPagInfo;
	CRect	tempRect;
	int		lengs  = 0;
	int		lengs2 = 0;
	int		sizeos = 0;
	if (NULL == pdc)
	{
		return;
	}
	m_printLevel = g_CtwnDanManage.SizeLeve;
	m_point.x = rcBounds.left +GetResult(50,m_printLevel);
	m_point.y = g_CtwnDanManage.NeiBounds.bottom +GetResult(150,m_printLevel);
	font.DeleteObject();
	font.CreateFont(-MulDiv(9,-pdc->GetDeviceCaps(LOGPIXELSY),70),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,_T("宋体"));
	pdc->SelectObject(&font);
	lengs = 80;
	lengs2 = 10;
	sizeos = GetResult(8,m_printLevel);
	m_point2 = m_point;
	tempRect.left = m_point.x;
	tempRect.right = tempRect.left+GetResult(lengs,m_printLevel);
	tempRect.top = m_point.y;
	tempRect.bottom = tempRect.top+80;
	
	m_point2.y +=GetResult(3,m_printLevel);
	pdc->DrawText("提示:",&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);

	m_point2.x = tempRect.right;
	ShowImageAGE(IDB_BITMAP2, m_point2,sizeos);
	tempRect.left = m_point2.x+GetResult(lengs2,m_printLevel);
	tempRect.right = tempRect.left+GetResult(lengs,m_printLevel);
	pdc->DrawText("口腔体温:",&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);
	

	m_point2.x = tempRect.right;
	ShowImageAGE(IDB_BITMAP1, m_point2,sizeos);
	tempRect.left = m_point2.x+GetResult(lengs2,m_printLevel);
	tempRect.right = tempRect.left+GetResult(lengs,m_printLevel);
	pdc->DrawText("腋窝体温:",&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);
	
	m_point2.x = tempRect.right;
	ShowImageAGE(IDB_BITMAP3, m_point2,sizeos);
	tempRect.left = m_point2.x+GetResult(lengs2,m_printLevel);
	tempRect.right = tempRect.left+GetResult(lengs,m_printLevel);
	pdc->DrawText("肛门体温:",&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);
	
	m_point2.x = tempRect.right;
	ShowImageAGE(IDB_BITMAP5, m_point2,sizeos);
	tempRect.left = m_point2.x+GetResult(lengs2,m_printLevel);
	tempRect.right = tempRect.left+GetResult(lengs,m_printLevel);
	pdc->DrawText("心率:",&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);
	
	m_point2.x = tempRect.right;
	ShowImageAGE(IDB_BITMAP6, m_point2,sizeos);
	tempRect.left = m_point2.x+GetResult(lengs2,m_printLevel);
	tempRect.right = tempRect.left+GetResult(lengs,m_printLevel);
	pdc->DrawText("脉率:",&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);
	
	m_point2.x = tempRect.right;
	tempRect.left = m_point2.x+GetResult(lengs2,m_printLevel);
	tempRect.right = tempRect.left+GetResult(lengs,m_printLevel);
	m_szPagInfo.Format("第%d周/共%d周", GetPageInfo(2), GetPageInfo(1));
	if (!m_szPagInfo.IsEmpty())
	{
		pdc->DrawText(m_szPagInfo,&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);
	}
	
	tempRect.top = tempRect.bottom;
	tempRect.bottom = tempRect.top+80;
	tempRect.left = m_point.x;
	tempRect.right = g_CtwnDanManage.NeiBounds.right;
	pdc->DrawText(PrintInfoVer,&tempRect,DT_CENTER|DT_TOP|DT_SINGLELINE);

//	pdc->TextOut(m_point.x,m_point.y,_T("入院日期:"));

}

void CCLcTwDanCtrl::OnSize(UINT nType, int cx, int cy) 
{
	SetInitialSize(m_ScreenSize.Width(),m_ScreenSize.Height());
	COleControl::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here
	
}

void CCLcTwDanCtrl::OnSetHospitalChanged() 
{
	SetModifiedFlag();
}

void CCLcTwDanCtrl::OnSetTitleNameChanged() 
{
	// TODO: Add notification handler code
	SetModifiedFlag();
}


void CCLcTwDanCtrl::OnSetTSChanged() 
{
	// TODO: Add notification handler code
	SetModifiedFlag();
}

void CCLcTwDanCtrl::OnSetMinuteChanged() 
{
	// TODO: Add notification handler code
	if (m_SetMinute<0 && m_SetMinute>60)
	{
		m_SetMinute = 30;
	}
	SetModifiedFlag();
}
void CCLcTwDanCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int rq=0,sj=0;
	BOOL bIsRefush = FALSE;
	CRect m_Crect;
	//int m_day1 =0, m_day2 =0;
	int nLastDay = 0;
	if (m_SetFS <CTWDAN_TIWEN_YEWO || m_SetFS > CTWDAN_DELETE)
	{
		MessageBox(_T("请选择要执行的方式!"),_T("提示"),MB_OK);
		return;
	}
	try{
	if (point.x>80 && point.x<668 && point.y>155 && point.y<=585)
	{
		rq=m_Fun.OrdinateToDate(point.x);			//日期
		nLastDay = m_AnlStr.GetZyDayLastDay(g_CtwnDanManage.stuLcTwDan[rq].m_ryDate);
		if (0 > nLastDay)
		{
			/*如果当前日期记录为空,则停止所有的操作*/
			return;
		}
		if (0 < g_SetAftDayDisable)
		{
			if ( g_SetAftDayDisable < nLastDay)
			{
				return ;
			}
		}
		m_Crect.top  = m_ScreenSize.top+135;
		m_Crect.bottom = m_ScreenSize.bottom-128;
		sj=m_Fun.OrdinateToTime(point.x);//-(rq*6);		//时间
		//记录体温方式
		switch(m_SetFS)
		{
		case CTWDAN_TIWEN_YEWO:
		case CTWDAN_TIWEN_KOUQIANG:
		case CTWDAN_TIWEN_GANGMEN:
			m_Tabmgr.SetTemperature(&g_CtwnDanManage.stuLcTwDan[rq],sj,m_SetFS,point.y);
			bIsRefush = TRUE;
			//GetTopPos(rq,sj,m_Crect,1);
			m_Crect.left = GetLeftPos(rq,sj,1);
			m_Crect.right  = GetRightPos(rq,sj,1);
			break;
		case CTWDAN_TIWEN_WULI:
			m_Tabmgr.SetTemperature(&g_CtwnDanManage.stuLcTwDan[rq],sj,m_SetFS,point.y);
			bIsRefush = TRUE;
			m_Crect.left = GetLeftPos(rq,sj,3);
			m_Crect.right  = GetRightPos(rq,sj,3);
			break;
		case CTWDAN_MAIBO_XINLV:
		case CTWDAN_MAIBO_MAILV:
			m_Tabmgr.SetPulse(&g_CtwnDanManage.stuLcTwDan[rq],sj,m_SetFS,point.y);
			bIsRefush = TRUE;
			m_Crect.left = GetLeftPos(rq,sj,2);
			m_Crect.right  = GetRightPos(rq,sj,2);
			break;
		case CTWDAN_TESHU:
			SetSpecial(rq,sj);
			bIsRefush = TRUE;
			m_Crect.top += 7;
			m_Crect.bottom = m_Crect.top + 250;
			m_Crect.left = g_CtwnDanManage.NeiBounds.left+rq*84+sj*14;
			m_Crect.right  = m_Crect.left+14;
			break;
		case CTWDAN_DELETE:
			if (g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].TemperatureValue <= ((short)point.y+1) && 
				g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].TemperatureValue >= ((short)point.y -1))
			{
				bIsRefush = TRUE;
				m_Crect.left = GetLeftPos(rq,sj,1);
				m_Crect.right  = GetRightPos(rq,sj,1);
				memset(&g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj], 0, sizeof(CTEMPERATURE));
			}
			else if (g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].PhysicsValue <= ((short)point.y+1) && 
					 g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].PhysicsValue >= ((short)point.y -1))
			{
				bIsRefush = TRUE;
				m_Crect.left = GetLeftPos(rq,sj,3);
				m_Crect.right  = GetRightPos(rq,sj,3);
				g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].PhysicsType =0;
				g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].PhysicsValue =0;
			}
			else if (g_CtwnDanManage.stuLcTwDan[rq].Pulse[sj].CpulseValue <= ((short)point.y+1) && 
					 g_CtwnDanManage.stuLcTwDan[rq].Pulse[sj].CpulseValue >= ((short)point.y -1))
			{
				bIsRefush = TRUE;
				m_Crect.left = GetLeftPos(rq,sj,2);
				m_Crect.right  = GetRightPos(rq,sj,2);
				memset(&g_CtwnDanManage.stuLcTwDan[rq].Pulse[sj], 0, sizeof(CPULSE));
			}
			break;
		default:break;
		}
	}
	SaveTeShuInStuct();
//	UpdateData(TRUE);
	if (TRUE == bIsRefush)
	{
		InvalidateRect(m_Crect,FALSE);
	}
	}
	catch(...)
	{
		MessageBox(_T("未知错误"),_T("提示"),MB_OK|MB_ICONERROR);
	}
	COleControl::OnLButtonDown(nFlags, point);
}

void CCLcTwDanCtrl::SaveTeShuInStuct()
{
	CPoint pt,m_nowpoint;
	CRect temrect;
	m_nowpoint = g_CtwnDanManage.SolidPoint;
	int m_inx = 0,m_iny = 0,m_level = 0;
	if (m_nowpoint.x <= 0 || m_nowpoint.y <=0)
	{
		return;
	}
	m_inx=m_nowpoint.x;
	m_iny=m_nowpoint.y;
	if (m_iny>554 && m_iny<704 && m_inx>81)
	{
		m_iny=m_Fun.GetPointPos(m_nowpoint.y,m_nowpoint.x);
		m_level=m_Fun.OrdinateToDate(m_nowpoint.x);//,4
		switch (m_iny)
		{
		case CTWD_HUXI_POINT:
			m_inx=m_Fun.OrdinateToTime(m_nowpoint.x);
			g_CtwnDanManage.InputChar.GetStr(g_CtwnDanManage.stuLcTwDan[m_level].SpecHuxi[m_inx],CTWNDAN_MAX_HUXI);
			//memcpy(g_CtwnDanManage.stuLcTwDan[m_level].m_huxi[m_inx],g_CtwnDanManage.strInput,CTWNDAN_MAX_HUXI);
			//g_CtwnDanManage.stuLcTwDan[m_level].m_huxi[m_inx][CTWNDAN_MAX_HUXI-1]=0;
			break;
		case CTWD_SHITTI_POINT:
			g_CtwnDanManage.InputChar.GetStr(g_CtwnDanManage.stuLcTwDan[m_level].m_shitti,CTWNDAN_MAX_TIME);
			//memcpy(g_CtwnDanManage.stuLcTwDan[m_level].m_shitti,g_CtwnDanManage.strInput,CTWNDAN_MAX_TIME);
			//g_CtwnDanManage.stuLcTwDan[m_level].m_shitti[CTWNDAN_MAX_TIME-1]=0;
			//strcpy(g_CtwnDanManage.stuLcTwDan[m_level].m_shitti,g_CtwnDanManage.strInput);
			break;
		case CTWD_INFUSE_POINT:
			g_CtwnDanManage.InputChar.GetStr(g_CtwnDanManage.stuLcTwDan[m_level].m_infuse,CTWNDAN_MAX_TIME);
			//memcpy(g_CtwnDanManage.stuLcTwDan[m_level].m_infuse,g_CtwnDanManage.strInput,CTWNDAN_MAX_TIME);
			//g_CtwnDanManage.stuLcTwDan[m_level].m_infuse[CTWNDAN_MAX_TIME-1]=0;
			break;
		case CTWD_URINES_POINT:
			g_CtwnDanManage.InputChar.GetStr(g_CtwnDanManage.stuLcTwDan[m_level].m_urines,CTWNDAN_MAX_TIME);
			//memcpy(g_CtwnDanManage.stuLcTwDan[m_level].m_urines,g_CtwnDanManage.strInput,CTWNDAN_MAX_TIME);
			//g_CtwnDanManage.stuLcTwDan[m_level].m_urines[CTWNDAN_MAX_TIME-1]=0;
			break;
		case CTWD_SPUTUM_POINT:
			g_CtwnDanManage.InputChar.GetStr(g_CtwnDanManage.stuLcTwDan[m_level].m_sputum,CTWNDAN_MAX_TIME);
			//memcpy(g_CtwnDanManage.stuLcTwDan[m_level].m_sputum,g_CtwnDanManage.strInput,CTWNDAN_MAX_TIME);
			//g_CtwnDanManage.stuLcTwDan[m_level].m_sputum[CTWNDAN_MAX_TIME-1]=0;
			break;
		case CTWD_BPRESS_POINT:
			g_CtwnDanManage.InputChar.GetStr(g_CtwnDanManage.stuLcTwDan[m_level].m_bpress,CTWNDAN_MAX_TESS);
			break;
		case CTWD_BPRESS2_POINT:
			g_CtwnDanManage.InputChar.GetStr(g_CtwnDanManage.stuLcTwDan[m_level].m_bpress2,CTWNDAN_MAX_TESS);
			break;
		case CTWD_WEIGHT_POINT:
			g_CtwnDanManage.InputChar.GetStr(g_CtwnDanManage.stuLcTwDan[m_level].m_weight,CTWNDAN_MAX_TIME);
			//memcpy(g_CtwnDanManage.stuLcTwDan[m_level].m_weight,g_CtwnDanManage.strInput,CTWNDAN_MAX_TIME);
			//g_CtwnDanManage.stuLcTwDan[m_level].m_weight[CTWNDAN_MAX_TIME-1]=0;
			break;
		}
		temrect.left=m_nowpoint.x;
		temrect.top=m_nowpoint.y;
		temrect.right=temrect.left+84;
		temrect.bottom=m_nowpoint.y+20;
		InvalidateRect(temrect,FALSE);
		g_CtwnDanManage.InputChar.Empty();
		g_CtwnDanManage.SolidPoint.x=-1;
		g_CtwnDanManage.SolidPoint.y=-1;
		SetCaretPos(g_CtwnDanManage.SolidPoint);
	}
	return ;
}
void CCLcTwDanCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CFont font;
	int length = CTWNDAN_MAX_TIME;
	font.CreatePointFont(90,_T("宋体"),NULL);
	CFont *pOldFont=dc.SelectObject(&font);
	TEXTMETRIC tm;
	CPoint pt,m_nowpoint;
	int OptType = 0;
	CRect temrect;
	static char  strRecv[2]={0};
	static char  nRecv=0;

	DLLPrintLog("Recv:[%x]-%c:%d:%d", nChar, nChar, nRepCnt, nFlags);
//	strcpy(strRecvTmp,"你");
	flg = true;
	m_nowpoint = g_CtwnDanManage.SolidPoint;
	if (m_nowpoint.x<0 || m_nowpoint.y<0)
	{
		DLLPrintLog("size error x->%d y->%d", m_nowpoint.x, m_nowpoint.y);
		return;
	}
	OptType = m_Fun.GetPointPos(m_nowpoint.y,m_nowpoint.x);
	DLLPrintLog("nChar:%X x->%d y->%d", nChar, m_nowpoint.x, m_nowpoint.y);
	if (0x80 < nChar)
	{
		DLLPrintLog("nChar:%X strRecv:%XL%X", nChar, strRecv[0], strRecv[1]);
		strRecv[nRecv] = nChar;
		nRecv == 0?nRecv = 1:nRecv=0;
		if (1 == nRecv)
		{
			return;
		}
		switch(OptType)
		{
		case CTWD_SHITTI_POINT:		//大便次数
		case CTWD_INFUSE_POINT:		//输入液量
		case CTWD_URINES_POINT:		//尿量
		case CTWD_SPUTUM_POINT:		//痰量
		case CTWD_BPRESS_POINT:		//高压、抵压
			break;
		case CTWD_WEIGHT_POINT:		//体重
			g_CtwnDanManage.InputChar.InsertStr(strRecv,2);
			goto PRINTTEXT;
		default:
			return ;
		}
		return ;
	}
	
	dc.GetTextMetrics(&tm);
	if(0x0d==nChar)
	{
		SaveTeShuInStuct();
		return ;
	}
	else if(0x08==nChar)
	{
		COLORREF clr=dc.SetTextColor(dc.GetBkColor());
		g_CtwnDanManage.InputChar.DelStr(0);
		dc.SetTextColor(clr);
		dc.TextOut(m_nowpoint.x,m_nowpoint.y,g_CtwnDanManage.InputChar.RetRes()+"    ");
	}
	else
	{
		if ('0' > nChar || nChar > '9')//!isdigit(nChar))
		{
			switch(OptType)
			{
			case CTWD_SHITTI_POINT:  //大便次数
				if ('/' == nChar||
					'E' == nChar)//
				{
					flg = false;
				}
				break;
			case CTWD_INFUSE_POINT:		//输入液量
				break;
			case CTWD_URINES_POINT:		//尿量
				break;
			case CTWD_SPUTUM_POINT:		//痰量
				break;
			case CTWD_WEIGHT_POINT:		//体重
				if ('.' == nChar)
				{
					flg = false;
				}
				break;
			case CTWD_BPRESS_POINT:		//高压、抵压
				if ('/' == nChar)
				{
					flg = false;
				}
				length = CTWNDAN_MAX_TESS;
				break;
			default:
				return ;
				break;
			}
		}
		else
		{
			flg = false;
		}
		switch(OptType)
		{
		case CTWD_HUXI_POINT:
			length = CTWNDAN_MAX_HUXI;
			break;
		case CTWD_SHITTI_POINT:
		case CTWD_INFUSE_POINT:
		case CTWD_URINES_POINT:
		case CTWD_SPUTUM_POINT:
		case CTWD_WEIGHT_POINT:
			break;
		case CTWD_BPRESS_POINT:
		case CTWD_BPRESS2_POINT:
			DLLPrintLog("add length %d:%d", length,CTWNDAN_MAX_TESS);
			length = CTWNDAN_MAX_TESS;
			break;
		default:
			return ;
			break;
		}
		if (false == flg && g_CtwnDanManage.InputChar.GetLen()<length-1)
		{
			g_CtwnDanManage.InputChar.InsertStr((char*)&nChar,1);
		}
		else
		{
			return;
		}
	}
PRINTTEXT:	
	CSize sz=dc.GetTextExtent(g_CtwnDanManage.InputChar.RetRes());
	pt.x=m_nowpoint.x+sz.cx;
	pt.y=m_nowpoint.y;

	SetCaretPos(pt);
	dc.TextOut(m_nowpoint.x,m_nowpoint.y,g_CtwnDanManage.InputChar.RetRes());
	dc.SelectObject(pOldFont);
	dc.DeleteDC();
	COleControl::OnChar(nChar, nRepCnt, nFlags);
}

void CCLcTwDanCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
//	if (0==strcmp("",GetZyDay(m_rydate[rq],0,5))){return;}
	CClientDC dc(this);
	int rq=0,sj=0;
	BOOL bIsRefush = FALSE;
	CRect m_Crect;
	int m_day1 =0, m_day2 = 0;
	TEXTMETRIC tm;
	if (point.x>g_CtwnDanManage.NeiBounds.left && point.x<g_CtwnDanManage.NeiBounds.right &&
		point.y>g_CtwnDanManage.NeiBounds.bottom && point.y <g_CtwnDanManage.Bounds.bottom)
	{
		rq=m_Fun.OrdinateToDate(point.x);			//日期
		if (0 == *g_CtwnDanManage.stuLcTwDan[rq].m_ryDate)
		{
			return;
		}
		
		if (0 != m_SetAftDayDisable)
		{
			m_day1 = GetBeginDay(g_CtwnDanManage.stuLcTwDan[rq].m_ryDate);
			m_day2 = GetCurrentDay() - m_SetAftDayDisable;
			if ( m_day1 < m_day2)
			{
				return ;
			}
		}
		dc.GetTextMetrics(&tm);
		CreateSolidCaret(tm.tmAveCharWidth/2,tm.tmHeight-3);
		ShowCaret();

		//flg = true;
		//point_flg = true;
		if (point.y<=600)
		{
			g_CtwnDanManage.SolidPoint.x=m_Fun.GetCaretPosHx_x(point.x);
			g_CtwnDanManage.SolidPoint.y=m_Fun.GetCaretPosHx_y(point.x);
			SetCaretPos(g_CtwnDanManage.SolidPoint);
		}
		else if ((point.y>604 && point.y<680) || (point.y>700 && point.y<720))
		{
			g_CtwnDanManage.SolidPoint.x=m_Fun.GetCaretPos_x(point.x);
			g_CtwnDanManage.SolidPoint.y=m_Fun.GetCaretPos_y(point.y);
			SetCaretPos(g_CtwnDanManage.SolidPoint);
		}
		else
		{
			g_CtwnDanManage.SolidPoint.x=m_Fun.GetCaretPosPress_x(point.x);
			g_CtwnDanManage.SolidPoint.y=m_Fun.GetCaretPos_y(point.y);
			SetCaretPos(g_CtwnDanManage.SolidPoint);
		}
	}
/*	if(atoi(m_zyday[rq])<=atoi(GetZyDay(m_gRyDate,0,6))-m_changeDay){return;}
	if (point.x>80 && point.y>586)
	{
		m_strLine.Empty();
		CRect temrect;
		temrect.top=m_nowpoint.x;
		temrect.right=m_nowpoint.y;
		temrect.left=0;
		temrect.bottom=m_nowpoint.y+20;
		InvalidateRect(temrect,FALSE);
		CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight-3);
		ShowCaret();
		m_Oldpoint=m_nowpoint;
	}	*/
	COleControl::OnLButtonDblClk(nFlags, point);
}

void CCLcTwDanCtrl::OnSetPatientInfoChanged() 
{
	// TODO: Add notification handler code
	SetModifiedFlag();
}

void CCLcTwDanCtrl::OnSetPatientRyDateChanged() 
{
	pCTWLCDANINFO stuLcTwDan=NULL;
//	g_CtwnDanManage.CTwDanTime = CheckDate(m_SetPatientRyDate);
	
	CTime tis=CheckDate(m_SetPatientRyDate);
	g_CtwnDanManage.CTwDanTime = CTime::CTime(tis.GetYear(),tis.GetMonth(),tis.GetDay(),0, 0,0);
	if (g_CtwnDanManage.CTwDanTime == 0)
	{
		return;
	}

	CtwDanMemSet();
	for (int i=0;i<PAGE_SUM;i++)
	{
		stuLcTwDan = &g_CtwnDanManage.stuLcTwDan[i];
		memcpy(stuLcTwDan->m_ryDate,GetZyDayFromInt(i,1),CTWNDAN_MAX_DATE);
		memcpy(stuLcTwDan->m_zyday,GetZyDayFromInt(i,2),CTWNDAN_MAX_DAY);
		if (0 == *stuLcTwDan->m_ryDate)
		{
			break;
		}
	}
	g_CtwnDanManage.CurrentBeginDay =CTWDAN_BEGIN_DAYS;
//	g_CtwnDanManage.CurrentEndDay = g_CtwnDanManage.CurrentBeginDay;
	SetModifiedFlag();
}

void CCLcTwDanCtrl::OnSetFSChanged() 
{
	SetModifiedFlag();
}

int CCLcTwDanCtrl::GetResult(int m_value, double m_level)
{
	if (1.0 == m_level)
	{
		return m_value;
	}
	return (int)(m_value*m_level);
}



void CCLcTwDanCtrl::PrintInfo() 
{
	// TODO: Add your dispatch handler code here
	CDC printDC;
	CDC m_memDC;
	CRect rect;

	CPrintDialog printDlg(FALSE);
	DOCINFO docInfo;
	CBitmap bitmap;
	if(printDlg.DoModal()==IDOK)
	{
		HDC hDC;
		hDC=printDlg.GetPrinterDC();
		if(!printDC.Attach(hDC))
		{
			return;
		}
	}
	else
	{
		printDC.Detach();
		return;
	}
	memset(&docInfo,0,sizeof(docInfo));
	docInfo.cbSize=sizeof(DOCINFO);
//	strcpy(docInfo.lpszDocName, "体温单");
	if(printDC.StartDoc(&docInfo)<=0)
	{
#ifdef _DEBUG
		AfxMessageBox(_T("Start Doc Failed"));
#endif
		printDC.Detach();
		return;
	}
	rect=CRect(0,0,printDC.GetDeviceCaps(HORZRES),printDC.GetDeviceCaps(VERTRES));


	printDC.StartPage();
	//memDC.SetMapMode(dc.GetMapMode());
	printDC.SetStretchBltMode(HALFTONE);
	printDC.SetMapMode(MM_TEXT);
	OnPrintInfo(&printDC,rect);
	printDC.SetTextColor(RGB(0,0,0));
	OnPrintLogInfo(&printDC, rect);
	//g_CtwnDanManage.NeiBounds.
	printDC.EndPage();
	printDC.EndDoc();
	printDC.Detach();
}


void CCLcTwDanCtrl::CtwDanMemSet()
{
	CTWLCDANINFO *pstuLcTwDan=NULL;
	int i=0, m_begin=0, m_end=PAGE_SUM;
	for (i=m_begin;i<m_end;i++)
	{
		pstuLcTwDan = &g_CtwnDanManage.stuLcTwDan[i];
		memset(pstuLcTwDan,0,sizeof(CTWLCDANINFO_T));
	}
}

int CCLcTwDanCtrl::GetCurrentDay()
{
	CTime tis=CTime::GetCurrentTime();
	return GetBeginDay(tis.Format("%Y-%m-%d").GetBuffer(0));
}

CString CCLcTwDanCtrl::GetZyDayFromInt(int tt, int zt)
{
	return m_AnlStr.GetZyDayFromInt(tt,zt);
}



void CCLcTwDanCtrl::ShowValueInfo()
{
	int index =0,pp=0,leftvalue=0;
	CFont font,minfont;
	CDC *pdc = NULL;
	CFont *pOldFont=NULL;
	CString m_strLine;
	CRect tempRect(0,0,84,20);
	CTWLCDANINFO_T *pstuLcTwDan=NULL;
	CRect *rcBounds= NULL;
	float m_printLevel = g_CtwnDanManage.SizeLeve;
	pdc = g_CtwnDanManage.pdc;
	if (NULL == pdc)
	{
		return;
	}
	rcBounds = &g_CtwnDanManage.Bounds;
	font.CreatePointFont((int)(100*m_printLevel),_T("宋体"),NULL);
	minfont.DeleteObject();
	minfont.CreatePointFont(GetResult(75,m_printLevel),_T("宋体"),NULL);
	//	leftvalue = rcBounds->left+GetResult(84,m_printLevel);
	leftvalue = g_CtwnDanManage.NeiBounds.left;
	for (index=0;index<PAGE_SUM;index++)
	{
		pOldFont=pdc->SelectObject(&font);
		pstuLcTwDan = &g_CtwnDanManage.stuLcTwDan[index];
/*		pstuLcTwDan->m_shittime=pstuLcTwDan->m_shittime.Left(2);
		pstuLcTwDan->m_infuse=pstuLcTwDan->m_infuse.Left(4);
		pstuLcTwDan->m_sputum=pstuLcTwDan->m_sputum.Left(4);
		pstuLcTwDan->m_bpress=pstuLcTwDan->m_bpress.Left(6);
		pstuLcTwDan->m_weight=pstuLcTwDan->m_weight.Left(4);
*/
		tempRect.left =leftvalue+GetResult(4,m_printLevel);
		tempRect.left += GetResult(84,m_printLevel)*index;
		tempRect.top=rcBounds->top+GetResult(85,m_printLevel);
		if (0 != pstuLcTwDan->m_ryDate[0])
		{
			pdc->TextOut(tempRect.left,tempRect.top,GetSpace(pstuLcTwDan->m_ryDate));
		}
		
		tempRect.top=rcBounds->top+GetResult(105,m_printLevel);
		if (0 != pstuLcTwDan->m_zyday[0])
		{
			pdc->TextOut(tempRect.left,tempRect.top,GetSpace(pstuLcTwDan->m_zyday));
		}
		tempRect.top=rcBounds->top+GetResult(125,m_printLevel);
		pdc->TextOut(tempRect.left,tempRect.top,GetSpace(GetSsFmDay(pstuLcTwDan->m_ssday,pstuLcTwDan->m_fmday)));
		tempRect.top=rcBounds->top+GetResult(603,m_printLevel);
		if (0 != pstuLcTwDan->m_shitti[0])
		{
			pdc->TextOut(tempRect.left,tempRect.top,GetSpace(pstuLcTwDan->m_shitti));
		}
		tempRect.top=rcBounds->top+GetResult(623,m_printLevel);
		if (0 != pstuLcTwDan->m_infuse[0])
		{
			pdc->TextOut(tempRect.left,tempRect.top,GetSpace(pstuLcTwDan->m_infuse));
		}
		tempRect.top=rcBounds->top+GetResult(643,m_printLevel);
		if (0 != pstuLcTwDan->m_urines[0])
		{
			pdc->TextOut(tempRect.left,tempRect.top,GetSpace(pstuLcTwDan->m_urines));
		}
		tempRect.top=rcBounds->top+GetResult(663,m_printLevel);
		if (0 != pstuLcTwDan->m_sputum[0])
		{
			pdc->TextOut(tempRect.left,tempRect.top,GetSpace(pstuLcTwDan->m_sputum));
		}
		tempRect.top=rcBounds->top+GetResult(703,m_printLevel);
		if (0 != pstuLcTwDan->m_weight[0])
		{
			pdc->TextOut(tempRect.left,tempRect.top,GetSpace(pstuLcTwDan->m_weight));
		}
		
//		tempRect.left+=GetResult(84,m_printLevel);
		
		pdc->SelectObject(&minfont);
		/**add press 2 info begin ***/
		tempRect.top=rcBounds->top+GetResult(684,m_printLevel);
		if (0 != pstuLcTwDan->m_bpress[0])
		{
			pdc->TextOut(tempRect.left,tempRect.top,GetSpace2(pstuLcTwDan->m_bpress));
		}
		if (0 != pstuLcTwDan->m_bpress2[0])
		{
			pdc->TextOut(tempRect.left+GetResult(43,m_printLevel),tempRect.top,GetSpace2(pstuLcTwDan->m_bpress2));
		}
		/**add press 2 info end ***/
		if (1.00 == m_printLevel)
		{
			tempRect.top=rcBounds->top+GetResult(586,m_printLevel);
		}
		else
		{
			tempRect.top=rcBounds->top+GetResult(587,m_printLevel);
		}
		tempRect.left -=GetResult(1,m_printLevel);
//		tempRect.left = rcBounds->left+GetResult(84,m_printLevel);
		for (pp=0;pp<CTWNDAN_MAX_COUNT;pp++)
		{
			if (0 == *pstuLcTwDan->SpecHuxi[pp])
			{
				continue;	
			}
			pdc->TextOut(tempRect.left+GetResult(14,m_printLevel)*pp,tempRect.top,pstuLcTwDan->SpecHuxi[pp]);
		}
	}
}

void CCLcTwDanCtrl::ShowTiWenInfo()
{
	int indexrq = 0,indexsj = 0,indextime = 0;
	CTWLCDANINFO * pstLcTwInfo = NULL;
	char m_Type =0;
	CPULSE TmpValue;
	int IDB_NULL = 0;
	CDC *pdc = NULL;
	CRect rcBounds;
	float m_printLevel = g_CtwnDanManage.SizeLeve;
	pdc = g_CtwnDanManage.pdc;
	if (NULL == pdc)
	{
		return;
	}
	rcBounds = g_CtwnDanManage.Bounds;
	for (indexrq=0;indexrq<PAGE_SUM;indexrq++)
	{
		pstLcTwInfo = g_CtwnDanManage.stuLcTwDan +indexrq;
		if (NULL == pstLcTwInfo || 0== *pstLcTwInfo->m_ryDate)
		{
			break;
		}
		for (indexsj=0; indexsj<CTWNDAN_MAX_COUNT; indexsj++)
		{
			memset(&TmpValue,0,sizeof(CPULSE));
			m_Type = pstLcTwInfo->Temperature[indexsj].Type;
			TmpValue.Time = pstLcTwInfo->Temperature[indexsj].Time;
			TmpValue.CpulseValue = pstLcTwInfo->Temperature[indexsj].TemperatureValue;
			switch(m_Type)
			{
			case CTWDAN_TIWEN_YEWO:
				TmpValue.Type = m_Type;
				IDB_NULL = IDB_BITMAP1;
				break;
			case CTWDAN_TIWEN_KOUQIANG:
				TmpValue.Type = m_Type;
				IDB_NULL = IDB_BITMAP2;
				break;
			case CTWDAN_TIWEN_GANGMEN:
				TmpValue.Type = m_Type;
				IDB_NULL = IDB_BITMAP3;
				break;
			default:break;
			}
			ShowImage(IDB_NULL,&TmpValue, indexrq, m_printLevel,1);
			if (CTWDAN_TIWEN_WULI == pstLcTwInfo->Temperature[indexsj].PhysicsType &&
				pstLcTwInfo->Temperature[indexsj].PhysicsValue > TmpValue.CpulseValue)
			{
				g_CtwnDanManage.jwpointFrom.x = rcBounds.left+GetResult(84,m_printLevel)*(indexrq+1)+14*GetResult(indexsj,m_printLevel);
				g_CtwnDanManage.jwpointFrom.y = rcBounds.top+GetResult(TmpValue.CpulseValue-5,m_printLevel);
				TmpValue.CpulseValue = pstLcTwInfo->Temperature[indexsj].PhysicsValue;
				ShowImage(IDB_BITMAP4,&TmpValue, indexrq, m_printLevel,3);
			}
			else
			{
				pstLcTwInfo->Temperature[indexsj].PhysicsType  =0;
				pstLcTwInfo->Temperature[indexsj].PhysicsValue =0;
			}
			memset(&TmpValue,0,sizeof(CPULSE));
			m_Type = pstLcTwInfo->Pulse[indexsj].Type;
			TmpValue.Time = pstLcTwInfo->Pulse[indexsj].Time;
			TmpValue.CpulseValue = pstLcTwInfo->Pulse[indexsj].CpulseValue;
			switch(m_Type)
			{
			case CTWDAN_MAIBO_XINLV:
				TmpValue.Type = m_Type;
				IDB_NULL = IDB_BITMAP5;
				break;
			case CTWDAN_MAIBO_MAILV:
				TmpValue.Type = m_Type;
				IDB_NULL = IDB_BITMAP6;
				break;
			default:break;
			}

			ShowImage(IDB_NULL,&TmpValue, indexrq, m_printLevel,2);

			/******************
			显示特殊的内容
			******************/
			pdc->SetTextColor(RGB(255,0,0));
			for (indextime = 0; indextime<CTWNDAN_MAX_TESHUNUM; indextime++)
			{
				ShowTeshu(&pstLcTwInfo->Special[indexsj][indextime], indexrq, indexsj,indextime);
			}
		}
	}
}
void CCLcTwDanCtrl::ShowVerticalFont(CPoint point,CString m_str,float m_printLevel, int types)
{
	CFont font,*oldfont;
	int height=0,indexrq = 0,indexsj = 0;
	CDC *pdc = NULL;
	CRect rcBounds, temp;
	pdc = g_CtwnDanManage.pdc;
	if (NULL == pdc)
	{
		return;
	}
	rcBounds.left = point.x;
	rcBounds.right = rcBounds.left+GetResult(10,m_printLevel);
	if (1 == types)
	{
		rcBounds.top = point.y-GetResult(8,m_printLevel);
//		rcBounds.bottom = point.y+GetResult(5,m_printLevel);;  // 限定宽度
	}
	if (2 == types)
	{
		rcBounds.top = point.y;
//		rcBounds.bottom = point.y+GetResult(40,m_printLevel);  // 限定宽度
	}
	font.DeleteObject();
	font.CreateFont(-MulDiv(8,-pdc->GetDeviceCaps(LOGPIXELSY),72),0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,VARIABLE_PITCH|FF_SWISS,_T("宋体"));
	oldfont=pdc->SelectObject(&font);
	temp = rcBounds;
	height = pdc->DrawText(m_str,temp,DT_CENTER | DT_WORDBREAK | DT_CALCRECT | DT_EDITCONTROL); // 获得文本高度
//	rcBounds.DeflateRect(0,(rcBounds.Height() - height) / 2); // 改变rect
	rcBounds.bottom = rcBounds.top+height;
	pdc->DrawText(m_str,rcBounds, DT_CENTER | DT_EDITCONTROL | DT_WORDBREAK);
	font.DeleteObject();
	oldfont->DeleteObject();
}

void CCLcTwDanCtrl::ShowTWDLine(CPoint point, float m_printLevel,int types)
{
	CDC *pdc = NULL;
	CRect *rcBounds = &g_CtwnDanManage.Bounds;
	int index =0;
	pdc = g_CtwnDanManage.pdc;
	CPoint pointTmp=point;
	pointTmp.x+=GetResult(4,m_printLevel);
	pointTmp.y+=GetResult(4,m_printLevel);
	if (1 == types)
	{
		pdc->SelectObject(&g_CtwnDanManage.penRed);
		if (0 == g_CtwnDanManage.twpointFrom.x)
		{
			g_CtwnDanManage.twpointFrom = pointTmp;
		}
		else
		{
			pdc->MoveTo(g_CtwnDanManage.twpointFrom);
			pdc->LineTo(pointTmp);
			g_CtwnDanManage.twpointFrom = pointTmp;
		}
	}
	else if (2 == types)
	{
		pdc->SelectObject(&g_CtwnDanManage.penBule);
		if (0 == g_CtwnDanManage.mbpointFrom.x)
		{
			g_CtwnDanManage.mbpointFrom = pointTmp;
		}
		else
		{
			pdc->MoveTo(g_CtwnDanManage.mbpointFrom);
			pdc->LineTo(pointTmp);
			g_CtwnDanManage.mbpointFrom = pointTmp;
		}
	}
	else if (3 == types)
	{
		g_CtwnDanManage.jwpointFrom.x+=GetResult(4,m_printLevel);
		g_CtwnDanManage.jwpointFrom.y+=GetResult(4,m_printLevel);
		pdc->SelectObject(&g_CtwnDanManage.penDot);
		pdc->MoveTo(g_CtwnDanManage.jwpointFrom);
		pdc->LineTo(pointTmp);

	}
}
void CCLcTwDanCtrl::ShowImageAGEEx(int IDB_NULL,CPoint point,int m_whit)
{
	CDC *pdc = NULL;
	CPen penBule;
	CRect m_Rect;
	CBrush m_buras;
	CPoint m_LeftTopP,m_LeftBtnP,m_RightTopP,m_RightBtnP;
	
	m_LeftTopP=m_LeftBtnP=m_RightTopP=m_RightBtnP = point;
	m_RightTopP.x += m_whit;
	m_RightBtnP.x += m_whit;
	m_LeftBtnP.y  += m_whit;
	m_RightBtnP.y += m_whit;
	pdc = g_CtwnDanManage.pdc;
	
	m_Rect=CRect::CRect(point.x,point.y,point.x+m_whit,point.y+m_whit);
	m_buras.DeleteObject();
	m_buras.CreateSolidBrush(RGB(255,255,255));
	
	switch (IDB_NULL)
	{
	case IDB_BITMAP1:
		
		penBule.DeleteObject();
		penBule.CreatePen(PS_SOLID,GetResult(2,g_CtwnDanManage.m_printLevel),RGB(0,0,255));
		pdc->SelectObject(&penBule);
		pdc->MoveTo(m_LeftTopP);
		pdc->LineTo(m_RightBtnP);
		pdc->MoveTo(m_RightTopP);
		pdc->LineTo(m_LeftBtnP);
		break;
	case IDB_BITMAP2:
		m_buras.DeleteObject();
		m_buras.CreateSolidBrush(RGB(0,0,0));
	case IDB_BITMAP3:
		penBule.DeleteObject();
		penBule.CreatePen(PS_SOLID,GetResult(2,g_CtwnDanManage.m_printLevel),RGB(0,0,0));
		pdc->SelectObject(&m_buras);
		pdc->SelectObject(&penBule);
		pdc->Ellipse(m_Rect);
		break;
	case IDB_BITMAP4:
		m_buras.DeleteObject();
		m_buras.CreateSolidBrush(RGB(0,0,0));
	case IDB_BITMAP5:
		penBule.DeleteObject();
		penBule.CreatePen(PS_SOLID,GetResult(2,g_CtwnDanManage.m_printLevel),RGB(255,0,0));
		pdc->SelectObject(&m_buras);
		pdc->SelectObject(&penBule);
		pdc->Ellipse(m_Rect);
		break;
	case IDB_BITMAP6:
		m_buras.DeleteObject();
		m_buras.CreateSolidBrush(RGB(255,0,0));
		penBule.DeleteObject();
		penBule.CreatePen(PS_SOLID,GetResult(2,g_CtwnDanManage.m_printLevel),RGB(0,0,0));
		pdc->SelectObject(&m_buras);
		pdc->SelectObject(&penBule);
		pdc->Ellipse(m_Rect);
		break;
	default:
		break;
	}
}
void CCLcTwDanCtrl::ShowImageAGE(int IDB_NULL,CPoint point,int m_whit)
{
	ShowImageAGEEx(IDB_NULL, point,m_whit);
	/*
	CBitmap bitmap;
	BITMAP bmp;
	CDC dcCompatible;
	CDC *pdc = NULL;
	pdc = g_CtwnDanManage.pdc;
	bitmap.LoadBitmap(IDB_NULL);
	bitmap.GetBitmap(&bmp);
	dcCompatible.CreateCompatibleDC(pdc);
	dcCompatible.SelectObject(&bitmap);
	dcCompatible.SetMapMode(pdc->GetMapMode());
	pdc->StretchBlt(point.x,point.y,m_whit,m_whit,&dcCompatible,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	bitmap.DeleteObject();*/
}

void CCLcTwDanCtrl::ShowImage(int IDB_NULL,pCPULSE pTmpValue,int Date,float m_printLevel,int types)
{
	CPoint point;
	CDC *pdc = NULL;
	CRect rcBounds;
	pdc = g_CtwnDanManage.pdc;
	if (NULL == pdc || NULL == pTmpValue || 0 == pTmpValue->Type || 0 ==IDB_NULL)
	{
		return ;
	}
	rcBounds = g_CtwnDanManage.Bounds;
	point.x = rcBounds.left+GetResult(84,m_printLevel)*(Date+1)+14*GetResult(pTmpValue->Time,m_printLevel);
	point.y  = rcBounds.top+GetResult(pTmpValue->CpulseValue-5,m_printLevel);
	if (point.y<rcBounds.top)
	{ 
		return;
	}
	
	ShowTWDLine(point,m_printLevel,types);
	if (1== types && g_CtwnDanManage.NeiBounds.bottom <= point.y+GetResult(5,m_printLevel))
	{
		pdc->SetTextColor(RGB(0,0,255));
		ShowVerticalFont(point,_T("不升"),m_printLevel,1);
		g_CtwnDanManage.stuLcTwDan[Date].Temperature[pTmpValue->Time].PhysicsType =0;
		g_CtwnDanManage.stuLcTwDan[Date].Temperature[pTmpValue->Time].PhysicsValue =0;
	}
	else
	{
		ShowImageAGE(IDB_NULL, point, GetResult(8,m_printLevel));
	}
}

void CCLcTwDanCtrl::ShowTeshu(pSPECIAL	pSpecial, int indexrq, int indexsj,int indextime)
{
	CPoint m_point;
	int m_index =0;
	CString  szValue;
	int		 NowDateRq = 0,NowDataSj = 0;
	if (NULL == pSpecial)
	{
		MessageBox("Special info is NULL program error!");
		return ;
	}
	if(0 == pSpecial->index)
	{
		return ;
	}

	m_point.x = g_CtwnDanManage.NeiBounds.left+ GetResult(3,g_CtwnDanManage.SizeLeve);// +GetResult(pSpecial->Date-1,g_CtwnDanManage.SizeLeve)*84+GetResult(pSpecial->Time,g_CtwnDanManage.SizeLeve)*14;
	m_point.y = g_CtwnDanManage.NeiBounds.top;

	NowDateRq = pSpecial->m_rq - g_CtwnDanManage.CurrentBeginDay;
	NowDataSj = pSpecial->shij;
	if ((pSpecial->shij == 5) &&((pSpecial->Times ==0)|| pSpecial->Times ==1)&& (NowDateRq>=1))
	{
		if (NowDateRq==1)
		{
			NowDataSj = 0;
		}
		else
		{
			NowDateRq--;
		}
	}

	if (0 != pSpecial->m_rq && NowDateRq > 0 )
	{
		m_point.x += GetResult(84,g_CtwnDanManage.SizeLeve)*(NowDateRq-1);
		if (0 != pSpecial->index || 5 != NowDataSj)
		{
			m_point.x += GetResult(14,g_CtwnDanManage.SizeLeve)*NowDataSj;
		}
		m_point.y += GetResult(7+110*indextime,g_CtwnDanManage.SizeLeve);

		szValue.Format(_T("%s%s%s%s%s"),GetIntToTS(pSpecial->index),GetTeShu(pSpecial->Times),"时",GetTeShu(pSpecial->Second),"分");
		ShowVerticalFont(m_point,szValue,g_CtwnDanManage.SizeLeve,2);
	}
}

CString CCLcTwDanCtrl::GetSpace(CString m_str)
{
	CString m_strTmp=_T("");
	char strbuffer[10]={0};
	int nLength= m_str.GetLength();
	switch (nLength)
	{
	case 1:
		strcat(strbuffer,"     ");
		break;
	case 2:
	case 3:
	case 4:
		strcat(strbuffer,"    ");
		break;
	case 5:
		strcat(strbuffer,"   ");
		break;
	case 6:
	case 7:
	case 8:
		strcat(strbuffer,"   ");
		break;
	default:
		strcat(strbuffer,"");
		break;
	}
	m_strTmp.Format(_T("%s%s"),strbuffer,m_str);
	return m_strTmp;
}

CString CCLcTwDanCtrl::GetSpace2(CString m_str)
{
	CString m_strTmp=_T("");
	m_strTmp.Format(_T("%7s"),m_str);
	return m_strTmp;
}

void * CCLcTwDanCtrl::GetSpecialInfo(int inrq,int insj,int intm)
{
	static pCTWLCDANINFO m_CtwDanInfo = NULL;
	static int previnrq = 0;
	pSPECIAL	pSpecial = NULL;
	int nCtwnTotal = g_CtwnDanManage.m_ptrArray.GetSize();
	if (inrq>nCtwnTotal)
	{
		MessageBox("Get Special info from array,but Date is Error ");
		goto EXIT_OK;
	}
	if (NULL == m_CtwDanInfo || previnrq != inrq)
	{
		m_CtwDanInfo = (pCTWLCDANINFO)g_CtwnDanManage.m_ptrArray.GetAt(inrq);
		previnrq = inrq;
	}
	if (NULL == m_CtwDanInfo)
	{
		MessageBox("Get Special info from array,but info is NULL, program error");
		goto EXIT_OK;
	}
	pSpecial = &m_CtwDanInfo->Special[insj][intm];
EXIT_OK:
	return pSpecial;
}
void * CCLcTwDanCtrl::GetSpecialTypeInfo(int m_Type,int *inrq,int *insj,int *intm)
{
	// TODO: Add notification handler code
	pSPECIAL	pSpecial = NULL;
	static pCTWLCDANINFO m_CtwDanInfo = NULL;
	int m_indexrq = 0,m_indexsj = 0,m_indextm = 0;
	int nCtwnTotal = g_CtwnDanManage.m_ptrArray.GetSize();
	for (m_indexrq =(NULL != inrq?*inrq:0); m_indexrq <nCtwnTotal ; m_indexrq++)
	{
		
		m_CtwDanInfo = (pCTWLCDANINFO)g_CtwnDanManage.m_ptrArray.GetAt(m_indexrq);
		if (NULL == m_CtwDanInfo)
		{
			MessageBox("Get Special info from array,but info is NULL, program error");
			break;
		}
		for (m_indexsj = (NULL != insj?*insj:0); m_indexsj < CTWNDAN_MAX_COUNT; m_indexsj++)
		{
			
			for (m_indextm = (NULL != intm?*intm:0); m_indextm < CTWNDAN_MAX_TESHUNUM; m_indextm++)
			{
				pSpecial = &m_CtwDanInfo->Special[m_indexsj][m_indextm];
				if (NULL == pSpecial)
				{
					goto EXIT_INFO;
				}
				if (m_Type == pSpecial->index)
				{
					goto EXIT_INFO;
				}
			}
		}
	}
	pSpecial = NULL;
EXIT_INFO:
	if (NULL != inrq)
	{
		*inrq = m_indexrq;
	}
	if (NULL != insj)
	{
		*insj = m_indexsj;
	}
	if (NULL != intm)
	{
		*intm = m_indextm;
	}
	return pSpecial;
}
void * CCLcTwDanCtrl::GetSpaceCtrlInfo(int m_Teshu)
{
	int m_index,m_ctrlcount = sizeof(g_Special_Ctrl_Info)/sizeof(SPACIAL_CTRL_INFO);
	pSPACIAL_CTRL_INFO pSpacial_CtrlInfo = NULL;
	
	for (m_index=0;m_index<m_ctrlcount;m_index++)
	{
		pSpacial_CtrlInfo = &g_Special_Ctrl_Info[m_index];
		if (m_Teshu == pSpacial_CtrlInfo->index)
		{
			break;
		}
		pSpacial_CtrlInfo = NULL;
	}
	return pSpacial_CtrlInfo;

}

int CCLcTwDanCtrl::CheckSpecialType(int type)
{
	pSPECIAL	  pSpecial = NULL;
	pSPACIAL_CTRL_INFO pSpacial_CtrlInfo = (pSPACIAL_CTRL_INFO)GetSpaceCtrlInfo(type);
	
	if (NULL == pSpacial_CtrlInfo)
	{
		return -1;
	}
	if (0 == pSpacial_CtrlInfo->bLjudge)
	{
		return 0;
	}
	pSpecial = (pSPECIAL)GetSpecialTypeInfo(type);
	if (NULL == pSpecial )
	{
		return 0;
	}	
	return 1;
} 
void CCLcTwDanCtrl::SetSpecial(int Date,int Time)
{
	pSPECIAL	pSpecialSrc = NULL,pSpecialDst = NULL;
	int nRetFlg = 0;
	CRect m_Crect = g_CtwnDanManage.NeiBounds;
	if (0 != CheckSpecialType(m_SetTS))
	{
		return;
	}
	m_Tabmgr.InitSpecial(m_SetPatientRyDate.GetBuffer(0),g_CtwnDanManage.CurrentBeginDay );
	nRetFlg = m_Tabmgr.SetSpecial(&g_CtwnDanManage,Date,Time, m_SetTS, m_SetMinute, m_Crect);
	if (0 >= nRetFlg )
	{
		pSpecialSrc = &g_CtwnDanManage.stuLcTwDan[Date].Special[Time][nRetFlg];
		pSpecialDst = (pSPECIAL)GetSpecialInfo(g_CtwnDanManage.CurrentBeginDay+Date+1,Time,nRetFlg);

		if (NULL != pSpecialDst && NULL != pSpecialSrc)
		{
			memcpy(pSpecialDst,pSpecialSrc,sizeof(SPECIAL));
		}
		SetZyDaySsDayLcDay(m_SetTS);
		InvalidateRect(m_Crect,FALSE);
	}
} 

void CCLcTwDanCtrl::SetZyDaySsDayLcDay(int m_Type)
{
	int m_index = 0,m_days=0;
	pCTWLCDANINFO pstuLcTwDan=NULL;
	pSPECIAL pSpecial = NULL;
	CRect m_temp = g_CtwnDanManage.NeiBounds;
	float m_printLevel = g_CtwnDanManage.SizeLeve;
	for (m_index =0;m_index<PAGE_SUM;m_index++)
	{
		pstuLcTwDan = &g_CtwnDanManage.stuLcTwDan[m_index];
		if (CLCTWDAN_RY == m_Type)
		{
			memcpy(pstuLcTwDan->m_zyday,GetZyDayFromInt(g_CtwnDanManage.CurrentBeginDay+m_index,2),CTWNDAN_MAX_DAY);
			g_CtwnDanManage.CurrentEndDay = atoi(pstuLcTwDan->m_zyday);
		}
		else
		{
			pSpecial = (pSPECIAL)GetSpecialTypeInfo(m_Type);
			if (NULL == pSpecial || 0 == pSpecial->index)
			{
				continue;
			}
			m_days = atoi(pstuLcTwDan->m_zyday) - pSpecial->m_rq + 1;
		}
		if (m_days <= 0)
		{
			continue;
		}
		
		if (CLCTWDAN_SS == m_Type)
		{
			memset(pstuLcTwDan->m_ssday,0,CTWNDAN_MAX_DAY);
			sprintf(pstuLcTwDan->m_ssday,"%d",m_days);
		}
		else if (CLCTWDAN_FM == m_Type)
		{
			memset(pstuLcTwDan->m_fmday,0,CTWNDAN_MAX_DAY);
			sprintf(pstuLcTwDan->m_fmday,"%d",m_days);
		}
	}
//	SetSSFMClear();
	if (CLCTWDAN_RY == m_Type)
	{
		m_temp.top = g_CtwnDanManage.Bounds.top+ GetResult(100,m_printLevel);
	}
	else if (CLCTWDAN_SS == m_Type || CLCTWDAN_FM == m_Type)
	{
		m_temp.top = g_CtwnDanManage.Bounds.top+ GetResult(120,m_printLevel);
	}
	if (m_temp.top != g_CtwnDanManage.NeiBounds.top)
	{
		m_temp.bottom = m_temp.top + GetResult(20,m_printLevel);
		InvalidateRect(m_temp,FALSE);
	}
}

int CCLcTwDanCtrl::GetLeftPos(int m_rq, int m_sj, int types)
{
	pCTEMPERATURE pTemperature=NULL;
	pCPULSE pPulse=NULL;
	int rq=m_rq,sj=m_sj;
	if (1 == types)
	{
		do 
		{
			sj--;
			if (sj<0)
			{
				if (0 == rq)
				{
					return g_CtwnDanManage.NeiBounds.left+m_rq*84+m_sj*14;
				}
				sj = CTWNDAN_MAX_COUNT-1;
				rq --;
			}
			pTemperature = &g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj];
		} while(0 == pTemperature->Type);
		return g_CtwnDanManage.NeiBounds.left+rq*84+sj*14;
	}
	else if (2 == types)
	{
		do 
		{
			sj--;
			if (sj<0)
			{
				if (0 == rq)
				{
					return g_CtwnDanManage.NeiBounds.left+m_rq*84+m_sj*14;
				}
				sj = CTWNDAN_MAX_COUNT-1;
				rq --;
			}
		pPulse = &g_CtwnDanManage.stuLcTwDan[rq].Pulse[sj];
		} while(0 == pPulse->Type);
		return g_CtwnDanManage.NeiBounds.left+rq*84+sj*14;
	}
	else if (3 == types)
	{
		return g_CtwnDanManage.NeiBounds.left+m_rq*84+m_sj*14;
	}
	else 
	{
		return 0;
	}
}

int CCLcTwDanCtrl::GetRightPos(int m_rq, int m_sj, int types)
{
	pCTEMPERATURE pTemperature=NULL;
	pCPULSE pPulse=NULL;
	int rq=m_rq,sj=m_sj;
	if (1 == types)
	{
		do 
		{
			sj++;
			if (sj>CTWNDAN_MAX_COUNT-1)
			{
				sj = 0;
				rq ++;
				if (PAGE_SUM == rq)
				{
					return g_CtwnDanManage.NeiBounds.left+m_rq*84+(m_sj+1)*14;
				}
				if (0 == *g_CtwnDanManage.stuLcTwDan[rq].m_zyday)
				{
					return g_CtwnDanManage.NeiBounds.left+m_rq*84+(m_sj+1)*14;
				}
			}
			pTemperature = &g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj];
		} while(0 == pTemperature->Type);
		return g_CtwnDanManage.NeiBounds.left+rq*84+(sj+1)*14;
	}
	else if (2 == types)
	{
		do 
		{
			sj++;
			if (sj>CTWNDAN_MAX_COUNT-1)
			{
				sj = 0;
				rq ++;
				if (PAGE_SUM == rq)
				{
					return g_CtwnDanManage.NeiBounds.left+m_rq*84+(m_sj+1)*14;
				}
				if (0 == *g_CtwnDanManage.stuLcTwDan[rq].m_zyday)
				{
					return g_CtwnDanManage.NeiBounds.left+m_rq*84+(m_sj+1)*14;
				}
			}
			pPulse = &g_CtwnDanManage.stuLcTwDan[rq].Pulse[sj];
		} while(0 == pPulse->Type && 0 != *g_CtwnDanManage.stuLcTwDan[rq].m_zyday);
		return g_CtwnDanManage.NeiBounds.left+rq*84+(sj+1)*14;
	}
	else if (3 == types)
	{
		return g_CtwnDanManage.NeiBounds.left+m_rq*84+(m_sj+1)*14;
	}
	else 
	{
		return 0;
	}
}

int CCLcTwDanCtrl::GetTopPos(int m_rq, int m_sj, CRect &m_crect , int types)
{
	pCTEMPERATURE pTLeft=NULL;
	pCTEMPERATURE pTRight=NULL;
	pCTEMPERATURE pTSelf=NULL;
	pCPULSE pPulse=NULL;
	pCPULSE pPulseSelf=NULL;
	int rq=m_rq,sj=m_sj;
	if (1 == types)
	{
		do 
		{
			sj--;
			if (sj<0)
			{
				if (0 == rq)
				{
					pTSelf = &g_CtwnDanManage.stuLcTwDan[m_rq].Temperature[m_sj];
					break;
				}
				sj = CTWNDAN_MAX_COUNT-1;
				rq --;
			}
			pTLeft = &g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj];
		} while(0 == pTLeft->Type);
		
		rq=m_rq;
		sj=m_sj;
		do 
		{
			sj++;
			if (sj>CTWNDAN_MAX_COUNT-1)
			{
				sj = 0;
				rq ++;
				if (PAGE_SUM == rq)
				{
					pTRight = &g_CtwnDanManage.stuLcTwDan[m_rq].Temperature[m_rq];
					break;
				}
				if (0 == *g_CtwnDanManage.stuLcTwDan[rq].m_zyday)
				{
					pTRight = &g_CtwnDanManage.stuLcTwDan[m_rq].Temperature[m_rq];
					break;
				}
			}
			pTRight = &g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj];
		} while(0 == pTRight->Type);
		pTSelf = &g_CtwnDanManage.stuLcTwDan[m_rq].Temperature[m_sj];
		m_crect.top = g_CtwnDanManage.NeiBounds.top+GetMinNumber(GetMinNumber(pTLeft->TemperatureValue, pTSelf->TemperatureValue),pTRight->TemperatureValue);
		m_crect.bottom = g_CtwnDanManage.NeiBounds.top+GetMinNumber(GetMaxNumber(pTLeft->TemperatureValue, pTSelf->TemperatureValue),pTRight->TemperatureValue);

		return g_CtwnDanManage.NeiBounds.top+pTSelf->TemperatureValue;
	}
	else if (2 == types)
	{
		do 
		{
			sj++;
			if (sj>CTWNDAN_MAX_COUNT-1)
			{
				sj = 0;
				rq ++;
				if (PAGE_SUM == rq)
				{
					return g_CtwnDanManage.NeiBounds.left+m_rq*84+(m_sj+1)*14;
				}
				if (0 == *g_CtwnDanManage.stuLcTwDan[rq].m_zyday)
				{
					return g_CtwnDanManage.NeiBounds.left+m_rq*84+(m_sj+1)*14;
				}
			}
			pPulse = &g_CtwnDanManage.stuLcTwDan[rq].Pulse[sj];
		} while(0 == pPulse->Type && 0 != *g_CtwnDanManage.stuLcTwDan[rq].m_zyday);
		return g_CtwnDanManage.NeiBounds.left+rq*84+(sj+1)*14;
	}
	else if (3 == types)
	{
		return g_CtwnDanManage.NeiBounds.left+m_rq*84+(m_sj+1)*14;
	}
	else 
	{
		return 0;
	}
}


CTime CCLcTwDanCtrl::CheckDate(CString m_Date)
{
	CString m_DateTmp = m_Date;
	CTime m_time = 0;

	int pos=0,day =0,mouth=0,year=0,hour = 0,minuts = 0,second = 0;
	pos=m_DateTmp.Find('-');
	
	year=atoi((const char *)m_DateTmp.Left(pos).GetBuffer(0));
	if (year <1990 || year >2025)
	{
		goto EXIT;
	}
	m_DateTmp=m_DateTmp.Right(m_DateTmp.GetLength() - pos-1);
	pos=m_DateTmp.Find('-');
	mouth=atoi((const char *)m_DateTmp.Left(pos).GetBuffer(0));
	if (mouth <0 || mouth >12)
	{
		goto EXIT;
	}
	m_DateTmp=m_DateTmp.Right(m_DateTmp.GetLength() - pos-1);
	pos=m_DateTmp.Find(' ');
	if (pos < 0)
	{
		day=atoi((const char *)m_DateTmp.GetBuffer(0));
		goto EXIT;
	}
	day=atoi((const char *)m_DateTmp.Left(pos).GetBuffer(0));

	m_DateTmp=m_DateTmp.Right(m_DateTmp.GetLength() - pos-1);
	pos=m_DateTmp.Find(':');
	hour=atoi((const char *)m_DateTmp.Left(pos).GetBuffer(0));
	if (hour <0 || hour >24)
	{
		goto EXIT;
	}
	
	m_DateTmp=m_DateTmp.Right(m_DateTmp.GetLength() - pos-1);
	pos=m_DateTmp.Find(':');
	minuts=atoi((const char *)m_DateTmp.Left(pos).GetBuffer(0));
	if (hour <0 || hour >60)
	{
		goto EXIT;
	}
	m_DateTmp=m_DateTmp.Right(m_DateTmp.GetLength() - pos-1);
	second=atoi((const char *)m_DateTmp.GetBuffer(0));
	if (hour <0 || hour >60)
	{
		goto EXIT;
	}
EXIT:
	if (day <0 || day >32)
	{
		return m_time;
	}
	m_time = CTime::CTime(year, mouth, day, hour, minuts, second);
	if(m_time <1000)
	{
		m_time = 0;
	}
	return m_time;
}

CString CCLcTwDanCtrl::GetIntToTS(int m_Teshu)
{
	pSPACIAL_CTRL_INFO pSpacial_CtrlInfo = (pSPACIAL_CTRL_INFO)GetSpaceCtrlInfo(m_Teshu);
	
	if (NULL != pSpacial_CtrlInfo)
	{
		return pSpacial_CtrlInfo->strtypeName;
	}
	return _T("未知");
}

CString CCLcTwDanCtrl::GetTeShu(int innum)
{
	int numGeweiTmp=0,numShiweiTmp =0;
	CString szresult="";
	int type = 0;
	if (0 == innum)
	{
		return _T("零");
	}
	if (innum<0 && innum>99)
	{
		return "";
	}
	numGeweiTmp = innum/10;
	numShiweiTmp = innum%10;
	if (0 == numGeweiTmp)
	{
		type =1;
	}
	else
	{
		type =2;
	}
	szresult.Format(_T("%s%s"),GetNumber(numGeweiTmp,type),GetNumber(numShiweiTmp,1));
	return szresult;
}

CString CCLcTwDanCtrl::GetNumber(int innum, int zt)
{
	switch (innum)
	{
	case 1:
		if (zt==1){return "一";}else if (zt==2){return "十";}
		break;
	case 2:
		if (zt==1){return "二";}else if (zt==2){return "廿";}
		break;
	case 3:
		if (zt==1){return "三";}else if (zt==2){return "三十";}
		break;
	case 4:
		if (zt==1){return "四";}else if (zt==2){return "四十";}
		break;
	case 5:
		if (zt==1){return "五";}else if (zt==2){return "五十";}
		break;
	case 6:
		if (zt==1){return "六";}else if (zt==2){return "六十";}
		break;
	case 7:
		if (zt==1){return "七";}else if (zt==2){return "七十";}
		break;
	case 8:
		if (zt==1){return "八";}else if (zt==2){return "八十";}
		break;
	case 9:
		if (zt==1){return "九";}else if (zt==2){return "九十";}
		break;
	case 0:
		if (zt==1){return "";}else{return "十";}
		break;
	}
	return "";
}

CString CCLcTwDanCtrl::GetSsFmDay(char* ssday, char* fmday)
{
	CString m_result,temp;
	if (0 !=*ssday && 0!=*fmday)
	{
		m_result.Format(_T("%s/%s"),ssday,fmday);
	}
	else if (0 ==*ssday && 0!=*fmday)
	{
		m_result.Format(_T("%s"),fmday);
	}
	else if (0 !=*ssday && 0==*fmday)
	{
		m_result.Format(_T("%s"),ssday);
	}
	else if (0 ==*ssday && 0==*fmday)
	{
		m_result="";
	}
	return m_result;
}

void CCLcTwDanCtrl::BefDay() 
{
	// TODO: Add your dispatch handler code here
	CString m_strMsg;
	try
	{
		if (g_CtwnDanManage.CurrentBeginDay>0)
		{
			g_CtwnDanManage.CurrentBeginDay --;
			UpdateInfo();
		}
	}
	catch (...)
	{
		m_strMsg.Format(_T("%s:%d"), _T("出错了"),__LINE__);
		MessageBox(m_strMsg);
	}
}

void CCLcTwDanCtrl::AftDay() 
{
	// TODO: Add your dispatch handler code here
	CString m_strMsg;
	try
	{
		CString m_str;
		int m_i=0;
		while(1)
		{
			if (0 == *(g_CtwnDanManage.stuLcTwDan[0].m_ryDate))//PAGE_SUM-1
			{
				break;
			}
			if (g_CtwnDanManage.CurrentBeginDay<g_CtwnDanManage.CurrentEndDay)
			{
				g_CtwnDanManage.CurrentBeginDay ++;
				UpdateInfo();
				break;
			}
			m_i++;
			m_str = GetZyDayFromInt(g_CtwnDanManage.CurrentBeginDay+m_i,2);
			if (m_str.IsEmpty())
			{
				break;
			}
			g_CtwnDanManage.CurrentEndDay = atoi((const char *)m_str.GetBuffer(0));
		}
	}
	catch (...)
	{
		
		m_strMsg.Format(_T("%s:%d"), _T("出错了"),__LINE__);
		MessageBox(m_strMsg);
	}

}

void CCLcTwDanCtrl::BefWeek() 
{
	// TODO: Add your dispatch handler code here
	CString m_strMsg;
	try
	{
		g_CtwnDanManage.CurrentBeginDay -= PAGE_SUM;
		if (g_CtwnDanManage.CurrentBeginDay < 0)
		{
			g_CtwnDanManage.CurrentBeginDay =CTWDAN_BEGIN_DAYS;
		}
		UpdateInfo();
	}
	catch (...)
	{
		
		m_strMsg.Format(_T("%s:%d"), _T("出错了"),__LINE__);
		MessageBox(m_strMsg);
	}
}

void CCLcTwDanCtrl::OnSetShowBeginDaysChanged() 
{
	CString m_strMsg;
	CString m_str,m_strTemp;
	try
	{
		int m_i=PAGE_SUM;
		
		m_str = GetZyDayFromInt(m_SetShowBeginDays,2);
		if (m_str.IsEmpty())
		{
			return;
		}
		g_CtwnDanManage.CurrentBeginDay = m_SetShowBeginDays;
		g_CtwnDanManage.CurrentEndDay = g_CtwnDanManage.CurrentBeginDay+PAGE_SUM;
		while(1)
		{
			if (0 == *(g_CtwnDanManage.stuLcTwDan[PAGE_SUM-1].m_ryDate))
			{
				break;
			}
			if (g_CtwnDanManage.CurrentBeginDay+PAGE_SUM < g_CtwnDanManage.CurrentEndDay)
			{
				g_CtwnDanManage.CurrentBeginDay += PAGE_SUM;
				UpdateInfo();
				break;
			}
			
			m_str = GetZyDayFromInt(g_CtwnDanManage.CurrentBeginDay+m_i,2);
			if (m_str.IsEmpty())
			{
				m_strTemp = GetZyDayFromInt(g_CtwnDanManage.CurrentEndDay,2);
				if (m_strTemp.IsEmpty())
				{
					break;
				}
				g_CtwnDanManage.CurrentBeginDay += PAGE_SUM;
				UpdateInfo();
				break;
			}
			g_CtwnDanManage.CurrentEndDay = atoi((const char *)m_str.GetBuffer(0));
			m_i+=PAGE_SUM;
		}
	}
	catch (...)
	{
		
		m_strMsg.Format(_T("%s:%d"), _T("出错了"),__LINE__);
		MessageBox(m_strMsg);
	}
	SetModifiedFlag();
}

void CCLcTwDanCtrl::AftWeek() 
{
	// TODO: Add your dispatch handler code here
	CString m_strMsg;
	CString m_str,m_strTemp;
	try
	{
		int m_i=PAGE_SUM;
		g_CtwnDanManage.CurrentEndDay = g_CtwnDanManage.CurrentBeginDay+PAGE_SUM;
	//	g_CtwnDanManage.CurrentBeginDay += PAGE_SUM;
		while(1)
		{
			if (0 == *(g_CtwnDanManage.stuLcTwDan[PAGE_SUM-1].m_ryDate))
			{
				break;
			}
			if (g_CtwnDanManage.CurrentBeginDay+PAGE_SUM < g_CtwnDanManage.CurrentEndDay)
			{
				g_CtwnDanManage.CurrentBeginDay += PAGE_SUM;
				UpdateInfo();
				break;
			}
			
			m_str = GetZyDayFromInt(g_CtwnDanManage.CurrentBeginDay+m_i,2);
			if (m_str.IsEmpty())
			{
				m_strTemp = GetZyDayFromInt(g_CtwnDanManage.CurrentEndDay,2);
				if (m_strTemp.IsEmpty())
				{
					break;
				}
				g_CtwnDanManage.CurrentBeginDay += PAGE_SUM;
				UpdateInfo();
				break;
			}
			g_CtwnDanManage.CurrentEndDay = atoi((const char *)m_str.GetBuffer(0));
			m_i+=PAGE_SUM;
		}
	}
	catch (...)
	{
		
		m_strMsg.Format(_T("%s:%d"), _T("出错了"),__LINE__);
		MessageBox(m_strMsg);
	}
}

void CCLcTwDanCtrl::UpdateInfo()
{
	int m_number = 0;
	pCTWLCDANINFO stuLcTwDan=NULL;
	pSPECIAL	  pSpecial = NULL;
	CRect Bounds;
	m_number = g_CtwnDanManage.CurrentBeginDay;
	//	CtwDanMemSet();
	for (int i=0;i<PAGE_SUM;i++)
	{
		stuLcTwDan = &g_CtwnDanManage.stuLcTwDan[i];
		memset(stuLcTwDan, 0, sizeof(CTWLCDANINFO));
		memcpy(stuLcTwDan->m_ryDate,GetZyDayFromInt(m_number+i,1),CTWNDAN_MAX_DATE);
		if (0 == *stuLcTwDan->m_ryDate)
		{
			continue;
		}
		pSpecial = (pSPECIAL)GetSpecialTypeInfo(CLCTWDAN_RY);
		if (NULL != pSpecial && pSpecial->m_rq != 0 ||
			!m_SetPatientRyDate.Compare((LPCTSTR)g_CtwnDanManage.stuLcTwDan[i].m_ryDate))
		{
			memcpy(stuLcTwDan->m_zyday,GetZyDayFromInt(m_number+i,2),CTWNDAN_MAX_DAY);
		}
		
		pSpecial = (pSPECIAL)GetSpecialTypeInfo(CLCTWDAN_SS);
		if (NULL != pSpecial && pSpecial->m_rq != 0 && CLCTWDAN_SS == pSpecial->index &&
			m_number+i+1-pSpecial->m_rq>=0 &&
			0 != stuLcTwDan->m_zyday[0])
		{							
			memcpy(stuLcTwDan->m_ssday,GetZyDayFromInt(m_number+i+1-pSpecial->m_rq,2),CTWNDAN_MAX_DAY);
		}

		pSpecial = (pSPECIAL)GetSpecialTypeInfo(CLCTWDAN_FM);
		if (NULL != pSpecial && pSpecial->m_rq != 0 && CLCTWDAN_FM == pSpecial->index &&
			m_number+i+1-pSpecial->m_rq>=0 &&
			0 != stuLcTwDan->m_zyday[0])
		{
			memcpy(stuLcTwDan->m_fmday,GetZyDayFromInt(m_number+i+1-pSpecial->m_rq,2),CTWNDAN_MAX_DAY);
		}
	}
	ShowData();
	Bounds = g_CtwnDanManage.Bounds;
	Bounds.left = g_CtwnDanManage.NeiBounds.left;
	InvalidateRect(Bounds,FALSE);
}

void CCLcTwDanCtrl::ShowData()
{
	int m_index=0,m_number1=0,m_number2 =0;
	pCTWLCDANINFO stuLcTwDan = NULL;
	m_number1 = g_CtwnDanManage.CurrentBeginDay;
	for (m_index=0; m_index<PAGE_SUM; m_index++)
	{
		m_number2 = g_CtwnDanManage.m_ptrArray.GetSize();
		if (m_number1+m_index < m_number2)
		{
			stuLcTwDan = (pCTWLCDANINFO)g_CtwnDanManage.m_ptrArray.GetAt(m_number1+m_index);
			//MessageBox(stuLcTwDan->m_zyday);
			strcpy(stuLcTwDan->m_zyday, g_CtwnDanManage.stuLcTwDan[m_index].m_zyday);
			strcpy(stuLcTwDan->m_ssday, g_CtwnDanManage.stuLcTwDan[m_index].m_ssday);
			strcpy(stuLcTwDan->m_fmday, g_CtwnDanManage.stuLcTwDan[m_index].m_fmday);
			memcpy(&g_CtwnDanManage.stuLcTwDan[m_index], stuLcTwDan, sizeof(CTWLCDANINFO));
		//	memcpy(stuLcTwDan, &g_CtwnDanManage.stuLcTwDan[m_index], sizeof(CTWLCDANINFO));
		}
		else
		{
			break;
		}
	}
}

void CCLcTwDanCtrl::SaveTmpStorage() 
{
	SaveTmpStorageTemp();
}
int CCLcTwDanCtrl::GetPageInfo(int type)
{
	int m_number1 =0,m_number2 =0,m_number3 = 0;
	pCTWLCDANINFO stuLcTwDan = NULL,stuLcTwDanTmp = NULL;

	m_number2 = g_CtwnDanManage.m_ptrArray.GetSize();
	if (1 == type)
	{
		m_number3 = m_number2/7;
		if (0 < m_number2%7)
		{
			m_number3++;
		}
		return m_number3;
	}
	stuLcTwDan = &g_CtwnDanManage.stuLcTwDan[0];
	for (m_number1 =0;m_number1<m_number2;m_number1++)
	{
		stuLcTwDanTmp = (pCTWLCDANINFO)g_CtwnDanManage.m_ptrArray.GetAt(m_number1);
		if (NULL == stuLcTwDanTmp )
		{
			continue;
		}
		if (0 == strcmp(stuLcTwDan->m_ryDate,stuLcTwDanTmp->m_ryDate))
		{
			break;
		}		
	}
	m_number3 = m_number1/7;
	if (0 < m_number1%7)
	{
		m_number3++;
	}
	return m_number3+1;
}
int CCLcTwDanCtrl::SaveTmpStorageTemp()
{
	pCTWLCDANINFO stuLcTwDan = NULL,stuLcTwDanTmp = NULL;
	int m_index=0,m_number1=0,m_number2 =0,m_index2=0;
	try{
		for (m_index=0; m_index<PAGE_SUM; m_index++)
		{
			stuLcTwDan = &g_CtwnDanManage.stuLcTwDan[m_index];
			//m_number1 = atoi(stuLcTwDan->m_zyday)-1;
			m_number1 = GetBeginDay(stuLcTwDan->m_ryDate);
			m_number2 = g_CtwnDanManage.m_ptrArray.GetSize();
			if (-1 == m_number1)
			{
				return -1;
			}
			else if (m_number1 < 0)
			{
				return -2;
			}
			else if (m_number2 == m_number1)
			{
				stuLcTwDanTmp = (pCTWLCDANINFO)calloc(1, sizeof(CTWLCDANINFO));
				memcpy(stuLcTwDanTmp, stuLcTwDan, sizeof(CTWLCDANINFO));
				g_CtwnDanManage.m_ptrArray.Add(stuLcTwDanTmp);
				stuLcTwDanTmp->m_bIsModified = CTWDAN_INSERT;
			}
			else if (m_number2 < m_number1)
			{
				for (m_index2 = m_number2;m_index2<=m_number1 ;m_index2++)
				{
					stuLcTwDanTmp = (pCTWLCDANINFO)calloc(1,sizeof(CTWLCDANINFO));
					memcpy(stuLcTwDanTmp->m_ryDate, GetZyDayFromInt(m_index2,1).GetBuffer(CTWNDAN_MAX_DATE), CTWNDAN_MAX_DATE);
					stuLcTwDanTmp->m_ryDate[CTWNDAN_MAX_DATE] = 0;
					memcpy(stuLcTwDanTmp->m_zyday, GetZyDayFromInt(m_index2,2).GetBuffer(CTWNDAN_MAX_DAY), CTWNDAN_MAX_DAY);
					stuLcTwDanTmp->m_zyday[CTWNDAN_MAX_DAY] = 0;
					g_CtwnDanManage.m_ptrArray.Add(stuLcTwDanTmp);
					stuLcTwDanTmp->m_bIsModified = CTWDAN_INSERT;
				}
				//MessageBox(_T("前面的数据没有不能保存"),_T("提示"),MB_OK);
			}
			stuLcTwDanTmp = (pCTWLCDANINFO)g_CtwnDanManage.m_ptrArray.GetAt(m_number1);
			memcpy(stuLcTwDanTmp, stuLcTwDan, sizeof(CTWLCDANINFO));
			if (CTWDAN_INSERT != stuLcTwDanTmp->m_bIsModified)
			{
				stuLcTwDanTmp->m_bIsModified = CTWDAN_MODIFIED;
			}
		}
	}
	catch(...)
	{
		MessageBox(_T("未知错误"),_T("提示"),MB_OK);
	}
	return 0;	
}

void CCLcTwDanCtrl::OnSetCTwDanInfoChanged() 
{
	// TODO: Add notification handler code
	int nRet = 0;
	char * SetCTwDanInfoTemp=(char*)malloc(m_SetCTwDanInfo.GetLength()+10);
	CString msgbox;

	sprintf(SetCTwDanInfoTemp,"%s",m_SetCTwDanInfo.GetBuffer(m_SetCTwDanInfo.GetLength()+10));
	g_SetAftDayDisable = m_SetAftDayDisable;
	nRet = SaveTmpStorageTemp();
	if (-1 == nRet)
	{
		msgbox.Format(_T("错误号:2%0.4d 请填写入院时间"),__LINE__);
		goto CEXIT;
	}
	else if (-2 == nRet)
	{
		msgbox.Format(_T("错误号:2%0.4d 保存数据跨度太大"),__LINE__);
		goto CEXIT;
	}
	if (0 == AnalyzeInString(SetCTwDanInfoTemp))
	{
		UpdateInfo();
	}
CEXIT:
	if (!msgbox.IsEmpty())
	{
		MessageBox(_T("解析出错"), _T("提示"), MB_OK);
	}
	free(SetCTwDanInfoTemp);
	SetCTwDanInfoTemp = NULL;
	m_SetCTwDanInfo.Empty();
//	delete SetCTwDanInfoTemp;
	SetModifiedFlag();
}

void CCLcTwDanCtrl::OnGetCTwDanInfoChanged() 
{
	//S[2011-11-03]
	char GetCTwDanInfo[36] = {0};
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	char *GetCTwDanInfoTemp = GetCTwDanInfo;
	char m_ryDate[CTWNDAN_MAX_DATE*2]={0};
	SaveTmpStorageTemp();
	strncpy(GetCTwDanInfo, m_GetCTwDanInfo.GetBuffer(0), 35);
	switch (m_AnlStr.GetAnalyzeValue(GetCTwDanInfo,m_ryDate))
	{
	case 1:			//获取特殊信息
		m_GetCTwDanInfo = GetSpacileValue();
		break;
	case 2:			//获取当天所有信息
		m_GetCTwDanInfo = GetOtherAllValue(m_ryDate,2);
		break;
	case 3:
		m_GetCTwDanInfo = GetOtherAllValue(m_ryDate,3);
		break;
	default:
		break;
	}
	SetModifiedFlag();
}
CString CCLcTwDanCtrl::GetSpacileValue(char * m_rydate)
{
	SPECIAL *pSpecial = NULL;
	CString m_result,m_resultTemp;
	int m_number1=0,m_number2 = sizeof(g_Special_Ctrl_Info)/sizeof(SPACIAL_CTRL_INFO);//PSPACEL_SUM;//
	CString m_outdate;
	int inDatarq=0,inDatasj=0,inDatatm=0;
	char *na = NULL;
	for (m_number1=0; m_number1 < m_number2; m_number1++)
	{
		do 
		{
			pSpecial = (pSPECIAL)GetSpecialTypeInfo(g_Special_Ctrl_Info[m_number1].index,&inDatarq,&inDatasj,&inDatatm);
			if (NULL == pSpecial)
			{
				break;
			}
			if (pSpecial->shij <=0 )
			{
				break;
			}
			m_outdate = GetZyDayFromInt(pSpecial->m_rq - g_SetRyDayBegin, 1);
			if (NULL != m_rydate && NULL == strstr(m_rydate,m_outdate))
			{
				break;
			}
			m_resultTemp.Format("U[%s %2d:%2d:00,%d;]",
				GetZyDayFromInt(pSpecial->m_rq - g_SetRyDayBegin, 1),
				pSpecial->Times,
				pSpecial->Second,m_number1+1);

			m_result += m_resultTemp;
			inDatatm ++;
		} while (NULL != pSpecial);
		inDatarq = 0;
		inDatasj = 0;
		inDatatm = 0;
	}
	return m_result;
}
/*********************************************************************
V[1,222;2,222;3,222;4,222;5,222;6,222]   
**********************************************************************/
CString CCLcTwDanCtrl::GetOtherAllValue(char *m_rydate,int type)
{
	CString m_result;
	pCTWLCDANINFO stuLcTwDan = NULL,stuLcTwDanTmp = NULL;
	char * m_strtemp = NULL;
	int m_index = 0;
	CString m_strTW,m_strMB,m_strHX,m_strSR;
	CString m_strTWtemp,m_strMBtemp,m_strHXtemp,m_strSRtemp;
	int m_number1=0,m_number2 = g_CtwnDanManage.m_ptrArray.GetSize();
	if (NULL == m_rydate)
	{
		return "";
	}
	for (m_number1 =0; m_number1<m_number2; m_number1++)
	{
		stuLcTwDan = (pCTWLCDANINFO)g_CtwnDanManage.m_ptrArray.GetAt(m_number1);
		m_strtemp = strstr(m_rydate, stuLcTwDan->m_ryDate);
		if (NULL != m_strtemp)
		{
			m_result.Format(_T("S[%s]"),stuLcTwDan->m_ryDate);
			m_strTW = _T("T[");
			m_strMB = _T("M[");
			m_strHX = _T("H[");
			m_strSR = _T("V[");
			for (m_index = 0; m_index < CTWNDAN_MAX_COUNT; m_index++)
			{
				if (stuLcTwDan->Temperature[m_index].Type>0)
				{
					
					m_strTWtemp.Format(_T("%d,%d,%.1f,%.1f;"),
						stuLcTwDan->Temperature[m_index].Time+1,
						stuLcTwDan->Temperature[m_index].Type,
						PointToTw(stuLcTwDan->Temperature[m_index].TemperatureValue),
						PointToTw(stuLcTwDan->Temperature[m_index].PhysicsValue));
					m_strTW+=m_strTWtemp;
				}
				if (stuLcTwDan->Pulse[m_index].Type>0)
				{
					m_strMBtemp.Format(_T("%d,%d,%.0f;"),
						stuLcTwDan->Pulse[m_index].Time+1,
						stuLcTwDan->Pulse[m_index].Type,
						PointToMb(stuLcTwDan->Pulse[m_index].CpulseValue));
					m_strMB+=m_strMBtemp;
				}
				if (0 != stuLcTwDan->SpecHuxi[m_index][0])
				{
					m_strHXtemp.Format("%d,%s;",
						m_index +1,
						stuLcTwDan->SpecHuxi[m_index]);
					m_strHX += m_strHXtemp;
				}
			}
			//大便次数,输入液量,尿量(ml):","痰量(ml):,血,压:,体重(kg):
			if (0 != stuLcTwDan->m_shitti[0])
			{
				m_strSRtemp.Format(_T("%d,%s;"),1, stuLcTwDan->m_shitti);
				m_strSR += m_strSRtemp;
			}
			if (0 != stuLcTwDan->m_infuse[0])
			{
				m_strSRtemp.Format(_T("%d,%s;"),2, stuLcTwDan->m_infuse);
				m_strSR += m_strSRtemp;
			}
			if (0 != stuLcTwDan->m_urines[0])
			{
				m_strSRtemp.Format(_T("%d,%s;"),3, stuLcTwDan->m_urines);
				m_strSR += m_strSRtemp;
			}
			if (0 != stuLcTwDan->m_sputum[0])
			{
				m_strSRtemp.Format(_T("%d,%s;"),4, stuLcTwDan->m_sputum);
				m_strSR += m_strSRtemp;
			}
			if (0 != stuLcTwDan->m_bpress[0])
			{
				m_strSRtemp.Format(_T("%d,%s;"),5, stuLcTwDan->m_bpress);
				m_strSR += m_strSRtemp;
			}
			if (0 != stuLcTwDan->m_weight[0])
			{
				m_strSRtemp.Format(_T("%d,%s;"),6, stuLcTwDan->m_weight);
				m_strSR += m_strSRtemp;
			}
			if ("[" != m_strTW.Right(1))
			{
				m_strTW +=_T("]");
			}
			else
			{
				m_strTW.Empty();
			}
			if ("[" != m_strMB.Right(1))
			{
				m_strMB +=_T("]");
			}
			else
			{
				m_strMB.Empty();
			}
			if ("[" != m_strHX.Right(1))
			{
				m_strHX +=_T("]");
			}
			else
			{
				m_strHX.Empty();
			}
			if ("[" != m_strSR.Right(1))
			{
				m_strSR +=_T("]");
			}
			else
			{
				m_strSR.Empty();
			}
			if (3 == type)
			{
				m_result += GetSpacileValue(m_rydate);
			}

			m_result +=  m_strTW+m_strMB+m_strHX+m_strSR;
			break;
		}
	}
	return m_result;
}

int CCLcTwDanCtrl::SetSPecialValue(CTime timeSPecial,int nTypes, int m_value,void *pstuLcTwDan)
{
	CRect m_crect1 = g_CtwnDanManage.NeiBounds,m_crect2 = g_CtwnDanManage.NeiBounds;

	m_crect1.top += 7;
	m_crect1.bottom = m_crect1.top + 100;
	m_crect2.top += 7;
	m_crect2.bottom = m_crect2.top + 100;

	if (0 != CheckSpecialType(nTypes))
	{
		return 11;
	}

	m_Tabmgr.InitSpecial(m_SetPatientRyDate.GetBuffer(0), g_CtwnDanManage.CurrentBeginDay);

	m_Tabmgr.SetSpecialStr(pstuLcTwDan,timeSPecial,nTypes,m_value,m_crect1,m_crect2);

	if (m_crect2.left >= g_CtwnDanManage.NeiBounds.left)
	{
		m_crect2.right = m_crect2.left+14;
		InvalidateRect(m_crect2,FALSE);
	}
	if (m_crect1.left >= g_CtwnDanManage.NeiBounds.left)
	{
		m_crect1.right = m_crect1.left+14;
		InvalidateRect(m_crect1,FALSE);
	}
	SetZyDaySsDayLcDay(nTypes);
	return 0;
}

/************************************************************************/
/*   
	 U[2011-11-03 16:28:40,1;]
	 D[2011-11-03 16:28:40,1;]
	 S[2011-11-03]
	 T[1,2,36,35.6;2,2,37,36;3,2,38,37;4,2,37.5,36;5,2,38,37;6,2,40.53,38.5;]
     M[1,4,20;2,4,20;3,4,20;4,4,20;5,4,20;6,4,20]
	 H[1,20;2,20;3,20;4,20;5,20;6,20]
	 V[1,222;2,222;3,222;4,222;5,222;6,222]*/
/************************************************************************/
int CCLcTwDanCtrl::AnalyzeInString(char *input)
{
	pCTWLCDANINFO stuLcTwDan = NULL,pstuLcTwDan = NULL;
	//CTWLCDANINFO stuLcTwDanInfo ;
	int  Time = 0,nRet = 0;
	int  day1 = 0,day2 = 0,m_day1 = 0;
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	CTWLCDANINFO stuLcTwDanInfo;
	CTime timeSPecial;
	CString msgbox;
	
	if (NULL == input)
	{
		msgbox.Format(_T("in error please check"));
		goto ERR_EXIT;
	}
	FindBegPos = input;
	while(NULL != FindBegPos && 0 != *FindBegPos)
	{
		nRet = m_AnlStr.DeleteTwdInfo(&FindBegPos,&FindEndPos);
		if (1 != nRet)
		{
			if (0 == nRet)
			{
				continue;
			}
			msgbox.Format(_T("DeleteInfo please check:%d"),nRet);
			goto ERR_EXIT;
		}
		nRet = m_AnlStr.SetAnalyzeValue(&FindBegPos,&FindEndPos,(void **)&stuLcTwDan,msgbox);
		if (1 != nRet)
		{
			if (10 == nRet)
			{
				memcpy(&stuLcTwDanInfo, stuLcTwDan, sizeof(CTWLCDANINFO));
				pstuLcTwDan = stuLcTwDan;
				stuLcTwDan = &stuLcTwDanInfo;
				continue;
			}
			else if (11 == nRet)
			{
				continue;
			}
			else if (0 == nRet)
			{
				memcpy(pstuLcTwDan, stuLcTwDan,sizeof(CTWLCDANINFO));
				continue;
			}
			goto ERR_EXIT;
		}
		if (!msgbox.IsEmpty())
		{
			goto ERR_EXIT;
		}
	}
	
END_EXIT:
	return nRet;
ERR_EXIT:
	if (!msgbox.IsEmpty())
	{
		MessageBox(msgbox,_T("提示"),MB_OK|MB_ICONERROR);
		nRet = -1;
	}
	goto END_EXIT;
}

void CCLcTwDanCtrl::OnSetTwDanFocusChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}


void CCLcTwDanCtrl::OnSetRyDayBeginChanged() 
{
	// TODO: Add notification handler code
	if (m_setRyDayBegin <0 || m_setRyDayBegin>2)
	{
		m_setRyDayBegin =0;
	}
	g_SetRyDayBegin = m_setRyDayBegin;
	SetModifiedFlag();
}

int CCLcTwDanCtrl::GetBeginDay(char *m_zydatetemp)
{
	int day =0;
	//,day2 = 0;
	CTime current = CheckDate(m_zydatetemp);
	CTimeSpan m_spantime;
//	long  hours = 0;
	if (0 == m_zydatetemp[0])
	{
		return -1;
	}
	if (current >0)
	{
/*		day2 =  (current.GetYear()-g_CtwnDanManage.CTwDanTime.GetYear())*365 +
			    (current.GetMonth()-g_CtwnDanManage.CTwDanTime.GetMonth())*31 + 
				(current.GetDay() - g_CtwnDanManage.CTwDanTime.GetDay());
				*/
		m_spantime = current - g_CtwnDanManage.CTwDanTime;
		day = m_spantime.GetDays();
		
/*		if (day2>day)
		{
			day =day2;
		}*/
	}
	if (day <0 )
	{
		day =0;
	}
	return day;
}

void CCLcTwDanCtrl::OnSetHospitalFontNameChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CCLcTwDanCtrl::OnSetHospitalFontSizeChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CCLcTwDanCtrl::OnSetTitleNameFontNameChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CCLcTwDanCtrl::OnSetTitleNameFontSizeChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}


void CCLcTwDanCtrl::OnPrintInfoVerChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}



void CCLcTwDanCtrl::OnSetAftDayDisableChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CCLcTwDanCtrl::OnGetChageListChanged() 
{
	// TODO: Add notification handler code
	int type = atoi(GetChageListstr);
	pCTWLCDANINFO m_CtwDanInfo = NULL;
	CString m_List,m_ListTemp;
	int m_number1 = 0,m_number2 = g_CtwnDanManage.m_ptrArray.GetSize();
	if (type < 0 && type > 3)
	{
		MessageBox(_T("状态不正,1:新增 2:修改 3:未变"), _T("提示"));
		return ;
	}
	for (m_number1 =0;m_number1 <m_number2;m_number1++)
	{
		m_CtwDanInfo = (pCTWLCDANINFO)g_CtwnDanManage.m_ptrArray.GetAt(m_number1);
		if (type != m_CtwDanInfo->m_bIsModified)
		{
			continue;
		}
		m_ListTemp.Format(_T("S[%s]"), m_CtwDanInfo->m_ryDate);
		m_List +=m_ListTemp;
	}
	GetChageListstr = m_List;
	SetModifiedFlag();
}
void CCLcTwDanCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	int rq=0,sj=0;
	BOOL bIsRefush = FALSE;
	CRect m_Crect;
	CBalloonTip *g_pBalloonTip = NULL;
	int m_day1 =0, m_day2 =0;
	try
	{
		if (point.x>80 && point.x<668 && point.y>155 && point.y<=585)
		{
			rq=m_Fun.OrdinateToDate(point.x);			//日期
			m_Crect.top  = m_ScreenSize.top+135;
			m_Crect.bottom = m_ScreenSize.bottom-128;
			if (0 == *g_CtwnDanManage.stuLcTwDan[rq].m_ryDate)
			{
				return;
			}
			sj=m_Fun.OrdinateToTime(point.x);			//时间
			if (0 == m_SetTipShow)				//不提示
			{
			}
			
			/*m_pBalloonTip=CBalloonTip::Show(newpoint, CSize(150,60),m_msgshow,lf,100,TRUE);
			UpdateData(TRUE);
			m_pBalloonTip=NULL;*/
			if (bIsRefush)
			{
				return;
			}
		}
	}
	catch(...)
	{
		MessageBox(_T("未知错误"),_T("提示"),MB_OK|MB_ICONERROR);
	}
	// TODO: Add your message handler code here and/or call default
	// TODO: Add your message handler code here and/or call default
	COleControl::OnMouseMove(nFlags, point);
}

void CCLcTwDanCtrl::OnSetTipShowChanged() 
{
	// TODO: Add notification handler code
	switch(m_SetTipShow)
	{
	case 0:
	case 1:
		break;
	default:
		m_SetTipShow = 1;
		break;
	}
	SetModifiedFlag();
}

CString CCLcTwDanCtrl::GetShowMsg(int rq, int sj)
{
	CString m_resultTW,m_resultTWTemp,m_resultMB,m_resultMBTemp;
	if (CTWDAN_TIWEN_KOUQIANG == g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].Type)
	{
		m_resultTWTemp =_T("口腔体温是:");
	}
	else if (CTWDAN_TIWEN_YEWO == g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].Type)
	{
		m_resultTWTemp =_T("腋窝体温是:");
	}
	else if (CTWDAN_TIWEN_GANGMEN == g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].Type)
	{
		m_resultTWTemp =_T("肛门体温是:");
	}
	if (!m_resultTWTemp.IsEmpty())
	{
		m_resultTW.Format(_T("%s%d"), 
			m_resultTWTemp,
			PointToTw(g_CtwnDanManage.stuLcTwDan[rq].Temperature[sj].TemperatureValue));
	}
	if (CTWDAN_MAIBO_MAILV == g_CtwnDanManage.stuLcTwDan[rq].Pulse[sj].Type)
	{
		m_resultMBTemp = _T("脉率是:");
	}
	if (CTWDAN_MAIBO_XINLV == g_CtwnDanManage.stuLcTwDan[rq].Pulse[sj].Type)
	{
		m_resultMBTemp = _T("心率是:");
	}
	if (!m_resultMBTemp.IsEmpty())
	{
		m_resultMB.Format(_T("%s%d"),
			m_resultMBTemp,
			PointToMb(g_CtwnDanManage.stuLcTwDan[rq].Pulse[sj].CpulseValue));
	}
	if (!m_resultTW.IsEmpty() &&
		!m_resultMB.IsEmpty())
	{
		return m_resultTW+_T("\r\n")+m_resultMB;
	}
	return m_resultTW+m_resultMB;
}


int CCLcTwDanCtrl::GetRyDayBegin()
{
	return g_SetRyDayBegin;
}

int CCLcTwDanCtrl::GetAftDayDisable()
{
	return g_SetAftDayDisable;
}
CTWDANMANAGE* CCLcTwDanCtrl::GetTWDanMgr()
{
	return &g_CtwnDanManage;
}

/*
	CBitmap bitmap;
	BITMAP bmp;
	CDC dcCompatible;
	int m_whit=0;		
	m_whit = GetResult(8,m_printLevel);
	bitmap.LoadBitmap(IDB_NULL);
	bitmap.GetBitmap(&bmp);
	dcCompatible.CreateCompatibleDC(pdc);
	dcCompatible.SelectObject(&bitmap);
	pdc->StretchBlt(point.x,point.y,m_whit,m_whit,&dcCompatible,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	bitmap.DeleteObject();
*/
