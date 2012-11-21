#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF  0x3fffffff
#define MAXN 110
int n;
int map[MAXN][MAXN];
int flag[MAXN]; 
int dis[MAXN]; 
int Dijkstra(int x)
{
   int i, j;
   dis[x] = 0;
   for(i = 1; i < n; i++)
      dis[i] = INF;
   for(i = 0; i < n; i++) 
   {
      int minVex, minValue = INF;
      for(j = 0; j < n; j++) 
      {
         if(!flag[j] && dis[j] < minValue)
         {
            minVex = j;
            minValue = dis[j];
         }
      }
      flag[minVex] = 1; 
      for(j = 1; j < n; j++) 
      {
         if((dis[j] > dis[minVex]+map[minVex][j]))
            dis[j] = dis[minVex]+map[minVex][j];
      }
   }
   return 0;
}
int main()
{
   char s[MAXN];
   scanf("%d", &n);
   int i,j;
   for(i = 1; i < n; i++)
   {
      for(j = 0; j < i; j++)
      {
         scanf("%s", s);
         if(s[0] == 'x')
           map[i][j] = map[j][i] = INF;
         else
            map[i][j] = map[j][i] = atoi(s);
      }
   }
 
   Dijkstra(0);
   int max = 0;
   int k;
   for(k = 1; k < n; k++)
      if(dis[k] > max)
         max = dis[k];
   printf("%d\n", max);
   return 0;
}

