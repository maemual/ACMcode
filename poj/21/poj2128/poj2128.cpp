#include <cstdio>
#include <climits>
int main()
{
	int num, index, n, i, pre = 0, min = INT_MAX;
	scanf("%d", &n);
	scanf("%d", &pre);
	for(i = 2; i < n-1; i++){
		scanf("%d", &num);
		if(num - pre < min){
			min = num - pre;
			index = i;
		}
		pre = num;
	}
	scanf("%d", &pre);
	if(n >= 4){
		printf("%ld\n", min + pre);
		printf("%d 1 %d %d\n",index + 1, n, index);
	}
	else{
		printf("0\n");
	}
	return 0;
}
