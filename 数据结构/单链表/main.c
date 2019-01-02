#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct Stu{
    int num;
    char name[10];
    char sex[4];
    char major[20];
    char class[10];
}stu;

typedef struct linklist{
    stu student;
    struct linklist *next;
}LinkList;

LinkList *Create_LinkList();  //ͷ�巨
LinkList *Create_LinkList2(); //β�巨
int Display_LinkList(LinkList *head);  //����������ʾ
int LinkList_Lenght(LinkList *head);  //����ĳ���
LinkList *getData_LinkList(LinkList *head,int i);

int main()
{
    int length=0;
    LinkList* p;
    p=Create_LinkList2();
    Display_LinkList(p);
    length=LinkList_Lenght(p);
    printf("����Ϊ��%d\n",length);
    printf("���ң�ѧ��Ϊ4��ѧ����Ϣ:");
    //LinkList *resarch=getData_LinkList(p,4);

    return 0;
}

//ͷ�巨����������
LinkList *Create_LinkList()
{
    stu student;
    LinkList *head,*p;
    head=(LinkList *)malloc(sizeof(LinkList));  //����ͷ�ڵ�ָ��
    if(head==NULL)
        return head;      //����ʧ��  ���ؿ�ָ��
    head->next=NULL;
    printf("������ѧ����Ϣ��ѧ�š��������Ա�רҵ���༶,��ѧ��Ϊ-1��������\n");
    scanf("%d",&student.num);
    scanf("%s %s %s %s",&student.name,&student.sex,&student.major,&student.class);
    while(1)
    {
        p=(LinkList*)malloc(sizeof(LinkList));
        if(p==NULL)
            return head;
        p->student=student;
        p->next=head->next;
        head->next=p;
        scanf("%d",&student.num);
        if(student.num==-1)
            break;
        scanf("%s %s %s %s",&student.name,&student.sex,&student.major,&student.class);
    }
    return head;
}

//������ı���
int Display_LinkList(LinkList *head)
{
    LinkList *p=head->next;
    if(p==NULL)
        return 0;
    while(p!=NULL)
    {
        printf("%d %s %s %s %s\n",p->student.num,p->student.name,p->student.sex,p->student.major,p->student.class);
        p=p->next;
    }
    return 1;
}

//β�巨����������
LinkList *Create_LinkList2()
{
    stu student;
    LinkList *head,*p,*tail;
    head=(LinkList*)malloc(sizeof(LinkList));
    if(head==NULL)
        return 0;
    head->next=NULL;
    tail=head;
    printf("������ѧ����Ϣ��ѧ�š��������Ա�רҵ���༶,��ѧ��Ϊ-1��������\n");
    scanf("%d",&student.num);
    scanf("%s %s %s %s",&student.name,&student.sex,&student.major,&student.class);
    while(1)
    {
        p=(LinkList*)malloc(sizeof(LinkList));
        if(p==NULL)
            return head;
        p->student=student;
        tail->next=p;
        tail=p;
        tail->next=NULL;
        scanf("%d",&student.num);
        if(student.num==-1)
            break;
        scanf("%s %s %s %s",&student.name,&student.sex,&student.major,&student.class);
    }
    return head;
}

//������ĳ���
int LinkList_Lenght(LinkList *head)
{
    LinkList *p=head;
    int j=0;
    while(p->next!=NULL)
    {
        p=p->next;
        j++;
    }
    return j;
}

//������Ĳ���8
LinkList *getData_LinkList(LinkList *head,int i)
{
    LinkList *p;
    int j=0;
    if(i <= 0)
        return NULL;
    p=head;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    if(i==j)
        return p;
    else
        return NULL;
}
