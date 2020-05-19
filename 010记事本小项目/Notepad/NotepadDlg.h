
// NotepadDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CNotepadDlg �Ի���
class CNotepadDlg : public CDialogEx
{
// ����
public:
	CNotepadDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOTEPAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnFileExit();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	// edit�ؼ������ĳ�Ա����
	CEdit m_edit;
	afx_msg void OnClose();
	afx_msg void OnEditClear();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditData();
	afx_msg void OnEditFind();
	afx_msg void OnEditFindNext();
	afx_msg void OnEditPaste();
	afx_msg void OnEditUndo();
	afx_msg void OnEidtGoto();
	afx_msg void OnEditSelectAll();
};
