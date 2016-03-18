// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"


//DLL入口函数，对于DLL文件来说DllMain并不是必须的
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

//自定义导出函数，被调用时会在MessageBox的标题处显示所在进程的进程名
//extern "C"表示以C的方式编译，因为C不支持重载，所以编译后会保留函数名，方便其它程序调用
//__declspec(dllexport)表示声明一个导出函数，该函数从本DLL中开放给其它函数使用
extern "C" __declspec(dllexport) VOID myMsgBox(wchar_t* szChar){
	wchar_t szFileName[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szFileName, MAX_PATH);//第一个参数NULL表示获取当前运行进程所在路径
	MessageBox(NULL, szChar, szFileName, MB_OK);
}

