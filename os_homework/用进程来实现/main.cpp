#include<iostream>
#include <bits/stdc++.h>
#include<windows.h>
#include "var.h"
using namespace std;
const int N = 1;
HANDLE WINAPI CreateThread(
     LPSECURITY_ATTRIBUTES lpThreadAttributes,
     SIZE_T dwStackSize,
     LPTHREAD_START_ROUTINE lpStartAddress,
     LPVOID lpParameter,
     DWORD dwCreationFlags,
     LPDWORD lpThreadId
    );
int main()
{
    cout<<sizeof(s1)<<endl;
    TCHAR szCommandLine1[] = TEXT("driver");//或者WCHAR
    TCHAR szCommandLine2[] = TEXT("seller");
    //LPWSTR szCommandLine = TEXT("NOTEPAD");//错误
    //STARTUPINFO si = { sizeof(si) };
    STARTUPINFO si[2];
    PROCESS_INFORMATION pi[2];
    ZeroMemory(&si, sizeof(si));
    si[0].cb = sizeof(si[0]);
    ZeroMemory(&pi[0], sizeof(pi[0]));
    si[1].cb = sizeof(si[1]);
    ZeroMemory(&pi[1], sizeof(pi[1]));
    si[0].dwFlags = STARTF_USESHOWWINDOW;  // 指定wShowWindow成员有效
    si[0].wShowWindow = TRUE;          // 此成员设为TRUE的话则显示新建进程的主窗口，
                        // 为FALSE的话则不显示
    si[1].dwFlags = STARTF_USESHOWWINDOW;  // 指定wShowWindow成员有效
    si[1].wShowWindow = TRUE;          // 此成员设为TRUE的话则显示新建进程的主窗口，
    BOOL bRet1 = ::CreateProcess (
        NULL,           // 不在此指定可执行文件的文件名
        szCommandLine1,      // 命令行参数
        NULL,           // 默认进程安全性
        NULL,           // 默认线程安全性
        FALSE,          // 指定当前进程内的句柄不可以被子进程继承
        CREATE_NEW_CONSOLE, // 为新进程创建一个新的控制台窗口
        NULL,           // 使用本进程的环境变量
        NULL,           // 使用本进程的驱动器和目录
        &si[0],
        &pi[0]);
    BOOL bRet2 = ::CreateProcess (
        NULL,           // 不在此指定可执行文件的文件名
        szCommandLine2,      // 命令行参数
        NULL,           // 默认进程安全性
        NULL,           // 默认线程安全性
        FALSE,          // 指定当前进程内的句柄不可以被子进程继承
        CREATE_NEW_CONSOLE, // 为新进程创建一个新的控制台窗口
        NULL,           // 使用本进程的环境变量
        NULL,           // 使用本进程的驱动器和目录
        &si[1],
        &pi[1]);
    if(bRet1&&bRet2)
    {
        while(true){
            WaitForSingleObject(pi[0].hProcess, 100);
            WaitForSingleObject(pi[1].hProcess, 100);
        }
    }
    return 0;
    return 0;
}
