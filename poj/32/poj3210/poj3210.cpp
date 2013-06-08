#include <stdio.h>
 
int main(){
    int n;
    while(1){
		scanf("%d",&n);
		if (n == 0)
		  break;
        if(n % 2) 
		  printf("%d\n",n - 1);
        else 
		  printf("No Solution!\n");
    }
    return 0;
}
