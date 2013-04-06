#include<stdio.h>  
#include<stdlib.h>
#include<string.h>  
#include<math.h>  
#define size 4  
int move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};//上 左 右 下  
char op[4]={'U','L','R','D'};  
int map[size][size],map2[size*size],limit,path[100];  
int flag,length;  
//int goal_st[3][3]={{1,2,3},{4,5,6},{7,8,0}};  
int goal[16][2]= {{3,3},{0,0},{0,1}, {0,2},{0,3}, {1,0},   
            {1,1}, {1,2}, {1,3},{2,0}, {2,1}, {2,2},{2,3},{3,0},{3,1},{3,2}};;//目标位置  
int nixu(int a[size*size])  
{  
    int i,j,ni,w,x,y;  
    ni=0;  
    for(i=0;i<size*size;i++)  
    {  
        if(a[i]==0)  
            w=i;  
        for(j=i+1;j<size*size;j++)  
        {  
            if(a[i]>a[j])  
                ni++;  
        }  
    }  
    x=w/size;  
    y=w%size;  
    ni+=abs(x-3)+abs(y-3);  
    if(ni%2==1)  
        return 1;  
    else  
        return 0;  
}  
int hv(int a[][size])//估价函数，曼哈顿距离，小等于实际总步数  
{  
    int i,j,cost=0;  
    for(i=0;i<size;i++)  
    {  
        for(j=0;j<size;j++)  
        {  
            int w=map[i][j];  
            cost+=abs(i-goal[w][0])+abs(j-goal[w][1]);  
        }  
    }  
    return cost;  
}  
void swap(int*a,int*b)  
{  
    int tmp;  
    tmp=*a;  
    *a=*b;  
    *b=tmp;  
}  
void dfs(int sx,int sy,int len,int pre_move)//sx,sy是空格的位置  
{  
    int i,j,nx,ny;  
    if(flag)  
        return;  
    int dv=hv(map);  
    if(len==limit)  
    {  
        if(dv==0)  
        {  
            flag=1;  
            length=len;  
            return;  
        }  
        else  
            return;  
    }  
    else if(len<limit)  
    {  
        if(dv==0)  
        {  
            flag=1;  
            length=len;  
            return;  
        }  
    }  
    for(i=0;i<4;i++)  
    {  
        if(i+pre_move==3&&len>0)//不和上一次移动方向相反，对第二步以后而言  
            continue;      
        nx=sx+move[i][0];  
        ny=sy+move[i][1];  
        if(0<=nx&&nx<size && 0<=ny&&ny<size)  
        {  
            swap(&map[sx][sy],&map[nx][ny]);  
            int p=hv(map);  
            if(p+len<=limit&&!flag)  
            {  
                path[len]=i;  
                dfs(nx,ny,len+1,i);  
                if(flag)  
                    return;  
            }  
            swap(&map[sx][sy],&map[nx][ny]);  
        }  
    }  
}  
int main()  
{  
    int i,j,k,l,m,n,sx,sy;  
    char c,g;  
    i=0;  
    //scanf("%d",&n);  
    while(scanf("%d",&n) != EOF)  
    {  
        flag=0;length=0;  
        memset(path,-1,sizeof(path));  
  
		map2[0] = n;
		if (map2[0] == 16)
			map2[0] = 0;
		if(map2[0]==0)  
		{   
			map[0/size][0%size]=0;  
			sx=0/size;sy=0%size;  
		}  
		else  
		{  
			map[0/size][0%size]=map2[0];  
		}  
        for(i=1;i<16;i++)  
        {  
            scanf("%d",&map2[i]);
			if (map2[i] == 16)
				map2[i] = 0;
            if(map2[i]==0)  
            {   
                map[i/size][i%size]=0;  
                sx=i/size;sy=i%size;  
            }  
            else  
            {  
                map[i/size][i%size]=map2[i];  
            }  
          
        }  
        if(nixu(map2)==1)//该状态可达  
        {  
            limit=hv(map);  
            while(!flag&&length<=50)//题中要求50步之内到达  
            {  
                dfs(sx,sy,0,0);  
                if(!flag)  
                limit++; //得到的是最小步数  
            }  
            if(flag)  
            {  
				printf("%d\n",length);
				/*
                for(i=0;i<length;i++)  
                printf("%c",op[path[i]]);  
                printf("\n");  
				*/
            }  
        }  
        else if(!nixu(map2)||!flag)  
            printf("unsolvable\n");  
    }  
    return 0;  
}  
