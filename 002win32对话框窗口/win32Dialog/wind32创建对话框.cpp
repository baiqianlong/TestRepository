#include<windows.h>
#include "resource.h"
//�Ի��򴰿ڻص�����
INT_PTR CALLBACK DialogProc(
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
	
	DialogBox(hInstance, MAKEINTRESOURCE(102), NULL, DialogProc);
	//MAKEINTRESOURCE�����ڽ���Դ�ĸ�λ��Ϊ0����λ����Ϊ��Դ�ı�ʶ��
	

	return 0;

}

INT_PTR CALLBACK DialogProc(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
)
{
	//MessageBox(NULL, LPCSTR("���ԶԻ���"), LPCSTR("TEST CAPTION"), MB_OK);
	//����ǶԻ���Ĺ��̺������Ի�����κθ��ģ�����ϵͳ��������������д���
	switch (uMsg)
	{
	case WM_COMMAND://�����menu���Ͱ�ť/��ݼ�������WM_COMMAND��Ϣ
		if(LOWORD(wParam)== IDC_EXIT)
		{
			EndDialog(hwndDlg, IDC_EXIT);//����ֵ����Ϊ��ť��ֵ1004
		}
		if(LOWORD(wParam)==IDCANCEL)//����Ի���������رպͼ���ESC����ȡ����ť����IDCCANCEL��ť
		{
			//MessageBox(hwndDlg, LPCSTR("�������ȡ����ť"), LPCSTR("��ʾ"), MB_OK);
			EndDialog(hwndDlg, IDC_EXIT);//����ֵ����Ϊ��ť��ֵ1004

		}
		if(LOWORD(wParam)==IDOK)//ȷ����ť���߼���enter
		{
			//MessageBox(hwndDlg, LPCSTR("�������ȷ����ť���߼���enter"), LPCSTR("��ʾ"), MB_OK);

			int nLeft=GetDlgItemInt(hwndDlg, IDC_LEFT, NULL, TRUE);
			int nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT, NULL, TRUE);
			SetDlgItemInt(hwndDlg, IDC_RESULT, nLeft+nRight,TRUE);
			
		}
		break;
	}
	
	return FALSE;//����false������ϵͳĬ�Ͻ��д������

}

/*
 *1.���ͼ��
 *2.��Ӱ汾��Ϣ��Դ�������ɵĿ�ִ�г��������������Բ鿴
 *3.��ӶԻ�����Դ
 *4.���һ��picture control��Ȼ�����һ��λͼ��Դ��type����ѡ��bitmap����icon���ͣ�Ȼ������image���ɡ�
 *
 *
 *�ܽ᣺
 *1.����ϵͳ�ڴ���һ��Ӧ�ó���ʱ�����������Դ���ص�һ��ʵ�����hInstance�У����е���Դ�����������棬���Կ�����Դ�ܹܡ�
 *2.����ϵͳΪÿһ�����򴴽�һ����Ϣ���У����û���������ʱ�򣬲���ϵͳ�ں˷�װ��Ϣ���͵�Ӧ�ó�������С�����ͨ��ѭ��ʹ�ú���GetMessage()��Ӧ�ó���ȡ��
 *	��Ϣ���д����ת��(ȡ����Ϣ��Ӧ�ó�����Զ���Ϣ����һЩԤ�������磬������ĳЩ��Ϣ����Ӧ�����ߵ��� TranslateMessage �����µ���Ϣ)��Ȼ�����
 *	DispatchMessage()����Ϣ�ش�������ϵͳ�ں�.
 *3.ϵͳ���� WNDCLASS �ṹ��� lpfnWndProc ��Ա����Ĵ��ڹ��̺�����ָ����ô��ڹ��̣�����Ϣ���д�������ϵͳ�ں˵��ô��ڹ��̺������д���
 *
 *4.�Ի��������ĵ�����ռ��������룬����϶����������룬������봰��ѭ���С�
 *
 *5.�ؼ���ʾcontrol�����Կؼ���idһ����IDC_

	
BOOL WINAPI EndDialog(
  _In_  HWND hDlg,
  _In_  INT_PTR nResult//����ֵһ������Ϊ����İ�ťid
);



*/

