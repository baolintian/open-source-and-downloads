#include <bits/stdc++.h>
#include <windows.h>
#include "var.h"
const int N = 1;
using namespace std;
void driver()
{
	while(1)
	{
	    //����s1������
        if(WaitForSingleObject(s1,INFINITE)==WAIT_OBJECT_0)//P(s1)
        {
			cout<<"˾�����ڿ���\n\n";
			Sleep(2000);
			cout<<"��վ��ͣ��\n\n";
			ReleaseSemaphore(s2,1,NULL);//V(s2)
			//����s2������
        }
	}
}
int main(){
    HANDLE thread; //�������߳̾��
    s1 = CreateSemaphore(NULL,N,N,"the driver");//��ȫ���ԣ�ͬ���ź�������ֵN�����N���ź���������
    s2 = CreateSemaphore(NULL,0,N,"the seller");//ͬ���ź�������ֵ0�����N
    DWORD threadID;
    thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(driver),NULL,0,&threadID);
    WaitForSingleObject(thread,INFINITE);//�ȴ�����
    return 0;
}
