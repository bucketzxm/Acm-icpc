#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int dp[2][1<<20];
int num[20][20];
int pre[1<<20];

int pp;
int sum(int i,int s)
{
    int ret = 0;

    for(int m=0;m<n;m++)
    {
        if( pre[s] & (1<<m))
        {
            ret += num[i][m];
        }
    }
    return ret;
}
int jud(int a,int b)
{
    return pre[a]&pre[b];
}

void init()
{

    pp = 0 ;
    for(int i=0;i<(1<<n);i++)
    {
        if( i & (i<<1))continue;
        pre[pp++] = i;
    }
    memset(dp,0,sizeof(dp));
}

int main()
{
    freopen("in","r",stdin);
    while(cin>>n)
    {
        init();

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>num[i][j];


        for(int i=0;i<pp;i++)
        {
            dp[0][i]  = sum(0,i);
        }
        int pl = 1;
        for(int i=1;i<n;i++)
        {
            for(int a=0;a<pp;a++){
                int d = sum(i,a);
                dp[pl][a] = 0;
                for(int b=0;b<pp;b++)
                {
                    if( ! jud (a,b) )
                    {
                        dp[pl][a] = max( dp[pl][a], dp[1-pl][b]+d);
                    }
                }
            }
            pl = 1-pl;
        }
        int ans = 0;


        for(int i=0;i<pp;i++)
        {
           // cout<<i<<" "<<dp[n-1][i]<<endl;
            ans = max( ans, dp[1-pl][i]);
        }
        cout<<ans<<endl;
    }


    return 0;
}
