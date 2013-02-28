#include <stdio.h>
#include <string.h>

int a[30];
int main()
{
    char s[10005];
    scanf("%s",s);
    int i;
    int len = strlen(s);
    memset(a,0,sizeof(a));
    for (i = 0; i < len; i++)
        a[s[i]-'a']++;
    int cnt_even = 0,cnt_odd = 0;
    for (i = 0; i < 26; i++)
    {
        if (a[i] % 2 == 1)
            cnt_odd++;
    }
    if (cnt_odd <= 1 || cnt_odd % 2 == 1)
        printf("First\n");
    else if (cnt_odd % 2 == 0)
        printf("Second\n");
    return 0;
}
