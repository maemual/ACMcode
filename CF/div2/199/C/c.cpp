#include <stdio.h>

int r,h;
int main()
{
	//scanf("%d %d",&r,&h);
    for (int r = 1; r <= 10; r++){
        for (int h = 1; h <= 10; h++){
	int cnt = h / r,tmp = h % r;
	int ans = cnt * 2;
    if (2 * tmp >= r){
        ans += 2;
        if (4 * tmp * tmp >= 3 * r * r)
            ans++;
    }else{
        ans++;
    }
	printf("%d %d %d\n",r, h, ans);
        }
    }
	return 0;
}

