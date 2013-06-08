/*************************************************************************
	> File Name: zoj1324.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月07日 星期四 19时05分06秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
    struct{
        char n[61];
        int l;
    }f[101],t;
    int i,j,k,n,l,max,nr,nc;

    while(scanf("%d",&n)!=EOF){
        max=0;
        for(i=0;i<n;i++){
            scanf("%s",f[i].n);
            f[i].l=strlen(f[i].n);
            if(f[i].l>max) max=f[i].l;
        }
        max+=2;
        nc=62/max;
        for(i=0;i<n;i++){
            k=i;
            for(j=i+1;j<n;j++)
                if(strcmp(f[j].n,f[k].n)<0) k=j;
            t=f[i];f[i]=f[k];f[k]=t;
        }
        /*
        for(i=0;i<n;i++){
            for(l=f[i].l;l<max;l++)
                f[i].n[l]=' ';
            f[i].n[max]='\0';               //PE2
        }
        */
        nr=(n+nc-1)/nc;
        printf("------------------------------------------------------------\n");
        for(i=0;i<nr;i++){
            k=i;
            for(j=0;j<nc;j++,k+=nr){
                /*
                for(l=f[k].l;l<max;l++)
                        printf(" ");                //PE1
                */
                if(k<n-nr){
                    printf("%s",f[k].n);
                    for(l=f[k].l;l<max;l++)
                        printf(" ");
                }
                else if(k<n) printf("%s\n",f[k].n);
            }
        }
    }

    return 0;   /* NZEC */
}
