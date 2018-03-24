// EX_ChatDlg.h : header file


#if !defined(AFX_EX_CHATDLG_H__F43FCDD8_DEA9_4024_813E_280F9121C232__INCLUDED_)
#define AFX_EX_CHATDLG_H__F43FCDD8_DEA9_4024_813E_280F9121C232__INCLUDED_

#include "ChatSocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEX_ChatDlg dialog
#include"ChatSocket.h"
class CEX_ChatDlg : public CDialog
{
// Construction
public:
	void Qiequ();
	void DoClose();
	void OnConnect();
	void OnReceive();
	void OnAccept();
	CChatSocket m_asClient;
	CChatSocket m_asServer;
	BOOL m_bServer;
	CEX_ChatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEX_ChatDlg)
	enum { IDD = IDD_EX_CHAT_DIALOG };
	CComboBox	m_comboType;
	CListBox	m_listMsg;
	CString	m_strMsg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEX_ChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEX_ChatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeComboType();
	afx_msg void OnClose();
	afx_msg void OnButtonRun();
	afx_msg void OnButtonSend();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CHATDLG_H__F43FCDD8_DEA9_4024_813E_280F9121C232__INCLUDED_)
