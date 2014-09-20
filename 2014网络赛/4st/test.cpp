#include<iostream>
#include<iomanip>
#include<cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1000][1000];
void hanshu(int n,int p)
{
	int i,j;
	memset(a,0,sizeof(a));

	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
		    if(j<1){
                a[i][j]=1;//开头的第一个数为1
		    }
            else if(i==0){
                break;
            }
            else
                a[i][j]=a[i-1][j-1]+a[i-1][j];
					//杨辉三角的规律

		}

	}


	i=n;
	printf("Case %d: n=%d",p,n);
	for(j=0;j<i;j++)
		printf("%d ",a[i][j]);
	printf("\n");

}

int main()
{
	int p=1,n;
	while(cin>>n)
	{
		hanshu(n,p);
		p++;
	}
	return 0;
}


