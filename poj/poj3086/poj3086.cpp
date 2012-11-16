#include <cstdio>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	for (int cas=1;cas<=N;cas++)
	{
		int n;
		scanf("%d",&n);
		printf("%d %d ",cas,n);
		int sum=0;
		for (int i=1;i<=n;i++)
			sum += i*(i+1)*(i+2)/2;
		printf("%d\n",sum);
	}
	return 0;
}
