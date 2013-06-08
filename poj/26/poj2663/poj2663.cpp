#include <stdio.h>
 
int main(){
    int n, i, j, dp[16];
    dp[0] = 1;
    for(i = 1; i <= 15; i ++){
        dp[i] = 3 * dp[i-1];
        for(j = 0; j <= i - 2; j ++)
            dp[i] += 2 * dp[j];
    }
    while(1){
		scanf("%d",&n);
		if (n==-1)
		  break;
        if (n % 2 == 1) 
		  printf("0\n");
        else 
		  printf("%d\n",dp[n/2]);
	}
    return 0;
}
