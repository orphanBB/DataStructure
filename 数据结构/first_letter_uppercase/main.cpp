//����һ��Ӣ��  ��ÿ�����ʵ�һ����ĸ��д

#include <iostream>
#include "stdio.h"
#include "string.h"
using namespace std;
char cstr[110];

int main()
{
    int i,n;
    gets(cstr);
    n=strlen(cstr);
    cstr[0]-=' ';
    for(i=0;i<n;i++)
    {
        if(cstr[i]==' ')
            cstr[i+1]-=' ';
    }
    cout<<cstr;
    return 0;
}
