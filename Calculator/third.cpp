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
	char s[50]; //�ַ����飬���ڴ���ַ�����ÿһ���ַ�
	cout << "Please input a string" << endl;
	cin >> input;//�����ַ�������������Enter��ʱ��������
	for (int m = 0; m < 50; m++)
	{
		s[m] = input[m];//���ַ�����Ϊ�ַ�����
	}
	int n = strlen(s);//����ַ�����ĳ���
	int i, j = 0;
	for (i = 0; i < n; i++)
	{
		str.push(s[i]);
		if (s[i] >= 48 && s[i] <= 57)
		{
			j++;//������������֣���j++���Դ��ж��Ƿ񳬹�ʮλ����
		}
	}
	if(j>=11)
	{
		cout << "ERROR!" <<endl;//��j>=11�����г���10λ����ʱ�����򱨴�
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
			cout << str.front();//�������Ԫ��
			str.pop();   //ɾ������Ԫ��
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
	char s[50]; //�ַ����飬���ڴ���ַ�����ÿһ���ַ�
    cout<<"Please input a string"<<endl;
	cin>>input;//�����ַ�������������Enter��ʱ��������
	for(int m=0;m<50;m++)
	{
		s[m]=input[m];//���ַ�����Ϊ�ַ�����
	}
	int n=strlen(s);//����ַ�����ĳ���
	int i,j=0;
	for(i=0;i<n;i++)
	{
		str.push(s[i]);
		if(s[i]>=48 && s[i]<=57)
		{
			j++;//������������֣���j++���Դ��ж��Ƿ񳬹�ʮλ����
		}
	}

	if(j<11)
	{
		while(!str.empty())
		{
			if(str.front()>=48 && str.front()<=57)
			{
				cout<<str.front();//�������Ԫ��
				str.pop();   //ɾ������Ԫ��
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
		cout<<"Error"<<endl;//��j<11�����г���10λ����ʱ�����򱨴�
	}
	system("pause");
}*/