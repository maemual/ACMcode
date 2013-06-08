#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_LEN = 100;
char a[MAX_LEN][6];
char ans[6],s[6];
int n;
int work(){
	int cnt = 0;
	for (int i=0;i<n;i++){
		for (int j=0;j<4;j++){
			for (int k=j+1;k<5;k++){
				for (int p=0;p<5;p++){
					if (a[i][p] == s[j])
					  break;
					if (a[i][p] == s[k]){
						cnt++;
						break;
					}
				}
			}
		}
	}
	return cnt;
}
int main()
{
	int m,min;
	while (1){
		scanf("%d",&n);
		if (n==0)
		  break;
		for (int i=0;i<n;i++)
		  scanf("%s",a[i]);
		strcpy(s,"ABCDE");
		min = 1000000;
		do{
			m = work();
			if (m < min){
				min = m;
				strcpy(ans,s);
			}
		}while (next_permutation(s, s+5));
		printf("%s is the median ranking with value %d.\n",ans,min);
	}
	return 0;
}
