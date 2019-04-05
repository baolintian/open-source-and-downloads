#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define SIZE 4

int score=0;

void get_number(int n[SIZE][SIZE]);//��������
void put_interface(int n[SIZE][SIZE]);//��ӡ��Ϸ����
int is_empty(int n[SIZE][SIZE]);//����Ƿ���δ��ֵ�ĸ���
int is_full(int n[SIZE][SIZE]);//��⸳ֵ�����Ƿ���������ȵ�
void match(int n[SIZE][SIZE],char c);//��������
void key_w(int n[SIZE][SIZE]);//�ĸ��ƶ���
void key_a(int n[SIZE][SIZE]);
void key_s(int n[SIZE][SIZE]);
void key_d(int n[SIZE][SIZE]);

int main()
{
    int n[SIZE][SIZE]={0};
    char c;
    printf("*****************************\n");//��ʼ����
    printf("            2048              \n");
    printf("        key:W/A/S/D\n");
    printf("  press any key to continue...\n");
    printf("******************************\n");
    getch();
    system("cls");

    while (1)
    {
        if (is_empty(n))
        {
            get_number(n);//��������
        }
        if (!(is_empty(n))&&!(is_full(n)))
        {
            break;//��Ϸ��⣬�����������˳���Ϸ
        }
        put_interface(n);//��ӡ��Ϸ����
        c=getch();
        while (c!='w'&&c!='a'&&c!='s'&&c!='d')
        {
            c=getch();
        }
        match(n,c);
        system("cls");

    }
    printf("***********************\n");
    printf("                       \n");
    printf("       Game Over!      \n");
    printf("      Score:%d\n",score);
    printf("                       \n");
    printf("***********************\n");
    getch();

    return 0;
}


void get_number(int n[SIZE][SIZE])//��������
{
    int a,b;
    a=rand()%4;
    b=rand()%4;
    while (n[a][b]!=0)//��δ��ֵ�ĸ��Ӹ�ֵ2
    {
        a=rand()%4;
        b=rand()%4;
    }
    n[a][b]=2;
}

void put_interface(int n[SIZE][SIZE])
{
    int i,j;
    for (i=0;i<SIZE;i++)
    {
        for (j=0;j<SIZE;j++)//һ�����������У��ڶ��д�ӡ���֡�������Ϊ0����ӡ����Ϊ0��ӡ���ֺͷֽ���
        {
            printf("|     ");
        }
        printf("|\n");

        for (j=0;j<SIZE;j++)
        {
            if (n[i][j]!=0)
            {
                printf("|%5d",n[i][j]);
            }
            else
            {
                printf("|     ");
            }
        }
        printf("|\n");

        for (j=0;j<SIZE;j++)
        {
            printf("|_____");
        }
            printf("|\n");
    }
    printf("Score:%d",score);
}

int is_empty(int n[SIZE][SIZE])//����ж��ٸ��ո�
{
    int i,j,count=0;
    for (i=0;i<SIZE;i++)
    {
        for (j=0;j<SIZE;j++)
        {
            if (n[i][j]==0)
            {
                count++;
            }
        }
    }
    //printf("%d",count);
    return count;
}

int is_full(int n[SIZE][SIZE])//����Ƿ�����ȵĿո�
{
    int i,j,count=0;
    for (i=0;i<SIZE;i++)//������
    {
        for (j=0;j<SIZE-1;j++)
        {
            if (n[i][j]==n[i][j+1])
                count++;
        }
    }
    for (j=0;j<SIZE;j++)//������
    {
        for (i=0;i<SIZE-1;i++)
        {
            if (n[i][j]==n[i+1][j])
            {
                count++;
            }
        }
    }
    return count;
}

void match(int n[SIZE][SIZE],char c)
{

    switch(c)
    {
        case 'w':key_w(n);break;
        case 'a':key_a(n);break;
        case 's':key_s(n);break;
        case 'd':key_d(n);break;
        //case 'c':to_clear();break;
        default: ;
    }
}

