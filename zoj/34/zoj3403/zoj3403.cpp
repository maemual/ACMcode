#include <cstdio>
const int year[]={0,1,10,46,146,371,812,1596,2892,4917,7942,12298,18382};
const int month[]={0,1,9,36,100,225,441,784,1296,2025,3025,4356,6084};
const int MAX_Day = 18382;
int main()
{
	long long year1,year2,mon1,mon2,day1,day2;
	while (scanf("%lld-%lld-%lld",&mon1,&day1,&year1) != EOF)
	{
		scanf("%lld-%lld-%lld",&mon2,&day2,&year2);
//printf("%d	%d	%d\n%d	%d	%d\n",year1,mon1,day1,year2,mon2,day2);
		long long sum1,sum2;
		sum1 = (year1-1)/12*MAX_Day;
		sum2 = (year2-1)/12*MAX_Day;
//printf("%lld	%lld\n",sum1,sum2);

		sum1+= year[year1%12];
		sum2+= year[year2%12];

//printf("%lld	%lld\n",sum1,sum2);

		sum1+= month[mon1-1]+day1;
		sum2+= month[mon2-1]+day2;
//printf("%lld	%lld\n",sum1,sum2);

		if (year1>0)
		{
			sum1 += (year1-1)/11;
			sum1++;
			if (year1%11==0 && mon1>1)
			  sum1++;
		}
		if (year2>0)
		{
			sum2 += (year2-1)/11;
			sum2++;
			if (year2%11==0 && mon2>1)
			  sum2++;
		}
		
//printf("%lld	%lld\n",sum1,sum2);

		if (sum1>sum2)
		  printf("%lld\n",sum1-sum2+1);
		else 
		  printf("%lld\n",sum2-sum1+1);
	}
	return 0;
}
