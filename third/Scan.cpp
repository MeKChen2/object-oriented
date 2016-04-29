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
	char s[50]; //字符数组，用于存放字符串的每一个字符
	cout << "Please input a string" << endl;
	cin >> input;//输入字符串，当输入是Enter键时结束输入
	for (int m = 0; m < 50; m++)
	{
		s[m] = input[m];//将字符串变为字符数组
	}
	int n = strlen(s);//测出字符数组的长度
	int i, j = 0;
	/*for (i = 0; i < n; i++)
	{
		str.push(s[i]);
		if (s[i] >= 48 && s[i] <= 57)
		{
			j++;//如果输入是数字，则j++，以此判断是否超过十位数字
		}
	}
	if (j >= 11)
	{
		cout << "ERROR!" << endl;//当j>=11，即有超过10位数字时，程序报错
		exit(0);
	}*/
	return str;
}