void key_w(int n[SIZE][SIZE])
{
    int i,j,a;
    int m[SIZE]={0};

    for (j=0;j<SIZE;j++)//�����е������Ƶ����̶�Ӧ�ķ���
    {
        for (a=0;a<SIZE;a++)//
        {
            for (i=0;i<SIZE-1;i++)
            {
                if (n[i][j]==0)
                {
                    n[i][j]=n[i+1][j];
                    n[i+1][j]=0;
                }
            }
        }
    }

    for (j=0;j<SIZE;j++)//����m[]���治Ϊ0�����֣�֮�󷵸�����ﵽ������Ӳ����ƶ���Ŀ��
    {
        for (i=0,a=0;i<SIZE;i++)        
        {
            if (n[i][j]!=n[i+1][j]&&n[i][j]!=0)
            {
                m[a++]=n[i][j];
                n[i][j]=0;
            }
            else if (n[i][j]==n[i+1][j])
            {
                m[a++]=n[i][j]+n[i+1][j];
                score+=m[a-1];//�ӷ�ϵͳ
                n[i][j]=0;
                n[i+1][j]=0;
            }
        }
        for (i=0;i<SIZE;i++)//��m[]�е����ַ�������λ���飬������0
            {
                n[i][j]=m[i];
                m[i]=0;
            }
    }
}

void key_a(int n[SIZE][SIZE])//�����������ͬ��
{
    int i,j,a;
    int m[SIZE]={0};
    for(i=0;i<SIZE;i++)
    {
        for(a=0;a<SIZE;a++)
        {
            for(j=0;j<SIZE-1;j++)
            {
                if(n[i][j]==0)
                {
                    n[i][j]=n[i][j+1];
                    n[i][j+1]=0;
                }
            }
        }
    }

    for(i=0;i<SIZE;i++)
    {
        for(a=0,j=0;j<SIZE;j++)
        {
            if(n[i][j]!=n[i][j+1]&&n[i][j]!=0)
            {
                m[a++]=n[i][j];
                n[i][j]=0;
            }

            else if(n[i][j]==n[i][j+1])
            {
                m[a++]=n[i][j]+n[i][j+1];
                score+=m[a-1];
                n[i][j]=0,n[i][j+1]=0;
            }
        }
        for(j=0;j<SIZE;j++)
        {
            n[i][j]=m[j];
            m[j]=0;
        }
    }

}

void key_s(int n[SIZE][SIZE])
{
    int i,j,a;
    int m[SIZE]={0};
    for(j=SIZE-1;j>=0;j--)
    {
        for(a=SIZE-1;a>=0;a--)
        {
            for(i=SIZE-1;i>0;i--)
            {
                if(n[i][j]==0)
                {
                    n[i][j]=n[i-1][j];
                    n[i-1][j]=0;
                }
            }
        }
    }

    for(j=SIZE-1;j>=0;j--)
    {
        for(a=SIZE-1,i=SIZE-1;i>=0;i--)
        {
            if(n[i][j]!=n[i-1][j]&&n[i][j]!=0)
            {
                m[a--]=n[i][j];
                n[i][j]=0;
            }
            else if(n[i][j]==n[i-1][j])
            {
                m[a--]=n[i][j]+n[i-1][j];
                score+=m[a+1];
                n[i][j]=0,n[i-1][j]=0;
            }
        }

        for(i=SIZE-1;i>=0;i--)
        {
            n[i][j]=m[i];
            m[i]=0;
        }
    }
}

void key_d(int n[SIZE][SIZE])
{
    int i,j,a;
    int m[SIZE]={0};
    for(i=SIZE-1;i>=0;i--)
    {
        for(a=SIZE-1;a>=0;a--)
        {
            for(j=SIZE-1;j>0;j--)
            {
                if(n[i][j]==0)
                {
                    n[i][j]=n[i][j-1];
                    n[i][j-1]=0;
                }
            }
        }
    }

    for(i=SIZE-1;i>=0;i--)
    {
        for(a=SIZE-1,j=SIZE-1;j>=0;j--)
        {
            if(n[i][j]!=n[i][j-1]&&n[i][j]!=0)
            {
                m[a--]=n[i][j];
                n[i][j]=0;
            }
            else if(n[i][j]==n[i][j-1])
            {
                m[a--]=n[i][j]+n[i][j-1];
                score+=m[a+1];
                n[i][j]=0,n[i][j-1]=0;
            }

        }
        for(j=SIZE-1;j>=0;j--)
        {
            n[i][j]=m[j];
            m[j]=0;
        }
    }

}
