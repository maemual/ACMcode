#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		getchar();
		string str;
		int sum = 0;
		int min = 999999;
		for (int i=0;i<n;i++)
		{
			getline(cin,str);
			int count = 0;
			for (int i=0;i<str.size();i++)
			{
				if (str[i] == ' ')
					count++;
			}
			if (min > count)
				min = count;
			sum += count;
		}
		sum -= min*n;
		cout << sum << endl;
	}
	return 0;
}
