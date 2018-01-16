#if !defined(AFX_CLCTWDANCTL_H__7227E7DE_34DD_4264_93B3_9D1E0573BD3B__INCLUDED_)
#define AFX_CLCTWDANCTL_H__7227E7DE_34DD_4264_93B3_9D1E0573BD3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CLcTwDanCtl.h : Declaration of the CCLcTwDanCtrl ActiveX Control class.
//		int m_tiwenvalue[6][8];				//����
//		int m_maibovalue[6][3];				//����
#include "Input.h"
#include "TwDanCommFun.h"
#include "TwDanTabManag.h"
#include "AnalyzeString.h"
/////////////////////////////////////////////////////////////////////////////
// CCLcTwDanCtrl : See CLcTwDanCtl.cpp for implementation.
#define CTWDAN_MAX_SECOND			24*60*60
#define SCREEN_HIGHT				720
#define SCREEN_WIGTH				668
#define PSPACEL_SUM					8	//��Ժ ��Ժ ���� ���� ���� ����  ��������
#define PAGE_SUM					7	//һ���м���
#define CTWNDAN_MAX_COUNT			6	//һ���м���ʱ��
#define CTWNDAN_MAX_DATE			12	//  2011-08-21
#define CTWNDAN_MAX_DAY				5	//��������
#define CTWNDAN_MAX_TIME			5	//��ֵ����
#define CTWNDAN_MAX_HUXI			3	//��������
#define CTWNDAN_MAX_TESHUNUM		3	//һ����Сʱ�ڿ��Խ��м������⴦��
#define CTWNDAN_MAX_TESS			CTWNDAN_MAX_TIME+(3)

#define CTWDAN_TIWEN_YEWO			0x01		//Ҹ��
#define CTWDAN_TIWEN_KOUQIANG		0x02		//��ǻ
#define CTWDAN_TIWEN_GANGMEN		0x03		//����
#define CTWDAN_TIWEN_WULI			0x04		//����
#define CTWDAN_MAIBO_XINLV			0x05		//����
#define CTWDAN_MAIBO_MAILV			0x06		//����
#define CTWDAN_TESHU				0x07		//����
#define CTWDAN_DELETE				0x08		//ɾ��

#define CLCTWDAN_RY					0x01		//��Ժ
#define CLCTWDAN_CY					0x02		//��Ժ 
#define CLCTWDAN_CK					0x03		//���� 
#define CLCTWDAN_SS					0x04		//���� 
#define CLCTWDAN_FM					0x05		//���� 
#define CLCTWDAN_SW					0x06		//���� 
#define CLCTWDAN_SO					0x07		//��������
#define CLCTWDAN_QJ					0x08		//��ٽ���
#define CLCTWDAN_QO					0x09		//���
#define CLCTWDAN_ZY					0x0a		//תԺ
#define CLCTWDAN_ZL					0x0b		//�Զ���Ժ
#define CLCTWDAN_FZHX				0x0c		//��������
#define CLCTWDAN_FZHO				0x0d		//ֹͣ��������

#define CTWDAN_DELETE_TW			0x01		//ɾ������
#define CTWDAN_DELETE_MB			0x02		//ɾ������
#define CTWDAN_DELETE_TS			0x03		//ɾ������

#define CTWDAN_INIT					0x00		//����
#define CTWDAN_SELF					0x01		//����ˢ��
#define CTWDAN_PRINT				0x02		//��ӡˢ��

#define CTWDAN_BEGIN_DAYS			0			//��ʼ��������
#define CTWDAN_NULL_ADDRESS			(char *)0x00000010

#define CTWDAN_INSERT				1
#define CTWDAN_MODIFIED				2
#define CTWDAN_NOT_MODIFIED			3


#define CTWD_SHITTI_POINT   1
#define CTWD_INFUSE_POINT   2
#define CTWD_URINES_POINT   3
#define CTWD_SPUTUM_POINT   4
#define CTWD_BPRESS_POINT   5
#define CTWD_WEIGHT_POINT   6
#define CTWD_BPRESS2_POINT  7
#define CTWD_HUXI_POINT		8

