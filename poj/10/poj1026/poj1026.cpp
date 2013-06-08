#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNUM=205;
int num[MAXNUM],cir[MAXNUM][MAXNUM],cnt,n,times;
bool vis[MAXNUM];
char mesg[MAXNUM];
int circle()
{
	int i,j,cnt=0;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++){
		int len=0,temp=i;
		while(!vis[temp]){
			vis[temp]=true;
			cir[cnt][++len]=temp;
			temp=num[temp];
		}
		if(len!=0){
			cir[cnt][0]=len;
			cnt++;
		}
	}
	return cnt;    
}
void solve()
{
	int i,j;
	for(i=0;i<cnt;i++){
		int len=times%cir[i][0];
		while(len--){
			for(j=2;j<=cir[i][0];j++){
				char temp=mesg[cir[i][1]];
				mesg[cir[i][1]]=mesg[cir[i][j]];
				mesg[cir[i][j]]=temp;
			}
		}
	}
	for(i=1;i<=n;i++)printf("%c",mesg[i]);
	printf("\n");
}
int main(){
	int i,j;
	while(scanf("%d",&n)&&n){
		for(i=1;i<=n;i++){
			scanf("%d",&num[i]);
		}
		cnt=circle();
		while(scanf("%d",&times)&&times){
			memset(mesg,0,sizeof(mesg));
			gets(mesg);
			for(i=strlen(mesg);i<=n;i++)mesg[i]=' ';
			mesg[n+1]='\0';
			solve();
		}
		printf("\n");
	}
	return 0;
}
