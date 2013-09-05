//O(N^2logN)
#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int mm=333;

struct point
{
    double x,y;
    point(){}
    point(double _x,double _y):x(_x),y(_y){}
}g[mm];
struct alpha
{
    double angle;
    bool flag;
}s[mm];
bool cmp(alpha P,alpha Q)
{
    return P.angle<Q.angle;
}
double SqrDis(point P,point Q)
{
    return (P.x-Q.x)*(P.x-Q.x)+(P.y-Q.y)*(P.y-Q.y);
}
int CircleMaxPoint(int n,double r)
{
    int i,j,m,sum,ret=n>0;
    double tmp,rad;
    for(i=0;i<n;++i)
    {
        m=0;
        for(j=0;j<n;++j)
            if(i!=j&&(tmp=SqrDis(g[i],g[j]))<=4)
            {
                rad=acos(sqrt(tmp)/2);
                tmp=atan2(g[j].y-g[i].y,g[j].x-g[i].x);
                s[m].angle=tmp-rad,s[m++].flag=1;
                s[m].angle=tmp+rad,s[m++].flag=0;
            }
        sort(s,s+m,cmp);
        for(sum=j=0;j<m;++j)
        {
            if(s[j].flag)++sum;
            else --sum;
            ret=max(ret,sum+1);
        }
    }
    return ret;
}
int main()
{
    int i,n;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;++i)
            scanf("%lf%lf",&g[i].x,&g[i].y);
        printf("%d\n",CircleMaxPoint(n,1.0));
    }
    return 0;
}