#define CTWD_KEYWD_CURRT	0x01		//������ϢS
#define CTWD_KEYWD_TEMPER	0x02		//����T
#define CTWD_KEYWD_PULSE	0x03		//����M
#define CTWD_KEYWD_SPEVAL	0x04		//����H
#define CTWD_KEYWD_SPECIAL	0x05		//����V
#define CTWD_KEYWD_RYINFO	0x06		//סԺ��ϢU
typedef struct _SPACIAL_CTRL_INFO_T
{
	char   index;										//��������
	char   bLjudge;										//�Ƿ�������
	short  ruf;											//�Ƿ�������
	char   strtypeName[28];
}SPACIAL_CTRL_INFO,*pSPACIAL_CTRL_INFO;
typedef struct SPECIAL_T{
	char    index;										//��������
	short	m_rq;										//����
	char	shij;										//�к�
	char	Times;										//Сʱ
	char	nTimeTmp;									//ģ��
	short	Second;
//	short	SpecialValue;
}SPECIAL,*pSPECIAL;
typedef struct CPULSE_T{
	char   Type;
	char   Time;
	short  CpulseValue;
}CPULSE,*pCPULSE;
typedef struct CTEMPERATURE_T{
	char   Type;										//��������
	char   Time;										//ʱ��
	short  TemperatureValue;							//����
	char   PhysicsType;									//����������
	short  PhysicsValue;								//������ֵ
}CTEMPERATURE,*pCTEMPERATURE;
typedef struct CTWLCDANINFO_T{
	char m_ryDate[CTWNDAN_MAX_DATE];					//סԺ����
	char m_zyday[CTWNDAN_MAX_DAY];						//סԺ����
	char m_ssday[CTWNDAN_MAX_DAY];						//��������
	char m_fmday[CTWNDAN_MAX_DAY];						//��������
	char m_shitti[CTWNDAN_MAX_TIME];					//������
	char m_infuse[CTWNDAN_MAX_TIME];					//����Һ��
	char m_urines[CTWNDAN_MAX_TIME];					//����
	char m_sputum[CTWNDAN_MAX_TIME];					//̵��
	char m_bpress[CTWNDAN_MAX_TESS];					//Ѫ    ѹ
	char m_weight[CTWNDAN_MAX_TIME];					//����
	char m_bpress2[CTWNDAN_MAX_TESS];					//Ѫ    ѹ2
	CTEMPERATURE  Temperature[CTWNDAN_MAX_COUNT];		//����
	CPULSE		  Pulse[CTWNDAN_MAX_COUNT];				//����
	char SpecHuxi[CTWNDAN_MAX_COUNT][CTWNDAN_MAX_HUXI];	//����
	SPECIAL	Special[CTWNDAN_MAX_COUNT][CTWNDAN_MAX_TESHUNUM];	//һ������⴦�� ��Ժ����Ժ������
	char m_bIsModified;
}CTWLCDANINFO,*pCTWLCDANINFO;
typedef struct CTWDANMANAGE_T
{
	BOOL			m_pd;
	CPtrArray		m_ptrArray;
	CTWLCDANINFO_T	stuLcTwDan[PAGE_SUM];
	char			bIsPrint;
	CPen			penRed;					//���ߺ��
	CPen			penBule;				//��������
	CPen			penDot;					//���ߺ����
	void			*pTwDandc;
	CDC				*pdc;
	CRect			Bounds;
	CRect			NeiBounds;
	CPoint			twpointFrom;			//���¿�ʼ
	CPoint			mbpointFrom;			//������ʼ
	CPoint			jwpointFrom;			//���¿�ʼ
	int				CurrentBeginDay;		//�����ϵĿ�ʼʱ��
	int				CurrentEndDay;			//�����ϵĽ���ʱ��
	float			SizeLeve;				//��ӡ����
	Input			InputChar;				//׼�����ܵ�����
	CPoint			SolidPoint;				//����λ��
	CTime			CTwDanTime;				//��ǰʱ��;
	float			m_printLevel;
}CTWDANMANAGE,*pCTWDANMANAGE;

