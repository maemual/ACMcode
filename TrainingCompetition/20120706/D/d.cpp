#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
const int MAX_LEN = 100005;
const int MAX_TIME = 23*60+59;
struct node
{
	int hour;
	int minite;
	char thing[40];
};
node a[MAX_LEN];
bool cmp(const node &m,const node &n)
{
	if (m.hour < n.hour)
	  return true;
	else if (m.hour > n.hour)
	  return false;
	else if (m.minite < n.minite)
	  return true;
	else if (m.minite > n.minite)
	  return false;
	else if (strcmp(m.thing,n.thing) > 0)
	  return false;
	else 
	  return true;
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		bool flag = false;
		getchar();
		for (int i=0;i<n;i++)
		{
			scanf("%d:%d",&a[i].hour,&a[i].minite);
			gets(a[i].thing);
		}
		for (int i=0;i<n;i++)
		{

			if (a[i].hour > 23 || a[i].minite > 59 || a[i].hour<0 || a[i].minite < 0)
			{
				flag = true;
				printf("Neville is so careless!\n"); 
				break;
			}
		}
		if (flag == false)
		{
			std::sort(a,a+n,cmp);
			for (int i=0;i<n;i++)
				printf("%02d:%02d%s\n",a[i].hour,a[i].minite,a[i].thing);
		}
	}
	return 0;
}
