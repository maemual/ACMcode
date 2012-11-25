#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    int c,x;
    while (scanf("%d%d",&c,&x) != EOF)
    {
        int t;
        vector<int> vec;
        for (int i = 0;i < c;++i)
        {
            scanf("%d",&t);
            vec.push_back(t);
        }
        int count = 0;
        for (int i = 0;i < vec.size();++i)
        {
            int sum = 0;
            for (int j = i;j <vec.size();++j)
            {
                sum += vec[j];
                if (sum >= x)
                {
                    ++count;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
