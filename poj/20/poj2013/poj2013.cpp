#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int count = 0;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
		  return 0;
		vector<string> s;
		string ss;
		for (vector<string>::size_type ix = 0;ix < n ;++ix)
		{
			cin >> ss;
			s.push_back(ss);
		}
		++count;
		cout << "SET " << count << endl;
		for (vector<string>::size_type ix = 0;ix < n ;ix += 2)
			cout << s[ix] << endl;
		if (n % 2 == 0)
			for (int ix = n-1;ix >= 0 ; ix -= 2)
				cout << s[ix] << endl;
		else 
			for (int ix = n-2;ix >= 0 ; ix -= 2)
				cout << s[ix] << endl;
	}
}
