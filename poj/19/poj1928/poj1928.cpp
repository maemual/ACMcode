#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
struct point
{
	int x;
	int y;
	int num;
}p[2505];

bool cmp(struct point a,struct point b){
	return a.num > b.num;
}
int main()
{
	int t;
	int m,n,k;
	int x;
	scanf("%d",&t);
	while (t--)
	{
		int count = 0;
		scanf("%d%d%d",&m,&n,&k);
		for (int i=0;i<m;i++)
		  for (int j=0;j<n;j++)
		  {
			  scanf("%d",&x);
			  if (x != 0)
			  {
				  p[count].x = i;
				  p[count].y = j;
				  p[count].num = x;
				  count++;
			  }
		  }
		sort(p,p+count,cmp);
		int curX = 0;
		int curY = p[0].y;
		int get = 0;
		k--;
		for (int i=0;i<count;i++)
		{
			k -= abs(p[i].x-curX)+abs(p[i].y-curY);
			if (k >= p[i].x+2)
			{
				get += p[i].num;
				curX = p[i].x;
				curY = p[i].y;
				k--;
			}
			else break;
		}
		printf("%d\n",get);
	}
	return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Peanut {
    int x, y; //坐标
    int n;      //数量    
}p[2501];

bool cmp(struct Peanut a, struct Peanut b) {
    return a.n > b.n;
}

int main()
{
    int cnt, r, c, time, get_peanut;
    int i, Case, num, cur_x, cur_y;
    scanf("%d", &Case);
    while(Case--) {
        scanf("%d%d%d", &r, &c, &time);
        cnt = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                scanf("%d", &num);
                if(0 != num) {
                    p[cnt].x = i; p[cnt].y = j; p[cnt].n = num; cnt++;
                }   
                    
            }    
        }
        sort(p, p+cnt, cmp);
        get_peanut = 0; time -= 1;
        cur_x = 0; cur_y = p[0].y;
        for(i = 0; i < cnt; i++) {
            time -= (abs(p[i].x - cur_x) + abs(p[i].y - cur_y));  
            if(time >= p[i].x+2) {    //检测如果拿起这堆peanut并且能拿出去走到road的时间是否充足
                get_peanut += p[i].n;
                cur_x = p[i].x;
                cur_y = p[i].y;
                time -= 1;       //捡起，要去掉一个单位时间
            //    printf("time: %d x:%d y:%d\n", time, cur_x, cur_y);
            }    
            else break;    
        }
        printf("%d\n", get_peanut);
        
    }    
    return 0;
}*/

