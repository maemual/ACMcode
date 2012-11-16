#include<stdio.h>  
  
#include<memory.h>  
  
#include<stdlib.h>  
  
#define maxn 102  
  
int d[maxn],g[maxn][maxn],f[maxn][maxn],pre[maxn],map[maxn][maxn],sum[maxn],current[maxn];  
  
int n,m,num,mm;  
  
struct node  
  
{  
  
int x,y;  
  
}seg[1000],time[1000];  
  
#define oo 0xfffffff  
  
int cmp(const void *a,const void *b)  
  
{  
  
struct node *va=(struct node*)a;  
  
struct node *vb=(struct node*)b;  
  
return va->x-vb->x;  
  
}  
  
void rev_bfs(int t)  
  
{  
  
int queue[maxn],flag[maxn];  
  
int head,tail,i;  
  
memset(sum,0,sizeof(sum));  
  
for (i=0;i<=n+49;i++)  
  
{  
  
d[i]=n+49;  
  
sum[n+49]++;  
  
}  
  
sum[n+49]--;  
  
sum[0]++;  
  
d[t]=0;  
  
queue[1]=t;  
  
flag[t]=1;  
  
head=1;tail=1;  
  
memset(flag,0,sizeof(flag));  
  
while (head<=tail)  
  
{  
  
for (i=0;i<=n+49;i++)  
  
if (flag[i]==0&&g[i][queue[head]]>0)  
  
{  
  
queue[++tail]=i;  
  
d[i]=d[queue[head]]+1;  
  
sum[n+49]--;  
  
sum[d[i]]++;  
  
flag[i]=1;  
  
}  
  
head++;  
  
}  
  
}  
  
void augment(int s,int t)  
  
{  
  
int i,min;  
  
min=oo;  
  
for (i=t;i!=s;i=pre[i])  
  
if (g[pre[i]][i]<min)  
  
min=g[pre[i]][i];  
  
for (i=t;i!=s;i=pre[i])  
  
{  
  
g[pre[i]][i]-=min;;  
  
g[i][pre[i]]+=min;  
  
f[pre[i]][i]+=min;  
  
f[i][pre[i]]-=min;  
  
}  
  
}  
  
int retreat(int *u,int s)  
  
{  
  
int v,min;  
  
min=n+49;  
  
for (v=0;v<=n+49;v++)  
  
if (g[*u][v]>0&&d[v]<min)  
  
min=d[v];  
  
sum[d[*u]]--;  
  
if ((sum[d[*u]])==0&&d[*u]<=n+49) return 0;  
  
d[*u]=min+1;  
  
sum[d[*u]]++;  
  
current[*u]=0;  
  
if (*u!=s) *u=pre[*u];  
  
return 1;  
  
}  
  
void ISAP(int s,int t)  
  
{  
  
int u,v;  
  
rev_bfs(t);  
  
u=s;  
  
while (d[s]<n+50)  
  
{   
  
for (v=current[u];v<=n+49;v++)   
  
if (g[u][v]>0&&d[u]==d[v]+1)  
  
break;  
  
if (v<=n+49)  
  
{  
  
current[u]=v;  
  
pre[v]=u;  
  
u=v;  
  
if (u==t)  
  
{  
  
augment(s,t);  
  
u=s;  
  
}  
  
}  
  
else if (retreat(&u,s)==0) return;  
  
}  
  
}  
  
void init()  
  
{  
  
int i,j,a,b,c,d,min,t,k,ans,max,st,en,temp;  
  
while (scanf("%d",&n)!=EOF&&n)  
  
{  
  
memset(map,0,sizeof(map));;  
  
for (i=1;i<=n;i++)  
  
{  
  
scanf("%d%d",&m,&t);  
  
map[48][i+48]=t/30;  
  
num=0;  
  
mm=0;  
  
for (j=1;j<=m;j++)  
  
{  
  
scanf("%d:%d %d:%d",&a,&b,&c,&d);  
  
if (a==c&&b==d)  
  
{  
  
for (k=0;k<48;k++)  
  
map[i+48][k]=1;  
  
continue;  
  
}  
  
if (c==0&&d==0)  
  
{  
  
num++;  
  
seg[num].x=a*60+b;  
  
seg[num].y=1440;  
  
}  
  
else if (a*60+b>c*60+d)  
  
{  
  
num++;  
  
seg[num].x=a*60+b;  
  
seg[num].y=1440;  
  
num++;  
  
seg[num].x=0;  
  
seg[num].y=c*60+d;  
  
}  
  
else  
  
{  
  
num++;  
  
seg[num].x=a*60+b;  
  
seg[num].y=c*60+d;  
  
}  
  
}  
  
if (num==0) continue;  
  
qsort(seg+1,num,sizeof(seg[1]),cmp);  
  
st=seg[1].x;en=seg[1].y;  
  
seg[num+1].x=1500;seg[num+1].y=1600;  
  
for (j=2;j<=num+1;j++)  
  
{  
  
a=seg[j].x;  
  
b=seg[j].y;  
  
if (st<=a&&a<=en&&en<b)  
  
en=b;  
  
else if (a>en)  
  
{  
  
mm++;  
  
time[mm].x=st;  
  
time[mm].y=en;  
  
st=a;  
  
en=b;  
  
}  
  
}  
  
for (j=1;j<=mm;j++)  
  
{  
  
a=time[j].x/60;  
  
b=time[j].x-60*a;  
  
c=time[j].y/60;  
  
d=time[j].y-60*c;  
  
if (a==c)  
  
{  
  
if (b==0&&d>=30)  
  
map[i+48][a*2]=1;  
  
}  
  
else  
  
{  
  
if (b>0&&b<=30) b=30;  
  
if (b>30)   
  
{  
  
a++;  
  
b=0;  
  
}  
  
if (d<30) d=0;  
  
if (d>30) d=30;  
  
while (a!=c||b!=d)  
  
{  
  
map[i+48][a*2+b/30]=1;  
  
b+=30;  
  
if (b==60)  
  
{  
  
a++;  
  
b=0;  
  
}  
  
}  
  
}  
  
}  
  
}  
  
max=oo;  
  
for (j=0;j<48;j++)  
  
{  
  
temp=0;  
  
for (k=49;k<n+49;k++)  
  
if (map[k][j]>0) temp++;  
  
if (temp<max)  
  
max=temp;  
  
}  
  
ans=0;  
  
for (j=1;j<=max;j++)  
  
{  
  
memset(g,0,sizeof(g));  
  
memset(f,0,sizeof(f));  
  
memset(current,0,sizeof(current));  
  
for (i=0;i<=49+n;i++)  
  
for (k=0;k<=49+n;k++)  
  
g[i][k]=map[i][k];  
  
for (i=0;i<48;i++)  
  
g[i][n+49]=j;  
  
ISAP(48,n+49);  
  
min=oo;  
  
for (i=0;i<48;i++)  
  
if (f[i][n+49]<min)  
  
min=f[i][n+49];  
  
if (min>ans) ans=min;  
  
}  
  
printf("%d\n",ans);  
  
 }  
  
 }  
  
 int main()  
  
 {  
  
 
  
init();  
  
return 0;  
  
 }  

