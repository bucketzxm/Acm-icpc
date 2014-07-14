#include <stdio.h>
int max(int a,int b);
int min(int a,int b);
int main(void)
{
    int n,a[2000],i,j,l,sum1,sum2,p,q,sum,maxindex,minindex;
    char b;

    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++){
        j=1;
        while(1){
            scanf("%d",&a[j]);
            b=getchar();
            if(b=='\n'||b==-1||b=='\r')break;
            j++;
        }
        printf("Case %d:\n",i);
        if(j<3){
            printf("No maximal and minimal!\n");
        }
        else if(j==3){
            p=q=a[1]+a[2]+a[3];
            maxindex=minindex=1;
            printf("maximum = %d, minimum = %d, MaxIndex = %d, MinIndex = %d\n",p,q,maxindex,minindex);
        }
        else{
            sum1=a[j-1]+a[j]+a[1];
            sum2=a[j]+a[1]+a[2];
            if(sum1>sum2){
                p=sum1;q=sum2;
                maxindex=j-1;minindex=j;
            }
            else{
                p=sum2;q=sum1;
                maxindex=j;minindex=j-1;
            }
            for(l=1;l<=j-2;l++){
                sum=a[l]+a[l+1]+a[l+2];
                if(sum>p){
                    p=sum;
                    maxindex=l;
                }
                 if(sum<q){
                    q=sum;
                    minindex=l;
                }
            }
            printf("maximum = %d, minimum = %d, MaxIndex = %d, MinIndex = %d\n",p,q,maxindex,minindex);
        }
    }
    return 0;
}
