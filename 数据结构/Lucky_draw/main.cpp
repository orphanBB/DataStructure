/*
��Ŀ������
������һ���齱������췽�������ǳ���һЩ��Ƭ��ÿ�ſ�Ƭ��ӡ��������ĸ��
ÿ���˿���ƾ���֤�������ɿ�Ƭ�����ڿ�Ƭ�ܹ�һ���˲�������ࣩܶ����
����ʱ�����췽���������һ����ĸ������⴮��ĸ�е�ÿ����ĸ������ĳһ��
�˵Ŀ�Ƭ���ҵ��Ļ�����ô�Ǹ��˾��ܻ�����췽�䷢�Ľ�Ʒ��CoCo������������
��Ƭ�����������ж����Ƿ��ܻ񽱡�

Input��
��һ������һ���ַ�����ʾ���췽����������Ǵ��ַ���������С��100��
�ڶ�������һ��������n��n��50��,��ʾCoCo����Ŀ�Ƭ������
������n�У�ÿ������һ���ַ�������ʾCoCo����ÿһ�ſ�Ƭ�ϵ����ݡ�

Output��
���CoCo�ܹ������Yes���������No��

������ʽ��
zhimakaimen
6
sdm
zmk
ai
idf
henfd
nk

�����ʽ��
Yes
*/

//��������
//<p>ilikethisgame</p><p>3</p><p>ac</p><p>bc</p><p>d</p>
//<p>abcdefghigk</p><p>5</p><p>abba</p><p>ok</p><p>ihgfe</p><p>dcmo</p><p>pob</p>

#include <iostream>
#include "string.h"
#define N 50

using namespace std;

char luckystr[101],str[101];
int res[N];
int m;

int findchar(char c,char* tempstr)
{
    int i,n;
    n=strlen(tempstr);
    for(i=0;i<n;i++)
    {
        if(tempstr[i]==c)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    int i,temp=0;
    char card[N][101];
    cin>>luckystr;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>card[i];
        strcat(str,card[i]);
    }
    m=strlen(luckystr);
    for(i=0;i<m;i++)
    {
        res[i]=findchar(luckystr[i],str);
    }
    for(i=0;i<m;i++)
    {
        if(res[i]==1)
            temp++;
    }
    if(temp==m)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
