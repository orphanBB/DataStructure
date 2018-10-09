/*****
题目描述：
给定两个一元多项式，求这两个多项式的和。
设ax^b为单项式，其中a是项的系数，b是项的指数。
一元多项式可由n个按指数从高到低顺序的单项式组成。例如：A(x) = 7x^8 - 8x^3 + 2x^2 + 9。

输入样式：
4 7 8 -8 3 2 2 9 0
3 -5 8 8 3 3 1
说明：
第一行数字表示多项式A(x) = 7x^8 - 8x^3 + 2x^2 + 9
这里，第1个数字表示A(x)的项数，接下来2个数字表示第1项的系数和指数，以此类推。
第二行表示多项式B(x) = -5x^8 + 8x^3 + 3x

输出样式：
4 2 8 2 2 3 1 9 0

说明：
表示和多项式：C(x) = 2x^8 + 2x^2 + 3x + 9
注意，同类项求和等于0的项，不输出。但若最终结果为常数项0，则应输出：1 0 0，例如求 A(x) = -x,  B(x) = x  之和的情形。
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