static SPACIAL_CTRL_INFO g_Special_Ctrl_Info[]={
	{CLCTWDAN_RY,	1,	1,	_T("��Ժ|")},								//��Ժ
	{CLCTWDAN_CY,	1,	1,	_T("��Ժ|")},								//��Ժ 
	{CLCTWDAN_CK,	0,	1,	_T("ת��|")},								//���� 
	{CLCTWDAN_SS,	0,	1,	_T("����|")},								//���� 
	{CLCTWDAN_FM,	0,	1,	_T("����|")},								//���� 
	{CLCTWDAN_SW,	0,	1,	_T("����|")},								//���� 
	{CLCTWDAN_SO,	0,	1,	_T("��������|")},							//��������
	{ CLCTWDAN_QJ,	0,	1,	_T("���|") },								//���
	{ CLCTWDAN_QO,	0,	1,	_T("��ٽ���|") },							//��ٽ���
	{ CLCTWDAN_ZY,	0,	1,	_T("תԺ|") },								//תԺ
	{ CLCTWDAN_ZL,	0,	1,	_T("�Զ���Ժ|") },							//�Զ���Ժ
	{ CLCTWDAN_FZHX, 2, 1,	_T("��������") },							//��������	
	{ CLCTWDAN_FZHO, 2, 1,	_T("ֹͣ����") },							//ֹͣ����
};

class CCLcTwDanCtrl : public COleControl
{
	DECLARE_DYNCREATE(CCLcTwDanCtrl)

// Constructor//��Ժ ��Ժ ���� ���� ���� ���� ��������
public:
	CCLcTwDanCtrl();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCLcTwDanCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CCLcTwDanCtrl();

	DECLARE_OLECREATE_EX(CCLcTwDanCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CCLcTwDanCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CCLcTwDanCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CCLcTwDanCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CCLcTwDanCtrl)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CCLcTwDanCtrl)
	CString m_SetHospital;
	afx_msg void OnSetHospitalChanged();
	CString m_SetTitleName;
	afx_msg void OnSetTitleNameChanged();
	CString m_SetPatientInfo;
	afx_msg void OnSetPatientInfoChanged();
	CString m_SetPatientRyDate;
	afx_msg void OnSetPatientRyDateChanged();
	short m_SetFS;
	afx_msg void OnSetFSChanged();
	short m_SetTS;
	afx_msg void OnSetTSChanged();
	double m_SetMinute;
	afx_msg void OnSetMinuteChanged();
	CString m_SetCTwDanInfo;
	afx_msg void OnSetCTwDanInfoChanged();
	CString m_GetCTwDanInfo;
	afx_msg void OnGetCTwDanInfoChanged();
	short m_SetTwDanFocus;
	afx_msg void OnSetTwDanFocusChanged();
	short m_setRyDayBegin;
	afx_msg void OnSetRyDayBeginChanged();
	CString SetHospitalFontName;
	afx_msg void OnSetHospitalFontNameChanged();
	short m_SetHospitalFontSize;
	afx_msg void OnSetHospitalFontSizeChanged();
	CString m_SetTitleNameFontName;
	afx_msg void OnSetTitleNameFontNameChanged();
	short m_SetTitleNameFontSize;
	afx_msg void OnSetTitleNameFontSizeChanged();
	CString PrintInfoVer;
	afx_msg void OnPrintInfoVerChanged();
	short m_SetAftDayDisable;
	afx_msg void OnSetAftDayDisableChanged();
	CString GetChageListstr;
	afx_msg void OnGetChageListChanged();
	short m_SetTipShow;
	afx_msg void OnSetTipShowChanged();
	short m_SetShowBeginDays;
	afx_msg void OnSetShowBeginDaysChanged();
	afx_msg void PrintInfo();
	afx_msg void BefDay();
	afx_msg void AftDay();
	afx_msg void BefWeek();
	afx_msg void AftWeek();
	afx_msg void  SaveTmpStorage();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	char input[3];
	bool flg;
	bool point_flg;
// Event maps
	//{{AFX_EVENT(CCLcTwDanCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	CTWDANMANAGE* GetTWDanMgr();
	int SetSPecialValue(CTime timeSPecial,int nTypes, int m_value,void *pstuLcTwDan);
	int GetRyDayBegin();
	int GetAftDayDisable();
	int GetCurrentDay();
	enum {
	//{{AFX_DISP_ID(CCLcTwDanCtrl)
	dispidSetHospital = 1L,
	dispidSetTitleName = 2L,
	dispidSetPatientInfo = 3L,
	dispidSetPatientRyDate = 4L,
	dispidSetFS = 5L,
	dispidSetTS = 6L,
	dispidSetMinute = 7L,
	dispidSetCTwDanInfo = 8L,
	dispidGetCTwDanInfo = 9L,
	dispidSetTwDanFocus = 10L,
	dispidSetRyDayBegin = 11L,
	dispidSetHospitalFontName = 12L,
	dispidSetHospitalFontSize = 13L,
	dispidSetTitleNameFontName = 14L,
	dispidSetTitleNameFontSize = 15L,
	dispidPrintInfoVer = 16L,
	dispidSetAftDayDisable = 17L,
	dispidGetChageList = 18L,
	dispidSetTipShow = 19L,
	dispidSetShowBeginDays = 20L,
	dispidPrintInfo = 21L,
	dispidBefDay = 22L,
	dispidAftDay = 23L,
	dispidBefWeek = 24L,
	dispidAftWeek = 25L,
	dispidSaveTmpStorage = 26L,
	//}}AFX_DISP_ID
	};
