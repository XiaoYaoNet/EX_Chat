#if !defined(AFX_CHATSOCKET_H__1056DB2C_D4B3_47F1_A7C3_3305DD86B72B__INCLUDED_)
#define AFX_CHATSOCKET_H__1056DB2C_D4B3_47F1_A7C3_3305DD86B72B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CChatSocket command target

class CEX_ChatDlg;
class CChatSocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CChatSocket();
	virtual ~CChatSocket();

// Overrides
public:
	CEX_ChatDlg *m_pDlg;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CChatSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATSOCKET_H__1056DB2C_D4B3_47F1_A7C3_3305DD86B72B__INCLUDED_)
