#include <stdio.h>  
  
int main()  
{  
    int T, n, i, a[50000], dp1[50000], dp2[50000], max;  
  
    scanf("%d", &T);  
    while (T--)  
    {  
        scanf("%d", &n);  
        scanf("%d", &a[0]);  
  
        dp1[0] = a[0];  
        for (i=1; i<n; i++) //在输入的同时求和，节约时间  
        {  
            scanf("%d", &a[i]);  
            if (dp1[i-1] > 0) dp1[i] = dp1[i-1] + a[i];  
            else dp1[i] = a[i];  
        }  
        for (i=1; i<n; i++) //再次扫描更新最大子段和  
        {  
            if (dp1[i] < dp1[i-1]) dp1[i] = dp1[i-1];  
        }  
  
        dp2[n-1] = a[n-1];  
        for (i=n-2; i>=0; i--) //从右往左求和  
        {  
            if (dp2[i+1] > 0) dp2[i] = dp2[i+1] + a[i];  
            else dp2[i] = a[i];  
        }  
        for (i=n-2; i>=0; i--) //更新  
        {  
            if (dp2[i] < dp2[i+1]) dp2[i] = dp2[i+1];  
        }  
  
        max = dp1[0] + dp2[1];  
        for (i=1; i<n-1; i++)  
        {  
            if (dp1[i] + dp2[i+1] > max) max = dp1[i] + dp2[i+1];  
        }  
        printf("%d\n", max);  
    }  
} 
