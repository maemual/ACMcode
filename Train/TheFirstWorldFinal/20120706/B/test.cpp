#include <iostream>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int s=0;
	for (int i=2;i<=n;i++)
	{
		s = (s+m) % i;
		cout << s << endl;
	}
	return 0;
}
