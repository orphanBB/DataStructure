#include "stdio.h"
#include "stdlib.h"
#include "SequenList.h"  //包含顺序表头文件

//顺序表的初始化，即构造一个空表
SequenList *Init_SequenList()
{
    SequenList *L;                              //定义顺序表指针变量
    L=(SequenList*)malloc(sizeof(SequenList));  //分配空间
    if(L!=NULL)
    {
        L->last=-1;                             //设置顺序表的长度last为-1,表示顺序表为空
        printf("顺序表创建成功！\n");
    }
    else
        printf("顺序表创建失败!\n");
    return L;
}

//顺序表的添加
//按顺序添加到顺序表的后面
void Add_SequenList(SequenList *L,elemtype data)
{
    if(L->last==MAXSIZE)
    {
        printf("顺序表空间不足，不能添加！\n");
    }
    else
    {
        L->last++;              //先将数组长度加1;
        L->data[L->last]=data;  //将数据存入顺序表
        printf("添加成功！\n");
    }
}

//插入到指定位置  将元素data插入到第x个位置
void Insert_SequenList(SequenList *L,int x,elemtype data)
{
    int i;
    //先检查顺序表是否满
    if(L->last>=MAXSIZE)
        printf("顺序表空间已满，不能插入\n");
    else if(x<1||x>L->last+2)          //判断插入位置是否有效
        printf("插入位置无效！\n");
    else
    {
        L->last++;
        //先将x位及其后的元素往后移
        for(i=L->last;i>=x;i--)
        {
            L->data[i]=L->data[i-1];
        }
        L->data[x-1]=data;
        printf("插入完成！\n");
    }
}

//删除第x个位置的元素
void Delete_SequenList(SequenList *L,int x)
{
    int i;
    if(L->last==-1)
        printf("顺序表为空，无法删除！\n");
    else if(x<1||x>L->last-1)
        printf("删除位置无效！\n");
    else
    {
        for(i=x;i<L->last;i++)
        {
            L->data[i]=L->data[i+1];
        }
        L->last--;
    }
}

//显示顺序表中的内容
void Display_SequenList(SequenList *L)
{
    int i;
    for(i=0;i<=L->last;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}


