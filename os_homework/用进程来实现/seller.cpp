#include <bits/stdc++.h>
#include <windows.h>
#include "var.h"
const int N = 1;
using namespace std;
void seller()
{
	while(1)
	{
        //WAIT_OBJECT_0是常数0；single只需要传入一个线程，并且等待的时间为无线
        if(WaitForSingleObject(s2,INFINITE)==WAIT_OBJECT_0)//P(s2)
        {
		    Sleep(2000);
			cout<<"开门，买票\n\n";
			Sleep(4000);
			cout<<"关门，\n\n";
			ReleaseSemaphore(s1,1,NULL);//V(s1)加
		}
	}
}
int main(){
    HANDLE thread; //定义两线程句柄
    DWORD threadID;
    s1 = CreateSemaphore(NULL,N,N,"the driver");//安全特性，同步信号量，初值N，最大N，信号量的名称
    s2 = CreateSemaphore(NULL,0,N,"the seller");//同步信号量，初值0，最大N
    thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(seller),NULL,0,&threadID);
    WaitForSingleObject(thread,INFINITE);//等待结束
    return 0;
}
