#include<stdio.h>
#include<string.h>
//#include<iostream>
#include<stdlib.h>

int main()
{
 char str[20];
 int i,j,n,a,b,sum;
 scanf("%d %d",&a,&b);
 //if(a>=-1000000 && a<=1000000 && b<=1000000 && b>=-1000000){
 sum=a+b;
 if(sum<0)
 {
	 sum=-sum;
	 printf("-");
 }
 //itoa(sum,str,10);//������ת�����ַ���
 sprintf(str,"%d",sum);
 n=strlen(str);//�õ����ַ����ĳ���
 for(i=0;i<n;i++)
 {
	 if(((i+1)%3==n%3)&&((i+1)!=n))
	 {
		 putchar(str[i]);
		 putchar(',');
	 }//���������������i+1�������ڸ��ַ������ȳ���3��������������һ�����Ÿ���
	 else
	 {
		 putchar(str[i]);
		 //printf("%d",&j);
	 }//ͬ������ʱ����Ҫ�Ӷ��Ÿ���
 }//}
 //printf("\n");
 //system("pause");
 return 0;
}