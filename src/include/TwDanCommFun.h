// TwDanCommFun.h: interface for the CTwDanCommFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TWDANCOMMFUN_H__53821A35_DB4E_4569_ADC6_06AEFDDB3A9E__INCLUDED_)
#define AFX_TWDANCOMMFUN_H__53821A35_DB4E_4569_ADC6_06AEFDDB3A9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTwDanCommFun  
{
public:
	int GetPointPos(int m_PointY, int m_PointX);
	int GetCaretPos_y(int pt);
	int GetCaretPosHx_y(int pt);
	int GetCaretPos_x(int pt);
	int GetCaretPosPress_x(int pt);
	int GetCaretPosHx_x(int pt);
	int OrdinateToTime(int x);
	int OrdinateToDate(int x);
	int OrdinateToTimeMi(int x);
	int OrdinateToDateMi(int x);


	CTwDanCommFun();
	virtual ~CTwDanCommFun();
private:
	int OrdinateToValue(int ptx,int type);
};

#endif // !defined(AFX_TWDANCOMMFUN_H__53821A35_DB4E_4569_ADC6_06AEFDDB3A9E__INCLUDED_)
