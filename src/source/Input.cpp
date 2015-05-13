// Input.cpp: implementation of the Input class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "../include/ctwdan.h"
#include "../include/Input.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Input::Input()
{
	Empty();
}

Input::~Input()
{

}

void Input::Empty()
{
	memset(strInput,0,256);
	strLen =0;
}

void Input::InsertStr(char *inc, int len)
{
	strncpy(strInput+strLen,inc,len);
	strLen+=len;
}

void Input::GetStr(char *inc, int len)
{
	int lens;
	if (inc == NULL)
	{
		return;
	}
	memset(inc,0,len);
	lens = len>strLen?strLen:len;
	strncpy(inc,strInput,lens);
	inc[len-1]=0;
}

void Input::DelStr(int len)
{
	char m_inx = 0;
	m_inx = strInput[strLen];
	if ((char)0x80 < m_inx)
	{
		m_inx = 2;
	}
	else
	{
		m_inx = 1;
	}
	memset(strInput+strLen-m_inx,0,(200-(strLen-m_inx)));
	strLen -=m_inx;
	//g_CtwnDanManage.strInput=g_CtwnDanManage.strInput.Left(g_CtwnDanManage.strInput.GetLength()-m_inx);
}

CString Input::RetRes()
{
	return strInput;
}

int Input::GetLen()
{
	return strLen;
}
