#include <iostream>
#include <cmath>
using namespace std;

long long a[41]={0,0,0,
26,
75,
216,
622,
1791,
5157,
14849,
42756,
123111,
354484,
1020696,
2938977,
8462447,
24366645,
70160958,
202020427,
581694636,
1674922950,
4822748423,
13886550633,
};
int main()
{
	int n;
	int k=0;
	while (cin >> n)
	{
		printf("Case %d: %lld",++k,a[n]);
	}
	return 0;
}
