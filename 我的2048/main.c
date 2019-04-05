#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define SIZE 4

int score=0;

void get_number(int n[SIZE][SIZE]);//获得随机数
void put_interface(int n[SIZE][SIZE]);//打印游戏界面
int is_empty(int n[SIZE][SIZE]);//检测是否有未赋值的格子
int is_full(int n[SIZE][SIZE]);//检测赋值格子是否有相邻相等的
void match(int n[SIZE][SIZE],char c);//操作键盘
void key_w(int n[SIZE][SIZE]);//四个移动键
void key_a(int n[SIZE][SIZE]);
void key_s(int n[SIZE][SIZE]);
void key_d(int n[SIZE][SIZE]);

int main()
{
    int n[SIZE][SIZE]={0};
    char c;
    printf("*****************************\n");//初始界面
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
            get_number(n);//获得随机数
        }
        if (!(is_empty(n))&&!(is_full(n)))
        {
            break;//游戏检测，不满足条件退出游戏
        }
        put_interface(n);//打印游戏界面
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


void get_number(int n[SIZE][SIZE])//获得随机数
{
    int a,b;
    a=rand()%4;
    b=rand()%4;
    while (n[a][b]!=0)//给未赋值的格子赋值2
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
        for (j=0;j<SIZE;j++)//一个格子有三行，第二行打印数字。其中若为0不打印，不为0打印数字和分界线
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

int is_empty(int n[SIZE][SIZE])//检测有多少个空格
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

int is_full(int n[SIZE][SIZE])//检测是否有相等的空格
{
    int i,j,count=0;
    for (i=0;i<SIZE;i++)//横向检查
    {
        for (j=0;j<SIZE-1;j++)
        {
            if (n[i][j]==n[i][j+1])
                count++;
        }
    }
    for (j=0;j<SIZE;j++)//纵向检查
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

    for (j=0;j<SIZE;j++)//将所有的数字移到键盘对应的方向
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

    for (j=0;j<SIZE;j++)//数组m[]保存不为0的数字，之后返给数组达到数字相加并且移动的目的
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
                score+=m[a-1];//加分系统
                n[i][j]=0;
                n[i+1][j]=0;
            }
        }
        for (i=0;i<SIZE;i++)//将m[]中的数字返还给二位数组，并且清0
            {
                n[i][j]=m[i];
                m[i]=0;
            }
    }
}

void key_a(int n[SIZE][SIZE])//后面的三个键同理
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
