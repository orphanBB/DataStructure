/*******
����һ��N���������飬M�β��������������顣ÿ�β���Ϊ���в���֮һ��
����1���ڵ�X����֮�����һ����Y��
����2��ɾ����X������
������ʽ��
5 3
1 2 3 4 5
1 1 6
2 1
2 2
˵����ÿ������֮���ÿո�ָ�
��һ����������N��M��N��M��100000���������Ŀ������
�ڶ���N����������ʾԭ�������顣
������M�У�ÿ�е�һ��������ʾ�������͡�
���ڲ���1��������������X��Y�������������������֤0��X�ܵ�ǰ����ĸ�������X=0����ʾ�����鿪ͷ���롣
���ڲ���2��������һ����X�������������������֤1��X�ܵ�ǰ����ĸ�����
�����ʽ��
6 3 4 5
*/

#include <stdio.h>
int arr[100];
int N;
void ins(int x,int y);
void del(int x);
void display();
int main()
{
    int M;
    int i;
    int option,x,y;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<M;i++)
    {
        scanf("%d",&option);
        if(option==1)
        {
            scanf("%d %d",&x,&y);
            ins(x,y);
        }
        else if(option==2)
        {
            scanf("%d",&x);
            del(x);
        }
    }
    display();
    return 0;
}
void ins(int x,int y)
{
    int i=N;
    while(i!=x)
    {
        arr[i]=arr[i-1];
        i--;
    }
    arr[x]=y;
    N++;
}
void del(int x)
{
    int i;
    for(i=x;i<N;i++)
        arr[i-1]=arr[i];
    N--;
}
void display()
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
}
