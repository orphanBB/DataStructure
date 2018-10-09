/*****
��Ŀ������
��������һԪ����ʽ��������������ʽ�ĺ͡�
��ax^bΪ����ʽ������a�����ϵ����b�����ָ����
һԪ����ʽ����n����ָ���Ӹߵ���˳��ĵ���ʽ��ɡ����磺A(x) = 7x^8 - 8x^3 + 2x^2 + 9��

������ʽ��
4 7 8 -8 3 2 2 9 0
3 -5 8 8 3 3 1
˵����
��һ�����ֱ�ʾ����ʽA(x) = 7x^8 - 8x^3 + 2x^2 + 9
�����1�����ֱ�ʾA(x)��������������2�����ֱ�ʾ��1���ϵ����ָ�����Դ����ơ�
�ڶ��б�ʾ����ʽB(x) = -5x^8 + 8x^3 + 3x

�����ʽ��
4 2 8 2 2 3 1 9 0

˵����
��ʾ�Ͷ���ʽ��C(x) = 2x^8 + 2x^2 + 3x + 9
ע�⣬ͬ������͵���0�����������������ս��Ϊ������0����Ӧ�����1 0 0�������� A(x) = -x,  B(x) = x  ֮�͵����Ρ�
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node *next;
};
typedef struct node PolyList;

PolyList* CreatPoly();
void PrintPoly(PolyList * head);
void AddPoly(PolyList *PA,PolyList* PB);

int main()
{
    PolyList *PA,*PB;
    PA=CreatPoly();
    PB=CreatPoly();
    AddPoly(PA,PB);
    PrintPoly(PA);
}

PolyList* CreatPoly()
{
    PolyList *head,*p,*tail;
    int ic,ie,n;
    head=(PolyList*)malloc(sizeof(PolyList));
    head->next=NULL;
    tail=head;
    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%d %d",&ic,&ie);
        p=(PolyList*)malloc(sizeof(PolyList));
        p->coef=ic;
        p->exp=ie;
        tail->next=p;
        tail=p;
        tail->next=NULL;
        n--;
    }
    return head;
}

void PrintPoly(PolyList * head)
{
    PolyList *p;
    int m=0;
    p=head->next;
    while(p!=NULL)
    {
        p=p->next;
        m++;
    }
    if(m!=0)
    printf("%d ",m);
    if(m==0)
        printf("1 0 0");
    p=head->next;
    while(p!=NULL)
    {
        printf("%d %d ",p->coef,p->exp);
        p=p->next;
    }
}

void AddPoly(PolyList *PA,PolyList* PB)
{
    PolyList *pa,*pb,*tail,*s;
    int sum;
    pa=PA->next;pb=PB->next;
    tail=PA;  PB->next=NULL;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->exp<pb->exp)
        {
            tail->next=pb;
            tail=pb;
            pb=pb->next;
        }
        else if(pa->exp>pb->exp)
        {
            tail->next=pa;
            tail=pa;
            pa=pa->next;
        }
        else
        {
            sum=pa->coef+pb->coef;
            if(sum!=0)
            {
                pa->coef=sum;    tail->next=pa;
                tail=pa;         pa=pa->next;
                s=pb;            pb=pb->next;
                free(s);
            }
            else
            {
                s=pa;pa=pa->next;free(s);
                s=pb;pb=pb->next;free(s);
            }
        }
    }
    if(!pa&&!pb)
        tail->next=NULL;
    if(pa!=NULL)
        tail->next=pa;
    if(pb!=NULL)
        tail->next=pb;
}
