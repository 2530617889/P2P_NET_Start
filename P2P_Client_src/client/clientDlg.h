// clientDlg.h : ͷ�ļ�
//
#include "p2ptype.h"

#pragma once

// CclientDlg �Ի���
class CclientDlg : public CDialog
{
// ����
public:
	CclientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
//	int ClientSetCmdSendBuf(char * pSendBuf, int iBufMaxLen, P2P_IOCTRL_TYPE u16IOCtrlType, char * pData, int iDataLen);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL bLogin;
	BOOL bConnect;
	BOOL bRelay;
	int m_nServerPort;
	CString m_strServerAddr;	
	CString m_strMyID;
	CString m_strToID;
	UserList ClientList;//�ͻ��ڵ��б�
	SOCKET m_cliSocket;
	sockaddr_in remoteAddr;
	sockaddr_in localAddr;
	char cliIpAddr[32];
	HANDLE h_recv;

	CEdit m_EditRecv;
	CEdit m_EditInfo;

	void GetUserList();
	void GetLocalIpAddr();
	void UpdateCtrlStates();
	stUserListNode GetLocalUser(const char *userName);

	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedBtnConnet();
	afx_msg void OnBnClickedBtnDisconnect();
	afx_msg void OnBnClickedBtnGetUsers();
	afx_msg void OnBnClickedBtnSend();
	afx_msg void OnBnClickedBtnClear();
	
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
