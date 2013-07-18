/*************************************************************************
	> File Name: test.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月18日 星期四 11时25分34秒
 ************************************************************************/

#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
const double eps = 1e-8;
const int N = 10000;
map<string,int> m1;
struct node{
	char name[30];
	double rate;
	bool operator<(node x)const{
		if(fabs(rate-x.rate)>eps)return rate>x.rate;
		return strcmp(name,x.name)<0;
	}
}p[500];
bool prim[N];
int v[N],sc[500];
bool J(int x){
	if(x==0||x==1)return 0;
	int i,k=(int)sqrt(1.0*x);
	for(i=2;i<=k;i++)if(x%i==0)return 0;
	return 1;
}
int main(){
	int T,i,j,R,S,Q,x,n,m;
	char team[30],sex[2];
	for(i=0;i<N;i++)prim[i]=J(i);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(v,0,sizeof(v));m1.clear();
		scanf("%d",&R);while(R--)scanf("%d",&x),v[x]=1;
		scanf("%d",&S);while(S--)scanf("%d",&x),v[x]=2;
		scanf("%d",&Q);while(Q--)scanf("%s%d",team,&x),m1[team]=x;
		for(i = 0; i < n; i++){
			scanf("%s%s%s%d%d", p[i].name, team , sex, &R , &S);
			if (sex[0]=='M') 
				p[i].rate = 0;
			else 
				p[i].rate = 33;
			if (m1[team] == 1) 
				p[i].rate += 36;
			else if (m1[team] == 2)
				p[i].rate += 27;
			else if (m1[team] == 3)
				p[i].rate +=18;
			while(R--){
				scanf("%d",&x);
				if(v[x]==1)
					p[i].rate+=2.5;
				else if(v[x]==2)
					p[i].rate+=1.5;
				else {
					if(prim[x])
						p[i].rate+=1;
					else 
						p[i].rate+=0.3;
				}
			}
			for(j = 0; j<S; j++)
				scanf("%d",sc+j);
			sort(sc, sc+S);
			if(S>2)
				p[i].rate += max(0.0,(sc[S-3]-1200)/100.0)*1.5;
		}
		sort(p, p+n);
		for(i = 0; i<m; i++)
			printf("%s %.3lf\n",p[i].name,p[i].rate);
	}
	return 0;
}
