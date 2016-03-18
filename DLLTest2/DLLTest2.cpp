// DLLTest2.cpp : 定义控制台应用程序的入口点。

//动态调用，调用在运行时完成而不是在链接时

#include "stdafx.h"

typedef VOID(*PFUNMSG)(char *);

int _tmain(int argc, _TCHAR* argv[])
{
	//加载dll文件
	HMODULE hModule = LoadLibrary(L"SimpleDLL.dll");
	if (hModule == NULL){
		MessageBox(NULL, L"没找到DLL文件", L"GG", MB_OK);
		return 0;
	}
	//通过函数名查找地址后调用
	//PFUNMSG pFunMsg = (PFUNMSG)GetProcAddress(hModule, "myMsgBox");
	//pFunMsg((char*)L"Hello");

	//通过内联汇编调用
	PROC mmsg = GetProcAddress(hModule, "myMsgBox");
	char *mystr =(char*)L"Hello";
	//典型的栈帧布局如下所示:
	/*
	|      函数参数      |
	|    函数返回地址    |
	|       帧指针       |
	|     错误处理帧     |
	|      局部变量      |
	|      栈缓冲区      |
	|被调函数保存的寄存器|
	*/
	//先将参数压栈，再通过call命令调用
	__asm{
		push mystr
		call mmsg
	}
	printf("hello\n");
	return 0;
}

