#include "Print.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

Print::Print()
{
}


Print::~Print()
{
}

void Print::getprint(queue<char> str)
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