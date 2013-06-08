#include <iostream>
#include <cstdio>
#include <map>
using namespace std ;

map<char,char> cypher ;

int main()
{
     
    char ch ;
    int i ;
    string from, to ;
    getline( cin, from ) ;
    getline( cin, to ) ;
    cout << to << endl << from << endl ;
    for( i=0; i<from.size(); ++i ){
        cypher[ from[i] ] = to[i] ;
    }
    while( EOF != scanf("%c", &ch ) ){
        if( cypher.count( ch ) )
            printf("%c", cypher[ch] ) ;
        else
            printf("%c", ch ) ;
    }
    return 0 ;
}
