/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月17日 星期日 12时47分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

double gpa;
double mmax;
double arr[1005];
double maxgpa;
int c,n,x;
typedef struct point{
	int sc;
	double po;
}point;
point stu[105];
bool cmp(const point &a,const point &b){
	if (a.po > b.po)
		return true;
	else if (a.sc > b.sc)
		return true;
	return false;
}
void dfs(int k,int remin){
	if (remin == 0){
		if (gpa > mmax)
			mmax = gpa;
	}
	if (k == n)
		return;
	if (k == n-1){
		gpa += stu[k].po * (arr[stu[k].sc+remin] - arr[stu[k].sc]);
		dfs(k + 1, 0);
		gpa -= stu[k].po * (arr[stu[k].sc+remin] - arr[stu[k].sc]);
	}else{
		for (int i = 0; i <= remin; i++)
		{
			if (stu[k].sc + i > 1000)
				return;
			if (i != 0 && arr[stu[k].sc + i] == arr[stu[k].sc])
				continue;
			if (i != 0 && arr[stu[k].sc + i] == arr[stu[k].sc + i-1])
				continue;
			
			if (arr[stu[k].sc + i] == arr[stu[k].sc + i - 1] 
				&& arr[stu[k].sc+i] == arr[1000])
				return ;

			double ss = 0;
			for (int j = k; j < n; j++)
			{
				ss += stu[j].po * (arr[1000] - arr[stu[j].sc]);
			}
			if (gpa + ss < mmax)
				return;

			gpa += stu[k].po * (arr[stu[k].sc+i] - arr[stu[k].sc]);
			dfs(k + 1, remin - i);
			gpa -= stu[k].po * (arr[stu[k].sc+i] - arr[stu[k].sc]);
		}
	}
}
int main()
{
	int cas;
	int p;
	double q;
	double sum;
	scanf("%d",&cas);
	for (int cc = 1; cc <= cas; cc++){
		scanf("%d %d %d",&c,&n,&x);
		memset(arr,0,sizeof(arr));
		for (int i = 0; i < c; i++)
		{
			scanf("%d %lf",&p,&q);
			arr[p] = q;
		}
		for (int i = 1; i <= 1000; i++)
		{
			if (arr[i] == 0){
				arr[i] = arr[i-1];
			}
		}
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %lf",&stu[i].sc,&stu[i].po);
			sum += stu[i].po;
		}
		//sort(stu,stu+n,cmp);
		/*
		for (int i = 0; i < n; i++)
		{
			printf("%d %lf\n",stu[i].sc,stu[i].po);
		}
		*/
		gpa = 0;
		mmax = 0;
		dfs(0,x);
		printf("Case %d: %.4lf\n",cc,mmax / sum);
	}
	return 0;
}
