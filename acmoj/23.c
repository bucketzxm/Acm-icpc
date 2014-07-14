#include<stdio.h>
#include<math.h>
int main(void)
{
    int a,b,i,j,max,min,t,x,y;
    j=0;
    int cse = 0;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(cse)printf("\n");
        cse++;
        x=fabs(a);
        y=fabs(b);
        j++;
        printf("Case %d:\n",j);
        if(x==0&&y==0){
            printf("no GCD\n");
            printf("no LCM\n");
        }
        else if(x==0 || y==0){
            printf("GCD(%d,%d) = %d\n",a,b,a+b);
            printf("no LCM\n");
        }
        else{
            if(x<y)
                min=x;
            else
                min=y;
            for(i=min;i>=1;i--)
            {
                if(x%i==0&&y%i==0)
                {
                     max=i;
                    break;
                }
            }
            t=x*y/max;
            printf("GCD(%d,%d) = %d\n",a,b,max);
            printf("LCM(%d,%d) = %d\n",a,b,t);
        }
    }
    return 0;
}
