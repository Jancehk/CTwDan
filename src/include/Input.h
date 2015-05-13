// Input.h: interface for the Input class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INPUT_H__21794BA1_C9C9_4D7F_B119_9565635FA6AE__INCLUDED_)
#define AFX_INPUT_H__21794BA1_C9C9_4D7F_B119_9565635FA6AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Input  
{
public:
	int GetLen();
	CString RetRes();
	void DelStr(int len);
	void GetStr(char *inc,int len);
	void InsertStr(char * inc,int len);
	void Empty();
	Input();

	virtual ~Input();
private:
	char			strInput[256];			//准备接受的内容
	int				strLen;
};

#endif // !defined(AFX_INPUT_H__21794BA1_C9C9_4D7F_B119_9565635FA6AE__INCLUDED_)
