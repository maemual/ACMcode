/*************************************************************************
	> File Name: i.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月24日 星期三 09时06分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int power[] = {16, 7, 8, 1, 1, 2, 3};
int main()
{
	int T;
	int n,m;
	cin >> T;
	while (T--){
		cin >> n;
		int sum1, sum2;
		sum1 = sum2 = 0;
		bool ma = false;
		bool pao = false;
		char ch;
		for (int i = 0; i < n; i++){
			cin >> ch;
			sum1 += power[ch - 'A'];
			if (ch == 'B')
				ma = true;
			if (ch == 'C')
				pao = true;
		}
		if (!ma || !pao)
			sum1--;
		if (sum1 == 0)
			sum1++;
		cin >> m;
		ma = false;
		pao = false;
		for (int i = 0; i < m; i++){
			cin >> ch;
			sum2 += power[ch - 'A'];
			if (ch == 'B')
				ma = true;
			if (ch == 'C')
				pao = true;
		}
		if (!ma || !pao)
			sum2--;
		if (sum2 == 0)
			sum2++;
		if (sum1 > sum2)
			cout << "red" << endl;
		else if (sum1 < sum2)
			cout << "black" << endl;
		else
			cout << "tie" << endl;
	}
	return 0;
}
