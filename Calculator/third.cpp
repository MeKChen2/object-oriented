#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Scan
{
public:
	queue<char>ToStringQueue(string  input);
	string tin;
};

class Print
{
public:
	void getprint(queue<char>str);
};

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
	for (i = 0; i < n; i++)
	{
		str.push(s[i]);
		if (s[i] >= 48 && s[i] <= 57)
		{
			j++;//如果输入是数字，则j++，以此判断是否超过十位数字
		}
	}
	if(j>=11)
	{
		cout << "ERROR!" <<endl;//当j>=11，即有超过10位数字时，程序报错
		exit(0);
	}
	return str;
}

void Print::getprint(queue<char>str)
{
    while (!str.empty())
	{
		if (str.front() >= 48 && str.front() <= 57)
		{
			cout << str.front();//输出队首元素
			str.pop();   //删除队首元素
		}
		else if (str.front() != 40 && str.front() != 41 && str.front() != 46)
		{
			cout << endl;
			cout << str.front() << endl;
			str.pop();
		}
		else if (str.front() == 40)
		{
			cout << str.front() << endl;
			str.pop();
		}
		else if (str.front() == 41)
		{
			cout << endl << str.front();
			str.pop();
		}
		else
		{
			cout << str.front();
			str.pop();
		}
	}
	cout << endl;
}

int main()
{
	Scan sc;
	Print pr;
	queue<char>str;
	str = sc.ToStringQueue(sc.tin);
	pr.getprint(str);
	system("pause");
	return 0;
}




/*#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<char> str;

void main(){
	string input;
	char s[50]; //字符数组，用于存放字符串的每一个字符
    cout<<"Please input a string"<<endl;
	cin>>input;//输入字符串，当输入是Enter键时结束输入
	for(int m=0;m<50;m++)
	{
		s[m]=input[m];//将字符串变为字符数组
	}
	int n=strlen(s);//测出字符数组的长度
	int i,j=0;
	for(i=0;i<n;i++)
	{
		str.push(s[i]);
		if(s[i]>=48 && s[i]<=57)
		{
			j++;//如果输入是数字，则j++，以此判断是否超过十位数字
		}
	}

	if(j<11)
	{
		while(!str.empty())
		{
			if(str.front()>=48 && str.front()<=57)
			{
				cout<<str.front();//输出队首元素
				str.pop();   //删除队首元素
			}
			else if(str.front()!=40 && str.front()!=41 && str.front()!=46)
			{
				cout<<endl;
				cout<<str.front()<<endl;
				str.pop();
			}
			else if(str.front()==40)
			{
				cout<<str.front()<<endl;
				str.pop();
			}
			else if(str.front()==41)
			{
				cout<<endl<<str.front();
				str.pop();
			}
			else
			{
				cout<<str.front();
				str.pop();
			}
		}
		cout<<endl;
	}
	else
	{
		cout<<"Error"<<endl;//当j<11，即有超过10位数字时，程序报错
	}
	system("pause");
}*/