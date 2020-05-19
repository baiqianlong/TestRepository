
// NotepadDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Notepad.h"
#include "NotepadDlg.h"
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


// CNotepadDlg �Ի���



CNotepadDlg::CNotepadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NOTEPAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CNotepadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT, m_edit);
}

BEGIN_MESSAGE_MAP(CNotepadDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, &CNotepadDlg::OnFileExit)
	ON_WM_DROPFILES()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_EDIT_CLEAR, &CNotepadDlg::OnEditClear)
	ON_COMMAND(ID_EDIT_COPY, &CNotepadDlg::OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, &CNotepadDlg::OnEditCut)
	ON_COMMAND(ID_EDIT_DATA, &CNotepadDlg::OnEditData)
	ON_COMMAND(ID_EDIT_FIND, &CNotepadDlg::OnEditFind)
	ON_COMMAND(ID_EDIT_FIND_NEXT, &CNotepadDlg::OnEditFindNext)
	ON_COMMAND(ID_EDIT_PASTE, &CNotepadDlg::OnEditPaste)
	ON_COMMAND(ID_EDIT_UNDO, &CNotepadDlg::OnEditUndo)
	ON_COMMAND(ID_EIDT_GOTO, &CNotepadDlg::OnEidtGoto)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CNotepadDlg::OnEditSelectAll)
END_MESSAGE_MAP()


// CNotepadDlg ��Ϣ�������

BOOL CNotepadDlg::OnInitDialog()
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

	//�����û��Զ����ͼ��
	
	
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	

	//���ô��ڿؼ����Ŵ��ڴ�С�任
	CWnd*p = GetDlgItem(IDC_TEXT);
	RECT rect;
	GetClientRect(&rect);
	p->MoveWindow(&rect, FALSE);

	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CNotepadDlg::OnSysCommand(UINT nID, LPARAM lParam)//ϵͳ������Ϣ����󻯣���С�����رգ��ı��С����Ϣ
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

void CNotepadDlg::OnPaint()
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
HCURSOR CNotepadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNotepadDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	//ע�ͣ�Ĭ��ȥ���س����رմ���
	CDialogEx::OnOK();
}


void CNotepadDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//ע�ͣ�Ĭ��ȥ��ESC�رմ���
	CDialogEx::OnCancel();
}


void CNotepadDlg::OnFileExit()//�˵�-�ļ�-�˳�����Ϣ������
{
	// TODO: �ڴ���������������
	EndDialog(ID_APP_EXIT);//�˳�Ӧ�ó���
}


void CNotepadDlg::OnDropFiles(HDROP hDropInfo)//�϶��ļ����Ի��򣬲�����WM_DROPFILE��Ϣ������
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	TCHAR sFile[256];
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	CFile file;//���ļ������Ƿ�Unicode��������Ҫ����
	if(!file.Open(sFile,CFile::modeRead))
	{
		AfxMessageBox(_T("���ļ�ʧ�ܣ������ļ��Ƿ����"));
		return;
	}
	TCHAR buffer[256];
	UINT nRet = 0;
	CString str;
	while (nRet = file.Read(buffer, sizeof(buffer)-1))
	{
		buffer[nRet] = _T('\0');//�����ļ�����\0
		str += buffer;
		
	}
	SetDlgItemText(IDC_TEXT,str);
	file.Close();
	
	
	
	CDialogEx::OnDropFiles(hDropInfo);
}


void CNotepadDlg::OnSize(UINT nType, int cx, int cy)//����������С��ť���߸ı䴮�ڴ�Сʱ���ᷢ��WM_SIZE��Ϣ��
{//ʹ�ؼ����Ŵ��ڴ�С�任
	
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	//���ô��ڿؼ����Ŵ��ڴ�С�任
	CWnd*p = GetDlgItem(IDC_TEXT);
	if(p)
	{
		RECT rect;
		GetClientRect(&rect);
		p->MoveWindow(&rect, FALSE);
	}
	
	
}


void CNotepadDlg::OnClose()//ϵͳ�ر���Ϣ������
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	EndDialog(IDCANCEL);
	CDialogEx::OnClose();
}


void CNotepadDlg::OnEditClear()//ɾ������
{
	// TODO: �ڴ���������������
	m_edit.Clear();
}


void CNotepadDlg::OnEditCopy()
{
	// TODO: �ڴ���������������
	m_edit.Copy();
}


void CNotepadDlg::OnEditCut()
{
	// TODO: �ڴ���������������
	m_edit.Cut();
}


void CNotepadDlg::OnEditData()//����ʱ������
{
	// TODO: �ڴ���������������
	CTime time = CTime::GetCurrentTime();
	CString str = time.Format(_T("%Y��%m��%d�� %H:%M"));
	m_edit.ReplaceSel(str, TRUE);
}


void CNotepadDlg::OnEditFind()
{
	// TODO: �ڴ���������������
}


void CNotepadDlg::OnEditFindNext()
{
	// TODO: �ڴ���������������
}


void CNotepadDlg::OnEditPaste()//ճ������
{
	// TODO: �ڴ���������������
	m_edit.Paste();
}


void CNotepadDlg::OnEditUndo()
{
	// TODO: �ڴ���������������
	m_edit.Undo();
}


void CNotepadDlg::OnEidtGoto()
{
	// TODO: �ڴ���������������
}


void CNotepadDlg::OnEditSelectAll()//ȫѡ����
{
	// TODO: �ڴ���������������
	m_edit.SetSel(0, -1);
	m_edit.SetFocus();
}
