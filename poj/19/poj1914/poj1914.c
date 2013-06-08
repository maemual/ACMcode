#include <stdio.h>

long long mat1[5][5],mat2[5][5];
long long b[5];

long long det(long long m[5][5])
{
	return m[1][1]*(m[2][2]*m[3][3] - m[2][3]*m[3][2])
		-m[1][2]*(m[2][1]*m[3][3] - m[2][3]*m[3][1])
		+m[1][3]*(m[2][1]*m[3][2] - m[2][2]*m[3][1]);
}
void copy(long long m1[5][5],long long m2[5][5])
{
	int i,j;
	for (i = 1; i <= 3; i++)
	  for (j = 1; j <= 3; j++)
		m1[i][j] = m2[i][j];
}
int main()
{
	int cas;
	scanf("%d",&cas);
	int i,j;
	long long A[5];
	double x[5];
	while (cas--)
	{
		for (i = 1; i <= 3; i++)
		{
			for (j = 1; j <= 3; j++)
			{
				scanf("%lld",&mat1[i][j]);
				mat2[i][j] = mat1[i][j];
			}
			scanf("%lld",&b[i]);
		}
		A[0] = det(mat1);

		for (i = 1; i <= 3; i++)
		{
			for (j = 1; j <= 3; j++)
			  mat2[j][i] = b[j];
			A[i] = det(mat2);
			copy(mat2,mat1);
		}
		printf("%lld %lld %lld %lld\n",A[1],A[2],A[3],A[0]);
		if (A[0] == 0){
			printf("No unique solution\n\n");
		}else {
			for (i = 1; i <= 3; i++)
			  x[i] = A[i]*1.0 / A[0];
			printf("Unique solution:");
			for (i = 1; i <= 3; i++)
			{
				if (x[i] > -0.0005 && x[i] < 0.0005)
				  printf(" 0.000");
				else
				  printf(" %.3lf",x[i]);
			}
			printf("\n\n");
		}
	}
	return 0;
}
