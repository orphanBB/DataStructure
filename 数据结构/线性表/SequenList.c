#include "stdio.h"
#include "stdlib.h"
#include "SequenList.h"  //����˳���ͷ�ļ�

//˳���ĳ�ʼ����������һ���ձ�
SequenList *Init_SequenList()
{
    SequenList *L;                              //����˳���ָ�����
    L=(SequenList*)malloc(sizeof(SequenList));  //����ռ�
    if(L!=NULL)
    {
        L->last=-1;                             //����˳���ĳ���lastΪ-1,��ʾ˳���Ϊ��
        printf("˳������ɹ���\n");
    }
    else
        printf("˳�����ʧ��!\n");
    return L;
}

//˳�������
//��˳����ӵ�˳���ĺ���
void Add_SequenList(SequenList *L,elemtype data)
{
    if(L->last==MAXSIZE)
    {
        printf("˳���ռ䲻�㣬������ӣ�\n");
    }
    else
    {
        L->last++;              //�Ƚ����鳤�ȼ�1;
        L->data[L->last]=data;  //�����ݴ���˳���
        printf("��ӳɹ���\n");
    }
}

//���뵽ָ��λ��  ��Ԫ��data���뵽��x��λ��
void Insert_SequenList(SequenList *L,int x,elemtype data)
{
    int i;
    //�ȼ��˳����Ƿ���
    if(L->last>=MAXSIZE)
        printf("˳���ռ����������ܲ���\n");
    else if(x<1||x>L->last+2)          //�жϲ���λ���Ƿ���Ч
        printf("����λ����Ч��\n");
    else
    {
        L->last++;
        //�Ƚ�xλ������Ԫ��������
        for(i=L->last;i>=x;i--)
        {
            L->data[i]=L->data[i-1];
        }
        L->data[x-1]=data;
        printf("������ɣ�\n");
    }
}

//ɾ����x��λ�õ�Ԫ��
void Delete_SequenList(SequenList *L,int x)
{
    int i;
    if(L->last==-1)
        printf("˳���Ϊ�գ��޷�ɾ����\n");
    else if(x<1||x>L->last-1)
        printf("ɾ��λ����Ч��\n");
    else
    {
        for(i=x;i<L->last;i++)
        {
            L->data[i]=L->data[i+1];
        }
        L->last--;
    }
}

//��ʾ˳����е�����
void Display_SequenList(SequenList *L)
{
    int i;
    for(i=0;i<=L->last;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}


