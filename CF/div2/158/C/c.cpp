#include <iostream>
using namespace std;

#define MY_MAX 0x7fffffff
const int MAX_LEN = 100005;
long long a[MAX_LEN];
int main()
{
	int n,x;
	cin >> n >> x;
	int min = MY_MAX;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (min > a[i])
			min = a[i];
	}
	for (int i = 0; i < n; i++)
	  a[i] -= min-1;

	x--;
	int sum = 0;
	while (1)
	{
		if (a[x] == 0)
		  break;
		a[x]--;
		sum++;
		x--;
		if (x < 0)
		  x = n-1;
	}
	a[x] += (long long)(min-1)*n+sum;//holy shit.long long!!!
	for (int i = 0; i < n-1; i++)
	  cout << a[i] << ' ';
	cout << a[n-1]<< endl;
	return 0;
}
