#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxans 5000
#define maxlong 3000
using namespace std;
int main()
{	
	int numerator,denominator,original_numerator,remainder;
	int remainder_exist[maxlong];
	int remainder_pos[maxlong];
	int ans[maxans];

	while (scanf("%d",&numerator) == 1)
	{
		memset(remainder_exist,0,sizeof(remainder_exist));
		memset(remainder_pos,0,sizeof(remainder_pos));	
	
		cin >> denominator;
		
		int n = 0;
		int beg = 1;
		original_numerator = numerator;
		bool pan1 = false,pan2 = false;
		while (n < maxlong)
		{
			ans[n] = numerator / denominator;
			remainder = numerator % denominator;
			if (remainder_exist[remainder])
			{
				beg = remainder_pos[remainder];
				pan1 = true;
				break;
			}
			else 
			{
				remainder_exist[remainder] = 1;
				remainder_pos[remainder] = n;
			}
			numerator = remainder * 10;
			if (numerator == 0)
			{
				pan2 = true;
				break;
			}
			++n;
		}

		cout << original_numerator << '/' << denominator << " = ";
		int limit = min (n,50);
		cout << ans[0] <<'.';
		if (pan1) 
		{
			for (int i = 1;i <= beg;++i)
			  cout << ans[i];
			cout << '(';
			for (int i = beg+1;i<=limit;++i)
			  cout <<ans[i];
			if (limit == 50)
				cout << "...)"<<endl;
			else
				cout << ')' <<endl;
			cout<<"   "<<n-beg
				<<" = number of digits in repeating cycle"<<endl<<endl;
		}
		if (pan2)
		{
			for (int i =1 ;i <= limit;++i)
			  cout << ans[i];
			cout << "(0)"<<endl;
			cout<<"   1 = number of digits in repeating cycle"<<endl<<endl;
		}
	}
	return 0;
}
