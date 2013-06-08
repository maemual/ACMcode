#include <stdio.h>

int main()
{
	int stamp_kind[1000];
	int stamp_total=0;
	int custmor[1000],custmor_total=0;
	int i,j1,j2,j3,j4,k;
	int kind[4];
	int kinds,flag,m,max,t,total;
	while (scanf("%d",&k)!=EOF)
	{
		stamp_total=1;
		stamp_kind[0]=0;
		while (k!=0)
		{
			stamp_kind[stamp_total++]=k;
			scanf("%d",&k);
		}
		scanf("%d",&k);
		custmor_total=0;
		while (k!=0)
		{
			custmor[custmor_total++]=k;
			scanf("%d",&k);
		}

		for (i=0;i<custmor_total;i++)
		{
			kinds=0;
			total=0;
			max=0;flag=0;
			kind[0]=0,kind[1]=0,kind[2]=0,kind[3]=0;
			for (j1=0;j1<stamp_total;j1++)
			  for (j2=j1;j2<stamp_total;j2++)
				for (j3=j2;j3<stamp_total;j3++)
				  for (j4=j3;j4<stamp_total;j4++)
					if ((stamp_kind[j1]+stamp_kind[j2]+stamp_kind[j3]+stamp_kind[j4])==custmor[i])
					{
						k=0;t=0;m=0;
						if (j1!=0)
						{
							k++;
							t++;
							if (stamp_kind[j1]>m) 
							  m=stamp_kind[j1];
						}
						if (j2!=0 && j2!=j1) 
						{
							k++;
							if (stamp_kind[j2]>m) 
							  m=stamp_kind[j2]; 
						}
						if (j3!=0 && j3!=j1 && j3!=j2) 
						{
							k++;
							if (stamp_kind[j3]>m) 
							  m=stamp_kind[j3];}
							if (j4!=0 && j4!=j1 && j4!=j2 && j4!=j3) 
							{
								k++;
								if (stamp_kind[j4]>m) 
								  m=stamp_kind[j4];
							}
							if (k<kinds) 
							  continue;
							if (j2!=0) 
							  t++;
							if (j3!=0) 
							  t++;
							if (j4!=0) 
							  t++;
							if (max==0) 
							  max=m;
							if (k>kinds) 
							{
								kinds=k;
								kind[0]=j1,kind[1]=j2,kind[2]=j3,kind[3]=j4;
								total=t;
								max=m;
								flag=0;
								continue;
							}
							if (total<t) continue;
							if (total>t)
							{
								kinds=k;
								kind[0]=j1,kind[1]=j2,kind[2]=j3,kind[3]=j4;
								total=t;
								max=m;
								flag=0;
								continue;
							}
							if (max>m) continue;
							if (max<m)
							{
								kinds=k;
								kind[0]=j1,kind[1]=j2,kind[2]=j3,kind[3]=j4;
								total=t;
								max=m;
								flag=0;
								continue;
							}
							if (max==m)
							{
								flag=1;
								continue;
							}
					}
			if (flag)
			{
				printf("%d (%d): tie\n",custmor[i],kinds);
				continue;
			}
			if (total==0) {
				printf("%d ---- none\n",custmor[i],kinds);
				continue;
			}
			printf("%d (%d):",custmor[i],kinds);
			for (j1=0;j1<4;j1++)
			  for (j2=j1;j2<4;j2++)
				if (stamp_kind[kind[j1]]>stamp_kind[kind[j2]])
				{  
					kind[j1]=kind[j1]+kind[j2];
					kind[j2]=kind[j1]-kind[j2];
					kind[j1]=kind[j1]-kind[j2];
				}
			for (j1=0;j1<4;j1++)
			  if (kind[j1]!=0) 
				printf(" %d",stamp_kind[kind[j1]]);
			printf("\n");
		}
	}
	return 0;
}
