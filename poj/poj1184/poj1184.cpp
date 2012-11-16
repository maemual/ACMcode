#include <cstdio>
#include <cstring>
bool vis[999999];
struct node{
	int step;
	int p;
	char s[7];
}queue[10000000];
char from[7],to[7];
int bfs(){
	int head = 0,tail = 0;
	int num;
	queue[tail].step = 0;
	queue[tail].p = 0;
	strcpy(queue[tail++].s,from);
	sscanf(from,"%d",&num);
	vis[num] = true;
	while (head<=tail){
		//swap0
		if (queue[head].p != 0){
			int step = queue[head].step;
			int point = queue[head].p;
			char temp[7];
			strcpy(temp,queue[head].s);
			char ch = temp[point];
			temp[point] = temp[0];
			temp[0] = ch;
			sscanf(temp,"%d",&num);
			if (!vis[num]){
				vis[num] = true;
				queue[tail].step = step+1;
				queue[tail].p = point;
				strcpy(queue[tail++].s,temp);
				if (!strcmp(temp,to))
				  return step+1;
			}
		}
		//swap1
		if (queue[head].p != 5){
			int step = queue[head].step;
			int point = queue[head].p;
			char temp[7];
			strcpy(temp,queue[head].s);
			char ch = temp[point];
			temp[point] = temp[5];
			temp[5] = ch;
			sscanf(temp,"%d",&num);
			if (!vis[num]){
				vis[num] = true;
				queue[tail].step = step+1;
				queue[tail].p = point;
				strcpy(queue[tail++].s,temp);
				if (!strcmp(temp,to))
				  return step+1;
			}
		}
		//Up
		if (queue[head].s[queue[head].p] != '9'){
			char temp[7];
			strcpy(temp,queue[head].s);
			temp[queue[head].p]++;
			sscanf(temp,"%d",&num);
			if (!vis[num]){
				vis[num] = true;
				queue[tail].step = queue[head].step+1;
				queue[tail].p = queue[head].p;
				strcpy(queue[tail++].s,temp);
				if (!strcmp(temp,to))
				  return queue[head].step+1;
			}
		}
		//Down
		if (queue[head].s[queue[head].p] != '0'){
			char temp[7];
			strcpy(temp,queue[head].s);
			temp[queue[head].p]--;
			sscanf(temp,"%d",&num);
			if (!vis[num]){
				vis[num] = true;
				queue[tail].step = queue[head].step+1;
				queue[tail].p = queue[head].p;
				strcpy(queue[tail++].s,temp);
				if (!strcmp(temp,to))
				  return queue[head].step+1;
			}
		}
		//Left
		if (queue[head].p != 5){
			queue[tail].step = queue[head].step+1;
			queue[tail].p = queue[head].p+1;
			strcpy(queue[tail++].s,queue[head].s);
		}
		//Right
		if (queue[head].p != 0){
			queue[tail].step = queue[head].step+1;
			queue[tail].p = queue[head].p-1;
			strcpy(queue[tail++].s,queue[head].s);
		}
		head++;
	}
	return -1;
}
int main()
{
	while (scanf("%s %s",from,to) != EOF){
		memset(vis,0,sizeof(vis));
		printf("%d\n",bfs());
	}
	return 0;
}
