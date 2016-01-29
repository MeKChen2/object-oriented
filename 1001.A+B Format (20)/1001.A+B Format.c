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
 //itoa(sum,str,10);//将整数转换成字符串
 sprintf(str,"%d",sum);
 n=strlen(str);//得到该字符串的长度
 for(i=0;i<n;i++)
 {
	 if(((i+1)%3==n%3)&&((i+1)!=n))
	 {
		 putchar(str[i]);
		 putchar(',');
	 }//如果从左往右数第i+1个数等于该字符串长度除以3的余数，则多输出一个逗号隔开
	 else
	 {
		 putchar(str[i]);
		 //printf("%d",&j);
	 }//同理，不等时不需要加逗号隔开
 }//}
 //printf("\n");
 //system("pause");
 return 0;
}