#ifndef SEQUENLIST_H_INCLUDED
#define SEQUENLIST_H_INCLUDED

typedef int elemtype;  //定义元素类型为整型

#define MAXSIZE 1000   //定义顺序表的最大长度

//定义顺序表结构体
typedef struct sequenlist
{
    char *name;
    elemtype data[MAXSIZE]; //顺序表数据域
    int last;               //用于记录当前最后一个元素的下标
}SequenList;

//顺序表的初始化
SequenList *Init_SequenList();
void Add_SequenList(SequenList *L,elemtype data);
void Insert_SequenList(SequenList *L,int x,elemtype data);
void Display_SequenList(SequenList *L);
void Delete_SequenList(SequenList *L,int x);
#endif // SEQUENLIST_H_INCLUDED
