#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
inline void NEXT(const string& T,vector<int>& next)
{
	next[0]=-1;
	for(int i=1;i<T.size();i++ )	
	{
		int j=next[i-1];
		while(T[i]!=T[j+1]&& j>=0 )
			j=next[j];
		if (T[i]==T[j+1])
		  next[i]=j+1;
		else next[i]=0; 
	}
}
inline string::size_type COUNT_KMP(const string& S,const string& T)
{
	vector<int> next(T.size());
	NEXT(T,next);
	string::size_type index,count=0;
	for(index=0;index<S.size();++index)
	{
		int pos=0;
		string::size_type iter=index;
		while (pos<T.size() && iter<S.size())
		{
			if(S[iter]==T[pos])
			{
				++iter;++pos;
			}
			else
			{
				if(pos==0)++iter;
				else pos=next[pos-1]+1;
			}
		}
		if(pos==T.size()&&(iter-index)==T.size())
		  ++count;
	}
	return count;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		string t;
		cin >> s;
		cin >> t;
		int sum = COUNT_KMP(s,t);
		int num = 0;
		for (int i = 1;i <= t.size()-1;++i)
		{
			string t1(t,0,i);
			string t2(t,t1.size(),t.size()-t1.size());
			for (int j = 0;j <=s.size()-t.size();++j)
			{
				//string s1(s,j,t1.);
				//string s2(s,,s.size());
				//num += COUNT_KMP(s1,t1)*COUNT_KMP(s2,t2);
			}
		}
		cout << sum << endl;
		cout << num<< endl;
	}
	return 0;
}
