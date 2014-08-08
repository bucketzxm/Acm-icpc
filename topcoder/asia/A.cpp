#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN= 100000;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));

    for(int i=2;i<=MAXN;i++)
    {
        if( !prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}

long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
    fatCnt = 0;

    long long tmp = x;
    for(int i=1;prime[i]<=tmp/prime[i];i++)
    {

        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatCnt][0]=prime[i];

            while(tmp%prime[i]==0)
            {
                factor[fatCnt][1]++;
                tmp/=prime[i];
            }
            fatCnt++;
        }
    }
    if(tmp!=1)
    {
        factor[fatCnt][0]=tmp;
        factor[fatCnt++][1]=1;
    }
    return fatCnt;

}


int main()
{
    getPrime();
    getFactors(100);

    long long ans = 0;
    for(int i=fatCnt-1;i>=0;i--)
    {
        for(int j=1;j<=factor[i][1];j++)
        {
            long long now = pow(factor[i][0],j);

            if( sqrt(now)*sqrt(now) == now)
            {
                if(now>ans)ans = now;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
