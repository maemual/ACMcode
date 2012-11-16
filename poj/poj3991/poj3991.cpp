#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAX_LEN = 2000;
char str[MAX_LEN+5];
int main()
{
	int k = 0;
	while (1)
	{
		scanf("%s",str);
		if (str[0] == '-')
		  break;
		stack<char> s;
		int p = 0;
		int len = strlen(str);
		for (int i=0;i<len;i++)
		{
			if (str[i] == '{')
			{
				s.push(str[i]);
			}else{
				if (!s.empty())
				{
					s.pop();
				}else p++;
			}
		}
		int q = s.size();
		if (p % 2 == 0)
		{
			printf("%d. %d\n",++k,(p+q)/2);
		}else 
			printf("%d. %d\n",++k,(p+q+2)/2);
	}
	return 0;
}
