/*��Ŀ������
����һ��ջ����ʼΪ�գ�Ԫ������Ϊ����������С�ڵ���100����ֻ��������������ջ�ͳ�ջ��
����N�β��������������֮���ջ��Ԫ�ء�
�������ˣ�����

������ʽ��
3
1 2
1 9
2

˵����
��һ�б�ʾN��������
�ӵڶ��п�ʼ����1������ʾ������1��ʾ��ջ��2��ʾ��ջ���������ջ�����2������ʾ��ջ��������

�����ʽ��
2

˵����
�������ջ��Ԫ�أ�������ջ�գ����-1��
*/
#include <stdio.h>
#define MAX 20

typedef struct Stack{
    int data[MAX];
    int top;
}Stack;

void push(Stack *S,int data);
int pop(Stack *S);

int main()
{
    int N,operate,num;
    Stack S;
    S.top=-1;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&operate);
        if(operate==1)
        {
            scanf("%d",&num);
            push(&S,num);
        }
        else if(operate==2)
        {
            pop(&S);
        }
    }
    if(S.top>=0)
        printf("%d",S.data[S.top]);
    else
        printf("-1");
    return 0;
}

void push(Stack *S,int data)
{
    S->top++;
    S->data[S->top]=data;
}

int pop(Stack *S)
{
    return S->data[S->top--];
}
