// DLLTest2.cpp : �������̨Ӧ�ó������ڵ㡣

//��̬���ã�����������ʱ��ɶ�����������ʱ

#include "stdafx.h"

typedef VOID(*PFUNMSG)(char *);

int _tmain(int argc, _TCHAR* argv[])
{
	//����dll�ļ�
	HMODULE hModule = LoadLibrary(L"SimpleDLL.dll");
	if (hModule == NULL){
		MessageBox(NULL, L"û�ҵ�DLL�ļ�", L"GG", MB_OK);
		return 0;
	}
	//ͨ�����������ҵ�ַ�����
	//PFUNMSG pFunMsg = (PFUNMSG)GetProcAddress(hModule, "myMsgBox");
	//pFunMsg((char*)L"Hello");

	//ͨ������������
	PROC mmsg = GetProcAddress(hModule, "myMsgBox");
	char *mystr =(char*)L"Hello";
	//���͵�ջ֡����������ʾ:
	/*
	|      ��������      |
	|    �������ص�ַ    |
	|       ָ֡��       |
	|     ������֡     |
	|      �ֲ�����      |
	|      ջ������      |
	|������������ļĴ���|
	*/
	//�Ƚ�����ѹջ����ͨ��call�������
	__asm{
		push mystr
		call mmsg
	}
	printf("hello\n");
	return 0;
}

