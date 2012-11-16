#include <stdio.h>
#include <string.h>

struct point{
	int x,y;
}pp[800];
int flag[800];
int main(){
	int n;
	int i,j,k;
	while(scanf("%d",&n) &&n){
	  for(i = 0; i < n; ++i)
		  scanf("%d%d",&pp[i].x,&pp[i].y);
	  int mmax = 0;
	  memset(flag,0,sizeof(flag));
	  for(i = 0; i < n; ++i){
		  for(j = i + 1;j < n; ++j){
			  int s = 2;
			  int a = pp[j].x - pp[i].x;
			  int b = pp[j].y - pp[i].y;
			  for(k = j + 1; k < n; ++k){
			     int c = pp[k].x - pp[j].x;
				 int d = pp[k].y - pp[j].y;
				 if(a * d == c * b)
					 s++;
			  }
			  if(mmax < s)
				  mmax = s;
		  }
	  }
	  printf("%d\n",mmax);
	}
	return 0;
}
