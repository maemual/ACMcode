#include <cstdio>
#define MAX 60010
using namespace std;
int out[MAX];
void print(){
    int i,j;
    for(i=1;i<MAX;i++)
        out[i]=1;
    out[1]=0;
    for(i=2;i<MAX;i++){
        for(j=2;j*i<MAX;j++)
            out[j*i]=out[j*i]+i;
    }
}
int main(){
    int n;
    print();
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)!=EOF &&n !=0){
        printf("%5d",n);
        if(out[n]==n) 
			printf("  PERFECT\n");
        else if(out[n]>n) 
				printf("  ABUNDANT\n");
			else 
				printf("  DEFICIENT\n");
    }
    printf("END OF OUTPUT");
    return 0;
}

