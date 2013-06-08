#include <cstdio>
#include <cstring>
int n;
char haabmonth[19][10] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char tzolkinday[20][10] = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int day;
char month[10];
int year;
int main()
{
	scanf("%d",&n);
	printf("%d\n",n);
	for(int i = 0;i < n;++i){
		scanf("%d. %s %d",&day,month,&year);
		int days;
		for(int k = 0;k < 19;++k){
			if(!strcmp(haabmonth[k],month)){
				days = year * 365 + k * 20 + day;
				break;
			}
		}
		int m = days % 260;
		printf("%d %s %d\n",m%13+1,tzolkinday[m%20],days/260);
	}
	return 0;
}
