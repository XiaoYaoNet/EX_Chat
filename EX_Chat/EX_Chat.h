// EX_Chat.h : main header file for the EX_CHAT application
//

#if !defined(AFX_EX_CHAT_H__19CC0ECB_D528_4EC2_B73E_B8BF9BA2586B__INCLUDED_)
#define AFX_EX_CHAT_H__19CC0ECB_D528_4EC2_B73E_B8BF9BA2586B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEX_ChatApp:
// See EX_Chat.cpp for the implementation of this class
//

class CEX_ChatApp : public CWinApp
{
public:
	CEX_ChatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEX_ChatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEX_ChatApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CHAT_H__19CC0ECB_D528_4EC2_B73E_B8BF9BA2586B__INCLUDED_)
