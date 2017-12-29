// AnalyzeString.cpp: implementation of the AnalyzeString class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\INCLUDE\ctwdan.h"
#include "..\INCLUDE\AnalyzeString.h"
#include "..\INCLUDE\CLcTwDanCtl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AnalyzeString::AnalyzeString()
{
	ParentPoint = NULL;
}

AnalyzeString::~AnalyzeString()
{

}

void AnalyzeString::SetParementValue(void * m_in)
{
	ParentPoint = m_in;
}

int AnalyzeString::GetRyDayBegin()
{
	CCLcTwDanCtrl *parents = (CCLcTwDanCtrl *)ParentPoint;
	if (NULL == parents)
	{
		return 0;
	}
	return parents->GetRyDayBegin();
}

CTime AnalyzeString::GetRYTime()
{
	CTWDANMANAGE* pCtwnDanManage =NULL;
	CCLcTwDanCtrl *parents = (CCLcTwDanCtrl *)ParentPoint;
	
	if (NULL == parents)
	{
		return 0;
	}
	pCtwnDanManage = parents->GetTWDanMgr();
	return pCtwnDanManage->CTwDanTime;
}
int AnalyzeString::GetAftDayDisable()
{
	
	CTWDANMANAGE* pCtwnDanManage =NULL;
	CCLcTwDanCtrl *parents = (CCLcTwDanCtrl *)ParentPoint;
	
	if (NULL == parents)
	{
		return 0;
	}
	return parents->GetAftDayDisable();
}
CTime AnalyzeString::CheckDate(CString m_Date)
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

int AnalyzeString::GetZyDayFromTime(CTime m_time1, CTime m_time2,int LogFlg)
{
	CTimeSpan times1;
	CTime time1,time2,time3;
	CString aaa;
	
	time1 = CTime::CTime(m_time1.GetYear(),m_time1.GetMonth(),m_time1.GetDay(),0,0,0);
	time2 = CTime::CTime(m_time2.GetYear(),m_time2.GetMonth(),m_time2.GetDay(),0,0,0);
	times1 = time1 - time2; //InputDate - ryDate
	if (times1 < 0)
	{
		aaa.Format("Currt:%s\nRyDat:%s\nTime:%d",time1.Format("%Y-%m-%d %H:%M:%S"),time2.Format("%Y-%m-%d %H:%M:%S"),times1);
		goto ERR_EXIT;
	}
	return (int)times1.GetDays();
ERR_EXIT:
	if (0 == LogFlg)
	{
		AfxMessageBox(aaa);
	}
	return -1;
}

CString AnalyzeString::GetZyDayFromInt(int m_day, int zt)
{
	CString m_zydays;
	int pos=0,day=0,moth=0,year=0;
	CTime time;
	CTime tis=CTime::GetCurrentTime();
	tis = CTime::CTime(tis.GetYear(),tis.GetMonth(),tis.GetDay(),23, 59,59);
	time=GetRYTime()+m_day*CTWDAN_MAX_SECOND;//86400;
	m_zydays.Empty();
	if (zt==1){m_zydays=time.Format("%Y-%m-%d");}
	else if (zt==2)
	{
		if (time>tis)
		{
			return "";
		}
		m_day = m_day - GetRyDayBegin()+1;
		if (m_day > 0 )
		{
			m_zydays.Format(_T("%d"),m_day);
		}
		else
		{
			m_zydays.Empty();
		}
	}
	else if (zt==3)
	{
		if (time>tis)
		{
			return "";
		}
		m_day = m_day+1;
		if (m_day > 0 )
		{
			m_zydays.Format(_T("%d"),m_day);
		}
		else
		{
			m_zydays.Empty();
		}
	}
	return m_zydays;
	
}

int AnalyzeString::GetZyDayLastDay(CString m_inStr)
{
	return GetZyDayFromTime(CTime::GetCurrentTime(), CheckDate(m_inStr),1);
}

int AnalyzeString::GetZyDayFromDay(CString m_inStr)
{
	return GetZyDayFromTime(CheckDate(m_inStr),GetRYTime());
}
CString AnalyzeString::GetZyDayFromString(CString m_inStr)
{
	CTime time;
	CString m_str;
	m_str.Format(_T("%d"),GetZyDayFromDay(m_inStr));
	return m_str;
}

