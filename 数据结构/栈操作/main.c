/*题目描述：
给定一个栈（初始为空，元素类型为正整数，且小于等于100），只有两个操作：入栈和出栈。
给定N次操作，请输出操作之后的栈顶元素。
（出题人：潘理）

输入样式：
3
1 2
1 9
2

说明：
第一行表示N个操作。
从第二行开始，第1个数表示操作，1表示入栈，2表示出栈。如果是入栈，则第2个数表示入栈的整数。

输出样式：
2

说明：
输出最终栈顶元素，若最终栈空，输出-1。
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
