// AnalyzeString.h: interface for the AnalyzeString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANALYZESTRING_H__5F5C26B1_B83F_45DB_92EB_62BE8758BF43__INCLUDED_)
#define AFX_ANALYZESTRING_H__5F5C26B1_B83F_45DB_92EB_62BE8758BF43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AnalyzeString  
{
public:
	AnalyzeString();
	virtual ~AnalyzeString();
	void SetParementValue(void * m_in);
	CString GetZyDayFromInt(int tt, int zt);
	int GetZyDayLastDay(CString m_inStr);
	int GetZyDayFromDay(CString m_inStr);
	CString GetZyDayFromString(CString m_inStr);

private:
	int GetSpsKey(char *input,char *Strout);
	int GetRyDayBegin();
	int SetPosForKey(char **strStart, char **strEnd);
	int GetPosForKey(char *strIn,char * strKey,char **strStart, char **strEnd);
	CTime CheckDate(CString m_Date);
	void * ParentPoint;
	BOOL GetUseString(char *InputStr, char *spit1, char **begin, char **end);
	int SetSPecialValue(char **strIn,char **strOut,void *pstuLcTwDan);
	int SetCurrentDay(char **strIn, char **strOut, void ** pstuLcTwDan);
	int SetTemperatureValue(char **strIn, char **strOut,void * pstuLcTwDan);
	int SetPulse(char **strIn, char **strOut, void *pstuLcTwDan);
	CTime GetRYTime();
	int GetAftDayDisable();
	void * GetCurrentData(char * zyDate, int &nRet);
	int GetZyDayFromTime(CTime m_time1, CTime m_time2,int LogFlg=0);
	int SetHuxi(char **strIn, char **strOut, void *pstuLcTwDan);
	int SetSpecValue(char **strIn, char **strOut, void *pstuLcTwDan);
public:
	int GetAnalyzeValue(char *strIn, char *strZy);
	int SetAnalyzeValue(char **strIn, char **strOut, void **pstuLcTwDan, CString &msgbox);
	int DeleteTwdInfo(char **strIn,char **strOut);
};

#endif // !defined(AFX_ANALYZESTRING_H__5F5C26B1_B83F_45DB_92EB_62BE8758BF43__INCLUDED_)