BOOL AnalyzeString::GetUseString(char *InputStr, char *spit1, char **begin, char **end)
{
	BOOL bIsExit = FALSE;
	char * key = NULL;
	key = strstr(InputStr, "[");
	if (NULL == key)
	{
		goto END_PROC;
	}
	*begin = strstr(InputStr, spit1);
	if (NULL == *begin)
	{
		goto END_PROC;
	}
	if (key != *begin+strlen("["))
	{
		goto END_PROC;
	}
	*begin += strlen(spit1);
	if (CTWDAN_NULL_ADDRESS > *begin)
	{
		goto CEXIT;
	}
	*end = strstr(*begin, "]");
	if (CTWDAN_NULL_ADDRESS > *end)
	{
		goto CEXIT;
	}
	**end = 0;
	bIsExit = TRUE;
	goto CEXIT;
END_PROC:
	*end = NULL;
	*begin = NULL;
	bIsExit = TRUE;
CEXIT:
	if (!bIsExit)
	{
		*begin = NULL;
		*end = NULL;
	}
	return bIsExit;
}

int AnalyzeString::GetPosForKey(char *strIn, char *strKey, char **strStart, char **strEnd)
{
	if (NULL == strIn)
	{
		return -1;
	}
	if (!GetUseString(strIn, strKey, strStart, strEnd))
	{
		return -2;
	}
	if ((NULL == strStart && NULL != strEnd) ||
		(NULL != strStart && NULL == strEnd))
	{
		return -2;
	}
	return 0;
}


int AnalyzeString::SetPosForKey(char **strStart, char **strEnd)
{
	if (NULL == strStart || NULL == strEnd)
	{
		return -1;
	}
	**strEnd = ']';
	*strStart = *strEnd;
	*strStart += strlen("]");
	return 0;
}
void * AnalyzeString::GetCurrentData(char *zyDate, int &nRet)
{
	pCTWLCDANINFO m_CtwDanInfo = NULL;
	int m_index = 0,m_arrCount =0;
	char m_ryDate[CTWNDAN_MAX_DATE] ={0};
	CTWDANMANAGE* pCtwnDanManage =NULL;
	CCLcTwDanCtrl *parents = (CCLcTwDanCtrl *)ParentPoint;

	if (NULL == parents)
	{
		nRet = -1;
		return NULL;
	}
	pCtwnDanManage = parents->GetTWDanMgr();
	if (NULL == pCtwnDanManage)
	{
		nRet = -2;
		return NULL;
	}
	m_arrCount = pCtwnDanManage->m_ptrArray.GetSize();
	//if (0 == g_CtwnDanManage.Special[0].Date || 0 == zyDate[0])
	if (0 == zyDate[0])
	{
		nRet = -3;
		return NULL;
	}
	for (m_index =0; m_index<m_arrCount; m_index++)
	{
		m_CtwDanInfo = (pCTWLCDANINFO)pCtwnDanManage->m_ptrArray.GetAt(m_index);
		if (0 == memcmp(zyDate,m_CtwDanInfo->m_ryDate,strlen(m_CtwDanInfo->m_ryDate)))
		{
			//MessageBox(m_CtwDanInfo->m_ryDate);
			nRet = -4;
			return m_CtwDanInfo;
		}
	}
	m_arrCount = atoi((const char *)GetZyDayFromString(zyDate).GetBuffer(0));
	for (m_index;m_index<=m_arrCount ;m_index++)
	{
		m_CtwDanInfo = (pCTWLCDANINFO)calloc(1,sizeof(CTWLCDANINFO));
		memcpy(m_CtwDanInfo->m_ryDate, GetZyDayFromInt(m_index,1).GetBuffer(CTWNDAN_MAX_DATE), CTWNDAN_MAX_DATE);
		m_CtwDanInfo->m_ryDate[CTWNDAN_MAX_DATE] = 0;
		memcpy(m_CtwDanInfo->m_zyday, GetZyDayFromInt(m_index,2).GetBuffer(CTWNDAN_MAX_DAY), CTWNDAN_MAX_DAY);
		m_CtwDanInfo->m_zyday[CTWNDAN_MAX_DAY] = 0;
		pCtwnDanManage->m_ptrArray.Add(m_CtwDanInfo);
		m_CtwDanInfo->m_bIsModified = CTWDAN_INSERT;
		if (0 == memcmp(zyDate,m_CtwDanInfo->m_ryDate,strlen(m_CtwDanInfo->m_ryDate)))
		{
			nRet = -5;
			return m_CtwDanInfo;
		}
	}
	nRet = -6;
	return NULL;
}

