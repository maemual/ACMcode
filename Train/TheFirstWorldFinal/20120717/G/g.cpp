#include <cstdio>
#include <cstdlib>
const int MAX_LEN = 1000000;
char s[10];
int a[MAX_LEN+5];
int n,x,tail;
void insert(int x)
{
	if (tail == 0)
	{
		a[tail++] = x;
		return;
	}
	int pos = tail;
	for (int i=0;i<tail;i++)
	{
		if (a[i] > x)
		{
			pos = i;
			break;
		}
	}
	if (pos == tail)
	{
		a[tail++] = x;
		return;
	}
	tail++;
	for (int i=tail;i>pos;i--)
	{
		a[i] = a[i-1];
	}
	a[pos] = x;
}
int query1(int x)
{
	if (x==1)
	{
		return a[0];
	}
	int ans = 0;
	int i;
	for (i=1;i<tail;i++)
	{
		if (a[i] != a[i-1])
		  x--;
		if (x==1)
		  break;
	}
	return a[i];
}
int query2(int x)
{
	int pos = tail-1;
	for (int i=0;i<tail;i++)
	{
		if (a[i]-x>=0)
		{
			pos = i;
			break;
		}
	}
	if (abs(a[pos]-x)>abs(a[pos-1]-x))
	  return a[pos-1];
	else 
	  return a[pos];
}
int query3(int x)
{
	if (x == a[0])
	  return 1;
	int ans = 1;
	for (int i=1;i<tail;i++)
	{
		if (a[i] != a[i-1] && a[i]<x)
		{
			ans++;
			break;
		}
	}
	return ans+1;
}
int main()
{
	while (scanf("%d",&n) != EOF)
	{
		tail = 0;
		for (int i=0;i<n;i++)
		{
			scanf("%s",s);
			scanf("%d",&x);
			if (s[0]=='I')
			{
				insert(x);
			}else if (s[0] == 'L')
			{
				printf("%d\n",query1(x));
			}else if (s[0] == 'U')
			{
				printf("%d\n",query2(x));
			}else if (s[0] == 'F')
			{
				printf("%d\n",query3(x));
			}
		}
	}
	return 0;
}
