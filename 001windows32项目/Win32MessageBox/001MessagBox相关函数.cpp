#include<windows.h>

int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,//A handle to the current instance of the application
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,//The command line for the application, excluding the program name. To retrieve the entire command line, use the GetCommandLine function.
	_In_  int nCmdShow
)
//����������
{
	//FindWindow����
	
	HWND nRet = FindWindowW(NULL, LPCWSTR("C:/Users/baixiaolong/Desktop/11.txt - Notepad++"));//ͨ���������ֲ��Ҵ���
	//������ڲ����ڣ��򷵻�ֵ��NULL�����ҵ������򷵻ش��ھ��
	HWND nRet02 = FindWindowW(LPCWSTR("Notepad++"),NULL);//ͨ���������ң��������spy++����

	
	int msgboxID = MessageBox(
		nRet02,//ʹ��������ҵ��Ĵ��ھ������Ϊ������
		(LPCWSTR)L"Resource not available\nDo you want to try again?",
		(LPCWSTR)L"Account Details",
		MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
	);

	switch (msgboxID)
	{
	case IDCANCEL:
		// TODO: add code
		MessageBox(NULL, (LPCWSTR)L"��������ȡ��", (LPCWSTR)L"�����",MB_CANCELTRYCONTINUE );
		break;
	case IDTRYAGAIN:
		// TODO: add code
		break;
	case IDCONTINUE:
		// TODO: add code
		break;
	}
	
}

/*
 * Messagbox()����--ͼ��ʹ�ø���λ����ť����ʹ�õ�4λ
 * FindWindow()����--����ȡ���ڵľ��
 *
 * ������ͼ���Ҽ�--����ӡ�--����Դ��--��ͼ�ꡱ���ͻ��Զ�����ͼ��ʹ�õ�win32�����У�����Ƕ��ͼ�꣬���Զ�ѡ��id��С��ͼ��
 */

