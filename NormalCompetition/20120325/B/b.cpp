#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    int c,x;
    while (scanf("%d%d",&c,&x) == 2)
    {
        int t;
        vector<int> vec;
        for (int i = 0;i < c;++i)
        {
            scanf("%d",&t);
            vec.push_back(t);
        }

        if (x <= 0)
        {
            printf("%d\n",c*(c+1) / 2);
            continue;
        }

        long long sum = 0;
        int count = 0;
        int k;
        for (k = 0;k < vec.size();++k)
        {
            sum += vec[k];
            if (sum >= x)
            {
                count = vec.size() - k;
                break;
            }
        }

        if (count == 0)
        {
            printf("0\n");
            continue;
        }

        //printf("1 count:%d\n",count);
        //printf("1 sum:%d\n",sum);
        for (int i = 1;i < vec.size();++i)
        {
            sum -= vec[i-1];
            //printf("2 sum:%d\n",sum);
            if (sum >= x)
            {
                count += vec.size() - k;
                //printf("2:%d\n",count);
            }
            else
            {
                int j;
                for (j = k+1;j < vec.size();++j)
                {
                    sum += vec[j];
                    //printf("3 sum:%d\n",sum);
                    if (sum >= x)
                    {
                        count += vec.size()-j;
                        //printf("3:%d\n",count);
                        k = j;
                        break;
                    }
                }
                if (j >= vec.size())
                {
                    break;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
