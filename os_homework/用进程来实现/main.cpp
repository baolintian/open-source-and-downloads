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
    TCHAR szCommandLine1[] = TEXT("driver");//����WCHAR
    TCHAR szCommandLine2[] = TEXT("seller");
    //LPWSTR szCommandLine = TEXT("NOTEPAD");//����
    //STARTUPINFO si = { sizeof(si) };
    STARTUPINFO si[2];
    PROCESS_INFORMATION pi[2];
    ZeroMemory(&si, sizeof(si));
    si[0].cb = sizeof(si[0]);
    ZeroMemory(&pi[0], sizeof(pi[0]));
    si[1].cb = sizeof(si[1]);
    ZeroMemory(&pi[1], sizeof(pi[1]));
    si[0].dwFlags = STARTF_USESHOWWINDOW;  // ָ��wShowWindow��Ա��Ч
    si[0].wShowWindow = TRUE;          // �˳�Ա��ΪTRUE�Ļ�����ʾ�½����̵������ڣ�
                        // ΪFALSE�Ļ�����ʾ
    si[1].dwFlags = STARTF_USESHOWWINDOW;  // ָ��wShowWindow��Ա��Ч
    si[1].wShowWindow = TRUE;          // �˳�Ա��ΪTRUE�Ļ�����ʾ�½����̵������ڣ�
    BOOL bRet1 = ::CreateProcess (
        NULL,           // ���ڴ�ָ����ִ���ļ����ļ���
        szCommandLine1,      // �����в���
        NULL,           // Ĭ�Ͻ��̰�ȫ��
        NULL,           // Ĭ���̰߳�ȫ��
        FALSE,          // ָ����ǰ�����ڵľ�������Ա��ӽ��̼̳�
        CREATE_NEW_CONSOLE, // Ϊ�½��̴���һ���µĿ���̨����
        NULL,           // ʹ�ñ����̵Ļ�������
        NULL,           // ʹ�ñ����̵���������Ŀ¼
        &si[0],
        &pi[0]);
    BOOL bRet2 = ::CreateProcess (
        NULL,           // ���ڴ�ָ����ִ���ļ����ļ���
        szCommandLine2,      // �����в���
        NULL,           // Ĭ�Ͻ��̰�ȫ��
        NULL,           // Ĭ���̰߳�ȫ��
        FALSE,          // ָ����ǰ�����ڵľ�������Ա��ӽ��̼̳�
        CREATE_NEW_CONSOLE, // Ϊ�½��̴���һ���µĿ���̨����
        NULL,           // ʹ�ñ����̵Ļ�������
        NULL,           // ʹ�ñ����̵���������Ŀ¼
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
