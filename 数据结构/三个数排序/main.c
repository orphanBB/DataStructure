#include <stdio.h>
#include <stdlib.h>
/*��Ŀ��������������x,y,z���������������С���������
1.���������������취����С�����ŵ�x�ϣ��Ƚ�x��y���бȽϣ����x>y��x��y��ֵ���н�����
Ȼ������x��z���бȽϣ����x>z��x��z��ֵ���н�����������ʹx��С��
*/

int main()
{
    int x,y,z,temp;
    printf("input the value of x,y,z:");
    scanf("%d %d %d",&x,&y,&z);
    if(x>y)
    {
        temp=x;
        x=y;
        y=temp;
        if(x>z)
    {
        temp=x;
        x=z;
        z=temp;
    }
    }
    printf("form min to max:%d %d %d",x,y,z);
    return 0;
}
