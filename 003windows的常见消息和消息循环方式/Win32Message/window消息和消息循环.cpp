

#include<windows.h>
#include <stdio.h>
#include "resource.h"

//��¼�Ի���Ļص�����
INT_PTR CALLBACK LogProc(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
);

INT_PTR CALLBACK MSGProc(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
);




int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,//A handle to the current instance of the application
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,//The command line for the application, excluding the program name. To retrieve the entire command line, use the GetCommandLine function.
	_In_  int nCmdShow
)
//����������
{
	//������¼�Ի���
	
	if((DialogBox(hInstance, MAKEINTRESOURCE(104), NULL, LogProc))==IDCANCEL)
	{
		return 0;//����¼�Ի�����ȡ����ť���˳�����
	}
	//����һ���Ի���
	DialogBox(hInstance, MAKEINTRESOURCE(101), NULL, MSGProc);

	
	return 0;
}


INT_PTR CALLBACK MSGProc(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
)//�Ի��򴰿ڹ��̺���
{
	switch (uMsg)
	{
	case WM_INITDIALOG://���case���涨�����������{}
		{
			//��û����ʾ�����Ի��򣬳�ʼ��
			//���öԻ���λ�þ���
			RECT rect;
			GetWindowRect(hwndDlg, &rect);
			int cx = GetSystemMetrics(SM_CXFULLSCREEN);
			int cy = GetSystemMetrics(SM_CYFULLSCREEN);//��ȡȫ��Ļ�ĸߺͿ�
			//���Ͻ�����
			int x = (cx - rect.right) / 2;//��Ļ�Ŀ�ȼ�ȥ�Ի���Ŀ��/2
			int y = (cy - rect.bottom) / 2;

			MoveWindow(hwndDlg, x, y, rect.right , rect.bottom, FALSE);


			SetWindowText(hwndDlg, LPCSTR("INITDIALOG���ĶԻ���ı���"));
			break;
		}
	case WM_CLOSE:
		//ϵͳ�ر���Ϣalt+F4,�������Ͻǵ�X��
		EndDialog(hwndDlg, IDCANCEL);
	case WM_LBUTTONDOWN://����������
		{
			int x = LOWORD(lParam);
			int y = HIWORD(lParam);
			char s[128];
			sprintf_s(s, "�����x=%d,y=%d", x, y);
			SetWindowText(hwndDlg, LPCSTR(s));//�ڱ���������ʾ����

			break;		
		}//������������Ϣ������������lParam��
	case WM_MOUSEMOVE://����ƶ���Ϣ
		{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		char s[128];
		sprintf_s(s, "�ƶ�ʱ���x=%d,y=%d", x, y);
		//�ж��Ƿ���ctrl��
		if(wParam&MK_CONTROL)
		{
			strcat_s(s, "--������ctrl��+");
		}
		//�ж��Ƿ�����shift��
		if (wParam&MK_SHIFT)
		{
			strcat_s(s, "--������shift��+");
		}
		SetWindowText(hwndDlg, LPCSTR(s));//�ڱ���������ʾ����
		break;
		}

	
		
	case WM_COMMAND://��ť����ݼ����������ť��Ϣ��F12�鿴��Ϣ����
		if(LOWORD(wParam)==IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
		}
		if(LOWORD(wParam)==IDOK)
		{
			//MessageBox(hwndDlg, LPCSTR("�����ȷ����ť"), LPCSTR("��ʾ"), MB_OK);
		}
	}
	
	return FALSE;
}

//��¼�Ի���Ļص�����
INT_PTR CALLBACK LogProc(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		if(LOWORD(wParam)==IDCANCEL)//ȡ����ť�����Ի���
		{
			EndDialog(hwndDlg, IDCANCEL);
		}
		if (LOWORD(wParam) == IDOK)//�����¼��ť����¼���������Ի�����ʾ����Ի���
		{
			//�ж��û����������Ƿ���ȷ
			char sName[128];
			char sPasswd[128];
			GetDlgItemText(hwndDlg, IDC_NAME, sName, 128);
			GetDlgItemText(hwndDlg, IDC_PASSWD, sPasswd, 128);
			//�û����������Ƿ���ȷ
			if (strcmp(sName,"admin") || strcmp(sPasswd,"123456"))//��ͬʱ������ֵ����0
			{
				MessageBox(hwndDlg, LPCSTR("��������û�������"), LPCSTR("������ʾ"), MB_OK);
			}
			else
			{
				EndDialog(hwndDlg, IDOK);
				
			}
			break;	
			
		}

		//��ȡ����ͼ��
	case WM_SETFOCUS:
		SetDlgItemText(hwndDlg, IDC_STATUS, LPCSTR("������������������"));
		return TRUE;
		
	}
	
	return FALSE;//�û����������Ϣ������TRUE,�û�û�д������Ϣ������FALSE������ϵͳ�ں�Ĭ�ϴ���
}


/*
 *�ڶԻ�����Ϣ�У�wParam��lParam�в����������ڱ�ʾ��ͬ����Ϣ��
 *����WM_RBUTTONDOWN��wParam���ڱ�ʾ�Ƿ�סĳһ�����̼���lParam���ڴ��������xy��
 *
 *2.Сд��bool������c++�е����ͣ�ռ��1���ֽڡ�BOOL������Visual C++�����ͣ�ռ��4���ֽڡ�
 *
 *3.���ʹ��|�����㣬�ж��Ƿ���ʹ��&������
 *
 *GetSystemMetrics()������ȡ����ϵͳ�Ĵ��ڣ���Ļ��ϵͳ������Ϣ
 *
 *��ӵ�¼�Ի���
 *
 *
*/

