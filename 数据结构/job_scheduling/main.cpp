#include <iostream>
#include "stdio.h"
#define N_MAX 10         //��������
#define NAME_MAX 100     //������������

using namespace std;

int n;     //���̸���
char name[N_MAX][NAME_MAX];   //����������
int arrival_time[N_MAX];          //���̵���ʱ��
int run_time[N_MAX];          //��������ʱ��
int star_time[N_MAX];         //���̿�ʼʱ��
int Check[N_MAX];             //��ҵ�Ƿ���ɱ��

/**���뺯��
*����ļ�input.txt������
*���ֶ�����
*/
void input()
{
    int i;
    FILE *fp;
    if((fp=fopen("input.txt","rb"))==NULL)
    {
        printf("��������̸���:");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("�����������:");
            scanf("%s",&name[i]);
            printf("���������%s�ĵ���ʱ��:",name[i]);
            scanf("%d",&arrival_time[i]);
            printf("���������%s������ʱ��:",name[i]);
            scanf("%d",&run_time[i]);
        }
    }
        else
        {
            for(i=0;!feof(fp);i++)
            {
                fscanf(fp,"%s",&name[i]);
                fscanf(fp,"%d",arrival_time[i]);
                fscanf(fp,"%d",run_time[i]);
            }
            n=i;
        }
}

/**ѡ���ȵ������ҵ
*/
int select_first(int a[])
{
    int i=0,k,j;
	for(k=0;k<n;k++){
		if(Check[k]==0){
			i=k;
			break;
		}
	}
	for(j=0;j<n;j++){
		if(a[i]>a[j]&&Check[j]==0){
			i=j;
		}
	}
	Check[i]=1;
	return i;
}

/*�����ȷ�����ҵ�����㷨
*/
void FCFS()
{
    printf("��ҵ��  �ύʱ��  ����ʱ��  ��ʼʱ��  ����ʱ��  ��תʱ��  ��Ȩ��תʱ��\n");
}

int main()
{
    input();
    return 0;
}
