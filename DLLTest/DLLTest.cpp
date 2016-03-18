// DLLTest.cpp : 定义控制台应用程序的入口点。

//静态调用SimpleDLL.dll中的函数，通过链接器将DLL函数的导出函数写进可执行文件

#include "stdafx.h"

#pragma comment (lib,"SimpleDLL")

extern "C" void myMsgBox(wchar_t* szChar);

int _tmain(int argc, _TCHAR* argv[])
{
	myMsgBox(L"Hello");
	return 0;
}

