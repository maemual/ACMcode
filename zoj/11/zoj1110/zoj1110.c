#include <stdio.h>
int main()
{
	int j, a, b, c, s, p, y;
	while(scanf("%d%d%d%d", &s, &p, &y, &j) != EOF)
	{
		for(a=12+j-1; a>=s+p; a--)
			for(b=p; b<=12+j-a; b++)
			{
				c = 12+j-b-a;
				if(  
					 ( a == b+s || a == b+s+1 ) &&
					 ( b == c+p || b == c+p+1 ) &&
					 ( a == y+c || a == y+c+1 )
				  )
				goto X;
			}
		X:
		printf("%d %d %d\n", a, b, c);
	}
    return 0;
}

