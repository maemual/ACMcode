#include <iostream>
#include <stdio.h>
using namespace std ;

int from, to ;

int stimu( )
{
	int i, step = 2 ;
	for( i=2,++from,--to; ; ++i ){
		from += i ;
		++step ;
		if( from >= to )
			return step ;
		to -= i ;
		++step ;
		if( to <= from )
			return step ;
	}
}

int main()
{
	int i, j ;
	while( EOF != scanf("%d%d", &from, &to ) ){
		if( to-from <= 2 ){
			printf("%d\n", to-from ) ;
			continue ;
		}
		printf("%d\n", stimu( ) ) ;
	}
	return 0 ;
}

