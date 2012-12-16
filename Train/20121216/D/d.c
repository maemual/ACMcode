#include <stdio.h>
#include <string.h>
#define MAX_LEN 505

int a[MAX_LEN][MAX_LEN], b[MAX_LEN][MAX_LEN] , c[MAX_LEN][MAX_LEN];
int temp1[MAX_LEN];
int temp2[MAX_LEN];
int temp3[MAX_LEN];
int n;

int equal()
{
	int i;
	for(i = 0; i < n; i++)
	  if(temp1[i] != temp3[i]) 
		return 0;
	return 1;
}

int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		memset(temp1, 0, sizeof(temp1));
		memset(temp2, 0, sizeof(temp2));
		memset(temp3, 0, sizeof(temp3));
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)  
			  scanf("%d",&a[i][j]);
		for( i = 0; i < n; i++)
			for(j = 0; j < n; j++)  
				scanf("%d",&b[i][j]);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)  
			  scanf("%d",&c[i][j]);

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			  temp2[i] += (j+1) * a[j][i];

		for (i = 0; i < n; i++)
		  for (j = 0; j < n; j++)
			temp1[i] += temp2[j] * b[j][i];

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				temp3[i] += (j+1) * c[j][i];

		if(equal())
		  printf("YES\n");
		else
		  printf("NO\n");
	}  
	return 0;
}
