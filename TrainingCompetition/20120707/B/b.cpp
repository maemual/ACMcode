#include <cstdio>
#include <cstring>
const int MAX_LEN = 50000;
double f[MAX_LEN+5];
int c[MAX_LEN+5];
double w[MAX_LEN+5];
int n[MAX_LEN+5];
double type[MAX_LEN+5];
int N,V;
double max(double a,double b)
{
	return a>b?a:b;
}
void ZeroOnePack(int cost,double weight)
{
	//for (int i=0;i<=N;i++)  
	  for (int v=V;v>=cost;v--)
		f[v] = max(f[v],f[v-cost]+weight);
}
void CompletePack(int cost,double weight)
{
	//for (int i=1;i<=N;i++)
		for (int v=cost;v<=V;v++)
			f[v] = max(f[v],f[v-cost]+weight);
}
void MultiplePack(int cost,double weight,int amount)
{
	if (cost*amount >= V)
	{
		CompletePack(cost,weight);
		return;
	}
	int k=1;
	int num = amount;
	while (k < num)
	{
		ZeroOnePack(k*cost,k*weight);
		amount -= k;
		k *=2;
	}
	ZeroOnePack(amount*cost,amount*weight);
}
int main()
{
	//int N,V;
	memset(f,0,sizeof(0));
	while(scanf("%d%d",&N,&V) != EOF)
	{
		double x,y;
		for (int i=1;i<=N;i++)
		{
			scanf("%d%lf%d",&n[i],&y,&type[i]);
			c[i]=1;
			w[i]=y/n[i];
			//printf("%lf\n",w[i]);
		}
		for (int i=1;i<=N;i++)
		{
			if (type[i] == 1)
			{
				CompletePack(c[i],w[i]);
			}else {
				MultiplePack(c[i],w[i],n[i]);
			}
		}
		double max = -1;
		//for (int i=0;i<=V;i++)
		//  if (max < f[i])
		//	max = f[i];
		printf("%.2lf\n",f[V]);
	}
	return 0;
}