int AnalyzeString::DeleteTwdInfo(char **strIn, char **strOut)
{
	CTime timeSPecial;
	int nRet = 0;
	int nTime = 0;
	int nType = 0;
	pCTWLCDANINFO pstuLcTwDan = NULL;

	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	if (NULL == strIn)
	{
		nRet = -1;
		goto ERR_EXIT;
	}
	if (GetPosForKey(*strIn,"D[",&FindBegPos,&FindEndPos))
	{
		nRet = -2;
		goto ERR_EXIT;
	}
	if (NULL == FindBegPos)
	{
		nRet = 1;
		goto ERR_EXIT;
	}
	BegPos = strstr(FindBegPos, ",");
	if (BegPos < CTWDAN_NULL_ADDRESS)
	{
		nRet = -1;
		goto END_EXIT;
	}
	*BegPos =0;
	pstuLcTwDan = (pCTWLCDANINFO)GetCurrentData(FindBegPos,nRet);
	if (NULL == pstuLcTwDan)
	{
		//	bIsExit = FALSE;
		//msgbox.Format(_T("错误号:2%0.4d 不能删除改天内容"),__LINE__);
		//nRet = 0;
		goto END_EXIT;
	}
	timeSPecial = CheckDate(FindBegPos);
	*BegPos = ',';
	if (GetRYTime() == 0 || timeSPecial ==0)
	{
		nRet = 0;
		goto END_EXIT;
	}
	nTime = CTwdGetShowValue(timeSPecial);
	if (nTime <0 || nTime >6)
	{
		nRet = 0;
		goto END_EXIT;
	}
	FindBegPos = BegPos+strlen(",");
	BegPos = strstr(FindBegPos, ";");
	if (BegPos < CTWDAN_NULL_ADDRESS)
	{
		nRet = 0;
		goto END_EXIT;
	}
	*BegPos =0;
	nType = atoi(FindBegPos);
	*BegPos = ';';
	
	if (0 != nType)
	{
		if (nType >= CTWDAN_TIWEN_YEWO && CTWDAN_TIWEN_GANGMEN <= nType)
		{
			nType = CTWDAN_DELETE_TW;
		}
		else if (nType >= CTWDAN_MAIBO_XINLV && CTWDAN_MAIBO_MAILV <= nType)
		{
			nType = CTWDAN_DELETE_MB;
		}
		else if (CTWDAN_TESHU == nType)
		{
			nType = CTWDAN_DELETE_TS;
		}
		else
		{
			nRet = 0;
			goto END_EXIT;
		}
	}
	else
	{
		nRet = 0;
		goto END_EXIT;
	}
	switch(nType)
	{
	case CTWDAN_DELETE_TW:
		pstuLcTwDan->Temperature[nTime].Type =0;
		memset(&pstuLcTwDan->Temperature[nTime], 0, sizeof(CTEMPERATURE));
		break;
	case CTWDAN_DELETE_MB:
		pstuLcTwDan->Pulse[nTime].Type =0;
		memset(&pstuLcTwDan->Pulse[nTime], 0, sizeof(CPULSE));
		break;
	case CTWDAN_DELETE_TS:
		pstuLcTwDan->Temperature[nTime].PhysicsType = 0;
		pstuLcTwDan->Temperature[nTime].PhysicsValue =0;
	default:
		break;
	}
END_EXIT:
	*strOut = FindEndPos;
	return SetPosForKey(strIn,strOut);
ERR_EXIT:
	return nRet;
}


