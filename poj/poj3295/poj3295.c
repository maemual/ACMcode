#include <stdio.h>

char str[105];
int pos = -1;
int state[5];
int cal()
{
	int p,q;
	switch (str[++pos])
	{
		case 'K':p = cal();q = cal();return p && q;
		case 'A':p = cal();q = cal();return p || q;
		case 'N':p = cal();return !p;
		case 'C':p = cal();q = cal();return !p || q;
		case 'E':p = cal();q = cal();return p == q;
		default:return state[str[pos]-'p'];
	}
}
int main()
{
	int p,q,r,s,t;
	while (1)
	{
		scanf("%s",str);
		if (str[0] == '0')
		  break;
		int ans = 1;
		for (p = 0; p <= 1; p++)
		{
			state[0] = p;
			for (q = 0; q <= 1; q++)
			{
				state[1] = q;
				for (r = 0; r <= 1; r++)
				{
					state[2] = r;
					for (s = 0; s <=1; s++)
					{
						state[3] = s;
						for (t = 0; t <=1; t++)
						{
							state[4] = t;
							pos = -1;
							ans = ans && cal();
							if (!ans)
							  break;
						}
						if (!ans)
						  break;
					}
					if (!ans)
					  break;
				}
				if (!ans)
				  break;
			}
			if (!ans)
			  break;
		}
		if (ans)
		  printf("tautology\n");
		else
		  printf("not\n");
	}
	return 0;
}
