
// Calulator.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCalulatorApp: 
// �йش����ʵ�֣������ Calulator.cpp
//

class CCalulatorApp : public CWinApp
{
public:
	CCalulatorApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCalulatorApp theApp;