#include <stdio.h>

int main()
{
  int cells[101];
  int n,t,i,j,ans,p;
  scanf("%d",&t);
  for (;t>0;t--)
    {
      scanf("%d",&n);
      for (i=0;i<n;i++)
	cells[i]=-1;
      for (i=2;i<=n;i++)
	for (j=i-1;j<n;j+=i)
	      cells[j] *= -1;
      ans=0;
      for (i=0;i<n;i++)
	if (cells[i] == -1)
	  ans++;
      printf("%d\n",ans);
    }
  return 0;
}
