#ifndef SEQUENLIST_H_INCLUDED
#define SEQUENLIST_H_INCLUDED

typedef int elemtype;  //����Ԫ������Ϊ����

#define MAXSIZE 1000   //����˳������󳤶�

//����˳���ṹ��
typedef struct sequenlist
{
    char *name;
    elemtype data[MAXSIZE]; //˳���������
    int last;               //���ڼ�¼��ǰ���һ��Ԫ�ص��±�
}SequenList;

//˳���ĳ�ʼ��
SequenList *Init_SequenList();
void Add_SequenList(SequenList *L,elemtype data);
void Insert_SequenList(SequenList *L,int x,elemtype data);
void Display_SequenList(SequenList *L);
void Delete_SequenList(SequenList *L,int x);
#endif // SEQUENLIST_H_INCLUDED
