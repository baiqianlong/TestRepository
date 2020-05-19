
// CTimeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CTime.h"
#include "CTimeDlg.h"
#include "afxdialogex.h"
#include <atltime.h>
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


// CCTimeDlg �Ի���



CCTimeDlg::CCTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CTIME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCTimeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TEST, &CCTimeDlg::OnBnClickedTest)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CCTimeDlg ��Ϣ�������

BOOL CCTimeDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCTimeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCTimeDlg::OnPaint()
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
HCURSOR CCTimeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCTimeDlg::OnBnClickedTest()//������ť���¼��������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����CTime��ĳ�Ա����
	//static��Ա��������Ҫ��������ֱ��ʹ�����Ϳ��Ե���
	CTime t = CTime::GetCurrentTime();
	int nYear = t.GetYear();
	int nMonth = t.GetMonth();
	int nDay = t.GetDay();
	int nHour = t.GetHour();
	int nMinute = t.GetMinute();
	int nSecond = t.GetMinute();
	
	CString szTime;
	//��ʽ���ַ��������������͵����ݺϲ�Ϊһ���ַ���
	//szTime.Format("%d-%d-%d-%d:%d:%d", nYear, nMonth, nDay, nHour, nMinute,nSecond);//vs2015���Ͳ�ƥ��
	szTime = t.Format(_T("%A-%B-%d-%Y"));//���ڣ�������  See the run-time function strftime for a list of formatting codes.
	
	AfxMessageBox(szTime);
	

	
}

/*����Ŀ�ģ��Ա�ctime��ķ�װ��c���Ե�time����ʵ�־�����̽��жԱ�
 *
 * static CTime WINAPI GetCurrentTime( ) throw( );
 * CTime::Format
 Converts a CTime object into a formatted string �� based on the local time zone.
 
CTime::FormatGmt
 Converts a CTime object into a formatted string �� based on UTC.
 
CTime::GetAsDBTIMESTAMP
 Converts the time information stored in the CTime object to a Win32-compatible DBTimeStamp structure.
 
CTime::GetAsSystemTime
 Converts the time information stored in the CTime object to a Win32-compatible SYSTEMTIME structure.
 
CTime::GetCurrentTime
 Creates a CTime object that represents the current time (static member function).
 
CTime::GetDay
 Returns the day represent by the CTime object.
 
CTime::GetDayOfWeek
 Returns the day of the week represented by the CTime object.
 
CTime::GetGmtTm
 Breaks down a CTime object into components �� based on UTC.
 
CTime::GetHour
 Returns the hour represented by the CTime object.
 
CTime::GetLocalTm
 Breaks down a CTime object into components �� based on the local time zone.
 
CTime::GetMinute
 Returns the minute represented by the CTime object.
 
CTime::GetMonth
 Returns the month represented by the CTime object.
 
CTime::GetSecond
 Returns the second represented by the CTime object.
 
CTime::GetTime
 Returns a __time64_t value for the given CTime object.
 
CTime::GetYear
 Returns the year represented by the CTime object.
 
CTime::Serialize64
 Serializes data to or from an archive.
 
 * 
 */


void CCTimeDlg::OnLButtonDown(UINT nFlags, CPoint point)//�Ի�������������,F1�鿴�����ĵ�
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//�������������ʾ�ڶԻ��������
	CString str;
	str.Format(_T("�������%d--%d"), point.x, point.y);
	if(nFlags&MK_LBUTTON)
	{
		str += _T("������");
	}
	SetWindowText(str);

	CDialogEx::OnLButtonDown(nFlags, point);
}
