#include <iostream>
#include <string>
#include <queue>
#include "Scan.h"
#include "Print.h"
using namespace std;


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