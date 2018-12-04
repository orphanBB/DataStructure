#include <stdio.h>
#include <stdlib.h>
#include "SequenList.h"

int select;
SequenList *L;

void Menu();

int main()
{
    Menu();
//    int n,i,data;
//    printf("请输入初始化数据项数：");
//    scanf("%d",&n);
//    for(i=0;i<n;i++)
//    {
//        scanf("%d",&data);
//        Add_SequenList(L,(elemtype)data);
//        Display_SequenList(L);
//    }
    return 0;
}


void Menu()
{
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");  // ┏ ┳ ┓ ┣ ╋ ┫ ┗ ┻ ┛  ━ ┃
    printf("┃\t\t\t\t\t顺序表系统\t\t\t\t\t┃\n");
    printf("┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
    printf("┃               1.创建顺序表                ┃                 2.添加数据                ┃\n");
    printf("┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
    printf("┃               3.插入数据                  ┃                 4.删除数据                ┃\n");
    printf("┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
    printf("┃               5.查看数据                  ┃                 6.退出系统                ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("请输入您的操作序号：");
    scanf("%d",&select);
}

void Option()
{
    switch(select)
    {
    case 1:
        {
            L=(SequenList*)malloc(sizeof(SequenList));
            L=Init_SequenList();
        }
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        printf("输入有误，请重新输入");
    }
}

void Add()
{
    printf("请输入需要添加的数据项数：");
    scanf("%d",)
}
