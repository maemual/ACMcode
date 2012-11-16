#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int month[]={0,1,8,27,64,125,216,343,512,729,1000,1331,1728};
int year[]={1,9,36,100,225,441,784,1296,2025,3025,4356,6084};
//int past[]={0,1,10,46,146,371,812,1596,2892,4917,7942,12298};
//const int MAX_DAYS = 6084;
const int MAX_12 = 18382;
int main()
{
    long long  year1,year2,mon1,mon2,day1,day2,sub1,sub2,ans;
    while (scanf("%lld-%lld-%lld",&mon1,&day1,&year1) != EOF)
    {
        scanf("%lld-%lld-%lld",&mon2,&day2,&year2);
		sub1=sub2=0;
		long long t=(year1)/12;
	//	cout<<"t:=="<<t<<endl;
		sub1+=t*MAX_12;
		//cout<<"sub1=="<<sub1<<endl;
		long long run=year1/11+1;
		if(year1%11==0 &&mon1<=1 && day1<=1)
			run--;
		sub1+=run;
		t=(year1)%12;
		for(int i=0;i<t;i++)
			sub1+=year[i];
		//cout<<"sub1:=="<<sub1<<endl;
		for(int i=1;i<mon1;i++)
			sub1+=month[i];
		//cout<<"sub1=="<<sub1<<endl;
		if(day1<=month[mon1])
			sub1+=day1;
		else
			sub1+=month[mon1];
		//cout<<"sub1=="<<sub1<<endl;


		sub2=0;
		t=(year2)/12;
		sub2+=t*MAX_12;
	//	cout<<"sub2=="<<sub2<<endl;
		run=year2/11+1;
		if(year2%11==0 && mon2<=1 && day2<=1)
			run--;
		sub2+=run;
		t=(year2)%12;
		for(int i=0;i<t;i++)
			sub2+=year[i];
	//	cout<<"sub2=="<<sub2<<endl;
		for(int i=1;i<mon2;i++)
			sub2+=month[i];
		if(day2<=month[mon2])
			sub2+=day2;
		else
			sub2+=month[mon2];
	//	cout<<"sub2=="<<sub2<<endl;
		if(sub2>sub1)
			ans=sub2-sub1+1;
		else
			ans=sub1-sub2+1;

		
        printf("%lld\n",ans);
    }
    return 0;
}
