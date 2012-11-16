#include<iostream>
#include<string>
using namespace std;

char digit[5][30]={{' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ','-',' '},
	{'|',' ','|',' ',' ','|',' ',' ','|',' ',' ','|','|',' ','|','|',' ',' ','|',' ',' ',' ',' ','|','|',' ','|','|',' ','|'},
	{' ',' ',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' '},
	{'|',' ','|',' ',' ','|','|',' ',' ',' ',' ','|',' ',' ','|',' ',' ','|','|',' ','|',' ',' ','|','|',' ','|',' ',' ','|'},
	{' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' '}};
void Display(int s,string &n,int i);
int main()
{

	int s;
	string n;
	while(cin>>s>>n,s!=0)
	{
		int i;
		for(i=0;i<5;i++)
		  if(i%2!=0)
		  {
			  int j;
			  for(j=0;j<s;j++)
				Display(s,n,i);
		  }
		  else
			Display(s,n,i);
		cout<<endl;
	}
	return 0;
}

void Display(int s,string &n,int i)
{
	int size=n.length();
	int j;
	for(j=0;j<size;j++)
	{
		int bg=(n[j]-'0')*3;
		cout<<digit[i][bg];
		int k;
		for(k=0;k<s;k++)
		  cout<<digit[i][bg+1];
		cout<<digit[i][bg+2];
		if(j!=size-1)
		  cout<<' ';
	}
	cout<<endl;
}