//U[2011-11-03 16:28:40,1;2011-11-03 16:28:40,2;]
int AnalyzeString::SetSPecialValue(char **strIn, char **strOut,void *pstuLcTwDan)
{
	int nRet = 0,nType =0;
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	CTime m_time = 0;
	//CTWDANMANAGE* pCtwnDanManage =NULL;
	pSPECIAL pSpecialInfo = NULL;
	CCLcTwDanCtrl *parents = (CCLcTwDanCtrl *)ParentPoint;

	if (NULL == strIn)
	{
		nRet = -1;
		goto END_EXIT;
	}
	
	if (NULL == parents)
	{
		nRet = -2;
		goto END_EXIT;
	}
	if (NULL == strIn || NULL == strOut)
	{
		nRet =-3;
		goto END_EXIT;
	}
	FindBegPos = *strIn;
	FindEndPos = *strOut;

	BegPos = strstr(FindBegPos, ",");
	if (BegPos < CTWDAN_NULL_ADDRESS)
	{
		nRet =-4;
		goto END_EXIT;
	}
	*BegPos =0;
	m_time = CheckDate(FindBegPos);
	*BegPos = ',';

	FindBegPos = BegPos+strlen(",");
	BegPos = strstr(FindBegPos, ";");
	if (NULL != BegPos)
	{
		*BegPos =0;
	}
	nType = atoi(FindBegPos);
	if (NULL != BegPos)
	{
		*BegPos = ';';
	}
	
	if (CLCTWDAN_RY > nType || CLCTWDAN_SO < nType)
	{
		nRet =-5;
		goto END_EXIT;
	}
	nRet = GetZyDayFromTime(m_time,GetRYTime());
	if (CLCTWDAN_RY == nType && 0 != nRet)
	{
		nRet =-7;
		goto END_EXIT;
	}
	nRet = parents->SetSPecialValue(m_time,nType,nRet,pstuLcTwDan);
	if (0 != nRet)
	{
		nRet = 11;
	}
	*strIn = FindBegPos ;
	*strOut = FindEndPos;
END_EXIT:
	return nRet ;
}

int AnalyzeString::GetAnalyzeValue(char *strIn, char *strZy)
{
	int type = -1;
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	if (GetUseString(strIn,"G[",&FindBegPos,&FindEndPos))
	{
		BegPos = strstr(FindBegPos, ",");
		*BegPos = 0;
		memcpy(strZy, FindBegPos,BegPos - FindBegPos);
		*BegPos = ',';
		
		FindBegPos = BegPos +strlen(",");
		BegPos = strstr(FindBegPos, ";");
		*BegPos = 0;
		type = atoi(FindBegPos);
		*BegPos = ';';
	}
	return type;
}

	//S[2011-11-03]
int AnalyzeString::SetCurrentDay(char **strIn, char **strOut,void ** pstuLcTwDan)
{
	int nRet = 0;
	int nLastDay = -1;
	int nAftDayDisable = 0;
	pCTWLCDANINFO m_CtwDanInfo = NULL;
	char m_ryDate[CTWNDAN_MAX_DATE*2]={0};
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;

	if (NULL == strIn || NULL == strOut)
	{
		nRet =-1;
		goto END_EXIT;
	}
	FindBegPos = *strIn;
	FindEndPos = *strOut;	
	memcpy(m_ryDate, FindBegPos,FindEndPos - FindBegPos);
	m_ryDate[CTWNDAN_MAX_DATE*2-1]=0;
	m_CtwDanInfo = (pCTWLCDANINFO)GetCurrentData(m_ryDate,nRet);
	if (NULL == m_CtwDanInfo)
	{
		nRet =-2;
		goto END_EXIT;
	}
	//日期
	nLastDay = GetZyDayLastDay(m_CtwDanInfo->m_ryDate);
	if (0 > nLastDay)
	{
		/*如果当前日期记录为空,则停止所有的操作*/
		nRet =-3;
		goto END_EXIT;
	}
/*	nAftDayDisable = GetAftDayDisable();
	if (0 != nAftDayDisable)
	{
		if ( nAftDayDisable < nLastDay)
		{
			nRet =-4;
			goto END_EXIT;
		}
	}*/
	*pstuLcTwDan = m_CtwDanInfo;
	*strIn = FindBegPos ;
	*strOut = FindEndPos;
	nRet = 10;
END_EXIT:
	return nRet ;
}

