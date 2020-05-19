
// StaffDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Staff.h"
#include "StaffDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaffDlg �Ի���



CStaffDlg::CStaffDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STAFF_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStaffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStaffDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CStaffDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_ADD, &CStaffDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DELETE, &CStaffDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_MODEFY, &CStaffDlg::OnBnClickedModefy)
	ON_BN_CLICKED(IDC_SAVE, &CStaffDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LOAD, &CStaffDlg::OnBnClickedLoad)
END_MESSAGE_MAP()


// CStaffDlg ��Ϣ�������

BOOL CStaffDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	//��listControl��ʼ��
	/*
	 * int InsertColumn( 
	   int nCol, 
	   LPCTSTR lpszColumnHeading, 
	   int nFormat = LVCFMT_LEFT, 
	   int nWidth = -1, 
	   int nSubItem = -1  
	);
	 */
	//����һ���ؼ�������ָ��pList��.Ҳ�����ڶԻ�����ʹ���Ҽ������������������ ��
	CListCtrl*pList = (CListCtrl*)GetDlgItem(IDC_LIST4);//���ص��ǻ���ָ�룬��Ҫǿ������ת��
	pList->InsertColumn(0, _T("����"), LVCFMT_CENTER, 200);
	pList->InsertColumn(1, _T("����"), LVCFMT_CENTER, 200);
	pList->InsertColumn(2, _T("����"), LVCFMT_CENTER, 200);
	pList->InsertColumn(4, _T("��Ӷ����"), LVCFMT_CENTER,250);

	//�����б���ɫ
	pList->SetOutlineColor(RGB(199,237,208));
	pList->SetBkColor(RGB(199, 237, 208));//����������ʱ�򣬱�����ɫ��ı䣬����������ɫ����
	pList->SetTextBkColor(RGB(199, 237, 208));
	pList->SetExtendedStyle(LVS_EX_CHECKBOXES|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//���ÿ��Դ���ʽ,ѡ��ȫ��,���
	//pList->SetBkImage()//���ñ���ͼƬ
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CStaffDlg::OnPaint()
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
HCURSOR CStaffDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStaffDlg::OnBnClickedOk()//��дok����ʹ�ûس����˳�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();//ע�͵�
}


void CStaffDlg::OnBnClickedAdd()//������Ӱ�ť�����Ա����Ϣ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListCtrl*pList = (CListCtrl*)GetDlgItem(IDC_LIST4);//���ص��ǻ���ָ�룬��Ҫǿ������ת��

	
	
	//��ȡEditControl����Ϣ��ʾ��ListControl��
	CString str;
	GetDlgItemText(IDC_NUMBER, str);

	//�ų��ظ���Ա����
	int i = 0;
	int nCount = pList->GetItemCount();
	while (i<nCount)
	{
		if (pList->GetItemText(i, 0) == str)
		{
			AfxMessageBox(_T("�����Ա�������ظ�������������"));
			//ʹ��ctrl+D�����Բ鿴�ؼ���˳�򣬵�������޸ġ�
			SetFocus();//���ý�����Ҫ����Ĺ���λ��
			return;
		}
		i++;
	}
	
	pList->InsertItem(0, str);//����һ��,�����úõ�һ��

	GetDlgItemText(IDC_NAME, str);//���úõڶ���
	pList->SetItemText(0, 1, str);

	GetDlgItemText(IDC_SALARY, str);//���úõڶ���
	pList->SetItemText(0, 2, str);

	GetDlgItemText(IDC_DATETIMEPICKER3, str);//���úõڶ���
	pList->SetItemText(0, 3, str);
	
	
	/*��ʹ��InsertItem()�����У�Ȼ��ʹ��SetItemText()�������е�����
	 * BOOL SetItemText( 
	   int nItem, 
	   int nSubItem, 
	   LPCTSTR lpszText  
	);

	 */
}


void CStaffDlg::OnBnClickedDelete()//����ɾ����ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListCtrl*pList = (CListCtrl*)GetDlgItem(IDC_LIST4);//���ص��ǻ���ָ�룬��Ҫǿ������ת��
	/*if(!pList->GetSelectedCount())
	{
		AfxMessageBox(_T("����ѡ����"));
		return;
		
	}*/
	int nSelect = pList->GetSelectionMark();//��ȡѡ���еı��
	if (nSelect==-1)
	{
		AfxMessageBox(_T("����ѡ����"));
	}
	if (AfxMessageBox(_T("��ȷ��Ҫɾ����"),MB_YESNO)==IDYES)
	{
		pList->DeleteItem(nSelect);

	}
	
	
}


void CStaffDlg::OnBnClickedModefy()//�����޸�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


void CStaffDlg::OnBnClickedSave()//���水ť�Ĺ���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���û������뱣�浽һ���ļ���
	CFile f;
	CFileException e;
	TCHAR* pszFileName = _T("./Staff_File.txt");
	if (!f.Open(pszFileName, CFile::shareDenyNone | CFile::modeWrite | CFile::modeCreate, &e))
	{
		TRACE(_T("File could not be opened %d\n"), e.m_cause);
	}
	
	//testд������
	//const char*p1 = "��������ԭ��";
	//f.Write(p1,strlen(p1));
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST4);
	int i = 0, nCount = pList->GetItemCount();
	SData data;
	while (i < nCount)//��Ҫͨ��һ���ṹ����ת
	{
		data.nNumb = _wtoi(pList->GetItemText(i, 0));
		pList->GetItemText(i, 1, data.sName, _countof(data.sName));
		data.fSala = (float)_wtof(pList->GetItemText(i, 2));
		f.Write(&data, sizeof(data));
		++i;
	}

	
	f.Close();


}


void CStaffDlg::OnBnClickedLoad()//�����ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFile f;
	CFileException e;
	TCHAR* pszFileName = _T("./Staff_File.txt");
	if (!f.Open(pszFileName, CFile::modeRead , &e))
	{
		TRACE(_T("File could not be opened %d\n"), e.m_cause);
		return;
	}

	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST4);
	int i = 0, nCount = pList->GetItemCount();
	SData data;
	CString str;
	while (f.Read(&data,sizeof(data))==sizeof(data))//��Ҫͨ��һ���ṹ����ת
	{
		str.Format(_T("%d"), data.nNumb);
		pList->InsertItem(i, str);
		pList->SetItemText(i, 1, data.sName);
		str.Format(_T("%d"), data.fSala);
		pList->SetItemText(i, 2, str);
		str.Format(_T("%d��%d��%d��"),data.tDate.GetYear(),data.tDate.GetMonth(),data.tDate.GetDay());
		pList->SetItemText(i, 3, str);
		
		++i;
	}
	f.Close();
	
}

//�޸ĵĹ���ʵ����ο�192  12���Ӻ