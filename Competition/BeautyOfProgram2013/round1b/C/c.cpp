#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
struct Point{
	double x,y;
}poin[50005];
double u[50005],v[50005],ans[50005];
int t,m;
double x,y;
void min_dis(double x,double y,double &inf)  //对一个坐标找最小点
{
	inf = 0;
	for(int j=0;j<m;j++)
	{
		double d=(x-u[j])*(x-u[j])+(y-v[j])*(y-v[j]);
		if(d>inf)
			inf=d;
	}
}
int main() {
	scanf("%d",&t);
	int n;
	for (int cc = 1; cc <= t; cc++)
	{
		scanf("%d",&m);
		x = 10000;
		y = 10000;
		for(int i=0;i<m;i++)
			scanf("%lf%lf",&u[i],&v[i]);

		srand((unsigned)time(NULL));  //获得随机种子
		int p=10,l=30;
		for(int i=0;i<p;i++)  //获得矩形内p个随机点
		{
			poin[i].x=(rand()%101)/100.0*x;
			poin[i].y=0;
			min_dis(poin[i].x,poin[i].y,ans[i]);
		}
		double delta=(x>y?x:y)/sqrt(m+0.0),eps=1e-6,PI=asin(1.0)*2.0;
		while(delta>eps)  //模拟退火算法
		{
			for(int i=0;i<p;i++){
				for(int j=0;j<l;j++)
				{
					double an=(rand()%101)/100.0*2.0*PI;  //一个随机角
					double vx=poin[i].x+delta*cos(an),vy=0;
					if (vx<-10000||vy<0||vx>10000||vy>10000) 
						continue; 
					double inf;
					min_dis(vx,vy,inf);
					if(inf<ans[i])
						ans[i]=inf,poin[i].x=vx,poin[i].y=vy;
				}
			}
			delta*=0.9;
		}
		double inf=ans[0];
		int k=0;
		for(int i=1;i<p;i++)
			if(ans[i]<inf) 
				inf=ans[i],k=i;
		printf("Case #%d: %lf\n",cc,poin[k].x);
	}
	return 0;
}
