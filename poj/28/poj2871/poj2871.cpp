#include <cstdio>
//#include <cmath>

int main(void){
    double last = 0, now;
    scanf("%lf", &last);
    while (1){
		scanf("%lf", &now);
		if (now == 999)
			break;
        printf("%.2lf\n", now - last);
        last = now;
    }
    printf("End of Output\n");

    return 0;
}

