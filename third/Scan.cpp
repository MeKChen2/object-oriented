#include "Scan.h"
#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>
using namespace std;

Scan::Scan()
{
}


Scan::~Scan()
{
}

queue<char>Scan::ToStringQueue(string input)
{
	queue<char>str;
	char s[50]; //�ַ����飬���ڴ���ַ�����ÿһ���ַ�
	cout << "Please input a string" << endl;
	cin >> input;//�����ַ�������������Enter��ʱ��������
	for (int m = 0; m < 50; m++)
	{
		s[m] = input[m];//���ַ�����Ϊ�ַ�����
	}
	int n = strlen(s);//����ַ�����ĳ���
	int i, j = 0;
	/*for (i = 0; i < n; i++)
	{
		str.push(s[i]);
		if (s[i] >= 48 && s[i] <= 57)
		{
			j++;//������������֣���j++���Դ��ж��Ƿ񳬹�ʮλ����
		}
	}
	if (j >= 11)
	{
		cout << "ERROR!" << endl;//��j>=11�����г���10λ����ʱ�����򱨴�
		exit(0);
	}*/
	return str;
}