#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int flag = 1;
	while (getline(cin,s))
	{
		string::size_type pos=0;
		while (true)
		{
			pos = s.find_first_of("\"",pos);
			if (pos == string::npos)
			  break;
			if (flag == 1)
			{
				s.replace(pos, 1, "``");
				flag = 2;
			}
			else {	
				s.replace(pos, 1, "''");
				flag = 1;
			}
			pos++;
		}
		cout << s << endl;
	}
	return 0;
}
