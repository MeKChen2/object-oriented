#include <iostream>
#include "cal.h"
using namespace std;

int main()
{
	double s, r;
	cout << "please input the radius" << endl;
	while (cin >> r)
	{
		cout << "The area is " << calS(r) << endl;
	}
	return 0;
}