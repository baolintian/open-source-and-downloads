#include <bits/stdc++.h>
#include <windows.h>
#include "var.h"
const int N = 1;
using namespace std;
void driver()
{
	while(1)
	{
	    //接受s1的数据
        if(WaitForSingleObject(s1,INFINITE)==WAIT_OBJECT_0)//P(s1)
        {
			cout<<"司机正在开车\n\n";
			Sleep(2000);
			cout<<"到站，停车\n\n";
			ReleaseSemaphore(s2,1,NULL);//V(s2)
			//传出s2的数据
        }
	}
}
int main(){
    HANDLE thread; //定义两线程句柄
    s1 = CreateSemaphore(NULL,N,N,"the driver");//安全特性，同步信号量，初值N，最大N，信号量的名称
    s2 = CreateSemaphore(NULL,0,N,"the seller");//同步信号量，初值0，最大N
    DWORD threadID;
    thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(driver),NULL,0,&threadID);
    WaitForSingleObject(thread,INFINITE);//等待结束
    return 0;
}
