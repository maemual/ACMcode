#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(float a,float b)
{
	return a > b;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		float x;
		float max = 0;
		vector<float> vec;
		scanf("%d",&n);
		for (int i = 0;i<n;++i)
		{
			scanf("%f",&x);
			vec.push_back(x);
		}
		sort(vec.begin(),vec.end(),compare);
		
		for (int i = 1;i <= 5;++i)
		{
			double temp = 0;
			if (vec.size() >= i)
			{
				for (int j = 0;j < i ;++j)
				{
					temp += vec[j];
				}
				temp /= i;
				temp += (i-1) * 100;
				if (max < temp)
				  max = temp;
			}
		}
		printf("%.2f\n",max);
	}
	return 0;
}
