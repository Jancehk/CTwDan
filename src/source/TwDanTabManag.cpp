// TwDanTabManag.cpp: implementation of the CTwDanTabManag class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\INCLUDE\ctwdan.h"
#include "..\INCLUDE\TwDanTabManag.h"
#include "..\Include\CLcTwDanCtl.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTwDanTabManag::CTwDanTabManag()
{

}

CTwDanTabManag::~CTwDanTabManag()
{

}

int CTwDanTabManag::SetTemperature(void * pVoid, int sj, int type, int m_value)
{
	pCTWLCDANINFO pstuLcTwDan = (pCTWLCDANINFO)pVoid;
	if (NULL == pstuLcTwDan)
	{
		return -2;
	}
	if (CTWDAN_TIWEN_WULI == type)
	{
		if (0 == pstuLcTwDan->Temperature[sj].Type)
		{
			return -1;
		}
		pstuLcTwDan->Temperature[sj].PhysicsType = type;
		pstuLcTwDan->Temperature[sj].PhysicsValue = (short)m_value;
		return 0;
	}
	else
	{
		pstuLcTwDan->Temperature[sj].TemperatureValue = (short)m_value;
	}
	pstuLcTwDan->Temperature[sj].Type = type;
	pstuLcTwDan->Temperature[sj].Time = sj;
	return 0;
}

int CTwDanTabManag::SetPulse(void * pVoid, int sj, int type, int m_value)
{
	pCTWLCDANINFO pstuLcTwDan = (pCTWLCDANINFO)pVoid;
	if (NULL == pstuLcTwDan)
	{
		return -2;
	}
	pstuLcTwDan->Pulse[sj].Type = type;
	pstuLcTwDan->Pulse[sj].Time = sj;
	pstuLcTwDan->Pulse[sj].CpulseValue = (short)m_value;
	return 0;
}

int CTwDanTabManag::InitSpecial(char *m_zyDate, int CurrentBeginDay)
{
	if (NULL == m_zyDate)
	{
		return -1;
	}
	strcpy(m_ryDate, m_zyDate);
	//	m_SetMinute = SetMinute;
	m_CurrentBeginDay = CurrentBeginDay;
	return 0;
}
int CTwDanTabManag::SetSpecial(void * pVoid, int rq, int sj, int type, double m_value,CRect &m_crect)
{
	int NowDate=0;
	int nRetFlg = 0;
	int m_day1 = 0,m_day2 = 0,OldLeft = 0,OldRight = 0;
	pCTWDANMANAGE pstuTwDanMgr=(pCTWDANMANAGE)pVoid;
	pCTWLCDANINFO pstuLcTwDan= NULL;
	pSPECIAL	  pSpecial = NULL;

	if (NULL == pstuTwDanMgr)
	{
		return -1;
	}
	pstuLcTwDan = &pstuTwDanMgr->stuLcTwDan[rq];
	
	if (NULL == pstuLcTwDan)
	{
		return -1;
	}
	pSpecial = &pstuLcTwDan->Special[sj][0];

	if (CLCTWDAN_RY == type)
	{
		if (0 != memcmp(m_ryDate, pstuLcTwDan->m_ryDate, strlen(pstuLcTwDan->m_ryDate)))
		{
			return 1;
		}
	}
	if (0 < pSpecial->index && type != pSpecial->index)
	{
		pSpecial++;
		nRetFlg =1;
	}
	if (sj== pSpecial->shij)
	{
		m_day2 = pSpecial->Times -CTwdGetValueToTime(sj)+1;
		m_day2 %= 4;
		if (0 != m_day2)
		{
			pSpecial->Times ++;
			if (24 == pSpecial->Times)
			{
				pSpecial->Times = 0;
			}
		}
		else
		{
			pSpecial->Times = CTwdGetValueToTime(sj);
		}
	}
	else
	{
		pSpecial->Times = CTwdGetValueToTime(sj);
	}
	if (0 != pSpecial->m_rq || 0 != pSpecial->shij)
	{
		OldLeft = m_crect.left;
		NowDate=pSpecial->m_rq;
		if ((pSpecial->shij == 5) &&((pSpecial->Times ==0)|| pSpecial->Times ==1|| pSpecial->Times ==22)&& (NowDate>1))
		{
			NowDate--;
		}
		m_crect.left += (NowDate - m_CurrentBeginDay - 1)*84+pSpecial->shij*14;
		//m_crect.left +=14;
		if (m_crect.left >= OldLeft)
		{
			m_crect.top += 7;
			m_crect.bottom = m_crect.top + 250;
			m_crect.right = m_crect.left+14;
		}
	}
	pSpecial->index = type;
	pSpecial->shij=sj;
	pSpecial->m_rq = m_CurrentBeginDay+rq+1;
	pSpecial->Second =(short)m_value;
//	pSpecial->SpecialValue =7;

	return nRetFlg;
}

int CTwDanTabManag::SetSpecialStr(void * pVoid, CTime timeSPecial, int type, short m_value,CRect &m_crect1,CRect &m_crect2)
{
	int m_index=0;
	int m_day1 = 0,m_day2 = 0,OldLeft = 0,OldRight = 0;
	int m_Datarq = 0,m_Datasj = 0;
	pSPACIAL_CTRL_INFO pSpacial_CtrlInfo = NULL;
	pCTWLCDANINFO pstuLcTwDan= (pCTWLCDANINFO)pVoid;
	pSPECIAL	  pSpecial = NULL;
	
	if (NULL == pstuLcTwDan)
	{
		return -1;
	}
	m_Datarq = m_value+1;//nRet+1;
	m_Datasj = CTwdGetShowValue(timeSPecial);
	if (m_Datasj<0 && m_Datasj> CTWNDAN_MAX_COUNT)
	{
		return -1;
	}

	pSpecial = &pstuLcTwDan->Special[m_Datasj][0];

	if (0 < pSpecial->index && type != pSpecial->index)
	{
		pSpecial++;
	}
	if (0 != pSpecial->m_rq)
	{
		m_crect1.left += (pSpecial->m_rq - m_CurrentBeginDay - 1)*84+pSpecial->shij*14;
	}
	pSpecial->index = type;
	pSpecial->m_rq = m_Datarq;
	pSpecial->shij =  CTwdGetShowValue(timeSPecial);
	pSpecial->Times = timeSPecial.GetHour();
	pSpecial->Second = timeSPecial.GetMinute();

	OldLeft = m_crect1.left;
	
	if (0 != pSpecial->m_rq)
	{
		m_crect2.left += (pSpecial->m_rq - m_CurrentBeginDay - 1)*84+pSpecial->shij*14;
	}
	return 0;
}



