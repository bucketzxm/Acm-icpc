#include<stdio.h>
int main(void)
{
	//freopen("input.txt","r",stdin);
	int t,m,a[105][105],f,i,j,h,col,max,min,panduan;
	scanf("%d",&t);

	for(h=1;h<=t;h++){
		panduan = 0;
		scanf("%d",&m);
        for(i=0;i<m;i++){
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        }

	 for(f=0;f<m;f++){
		 max=a[f][0];
		 col = 0;
        for(j=1;j<m;j++){
            if(a[f][j]>max)
            {
                max=a[f][j];
                col=j;
            }
        }
		min=max;
		int q =0;
        for(q=0;q<m;q++)
        {
            if(a[q][col]<min)
            {
                min = a[q][col];
                break;
            }
        }
        if( max == min)
        {
            panduan =1;
            break;
        }
	}
	if(panduan==0)
		printf("NO\n");
	else
		printf("YES\n");

	}
	return 0;
}
