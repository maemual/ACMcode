/*************************************************************************
	> File Name: poj1167.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月20日 星期三 15时23分59秒
 ************************************************************************/

#include<cstdio>
#include<string.h>
int n,begin,end,min,tmp;
int time[60],used[60],first[60];

void init(){
	memset(time,0,sizeof(time));
	memset(used,0,sizeof(used));
	memset(first,0,sizeof(first));
}
bool check(int first, int inte){
	for (int i = first; i < 60; i += inte){
		if (time[i] - used[i] <= 0)
			return false;
	}
	return true;
}
void use(int first, int inte, int x){
	for (int i = first; i < 60; i += inte){
		used[i] += x;
	}
}
void dfs(int k){
	if (k == 60){
		if (tmp < min)
			min = tmp;
		return;
	}
	if (tmp > min)
		return;
	//如果在k分钟的时候没有公交车
	if (time[k] - used[k] <= 0){
		int i;
		for (i = k + 1; i < 60; i++){
			if (time[i] - used[i] > 0){
			//寻找下一辆公交车
				break;
			}
		}
		dfs(i);
		return;
	}
	//默认假设这辆车是第二辆车，进行可行性验证
	for (int i = begin; 2 * i < k; i++){
		if (first[i] > 0){//存在第一辆车
			if (check(k, k - i)){//并且后面能构成等差数列
				first[i]--;
				use(k, k - i, 1);
				dfs(k);
				use(k, k - i, -1);
				first[i]++;
			}
		}
	}
	//上面不成立的话，那么就假设这辆车是第一辆车
	//第一辆车必然是在(0,30)之间的
	if (k * 2 < end){
		first[k]++;
		used[k]++;
		tmp++;
		dfs(k);
		tmp--;
		used[k]--;
		first[k]--;
	}
}
int main()
{
	init();
	scanf("%d",&n);
	if (n == 0){
		printf("0\n");
		return 0;
	}
	scanf("%d",&tmp);
	time[tmp]++;
	begin = tmp;
	for (int i = 1; i < n; i++){
		scanf("%d",&tmp);
		time[tmp]++;
	}
	end = tmp;
	min = n / 2;
	tmp = 0;
	dfs(begin);
	printf("%d\n", min);
	return 0;
}
