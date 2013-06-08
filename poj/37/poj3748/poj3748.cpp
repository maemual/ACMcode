#include <stdio.h>
#include <bitset>
using namespace std;
int main()
{
	int n,x,y;
	while (scanf("%x,%d,%d",&n,&x,&y) != EOF)
	{
		bitset<32> bit(n);
		bit.set(x,0);
		bit.set(y,1);
		bit.set(y-1,1);
		bit.set(y-2,0);
		printf("%x\n",bit.to_ulong());
	}
	return 0;
}
