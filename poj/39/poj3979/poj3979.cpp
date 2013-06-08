#include <cstdio>
#include <cstdlib>
int gcd(int a,int b)
{
	if (a%b==0) return b;
	return gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	int a,b,c,d;
	char ch;
	while (scanf("%d/%d%c%d/%d",&a,&b,&ch,&c,&d) != EOF)
	{
		int p = lcm(b,d);
		int ans;
		a = a * (p / b);
		c = c * (p / d);
		//printf("%d %d %d\n",a,p,c);
		if (ch == '+')
		{
			ans = a+c;
		}else if (ch == '-')
		{
			ans = a-c;
		}
		if (ans == 0)
		  printf("0\n");
		else {
			int p1 = abs(gcd(ans,p));
			ans /= p1;
			p /= p1;
			if (p == 1)
			  printf("%d\n",ans);
			else 
			  printf("%d/%d\n",ans,p);
		}
	}
	return 0;
}
