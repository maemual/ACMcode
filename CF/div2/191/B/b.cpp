/*************************************************************************
  > File Name: b.cpp
  > Author: maemual
  > Mail: maemual@gmail.com 
  > Created Time: 2013年07月04日 星期四 20时56分43秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
const int MAX_LEN = 10000000;
bool prime[MAX_LEN+5];
int p = 4;

int main()
{
	memset(prime,1,sizeof(prime));
	for (int i=2;i<MAX_LEN;i++)
	{
		if (prime[i])
		{
			while (p<MAX_LEN)
			{
				prime[p] = false;
				p += i;
			}
		}
		p = 2*(i+1);
	}
	prime[0] = false;
	prime[1] = false;
	int n;
	cin >> n;
	cout << "2";
	n--;
	for (int i = 3; i <= MAX_LEN; i++){
		if (n == 0)
			break;
		if (prime[i]){
			cout << " " << i;
			n--;
		}
	}
	cout << endl;
	return 0;
}
