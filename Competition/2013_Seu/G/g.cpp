#include<stdio.h>
#include<algorithm>
using namespace std;
int ind[200000];
int n;
long long m;
long long tab[200000];
long long cum[200000];
long long srt[200000];
long long tree[200000];
int ii[200000];
int cmp(int a,int b){
	return cum[a] < cum[b];
}
int update(int k,long long x){
	k++;
	for( ; k <= n ; ){
		tree[k] += x;
		k += (k&(-k));
	}
}
long long qq(int k){
	k++;
	long long sum = 0;
	for( ; k > 0 ; ){
		sum += tree[k];
		k -= (k&(-k));
	}
	return sum;
}
long long query(int a,int b){
	long long sum = 0;
	sum += qq(b);
	if( a!= 0 ) sum-= qq(a-1);
	return sum;
}
long long check(long long k){
	for(int i = 0; i<=n ; i++ ) tree[i] = 0;
	for(int i = 0; i< n; i++ ) update(i,1);
	long long res = 0;
	long long tmp = k;
	for(int l = 0 ; l < n ; l++ ){
		res += query( lower_bound(srt,srt+n,tmp)-srt , n-1 );
		tmp += tab[l];
		update(ii[l],-1);
	}
	return res;
}
int main(){
	while(scanf("%d %lld",&n,&m) != EOF){
		for(int i =0 ; i < n; i++ ) 
			scanf("%lld",&tab[i]);
		cum[0] = tab[0];
		for(int i =1 ;i < n ;i++ ){
			cum[i] = cum[i-1]+tab[i];
		}
		for(int i =0 ;i < n;i++ ) 
			ind[i] = i;
		sort(ind,ind+n,cmp);
		for(int i = 0;i < n;i++ ) 
			ii[ ind[i] ] = i;
		for(int i = 0;i < n;i++ ) 
			srt[i] = cum[ind[i]];

		long long inf = 1;
		for(int i = 0 ;i < 15 ;i++ ) 
			inf *=10;
		long long left = -inf, right = inf;
		for( ; left < right ; ){
			long long mid = (left+right+1)/2;
			long long res = check(mid);
			if( res >= m ){
				left = mid;
			}
			else right = mid-1;
		}
		printf("%lld\n",left);
	}
}
