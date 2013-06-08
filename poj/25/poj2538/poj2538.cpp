#include <cstdio>
#include <map>
using namespace std;

int main()
{
	map<char,char> m;
	m['W']='Q';m['E']='W';m['R']='E';m['R']='E';m['T']='R';m['Y']='T';
	m['U']='Y';m['I']='U';m['O']='I';m['P']='O';m['[']='P';m[']']='[';
	m['\\']=']';m['S']='A';m['D']='S';m['F']='D';m['G']='F';m['H']='G';
	m['J']='H';m['K']='J';m['L']='K';m[';']='L';m['\'']=';';m['X']='Z';
	m['C']='X';m['V']='C';m['B']='V';m['N']='B';m['M']='N';m[',']='M';
	m['.']=',';m['/']='.';
	m['1']='`';m['2']='1';m['3']='2';m['4']='3';m['5']='4';m['6']='5';
	m['7']='6';m['8']='7';m['9']='8';m['0']='9';m['-']='0';m['=']='-';
	char ch;
	while (scanf("%c",&ch) != EOF)
	{
		if (ch>='A' && ch<='Z'||ch=='['||ch==']'||ch=='\\'||ch==';'
			||ch=='\''||ch==','||ch=='.'||ch=='/'||ch>='0'&&ch<='9'
			||ch=='-'||ch=='=')
		  printf("%c",m[ch]);
		else 
		  printf("%c",ch);
	}
	return 0;
}
