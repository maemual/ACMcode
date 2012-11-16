#include <iostream>  
#include <cstdio>
using namespace std;  
  
int data[100000], dp[100000];  
int main()  
{  
    int n;  
    while(scanf("%d", &n) != EOF){  
        if(!n)  
            break;  
        int sum = 0, maxSum = -999999999;  
        for(int i = 0; i < n; i++){  
            scanf("%d", &data[i]);  
            sum += data[i];  
            if(sum > maxSum)  
                maxSum = sum;  
            dp[i] = maxSum;  
            if(sum < 0)  
                sum = 0;  
        }  
		for (int i=0;i<n;i++)
		  printf("%d ",dp[i]);
		printf("\n");
        sum = 0;  
        int ans = -999999999;  
        for(int i = n-1; i > 0; i--){  
            sum += data[i];  
            if(dp[i-1]+sum > ans)  
                ans = dp[i-1]+sum;  
            if(sum < 0)  
                sum = 0;  
        }  
        printf("%d\n", ans);  
    }  
    return 0;  
}  
