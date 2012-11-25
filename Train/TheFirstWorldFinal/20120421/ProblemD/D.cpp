#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

int str2num(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		string s2(s);
		bool conti = true;
		while (conti)
		{
			s = s2;
			s2 = "";
			int j = 0;
			while (j < s.size())
			{
				int k;
				if (s[j]>='0' && s[j]<='9')
				{
					string sNum;
					//int j=i;
					while (s[j]>='0' && s[j]<='9')
					{
						sNum += s[j];
						++j;
					}
					int n = str2num(sNum);
	
					if (s[j] != '(')
					{
						//string stemp;
						for (int m=0;m<n;++m)
							s2 += s[j];
						//s.insert(j,stemp,0,stemp.size());
						//s2 += stemp;
						k = j;
					}else{
						int count1 = 1;
						int count2 = 0;
						k = j;
						while (count1 != count2)
						{
							++k;
							if (s[k] == '(' )
							++count1;
							if (s[k] == ')')
							++count2;
						}
						string stemp(s,j+1,k-j-1);
						//string st;
						for (int m=0;m<n;++m)
							s2 += stemp;
						//s.insert(k,st,0,st.size());
						//s2 += st;
						j=k;
					}
				}
				//i = k+1;
			}
			
			conti = false;
			for (int i = 0;i<s2.size();++i)
			{
				if (s2[i] >'0' && s2[i] <= '9')
				{
					conti = true;
					break;
				}
			}
		}
		cout << s2 << endl;
		//int i = 0;
		for (int i = 0;i<s2.size();++i)
		{
			if (s2[i]>='a' && s2[i]<='z')
			  printf("%c",s2[i]);
		}
		printf("\n");
	}
	return 0;
}
