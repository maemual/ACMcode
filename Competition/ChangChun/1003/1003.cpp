#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
struct minxture{
	string name;
	int num;
};
struct equipment{
	string name;
	int price;
	int property;//0 means normal,1 means minxture,2 means consume
	vector<minxture> vec;
}backpack[6],em[100];
double converFromString(string &s)
{
	istringstream i(s);
	double x;
	if (i >> x)
	  return x;
	return 0.0;
}
int worth(int n,const string & s)
{
	for (int i=0;i<n;i++)
	{
		if (em[i].name == s)
		  return price;
	}
}
int main()
{
	int n1,n2,n3,m;
	int k = 0;
	string strtem;
	int tem;
	while (scanf("%d",&n1) != EOF){
		int num = 0;
		int gold = 0;
		for (int i=0;i<n1;i++)
		{
			//cin >> em[num].name;
			scanf("%s %d",&em[num].name,&em[num].price);
			em[num++].property = 0;
		}
		scanf("%d",&n2);
		for (int i=0;i<n2;i++)
		{
			scanf("%s %d: ",&em[num].name,&em[num].price);
			em[num].property = 1;
			//getchar();
			getline(cin,strtem);
			if (strtem.size() == 0)
			  continue;
			int beg=0,end=1;
			while (beg != end){
				while (strtem[end] != ' ') end++;
				string temp1="",temp2="";
				for (int i=beg;i<end;i++)
				  temp1+=strtem[i];
				beg = end;
				while (end < strtem.size() && strtem[end] != " ") end++;
				int k;
				if (end == strtem.size())
				{
					for (int i=beg+1;i<end;i++)
					  temp2 += strtem[i];
				}else {
					for (int i=beg+1;i<end-1;i++)
					  temp2 += strtem[i];
				}
				int k = converFromString(temp2);
				struct minxture mm;
				mm.name = temp1;
				mm.num = k;
				em[num].vec.push_back(mm);
			}
			for (int i=0;i<em[num].vec.size();i++){
				em[num].price += worth(num,em[num].vec[i].name) * em[num].vec[i].num;
			}
			num++;
			//cout << strtem << endl;
		}
		scanf("%d",&n3;);
		for (int i=0;i<n3;i++)
		{
			scanf("%s %d",&em[num].name,&em[num].price);
			em[num++].property = 2;
		}
		scanf("%d",&m);	
		getchar();
		char ch;
		for (int i=0;i<m;i++)
		{
			ch = getchar();
			if (ch == '+'){
				scanf("%s",&strtem);
				if (strtem[0]>='0' && strtem[0]<='9'){
					gold += (int) converFromString(strtem);
				}else {
					int w = worth(num,strtem);
					if (gold >= w && backpack.size() < 6){
						gold -= w;

					}
				}
			}else {

			}
		}
	}
	return 0;
}
