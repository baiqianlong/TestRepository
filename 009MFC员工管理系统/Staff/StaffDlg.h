
// StaffDlg.h : ͷ�ļ�
//

#pragma once
//���ڱ�����Ϣ�Ľṹ��
struct SData
{
	int nNumb;
	TCHAR sName[20];
	float fSala;
	CTime tDate;
};

// CStaffDlg �Ի���
class CStaffDlg : public CDialogEx
{
// ����
public:
	CStaffDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAFF_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedModefy();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
};
