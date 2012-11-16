#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
using namespace std;
const int INF = 0x3fffffff;
const int MAXN = 110;
int n;
int map[MAXN][MAXN];
bool flag[MAXN];  //��ʾ�ڵ�i�Ƿ��ڣ����ɳ��ڽӱ�)
int dis[MAXN];  //distance
int Dijkstra(int x)
{
   int i, j;
   dis[x] = 0;
   for(i = 1; i < n; i++)
      dis[i] = INF;
  // memset(flag, 0, sizeof(flag));
   for(i = 0; i < n; i++)  //n���ڵ㲻������
   {
      int minVex, minValue = INF;
      for(j = 0; j < n; j++)         //�ҳ���СȨֵ�ڵ㣬Ҳ���ǽ���ڵĽڵ�
      {
         if(!flag[j] && dis[j] < minValue)
         {
            minVex = j;
            minValue = dis[j];
         }
      }
      flag[minVex] = true;  //���
      for(j = 1; j < n; j++)  //���ڽӶ������·���ɳ�
      {
         if((dis[j] > dis[minVex]+map[minVex][j]))//!flag[j] && map[j][minVex] < INF &&
            dis[j] = dis[minVex]+map[minVex][j];
      }
   }
   return 0;
}
int main()
{
   char s[MAXN];
   scanf("%d", &n);
  // memset(map, 0, sizeof(map));
   for(int i = 1; i < n; i++)
   {
      for(int j = 0; j < i; j++)
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
   for(int k = 1; k < n; k++)
      if(dis[k] > max)
         max = dis[k];
   printf("%d\n", max);
   return 0;
}

