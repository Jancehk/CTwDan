#if !defined(AFX_STDAFX_H__1E49E0A0_CDED_479E_9572_329B21B514D9__INCLUDED_)
#define AFX_STDAFX_H__1E49E0A0_CDED_479E_9572_329B21B514D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxctl.h>         // MFC support for ActiveX Controls
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Comon Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

// Delete the two includes below if you do not wish to use the MFC
//  database classes
#include <afxdb.h>			// MFC database classes
#include <afxdao.h>			// MFC DAO database classes
#include <stdlib.H>
//�Զ�����뷽ʽ 
//#pragma comment(linker, "/FILEALIGN:512") 
//#pragma comment (linker, "/ALIGN:512") 

// �Ż�ѡ�� 
//#pragma comment(linker, "/opt:nowin98") 
//#pragma comment(linker, "/opt:ref") 
//#pragma comment (linker, "/OPT:ICF") 
//#pragma comment(linker, "/OPT:noref")
void DLLPrintLog(char * strFormat, ...);
int CTwdGetHourtoTime(int hour);
int CTwdGetTimeToValue(int hour);
int CTwdGetValueToTime(int hour);
int GetMaxNumber(int a,int b);
int GetMinNumber(int a,int b);
int TwToPoint(float fTw);
int MbToPoint(float fTw);
float PointToTw(int point);
float PointToMb(int point);
int CTwdGetShowTime(CTime m_time);
int CTwdGetShowValue(CTime m_time);
// �ϲ����� 
//#pragma comment(linker, "/MERGE:.rdata=.data") 
//#pragma comment(linker, "/MERGE:.text=.data") 
//#pragma comment(linker, "/MERGE:.reloc=.data") 
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__1E49E0A0_CDED_479E_9572_329B21B514D9__INCLUDED_)
