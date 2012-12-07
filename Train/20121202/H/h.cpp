#include <stdio.h>
#include <algorithm>
using namespace std;
struct node{
	char name[100];
	int year,mon,day;
}a[105];
bool cmp(const node &a1,const node &a2)
{
	if (a1.year > a2.year)
	  return true;
	else if (a1.year < a2.year)
	  return false;
	else
	{
		if (a1.mon < a2.mon)
		  return false;
		else if (a1.mon > a2.mon)
		  return true;
		else {
			if (a1.day > a2.day)
			  return true;
			else if (a1.day < a2.day)
			  return false;
		}
	}
	return false;
}
int main()
{
	int n;
	int i,j;
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s %d %d %d",a[i].name,&a[i].day,&a[i].mon,&a[i].year);
		}
		sort(a,a+n,cmp);
	//	for (int i = 0; i< n;i++)
	//	{
	//		printf("%s %d %d %d\n",a[i].name,a[i].year,a[i].mon,a[i].day);
	//	}
		printf("%s\n%s\n",a[0].name,a[n-1].name);
	}
	return 0;
}
