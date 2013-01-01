#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	map<char,string> c2s;
	map<string,char> s2c;
	c2s['A']=".-";c2s['B']="-...";c2s['C']="-.-.";c2s['D']="-..";
	c2s['E']=".";c2s['F']="..-.";c2s['G']="--.";c2s['H']="....";
	c2s['I']="..";c2s['J']=".---";c2s['K']="-.-";c2s['L']=".-..";
	c2s['M']="--";c2s['N']="-.";c2s['O']="---";c2s['P']=".--.";
	c2s['Q']="--.-";c2s['R']=".-.";c2s['S']="...";c2s['T']="-";
	c2s['U']="..-";c2s['V']="...-";c2s['W']=".--";c2s['X']="-..-";
	c2s['Y']="-.--";c2s['Z']="--..";
	c2s['_']="..--";c2s['.']="---.";c2s[',']=".-.-";c2s['?']="----";

	s2c[".-"]='A';s2c["-..."]='B';s2c["-.-."]='C';s2c["-.."]='D';
	s2c["."]='E';s2c["..-."]='F';s2c["--."]='G';s2c["...."]='H';
	s2c[".."]='I';s2c[".---"]='J';s2c["-.-"]='K';s2c[".-.."]='L';
	s2c["--"]='M';s2c["-."]='N';s2c["---"]='O';s2c[".--."]='P';
	s2c["--.-"]='Q';s2c[".-."]='R';s2c["..."]='S';s2c["-"]='T';
	s2c["..-"]='U';s2c["...-"]='V';s2c[".--"]='W';s2c["-..-"]='X';
	s2c["-.--"]='Y';s2c["--.."]='Z';
	s2c["..--"]='_';s2c["---."]='.';s2c[".-.-"]=',';s2c["----"]='?';

	cin >> n;
	string from,to,temp;
	vector<int> v;
	int k = 0;
	while (cin >> from)
	{
		v.clear();
		temp = "";
		for (int i = 0; i < from.size(); i++)
		{
			temp += c2s[from[i]];
			v.push_back(c2s[from[i]].length());
		}
		reverse(v.begin(),v.end());
		to = "";
		int p = 0;
		for (int i = 0; i < v.size(); i++)
		{
			string substring;
			for (int j = 0; j < v[i]; j++)
			  substring += temp[p + j];
			to += s2c[substring];
			p += v[i];
		}
		cout << ++k << ": ";
		cout << to << endl;
	}
	return 0;
}
