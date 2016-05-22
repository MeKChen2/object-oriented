#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int add;
	int data;
	int nadd;
};

int main()
{
	int fadd;
	int n,k;
	vector<node>a(100000);
	vector<node> b;
	vector<node> c;
	node temp;
	cin >> fadd >> n >> k;
	
	for (int i=0; i < n; i++)
	{
		cin >> temp.add >> temp.data >> temp.nadd;
		a[temp.add] = temp;
	}
	
	if (fadd == -1)
	{
		cout << "-1" << endl;
	}
	else
	{
	    int nextadd = fadd;
        while (nextadd != -1)
        {
            b.push_back(a[nextadd]);
            nextadd = a[nextadd].nadd;
        }

        int N2 = b.size();
        int rdx = k - 1;
        while (rdx < N2)
        {
            for (int i = rdx; i >  rdx - k; i--)
            {
                c.push_back(b[i]);
            }
            rdx += k;
        }
        for (int i = rdx - k + 1; i < N2; i++)
        {
            c.push_back(b[i]);
        }
        for (int i = 0; i < N2 - 1; i++)
        {
            c[i].nadd = c[i+1].add;
            printf("%05d %d %05d\n", c[i].add, c[i].data, c[i].nadd);
        }
        printf("%05d %d %d", c[N2 - 1].add, c[N2 - 1].data, -1);

    }
        
    return 0;
}
