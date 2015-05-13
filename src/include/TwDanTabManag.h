// TwDanTabManag.h: interface for the CTwDanTabManag class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TWDANTABMANAG_H__9AD17419_9620_45EF_888E_7D8C0595B01C__INCLUDED_)
#define AFX_TWDANTABMANAG_H__9AD17419_9620_45EF_888E_7D8C0595B01C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTwDanTabManag  
{
public:
	int InitSpecial(char * m_zyDate, int CurrentBeginDay);
	int SetTemperature(void * pstuLcTwDan, int sj,int type,int m_value);
	int SetPulse(void * pVoid, int sj, int type, int m_value);
	int SetSpecial(void * pVoid, int rq, int sj, int type, double m_value,CRect &m_crect);
	int SetSpecialStr(void * pVoid, CTime timeSPecial, int type, short m_value,CRect &m_crect1,CRect &m_crect2);
	CTwDanTabManag();
	virtual ~CTwDanTabManag();
private:
	char m_ryDate[256];
	//int m_SetMinute;
	int m_CurrentBeginDay;
};

#endif // !defined(AFX_TWDANTABMANAG_H__9AD17419_9620_45EF_888E_7D8C0595B01C__INCLUDED_)
