// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"


//DLL��ں���������DLL�ļ���˵DllMain�����Ǳ����
BOOL APIENTRY DllMain( HMODULE hModule, //handle to DLL module
                       DWORD  ul_reason_for_call, //reason for calling function
                       LPVOID lpReserved //reserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

//�Զ��嵼��������������ʱ����MessageBox�ı��⴦��ʾ���ڽ��̵Ľ�����
//extern "C"��ʾ��C�ķ�ʽ���룬��ΪC��֧�����أ����Ա����ᱣ�������������������������
//__declspec(dllexport)��ʾ����һ�������������ú����ӱ�DLL�п��Ÿ���������ʹ��
extern "C" __declspec(dllexport) VOID myMsgBox(wchar_t* szChar){
	wchar_t szFileName[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szFileName, MAX_PATH);//��һ������NULL��ʾ��ȡ��ǰ���н�������·��
	MessageBox(NULL, szChar, szFileName, MB_OK);
}

