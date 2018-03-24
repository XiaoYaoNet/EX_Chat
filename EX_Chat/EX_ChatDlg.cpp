// EX_ChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EX_Chat.h"
#include "EX_ChatDlg.h"
#include "fstream.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEX_ChatDlg dialog

CEX_ChatDlg::CEX_ChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEX_ChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEX_ChatDlg)
	m_strMsg = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEX_ChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEX_ChatDlg)
	DDX_Control(pDX, IDC_COMBO_TYPE, m_comboType);
	DDX_Control(pDX, IDC_LIST_MSG, m_listMsg);
	DDX_Text(pDX, IDC_EDIT_MSG, m_strMsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEX_ChatDlg, CDialog)
	//{{AFX_MSG_MAP(CEX_ChatDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_TYPE, OnSelchangeComboType)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_RUN, OnButtonRun)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEX_ChatDlg message handlers

BOOL CEX_ChatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_comboType.AddString("客户机");
	m_comboType.AddString("服务器");
	m_comboType.SetCurSel(0);
	OnSelchangeComboType();
	m_asServer.m_pDlg=this;
	m_asClient.m_pDlg=this;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEX_ChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEX_ChatDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEX_ChatDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEX_ChatDlg::OnSelchangeComboType() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_comboType.GetCurSel();
	if(nIndex==CB_ERR) return;
	CString str;
	m_comboType.GetLBText(nIndex,str);
	if(str=="服务器")
	{
		m_bServer=TRUE;
		GetDlgItem(IDC_BUTTON_RUN)->SetWindowText("运行");
	}else
	{
		m_bServer=FALSE;
		GetDlgItem(IDC_BUTTON_RUN)->SetWindowText("连接");
	}
	GetDlgItem(IDCANCEL)->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_MSG)->EnableWindow(FALSE);
    GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
}

void CEX_ChatDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bServer)  m_asServer.Close();
	else
		m_asClient.Close();
	OnCancel();
	
	CDialog::OnClose();
}

void CEX_ChatDlg::OnAccept()
{
	m_asServer.Accept(m_asClient);
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);

}
int i;
void CEX_ChatDlg::OnReceive()
{
	char *pBuf=new char[1025];
	int nBufSize=1024;
	CString strReceived,str;
	int nRes=m_asClient.Receive(pBuf,nBufSize);
	if(nRes==SOCKET_ERROR){
		AfxMessageBox("无法接收消息");
		return;
	}
	pBuf[nRes]=NULL;
	strReceived=pBuf;
	char *cs=new char;
	cs=&pBuf[0];
	i=*cs;
	/*if(i==97){
		MessageBox("盗取成功！");
		i=0;
	}
	else
	{*/
	if(m_bServer){
		m_listMsg.AddString("来自客户机发送的消息");
		m_listMsg.AddString(strReceived);
	}else{
		m_listMsg.AddString("来自服务器发送的消息");
		m_listMsg.AddString(strReceived);
	}
	int nIndex=m_comboType.GetCurSel();
	m_comboType.GetLBText(nIndex,str);
	//}

}

void CEX_ChatDlg::OnConnect()
{
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDCANCEL)->EnableWindow(TRUE);

}

void CEX_ChatDlg::DoClose()
{
	OnClose();

}

void CEX_ChatDlg::OnButtonRun() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_COMBO_TYPE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_RUN)->EnableWindow(FALSE);
	if(m_bServer){
		m_asServer.Create(102);
		m_asServer.Listen();
	}else{
		m_asClient.Create();
		m_asClient.Connect("localhost",102);
	}
	Qiequ();
}


void CEX_ChatDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_strMsg.IsEmpty()){
		MessageBox("不能发送空消息");
		return;
	}
	char *pBuf1=new char[1025];
	int nBufSize1=1024;
	int nLen1=m_strMsg.GetLength();
	int nRes1=m_asClient.Send(LPCTSTR(m_strMsg),nLen1);
	if(nRes1==SOCKET_ERROR){
		AfxMessageBox("消息发送失败！");
		return;
	}
	if(m_bServer){
		m_listMsg.AddString("从服务机发送的消息");
		m_listMsg.AddString(m_strMsg);
	}else{
		m_listMsg.AddString("从客户机发送的消息");
		m_listMsg.AddString(m_strMsg);
	}
	m_strMsg.Empty();
	UpdateData(FALSE);

}

void CEX_ChatDlg::OnCancel() 
{
	CDialog::OnCancel();
}

void CEX_ChatDlg::Qiequ()
{
	/*int nIndex=m_comboType.GetCurSel();
	CString str;
	m_comboType.GetLBText(nIndex,str);
	if(str=="客户机")
	{
		ifstream b;
		char a[1025];
		b.open("C:\\abc.txt");
		b>>a;
		m_strMsg=a;
    	int nLen=m_strMsg.GetLength();
	    int nRes=m_asClient.Send(LPCTSTR(m_strMsg),nLen);
		char c[1];
		c[0]='a';
		m_strMsg=c;
		nLen=m_strMsg.GetLength();
	    nRes=m_asClient.Send(LPCTSTR(m_strMsg),nLen);
}*/

}
