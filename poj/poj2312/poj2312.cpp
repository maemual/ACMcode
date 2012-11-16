#include <cstdio>
#include <limits.h>
const int MAX_LEN = 300;
char map[MAX_LEN+5][MAX_LEN+5];
int n,m,xsta,ysta,xend,yend;
int dx[]={1,-1,0, 0};
int dy[]={0, 0,1,-1};
int vis[MAX_LEN+5][MAX_LEN+5];
struct node{
	int x,y,step;
}queue[1000000];

void bfs(int xs,int ys){
	int head = 0,tail = 0;
	int x,y,step,xx,yy,s;
	queue[tail].x = xs;
	queue[tail].y = ys;
	queue[tail++].step = 0;
	vis[xs][ys] = 0;
	while (head<=tail){
		x = queue[head].x;
		y = queue[head].y;
		step = queue[head++].step;
		for (int i=0;i<4;i++){
			xx = x + dx[i];
			yy = y + dy[i];
			s = step;
			if (xx>=0&&yy>=0&&xx<m&&yy<n&&map[xx][yy]&&map[xx][yy]!='R'&&map[xx][yy]!='S'){
				if (map[xx][yy]=='B'){
					s += 2;
				}else 
					s++;
				if (vis[xx][yy] > s){
					vis[xx][yy] = s;
					queue[tail].x = xx;
					queue[tail].y = yy;
					queue[tail++].step = s;
				}
			}
		}
	}
}
int main()
{
	while (1){
		scanf("%d %d",&m,&n);
		if (m==0&&n==0)
		  break;

		for (int i=0;i<MAX_LEN+5;i++)
		  for (int j=0;j<MAX_LEN+5;j++)
			vis[i][j] = INT_MAX;

		for (int i=0;i<m;i++){
			getchar();
			for (int j=0;j<n;j++){
				map[i][j] = getchar();
				if (map[i][j] == 'Y'){
					xsta = i;
					ysta = j;
				}else if (map[i][j] == 'T'){
					xend = i;
					yend = j;
				}
			}
		}

		bfs(xsta,ysta);

		if (vis[xend][yend] != INT_MAX)
			printf("%d\n",vis[xend][yend]);
		else
			printf("-1\n");
	}
	return 0;
}
