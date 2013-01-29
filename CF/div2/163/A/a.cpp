#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	char str[55];
	scanf("%s",str);
	int i = 0,j = 1;
	int ans = 0;
	while (i < n)
	{
		while (j < n && str[j] == str[i]) j++;
		ans += j - i - 1;
		i = j;
	} 
	printf("%d\n",ans);
	return 0;
}
