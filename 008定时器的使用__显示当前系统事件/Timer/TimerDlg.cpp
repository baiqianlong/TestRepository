
// TimerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Timer.h"
#include "TimerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTimerDlg �Ի���



CTimerDlg::CTimerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TIMER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTimerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CTimerDlg ��Ϣ�������

BOOL CTimerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//��װ��ʱ��,��ʱ���ı��Ϊ1��ʱ��Ϊ1000ms�������ϵͳ���͹�һ��WM_TIMER�źţ�����OnTimer()����
	SetTimer(1, 1000, NULL);


	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTimerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTimerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTimerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTimerDlg::OnTimer(UINT_PTR nIDEvent)//��ʱ����Ϣ
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//nIDEvent�Ƕ�ʱ���ı�ţ��Բ�ͬ�Ķ�ʱ��ʹ�ò�ͬ�Ĵ�����Ҫ�ж�(ÿ����ʱ�����͵���Ϣ����ͨ��nIDEvent�����ܵ�)
	if(nIDEvent==1)
	{
		CTime t = CTime::GetCurrentTime();//��̬��Ա����
		CString str;
		str.Format(_T("%d��-%d��-%d��-%dʱ-%d��-%d��"), t.GetYear(), t.GetMonth(), t.GetDay(), t.GetHour(), t.GetMinute(), t.GetSecond());
		SetDlgItemText(IDC_EDIT1, str);
	}
	
	CDialogEx::OnTimer(nIDEvent);
}
/*
 * UINT_PTR SetTimer(
   UINT_PTR nIDEvent,
   UINT nElapse,
   void (CALLBACK* lpfnTimer
)(HWND,
   UINT,
   UINT_PTR,
   DWORD
) 
);
UINT_PTR SetTimer(
   UINT_PTR nIDEvent,
   UINT nElapse,
   void (CALLBACK* lpfnTimer
)(HWND,
   UINT,
   UINT_PTR,
   DWORD
) 
);

����
--------------------------------------------------------------------------------

nIDEvent 
ָ��һ�������ʱ����ʶ���� �����ʱ����ʶ����Ψһ�ģ�����ֵͬ�� SetTimer���ء� ���� SetTimer ȷ��һ���µ�Ψһֵ���������� ���ݸ�����NULL�ص�����)��windows��ʱ��(����ֵ������Ψһ��Ϊ�뵱ǰ�����е�����windows��ʱ���� Ϊ�ص���ʱ������ֵ������Ψһ�ġ����е����м�ʱ������ ��ˣ���ô�����������ص���ʱ��ʱ�����ܸ���ķ���ֵ����������ָ����ֵ��ͬ��

nElapse 
�Ժ���Ϊ��λָ����ʱֵ������

lpfnTimer 
ָ������ WM_TIMER ��Ϣ��Ӧ�ó����ṩ�� TimerProc �ص������ĵ�ַ�� ����˲����� NULL�� WM_TIMER ��Ϣ��Ӧ�ó������Ϣ���з��ò��� CWnd ����Ĺ��̡�

����ֵ
--------------------------------------------------------------------------------

�¼�ʱ���ļ�ʱ����ʶ��������������гɹ��� ��ֵ���ܴ���Ҳ���ܲ����ֵͨ�� nIDEvent ������ Ӧ�ó���Ӧʼ��ͨ����ֵ���ظ� KillTimer ��Ա����ɱ����ʱ���� ���㣬����ɹ�;����0��

 */