public:
	void *GetSpecialInfo(int inrq,int insj,int intm);
	void *GetSpecialTypeInfo(int m_Type,int *inrq=NULL,int *insj=NULL,int *intm=NULL);
private:
	int AnalyzeInString(char *input);
	CString GetShowMsg(int rq, int sj);
	CString GetOtherAllValue(char * m_rydate,int type);
	CString GetSpacileValue(char * m_rydate= NULL);
	void ShowImageAGEEx(int IDB_NULL,CPoint point,int m_whit);
	void ShowImageAGE(int IDB_NULL,CPoint point,int m_whit);
	int GetBeginDay(char * m_zydatetemp);
	int SaveTmpStorageTemp();
	void SaveTeShuInStuct();
	void ShowData();
	void UpdateInfo();
	CString GetSsFmDay(char* ssday, char* fmday);
	CString GetTeShu(int innum);
	CString GetNumber(int innum, int zt);
	void * GetSpaceCtrlInfo(int m_Teshu);
	void ShowTeshu(pSPECIAL	pSpecial, int indexrq, int indexsj,int indextime);
	
	int CmpTeshu(int inPut, int Value);
	void SetZyDaySsDayLcDay(int m_Type);
	CTime CheckDate(CString m_Date);
	void ShowVerticalFont(CPoint point,CString m_str,float m_printLevel, int types);
	int GetRightPos(int m_rq, int m_sj, int types);
	int GetLeftPos(int m_rq, int m_sj,int types);
	int GetTopPos(int m_rq, int m_sj, CRect &m_crect, int types);
	void ShowTWDLine(CPoint point,float m_printLevel,int types);
	int CheckSpecialType(int type);
	void SetSpecial(int Date,int Time);
	void ShowImage(int IDB_NULL,pCPULSE pTmpValue,int Date, float m_printLevel,int types);
	void ShowTiWenInfo();
	CString GetSpace(CString m_str);
	CString GetSpace2(CString m_str);
	void ShowValueInfo();
	CString GetZyDayFromInt(int tt, int zt);
	void CtwDanMemSet();
	CRect m_ScreenSize;
	int GetResult(int m_value, double m_level);
	void OnPrintInfo(CDC *pdc,CRect rcBounds);
	void OnPrintLogInfo(CDC *pdc,CRect rcBounds);
	int GetPageInfo(int type);
	short g_SetRyDayBegin;
	short g_SetAftDayDisable;
	CTwDanCommFun	m_Fun;
	CTwDanTabManag	m_Tabmgr;
	AnalyzeString	m_AnlStr;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLCTWDANCTL_H__7227E7DE_34DD_4264_93B3_9D1E0573BD3B__INCLUDED)
/************************************************************************/
/*      
  typedef struct CTWLCDANINFO_T{
		CString m_ryDate;		//סԺ����
		CString m_zyday;		//סԺ����
		CString m_ckday;		//��������
		CString m_ssday;		//��������
		CString m_fmday;		//��������
		CString m_swday;		//��������
		CString m_cyday;		//��Ժ����
		CString m_shittime;		//������
		CString m_infuse;		//����Һ��
		CString m_urine;		//����
		CString m_sputum;		//̵��
		CString m_bpress;		//Ѫ    ѹ
		CString m_weight;		//����
		int m_tiwenvalue[6][8];	//����
		int m_maibovalue[6][3];	//����
		char m_huxi[6][8];		//����
		}CTWLCDANINFO,*pCTWLCDANINFO;
		//		char m_ckday[CTWNDAN_MAX_DAY];						//��������
		//		char m_swday[CTWNDAN_MAX_DAY];						//��������
//		char m_cyday[CTWNDAN_MAX_DAY];						//��Ժ����
***********************************************************************/
