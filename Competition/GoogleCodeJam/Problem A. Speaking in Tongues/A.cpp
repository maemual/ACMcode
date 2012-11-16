#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
	freopen("out.out","w",stdout);

    char s[27]="yhesocvxduiglbkrztnwjpfmaq";
    char st[100];
    int tt;
    scanf("%d",&tt);
    getchar();
    for (int k=1;k<=tt;k++)
    {
        char ss[200];
        gets(ss);
        printf("Case #%d: ",k);
        for (int i=0;i<strlen(ss);++i)
        {
            if (ss[i] >='a' && ss[i]<='z')
            {
                printf("%c",s[ss[i]-'a']);
            }
            else
                printf("%c",ss[i]);
        }
        printf("\n");
    }
    return 0;
}
