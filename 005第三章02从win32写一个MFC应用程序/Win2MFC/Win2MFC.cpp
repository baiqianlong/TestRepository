// Win2MFC.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Win2MFC.h"

class myApplication:public CWinApp
{
	BOOL InitInstance()//�˴���Ӷϵ㣬�鿴���ö�ջ���ǲ���ϵͳ����WinMain()��������winMain�����е���InitInstance()����
	{
		AfxMessageBox(_T("����һ������д��MFCӦ�ó���"));
		return TRUE;
	}
};

myApplication theApp;//����һ��Ӧ�ó������


/*
 *1.�½�һ��win32��Ŀ��ɾ���������е����д��룬�����������
 *	��CWinApp��������һ��Ӧ�ó�����
 *	ʹ��Ӧ�ó����ඨ��ȫ�ֱ���theApp
 *2.��Ԥ����ͷ�ļ�stdafx.hɾ��windows.hͷ�ļ���Ȼ�����mfcͷ�ļ�
 *3. ����Ŀ--����������--���ھ�̬����ʹ��MFC��
 *4.��CWinApp����������дInitInstance������Ϊ�����������롣
 *
 *InitInstance()�������麯����ÿ��Ӧ�ó����඼��Ҫ��д��pThread��ֻ��theAppȫ�ֱ�����ָ�����
 *pThread->InitInstance()���Զ����õ��������У������Ƕ�̬��
 */