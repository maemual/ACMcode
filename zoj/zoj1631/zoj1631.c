#include <stdio.h>
#include <stdlib.h>

struct unit
{
	char name[20];
	int hp, armor, power, amount, cool;
}s[2];
int main()
{
	int i, j, temp, attack[2], times[2];
	while(scanf("%s", s[0].name)!=EOF)
	{
		if(s[0].name[0] == -1)break;
		i=0;
		scanf("%d%d%d%d%d", &s[i].hp, &s[i].armor, &s[i].cool, &s[i].amount, &s[i].power);
		i=1;
		scanf("%s", s[i].name);
		scanf("%d%d%d%d%d", &s[i].hp, &s[i].armor, &s[i].cool, &s[i].amount, &s[i].power);
		for(i=0; i<2; i++)
		{
			attack[i] = s[i].power - s[ !i ].armor;
			if(attack[i] <= 0)
				attack[i] = 1;
			attack[i] *= s[i].amount;
			times[ !i ] = ( s[ !i ].hp / attack[i]  + (s[!i].hp % attack[i] ? 1:0 ) )* s[i].cool;
		}		
		if( times[0] < times[1] )
			printf("%s Survive!\n", s[1].name);
		else if( times[0] > times[1] )
			printf("%s Survive!\n", s[0].name);
		else
			printf("All Die!\n");
	}
    return 0;
}