int AnalyzeString::SetTemperatureValue(char **strIn, char **strOut, void *pstuLcTwDan)
{
	pCTWLCDANINFO m_CtwDanInfo = NULL;
	int nRet =0;
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	int nTime=-1,nType=-1,nTemperature=-1,nPhysicsValue=-1;
	if (NULL == pstuLcTwDan)
	{
		nRet =-3;
		goto CEXIT;
	}
	if (NULL == strIn || NULL == strOut)
	{
		nRet =-1;
		goto CEXIT;
	}
	FindBegPos = *strIn;
	FindEndPos = *strOut;
	m_CtwDanInfo = (pCTWLCDANINFO)pstuLcTwDan;
	while (NULL != FindBegPos && 0 != *FindBegPos)
	{
		BegPos = strstr(FindBegPos, ",");
		*BegPos =0;
		nTime = atoi(FindBegPos)-1;
		*BegPos =',';
		if (nTime<0 || nTime>CTWNDAN_MAX_COUNT)
		{
			//msgbox.Format(_T("错误号:202 时间不在允许的凡内之内"));
			nRet =-1;
			goto CEXIT;
		}
		FindBegPos = BegPos+strlen(",");
		BegPos = strstr(FindBegPos, ",");
		*BegPos =0;
		nType = atoi(FindBegPos);
		*BegPos =',';
		if (nType<CTWDAN_TIWEN_YEWO || nType>CTWDAN_TIWEN_GANGMEN)
		{
			//msgbox.Format(_T("错误号:203 请选择体温方式"));
			nRet =-1;
			goto CEXIT;
		}
		
		FindBegPos = BegPos+strlen(",");
		BegPos = strstr(FindBegPos, ",");
		*BegPos =0;
		nTemperature = TwToPoint((float)atof(FindBegPos));
		*BegPos =',';
		FindBegPos = BegPos+strlen(",");
		BegPos = strstr(FindBegPos, ";");
		*BegPos =0;
		nPhysicsValue = TwToPoint((float)atof(FindBegPos));
		*BegPos =';';
		
		m_CtwDanInfo->Temperature[nTime].Time = nTime;
		m_CtwDanInfo->Temperature[nTime].Type = nType;
		m_CtwDanInfo->Temperature[nTime].TemperatureValue = nTemperature;
		if (0 != nPhysicsValue && nPhysicsValue < nTemperature)
		{
			m_CtwDanInfo->Temperature[nTime].PhysicsType = CTWDAN_TIWEN_WULI;
		}
		if (BegPos == FindEndPos)
		{
			break;
		}
		FindBegPos = BegPos+strlen(";");
	}
	*strIn = FindBegPos ;
	*strOut = FindEndPos;
CEXIT:
	return nRet;
}
//M[1,4,20;2,4,20;3,4,20;4,4,20;5,4,20;6,4,20]
int AnalyzeString::SetPulse(char **strIn, char **strOut, void *pstuLcTwDan)
{
	pCTWLCDANINFO m_CtwDanInfo = NULL;
	int nRet =0;
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	int nTime=-1,nType=-1,nCpulseValue=-1;
	if (NULL == pstuLcTwDan)
	{
		nRet =-3;
		goto CEXIT;
	}
	if (NULL == strIn || NULL == strOut)
	{
		nRet =-1;
		goto CEXIT;
	}
	FindBegPos = *strIn;
	FindEndPos = *strOut;
	
	m_CtwDanInfo = (pCTWLCDANINFO)pstuLcTwDan;
	while (NULL != FindBegPos && 0 != *FindBegPos)
	{
		BegPos = strstr(FindBegPos, ",");
		*BegPos =0;
		nTime = atoi(FindBegPos)-1;
		*BegPos =',';
		if (nTime<0 || nTime>CTWNDAN_MAX_COUNT)
		{
			//msgbox.Format(_T("错误号:202 时间不在允许的凡内之内"));
			nRet =-1;
			goto CEXIT;
		}
		FindBegPos = BegPos+strlen(",");
		BegPos = strstr(FindBegPos, ",");
		*BegPos =0;
		nType = atoi(FindBegPos);
		*BegPos =',';
		if (nType<CTWDAN_MAIBO_XINLV || nType>CTWDAN_MAIBO_MAILV)
		{
			//msgbox.Format(_T("错误号:203 请选择体温方式"));
			nRet =-1;
			goto CEXIT;
		}
		
		FindBegPos = BegPos+strlen(",");
		BegPos = strstr(FindBegPos, ";");
		*BegPos =0;
		nCpulseValue = MbToPoint((float)atoi(FindBegPos));
		*BegPos =';';
		if (nCpulseValue == 0)
		{
			nRet =-1;
			goto CEXIT;
		}
		m_CtwDanInfo->Pulse[nTime].Time = nTime;
		m_CtwDanInfo->Pulse[nTime].Type = nType;
		m_CtwDanInfo->Pulse[nTime].CpulseValue = nCpulseValue;

		if (BegPos == FindEndPos)
		{
			break;
		}
		FindBegPos = BegPos+strlen(";");
	}
	*strIn = FindBegPos ;
	*strOut = FindEndPos;
CEXIT:
	return nRet;
}
//H[1,20;2,20;3,20;4,20;5,20;6,20]
int AnalyzeString::SetHuxi(char **strIn, char **strOut, void *pstuLcTwDan)
{
	pCTWLCDANINFO m_CtwDanInfo = NULL;
	int nRet =0;
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	int nTime=-1,nType=-1;
	char m_huxi[CTWNDAN_MAX_HUXI] = {0};
	if (NULL == pstuLcTwDan)
	{
		nRet =-3;
		goto CEXIT;
	}
	if (NULL == strIn || NULL == strOut)
	{
		nRet =-1;
		goto CEXIT;
	}
	FindBegPos = *strIn;
	FindEndPos = *strOut;
	
	m_CtwDanInfo = (pCTWLCDANINFO)pstuLcTwDan;
	while (NULL != FindBegPos && 0 != *FindBegPos)
	{
		BegPos = strstr(FindBegPos, ",");
		*BegPos =0;
		nTime = atoi(FindBegPos)-1;
		*BegPos =',';
		if (nTime<0 || nTime>CTWNDAN_MAX_COUNT)
		{
			//msgbox.Format(_T("错误号:202 时间不在允许的凡内之内"));
			nRet =-1;
			goto CEXIT;
		}
		FindBegPos = BegPos+strlen(",");
		BegPos = strstr(FindBegPos, ";");
		*BegPos =0;
		memcpy(&m_CtwDanInfo->SpecHuxi[nTime],FindBegPos,CTWNDAN_MAX_HUXI);
		*BegPos =';';

		if (BegPos == FindEndPos)
		{
			break;
		}
		FindBegPos = BegPos+strlen(",");
	}
	*strIn = FindBegPos ;
	*strOut = FindEndPos;
CEXIT:
	return nRet;
}

