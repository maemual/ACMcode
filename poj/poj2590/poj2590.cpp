#include <cstdio>
#include <cmath>
int main(){
    int t,a,s,ans;
    scanf("%d",&t);
    while (t--){
        scanf("%d %d",&a,&s); 
		s-=a;
        if (s<4){
            printf("%d\n",s);
            continue;
        }
        a=(int)(sqrt(s*1.0)+.5);
        if (s-a*(a-1)<=a) 
			ans=2*a-1;
        else 
			ans=2*a;
        printf("%d\n",ans);
    }
    return 0;
}

