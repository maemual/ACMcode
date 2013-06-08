#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_LEN = 50;
struct DNA
{
	char s[MAX_LEN+5];
	int key;
	int pos;
};
DNA a[2*MAX_LEN+5];
bool cmp(const DNA &p1,const DNA &p2)
{
	if (p1.key != p2.key)
	  return p1.key < p2.key; 
	else 
	  return p1.pos < p2.pos;

}
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		for (int i=0;i<m;i++)
		{
			scanf("%s",&a[i].s);
			//printf("%s",a[i].s);
			int len = strlen(a[i].s);
			int sum = 0;
			for (int j=0;j<len;j++)
			{
				for (int k=j+1;k<len;k++)
				{
					if (a[i].s[j] > a[i].s[k])
					  sum++;
				}
			}
			a[i].key = sum;
			a[i].pos = i;
		}
		sort(a,a+m,cmp);
		for (int i=0;i<m;i++)
		  printf("%s\n",a[i].s);
	}
	return 0;
}
