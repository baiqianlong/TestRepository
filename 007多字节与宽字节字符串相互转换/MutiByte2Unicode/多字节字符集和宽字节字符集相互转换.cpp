#include<windows.h>
#include<tchar.h>
int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,//A handle to the current instance of the application
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,//The command line for the application, excluding the program name. To retrieve the entire command line, use the GetCommandLine function.
	_In_  int nCmdShow
)
//����������
{
	//���ֽ��ַ���
	wchar_t *p1 = L"�й�";//���ֽ��ַ���
	TCHAR *p2 = L"��������ԭ��";//TCHAR����Ӧ�ַ������ڲ�ͬ���ַ�����TCHAR��ʾ��ͬ���ַ�����w_char ��char
	TCHAR *p3 = _TEXT("����������");//������ת��Ϊ����Ӧ�ַ���--�Ƽ�ʹ��



	////1.Unicode��CStringת��Ϊchar *
	////����һ�� ʹ��API��WideCharToMultiByte����ת��
	//	CString str = _T("��ã����磡Hello,World");
	////ע�⣺����n��len��ֵ��С��ͬ,n�ǰ��ַ�����ģ�len�ǰ��ֽڼ����
	//int n = str.GetLength();
	////��ȡ���ֽ��ַ��Ĵ�С����С�ǰ��ֽڼ����
	//int len = WideCharToMultiByte(CP_ACP, 0, str, str.GetLength(), NULL, 0, NULL, NULL);
	////Ϊ���ֽ��ַ���������ռ䣬�����СΪ���ֽڼ���Ŀ��ֽ��ֽڴ�С
	//char * pFileName = new char[len + 1];   //���ֽ�Ϊ��λ
	//										//���ֽڱ���ת���ɶ��ֽڱ���
	//WideCharToMultiByte(CP_ACP, 0, str, str.GetLength(), pFileName, len, NULL, NULL);
	//pFileName[len + 1] = ��\0��;   //���ֽ��ַ��ԡ�\0�����

	//��������ʹ�ú�����T2A��W2A
	//	CString str = _T("��ã����磡Hello,World");
	////������ʶ��
	//USES_CONVERSION;
	////���ú�����T2A��W2A��֧��ATL��MFC�е��ַ�ת��
	//char * pFileName = T2A(str);
	////char * pFileName = W2A(str); //Ҳ��ʵ��ת��

	//ע�⣺��ʱ����ܻ���Ҫ�������#include
	//	2��Unicode��char *ת��ΪCString

	//	����һ��ʹ��API��MultiByteToWideChar����ת��
	//	char * pFileName = "��ã����磡Hello,World";
	////����char *�����С�����ֽ�Ϊ��λ��һ������ռ�����ֽ�
	//int charLen = strlen(pFileName);
	////������ֽ��ַ��Ĵ�С�����ַ����㡣
	//int len = MultiByteToWideChar(CP_ACP, 0, pFileName, charLen, NULL, 0);
	////Ϊ���ֽ��ַ���������ռ䣬�����СΪ���ֽڼ���Ķ��ֽ��ַ���С
	//TCHAR *buf = new TCHAR[len + 1];
	////���ֽڱ���ת���ɿ��ֽڱ���
	//MultiByteToWideChar(CP_ACP, 0, pFileName, charLen, buf, len);
	//buf[len] = ��\0��; //����ַ�����β��ע�ⲻ��len+1
	//				 //��TCHAR����ת��ΪCString
	//CString pWideChar;
	//pWideChar.Append(buf);
	////ɾ��������
	//delete[]buf;


	//Unicode����ֽ��ַ���ת��
	
}

/*1.���ֽ��ַ���
 *������ ASCII�Ļ������ƶ����Լ����ַ�������Щ��ANSI��׼�������ַ�����ϰ�ߵ�ͳ��ΪANSI�ַ�����
 *������ʽ������Ӧ����MBCS(Multi-Byte Chactacter System�������ֽ��ַ�ϵͳ)
 *
 *2unicode�ַ���
 *��Unicode��ѧ�� ��"Universal Multiple-Octet Coded Character Set"�����ΪUCS.
 *nicode�ַ����ж��ֱ�����ʽ�����̶�ʹ��16 bits�������ֽڡ�һ���֣�����ʾһ���ַ��������Ա�ʾ65536���ַ���
 *
 *L��������־һ���ַ�(��)Ϊ���ַ�(��)������Unicode��ʽ�£���Ҫ���ַ�(��)����ǰ���L�����߱��������ǿ��ַ���MSΪ���Ƕ����˺ü�����صĺ꣺_T��������tchar.h����_TEXT��ͬ��������tchar.h����
����TEXt()�����������Unicode����ʶ�ַ�ΪUnicode;����ΪANSI�ַ�����
 *
 *
 *windowsΪ���ֽںͿ��ֽ��ṩ������api�������ֱ���--A�͡���W����
*/

