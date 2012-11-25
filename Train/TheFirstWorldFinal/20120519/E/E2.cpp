#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int p[100005];
int main()
{
    int t;
    //scanf("%d",&t);
    cin >> t;
    while (t--)
    {
        int n,m;
        //scanf("%d%d",&n,&m);
        cin >> n >> m;
        for (int i=0;i<n;i++)
            p[i]=0;

        for (int i=0;i<n;i++)
            cin >> p[i];
            //scanf("%d",&p[i]);

        //printf("MMMM  %d\nNNNN  %d\n",m,n);
        /*for (int i=0;i<n;i++)
            printf("%d ",p[i]);
        printf("\n");*/

        for (int i=0;i<m;++i)
        {
            char ch;
            int a,b;
            cin >> ch >> a >> b;
            if (ch == 'U')
            {
                p[a] = b;
                //for (int i=0;i<n;i++)
               //     cout << p[i] << " ";
                //cout << endl;
            }else if (ch == 'Q')
            {
                if (a == b)
                {
                    //printf("3333\n");
                    cout << 1 << endl;
                }else{
                    int fo = a,ta=a+1;
                    int max = 1;
                    int count = 1;
                    while (ta <= b)
                    {
                        if (p[ta]>p[ta-1])
                        {
                            ta++;
                            count++;
                        }else{
                            if (max < count)
                                max = count;

                            fo = ta;
                            count = 1;
                            ta++;
                        }
                    }
                    if (max < count)
                        max = count;
                    cout << max << endl;
                }
            }
        }
    }
    return 0;
}
