// TwDanCommFun.cpp: implementation of the CTwDanCommFun class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Include\CLcTwDanCtl.h"
#include "..\INCLUDE\ctwdan.h"
#include "..\INCLUDE\TwDanCommFun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define GET_TWDAN_DATE_MI		1
#define GET_TWDAN_TIME_MI		2
#define GET_TWDAN_TIME			3
#define GET_TWDAN_DATE			4
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTwDanCommFun::CTwDanCommFun()
{

}

CTwDanCommFun::~CTwDanCommFun()
{

}

int CTwDanCommFun::OrdinateToValue(int ptx, int type)
{
	switch(type)
	{
	case GET_TWDAN_DATE_MI:
		return ptx-((ptx-80)%14);
	case GET_TWDAN_TIME_MI:
		return ptx-((ptx-80)%84)+2;
	case GET_TWDAN_TIME:
		return ((ptx-80)/14)-(OrdinateToDate(ptx)*6);
	case GET_TWDAN_DATE:
		return ((ptx-80)/84);
	default:
		break;
	}
	return 0;
}

int CTwDanCommFun::OrdinateToDateMi(int x)
{
	return OrdinateToValue(x,GET_TWDAN_DATE_MI);
}

int CTwDanCommFun::OrdinateToTimeMi(int x)
{
	return OrdinateToValue(x,GET_TWDAN_TIME_MI);
}

int CTwDanCommFun::OrdinateToDate(int x)
{
	return OrdinateToValue(x,GET_TWDAN_DATE);
}

int CTwDanCommFun::OrdinateToTime(int x)
{
	return OrdinateToValue(x,GET_TWDAN_TIME);
}

int CTwDanCommFun::GetCaretPosHx_x(int pt)
{
	return pt-((pt-80)%14)+2;			//以小时坐标取整
}

int CTwDanCommFun::GetCaretPos_x(int pt)
{
	return pt-((pt-80)%84)+2;				//以星期坐标取整
}

int CTwDanCommFun::GetCaretPosPress_x(int pt)
{
	return pt-((pt-80)%42)+2;				//以星期坐标取整
}

int CTwDanCommFun::GetCaretPosHx_y(int pt)
{
	return 586;
}

int CTwDanCommFun::GetCaretPos_y(int pt)
{
	return pt-((pt-585)%20)-2;
}

int CTwDanCommFun::GetPointPos(int m_PointY, int m_PointX)
{
	int nRet = 0;
	
	switch(m_PointY)
	{
	case 586:
		nRet = CTWD_HUXI_POINT;
		break;
	case 603:
		nRet = CTWD_SHITTI_POINT;
		break;
	case 623:
		nRet = CTWD_INFUSE_POINT;
		break;
	case 643:
		nRet = CTWD_URINES_POINT;
		break;
	case 663:
		nRet = CTWD_SPUTUM_POINT;
		break;
	case 683:
		if (124 == m_PointX ||
			208 == m_PointX ||
			292 == m_PointX ||
			376 == m_PointX ||
			460 == m_PointX ||
			522 == m_PointX ||
			628 == m_PointX)
		{
			nRet = CTWD_BPRESS2_POINT;
		}
		else
		{
			nRet = CTWD_BPRESS_POINT;
		}
		break;
	case 703:
		nRet = CTWD_WEIGHT_POINT;
		break;
	default:
		break;
	}
	return nRet;
}
