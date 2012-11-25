#include <iostream>
#include <string>
using namespace std;
string map[26]={".-","-...","-.-.","-..",".","..-.","--.","...."
				,"..",".---","-.-",".-..","--","-.","---",".--."
				,"--.-",".-.","...","-","..-","...-",".--","-..-"
				,"-.--","--.."};
int main()
{
	int cas;
	cin >> cas;
	string morse;
	int words;
	string word;
	while (cas--)
	{
		cin >> morse;
		cin >> words;
		int cnt = 0;
		for (int i=0;i<words;i++)
		{
			cin >> word;
			string st = "";
			for (int i=0;i<word.size();i++)
			{
				st += map[word[i]-'A'];
			}
			//cout << st << endl;
			if (morse.find(st) < morse.size())
			{	
				cout << st << endl;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
