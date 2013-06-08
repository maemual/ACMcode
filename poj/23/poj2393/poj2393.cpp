#include <cstdio>
 
int main(){
    int n, s, minc = 9999;
    scanf("%d %d",&n, &s);
    long long sum = 0;
    while(n --){
        int c, y;
        scanf("%d %d",&c, &y);
        if(c > minc + s)  
		  c = minc + s;  //  维护最优的代价。
        minc = c;
        sum += c * y;
    }
    printf("%lld\n", sum);
    return 0;
}
