// DLLTest.cpp : �������̨Ӧ�ó������ڵ㡣

//��̬����SimpleDLL.dll�еĺ�����ͨ����������DLL�����ĵ�������д����ִ���ļ�

#include "stdafx.h"

#pragma comment (lib,"SimpleDLL")

extern "C" void myMsgBox(wchar_t* szChar);

int _tmain(int argc, _TCHAR* argv[])
{
	myMsgBox(L"Hello");
	return 0;
}

