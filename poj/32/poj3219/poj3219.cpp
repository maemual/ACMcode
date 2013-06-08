#include <cstdio>
int n,k;
int main(){
	while(scanf("%d%d",&n,&k) != EOF)
	{
		printf("%d\n", k&(n-k)?0:1);
	}
	return 0;
}
//此为神代码，证明不懂。。。。
