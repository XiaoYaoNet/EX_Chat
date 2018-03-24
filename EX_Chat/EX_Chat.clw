; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEX_ChatDlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "EX_Chat.h"

ClassCount=4
Class1=CEX_ChatApp
Class2=CEX_ChatDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CChatSocket
Resource3=IDD_EX_CHAT_DIALOG

[CLS:CEX_ChatApp]
Type=0
HeaderFile=EX_Chat.h
ImplementationFile=EX_Chat.cpp
Filter=N

[CLS:CEX_ChatDlg]
Type=0
HeaderFile=EX_ChatDlg.h
ImplementationFile=EX_ChatDlg.cpp
Filter=D
LastObject=IDC_BUTTON_RUN
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=EX_ChatDlg.h
ImplementationFile=EX_ChatDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889

[DLG:IDD_EX_CHAT_DIALOG]
Type=1
Class=CEX_ChatDlg
ControlCount=9
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_RUN,button,1342242816
Control3=IDC_LIST_MSG,listbox,1352728835
Control4=IDC_EDIT_MSG,edit,1350631552
Control5=IDC_BUTTON_SEND,button,1342242816
Control6=IDC_COMBO,static,1342308864
Control7=IDC_LIST_MSG4,static,1342308864
Control8=IDC_EDIT_MSG0,static,1342308864
Control9=IDC_COMBO_TYPE,combobox,1344340226

[CLS:CChatSocket]
Type=0
HeaderFile=ChatSocket.h
ImplementationFile=ChatSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CChatSocket

