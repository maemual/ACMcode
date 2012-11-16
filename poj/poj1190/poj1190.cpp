/*
 *	Problem: 1190		User: maemual
 *	Memory: 388K		Time: 32MS
 *	Language: G++		Result: Accepted
 *	2012-07-21 16:50:01
 */
#include <cstdio>
#include <cmath>
#include <climits>
#include <time.h>
int n,m;
int ans;
int last[]={0,1,9,36,100,225,441,784,1296,2025,3025,4356,6084,8281,11025,14400,18496,23409,29241,36100,44100};
void dfs(int sum,int v,int p,int q,int k)
{
	if (k>m)
	{
		if (v != n)
		  return;
		if (sum<ans)
		  ans=sum;
		return;
	}
	for (int r=p;r>=m-k+1;r--)
	{
		if (k==1)
		  sum=r*r;
		for (int h=q;h>=m-k+1;h--)
		{
			if (v+r*r*h<=n-last[m-k] && 2*(n-v)/r+sum<ans)
			//第2个是神剪枝，从TLE直接降到32ms。剩余体积/现在的半径，是小于剩下的面积的。
			{
				dfs(sum+2*r*h,v+r*r*h,r-1,h-1,k+1);
			}
		}
	}
}
int main()
{
	//clock_t start,finish;
	//double totaltime;
	//start=clock();
	scanf("%d%d",&n,&m);
	ans=INT_MAX;
	dfs(0,0,(int)sqrt(n),n,1);
	if (ans != INT_MAX)
		printf("%d\n",ans);
	else 
		printf("0\n");
	//finish=clock();
	//totaltime= (double)(finish-start)/CLOCKS_PER_SEC;
	//printf("Time:%lf\n",totaltime);
	return 0;
}
