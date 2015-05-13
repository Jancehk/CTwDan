// CTwDan.cpp : Implementation of CCTwDanApp and DLL registration.

#include "stdafx.h"
#include "..\include\CTwDan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CCTwDanApp NEAR theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0xf30feb77, 0xdc2a, 0x44b7, { 0xa7, 0xf0, 0xe4, 0x73, 0x11, 0x8a, 0x34, 0xdb } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


////////////////////////////////////////////////////////////////////////////
// CCTwDanApp::InitInstance - DLL initialization

BOOL CCTwDanApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}


////////////////////////////////////////////////////////////////////////////
// CCTwDanApp::ExitInstance - DLL termination

int CCTwDanApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}


/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
int g_LogFlag =1;

void DLLPrintLog(char * strFormat, ...)
{
	CString m_strRes;
	CString m_strCmd;
	CString m_strFilePath = "c:\\test.log";
	int		m_uCount = 0;
	va_list ap;
	if (1 == g_LogFlag)
	{
		return ;
	}
	m_uCount = GetPrivateProfileInt("NUM", "COUNT", 0, m_strFilePath);
	m_uCount++;
	m_strCmd.Format("%d",m_uCount);
	WritePrivateProfileString("NUM", "COUNT", m_strCmd, m_strFilePath);
	va_start(ap, strFormat);
	m_strRes.FormatV(strFormat, ap);
	va_end(ap);
	
	m_strCmd.Format("%04d",m_uCount);
	WritePrivateProfileString("LOG",m_strCmd, m_strRes,m_strFilePath);
	if (m_uCount >= 0X000FFFF)
	{
		unlink(m_strFilePath);
	}
//	system(m_strCmd);
}

int CTwdGetHourtoTime(int hour)
{
	if (hour>=0 && hour<3){return 24;}
	else if (hour>=3 && hour<7){return 4;}
	else if (hour>=7 && hour<11){return 8;}
	else if (hour>=11 && hour<15){return 12;}
	else if (hour>=15 && hour<19){return 16;}
	else if (hour>=19 && hour<23){return 20;}
	else if (hour>=23 && hour<24){return 24;}
	return 0;
}

int CTwdGetTimeToValue(int hour)
{
	if (hour<0 || hour>24){return 0;}
	switch (hour)
	{
	case 4:return 0;
	case 8:return 1;
	case 12:return 2;
	case 16:return 3;
	case 20:return 4;
	case 24:return 5;
	}
	return 0;
}
int CTwdGetValueToTime(int hour)
{
	if (hour<0 || hour>5){return 0;}
	switch (hour)
	{
	case 0:return 2;
	case 1:return 6;
	case 2:return 10;
	case 3:return 14;
	case 4:return 18;
	case 5:return 22;
	}
	return 4;
}

int GetMinNumber(int a,int b)
{
	if ((a)<=(b))
	{
		return (a);
	}
	return (b);
}
int GetMaxNumber(int a,int b)
{
	if ((a)>=(b))
	{
		return (a);
	}
	return (b);
}
int TwToPoint(float fTw)
{
	int point =0;
	point = (int)((42.60-fTw)*50)+156;
	if (point<155 || point>586)
	{
		return 0;
	}
	return point;
}

int MbToPoint(float fTw)
{
	int point =0;
	point = (int)((192-fTw)*2.5)+156;
	if (point<155 || point>585)
	{
		return 0;
	}
	return point;
}

float PointToTw(int point)
{
	if (point<155 || point>585)
	{
		return 0.0;
	}
	return (float)(42.6-(point-155)*0.02);
}

float PointToMb(int point)
{
	if (point<155 || point>585)
	{
		return 0.0;
	}
	return (float)(192-((point-155)*0.4));
}

int CTwdGetShowTime(CTime m_time)
{
	return CTwdGetHourtoTime(m_time.GetHour());	
}
int CTwdGetShowValue(CTime m_time)
{
	return CTwdGetTimeToValue(CTwdGetShowTime(m_time));
}
