#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int>  stamps;
vector<int>  customers;
map<int,int>  C_nt;  //用于剪枝，当同一种面值不同种类的的邮票种类超过5种的时候，他们的解和等于5一样；
vector<int>  result;   //存放临时分配方案
vector<int>  Result;/*存放最终分配方案（Result[0] :当前分配方案中邮票的种类，Result[1]:当前分配方案中邮票的数目，Result[2]:存放当前分配方案中单张面值最大的，后面的就存放每种邮票的数目）*/
int request;
bool Tie;
void reflesh() //这个应该不难看懂，就是满足题中的各个限制条件
{

	if (result[0] >  Result[0]){ 
		Result = result;
	}else if (result[0] == Result[0] && result[1] < Result[1]){ 
		Result = result; 
	}else if (result[0] == Result[0] &&result[1] == Result[1]&& result[2] > Result[2]) { 
		Result = result; 
	}else if (result[0] == Result[0] &&result[1] == Result[1]&& result[2]== Result[2]&& result != Result) { 
		Tie = true; 
	}
	if  (result == Result) 
	  Tie = false;
}
void slove(int preT,int val)
{
	if(result[1]>4)   
		return;//当邮票的数量大于4时就没有必要继续向下搜索了；剪枝2；
	if(val==request)   
	  reflesh(); // 找到了一中分配方案
	for(int i=preT;i>=0;i--) // 枚举所有情况
	{
		if(val + stamps[i] <= request) 
		{
			int   tp = result[0];
			if (i != preT || result[0] == 0)  
			  result[0]++; //如过当前分配方案还没有第i 种邮票，种类数加1
			result[1]++; //邮票数目加1；
			int t = result[2];
			if (stamps[i] > result[2])  
			  result[2] = stamps[i];// 更新单张最大面值
			result[3+i]++;

			slove(i,val+stamps[i]);

			if( tp  <  result[0])   
			  result[0] --; //下面的就是恢复现场

			result[1]--;
			result[2] = t;
			result[3+i]--;
		}
	}
}
void print()
{
	cout<<request<<" ";
	if (Tie)     
	  cout <<"(" <<Result[0]<< "): tie"<<endl;
	else if (Result[0]==0)
	  cout << "---- none" <<endl;
	else
	{
		cout <<"("<<Result[0] << "):";
		for(int i = 3; i < Result.size();i++)
		  for(int j = 0; j < Result[i];j++)
			cout << " " <<stamps[i-3] ;
		cout<<endl;
	}
}
void prepare(int t)
{
	request = customers[t];
	result.assign(3+stamps.size(),0);
	Result.assign(3+stamps.size(),0);
	Tie = false;

	slove(stamps.size()-1,0);
	print();
}
int main()
{
	int tp;
	while (cin  >>  tp,tp)
	{
		C_nt[tp]++; stamps.push_back(tp);
		while(cin >> tp,tp)
		{ 
			if(C_nt[tp]++ < 5) 
			  stamps.push_back(tp);
		}//剪枝（1） 理由见C_nt 定义的地方；
		while(cin >> tp,tp)
		{
			customers.push_back(tp);
		}

		sort(stamps.begin() ,stamps.end());

		for(int i = 0; i < customers.size();i++)
		  prepare(i);

		C_nt.clear();
		customers.clear();
		stamps.clear();
	}
	return 0;
}
