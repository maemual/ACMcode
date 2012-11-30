#include <stdio.h>
#define PI 3.1415927
int main()
{
	float diameter,time;
	int revolutions;
	int k = 1;
	while (1)
	{
		scanf("%f %d %f",&diameter,&revolutions,&time);
		if (revolutions == 0)
		  break;
		float distance = PI * diameter * revolutions;
		float mile = distance / (12.0*5280);
		printf("Trip #%d: %.2f %.2f\n",k++,mile,mile / (time / 3600));
	}
	return 0;
}
