#include <bits/stdc++.h>
#include <windows.h>
#include "var.h"
const int N = 1;
using namespace std;
void seller()
{
	while(1)
	{
        //WAIT_OBJECT_0�ǳ���0��singleֻ��Ҫ����һ���̣߳����ҵȴ���ʱ��Ϊ����
        if(WaitForSingleObject(s2,INFINITE)==WAIT_OBJECT_0)//P(s2)
        {
		    Sleep(2000);
			cout<<"���ţ���Ʊ\n\n";
			Sleep(4000);
			cout<<"���ţ�\n\n";
			ReleaseSemaphore(s1,1,NULL);//V(s1)��
		}
	}
}
int main(){
    HANDLE thread; //�������߳̾��
    DWORD threadID;
    s1 = CreateSemaphore(NULL,N,N,"the driver");//��ȫ���ԣ�ͬ���ź�������ֵN�����N���ź���������
    s2 = CreateSemaphore(NULL,0,N,"the seller");//ͬ���ź�������ֵ0�����N
    thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(seller),NULL,0,&threadID);
    WaitForSingleObject(thread,INFINITE);//�ȴ�����
    return 0;
}
