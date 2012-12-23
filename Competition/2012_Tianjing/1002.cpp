#include<cstdio>
#include<cmath>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    _int64 x,y;
		_int64  ans=0;
		scanf("%lld%lld",&x,&y);
		ans+=(y-x+1)/2;
		if(x%2==0&&y%2==0)
		  ans++;
	//	printf("%lld\n",ans);
		long long p1=sqrt(x);
		if(p1*p1!=x)
		  p1++;
		long long p2=sqrt(y);
		long long ou=(p2-p1+1)/2;
	//	printf("%lld %lld\n",p1,p2);
		if(p1%2==0&&p2%2==0)
		  ou++;
		ans-=ou;
		long long ji=p2-p1+1-ou;
		ans+=ji;
		if(x<=2&&y>=2)
		  ans--;
		if(x<=1&&y>=1)
		  ans--;
		printf("%lld\n",ans);
	}
	return 0;
}