int AnalyzeString::SetSpecValue(char **strIn, char **strOut, void *pstuLcTwDan)
{
	pCTWLCDANINFO m_CtwDanInfo = NULL;
	int nRet =0;
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	int nType=-1;
	char m_huxi[CTWNDAN_MAX_HUXI] = {0};
	if (NULL == pstuLcTwDan)
	{
		nRet =-3;
		goto CEXIT;
	}
	if (NULL == strIn || NULL == strOut)
	{
		nRet =-1;
		goto CEXIT;
	}
	FindBegPos = *strIn;
	FindEndPos = *strOut;
	
	m_CtwDanInfo = (pCTWLCDANINFO)pstuLcTwDan;
	while (NULL != FindBegPos && 0 != *FindBegPos)
	{
		BegPos = strstr(FindBegPos, ",");
		*BegPos =0;
		nType = atoi(FindBegPos);
		*BegPos =',';

		FindBegPos = BegPos+strlen(",");
		BegPos = strstr(FindBegPos, ";");
		*BegPos =0;
		switch(nType)
		{
		case CTWD_SHITTI_POINT:
			memcpy(m_CtwDanInfo->m_shitti,FindBegPos,CTWNDAN_MAX_TIME);
			break;
		case CTWD_INFUSE_POINT:
			memcpy(m_CtwDanInfo->m_infuse,FindBegPos,CTWNDAN_MAX_TIME);
			break;
		case CTWD_URINES_POINT:
			memcpy(m_CtwDanInfo->m_urines,FindBegPos,CTWNDAN_MAX_TIME);
			break;
		case CTWD_SPUTUM_POINT:
			memcpy(m_CtwDanInfo->m_sputum,FindBegPos,CTWNDAN_MAX_TIME);
			break;
		case CTWD_BPRESS_POINT:
			memcpy(m_CtwDanInfo->m_bpress,FindBegPos,CTWNDAN_MAX_TESS);
			break;
		case CTWD_BPRESS2_POINT:
			memcpy(m_CtwDanInfo->m_bpress2,FindBegPos,CTWNDAN_MAX_TESS);
			break;
		case CTWD_WEIGHT_POINT:
			memcpy(m_CtwDanInfo->m_weight,FindBegPos,CTWNDAN_MAX_TIME);
			break;
		default:
			//msgbox.Format(_T("错误号:202 时间不在允许的凡内之内"));
			nRet =-3;
			goto CEXIT;
			break;
		}
		*BegPos =';';
		
		if (BegPos == FindEndPos)
		{
			break;
		}
		FindBegPos = BegPos+strlen(";");
	}
	*strIn = FindBegPos ;
	*strOut = FindEndPos;
CEXIT:
	return nRet;
}


int AnalyzeString::GetSpsKey(char *input,char *Strout)
{
	int nType = 0;
	if (NULL == Strout|| NULL == input)
	{
		return -1;
	}
	Strout[0] = 0;
	switch (input[0])
	{
	case 'S':			//体温
		strcpy(Strout,"S[");
		nType = CTWD_KEYWD_CURRT;
		break;
	case 'T':			//体温
		strcpy(Strout,"T[");
		nType = CTWD_KEYWD_TEMPER;
		break;
	case 'M':			//脉搏
		strcpy(Strout,"M[");
		nType = CTWD_KEYWD_PULSE;
		break;
	case 'H':			//呼吸
		strcpy(Strout,"H[");
		nType = CTWD_KEYWD_SPEVAL;
		break;
	case 'V':			//特殊
		strcpy(Strout,"V[");
		nType = CTWD_KEYWD_SPECIAL;
		break;
	case 'U':
		strcpy(Strout,"U[");
		nType = CTWD_KEYWD_RYINFO;
		break;
	}
	if (0 != nType)
	{
		return nType;
	}
	return -2;		//其他
}

int AnalyzeString::SetAnalyzeValue(char **strIn, char **strOut, void **pstuLcTwDan, CString &msgbox)
{
	pCTWLCDANINFO m_CtwDanInfo = NULL;
	int nRet =0;
	char * FindBegPos = NULL, * FindEndPos = NULL,* BegPos = NULL;
	int nTime=-1,nType=-1,nKeyType = 0;
	char m_keyWd[20] = {0};
	char m_huxi[CTWNDAN_MAX_HUXI] = {0};

	if (NULL == strIn)
	{
		nRet =-1;
		goto ERR_EXIT;
	}
	nKeyType = GetSpsKey(*strIn,m_keyWd);
	if (0 > nKeyType)
	{
		nRet =nKeyType;
		goto ERR_EXIT;
	}
	if (GetPosForKey(*strIn,m_keyWd,&FindBegPos,&FindEndPos))
	{
		nRet =-2;
		goto CEXIT;
	}
	if (NULL == FindBegPos)
	{
		nRet =1;
		goto ERR_EXIT;
	}
	
	switch(nKeyType)
	{
	case CTWD_KEYWD_TEMPER:		//体温T
	case CTWD_KEYWD_PULSE:		//脉搏M
	case CTWD_KEYWD_SPEVAL:		//呼吸H
	case CTWD_KEYWD_SPECIAL:	//特殊V
	case CTWD_KEYWD_RYINFO:		//住院信息U
		if (NULL == pstuLcTwDan)
		{
			nRet =-12;
			goto ERR_EXIT;
		}
		break;
	default:
		break;
	}
	switch(nKeyType)
	{
	case CTWD_KEYWD_CURRT://当天信息S
		nRet = SetCurrentDay(&FindBegPos,&FindEndPos,pstuLcTwDan);
		break;
	case CTWD_KEYWD_TEMPER:		//体温T
		nRet = SetTemperatureValue(&FindBegPos,&FindEndPos,*pstuLcTwDan);
		break;
	case CTWD_KEYWD_PULSE:		//脉搏M
		nRet = SetPulse(&FindBegPos,&FindEndPos,*pstuLcTwDan);
		break;
	case CTWD_KEYWD_SPEVAL:		//呼吸H
		nRet = SetHuxi(&FindBegPos,&FindEndPos,*pstuLcTwDan);
		break;
	case CTWD_KEYWD_SPECIAL:	//特殊V
		nRet = SetSpecValue(&FindBegPos,&FindEndPos,*pstuLcTwDan);
		break;
	case CTWD_KEYWD_RYINFO:		//住院信息U
		nRet = SetSPecialValue(&FindBegPos,&FindEndPos,*pstuLcTwDan);
		break;
	default:
		break;
	}
	if (0 != nRet && 10 != nRet && 11 != nRet)
	{
		msgbox.Format(_T("DO:%d,Ret:%d"),nKeyType,nRet);
	}
CEXIT:
	*strOut = FindEndPos;
	SetPosForKey(strIn,strOut);
	return nRet;
ERR_EXIT:
	if (0 != nRet && 10 != nRet && 11 != nRet)
	{
		msgbox.Format(_T("system error Ret:%d"),nRet);
	}
	goto CEXIT;

}
