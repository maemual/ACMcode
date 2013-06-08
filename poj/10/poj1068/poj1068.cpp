#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	int t;
	cin >> t;

	for (int i = 0;i < t;++i)
	{
		int n;
		cin >> n;
		int p,q = 0;
		vector<char> s;
		for (int j = 0;j < n;++j)
		{
			cin >> p;
			for (int k = q;k < p;++k)
				s.push_back('(');
			s.push_back(')');
			q = p;
		}

		vector<int> sta(s.size(),0);
		for (vector<char>::size_type ix = 0; ix != s.size();++ix)
			if (s[ix] == ')')
			{
				int count = 0;
				for (vector<char>::size_type jx = ix; jx >= 0;--jx)
					if (s[jx] == '(')
					{
						++count;
						if (sta[jx] == 0)
						{
							cout << count << ' ';
							sta[jx] = 1;
							break;
						}
					}
			}

		cout << endl;
	}

	return 0;
}
