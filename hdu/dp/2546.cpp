#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x7fffffff
int dp[600000];
int cost[2000];


int main()
{
    int n,m;
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i];
        }
        sort(cost+1,cost+n+1);
        cin>>m;
        //用５元去买最贵的
        int V = m-5;
        //剩余的背包
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++)
        {
            for(int j=V;j-cost[i]>=0;j--)
            {
                dp[j] = max( dp[j], dp[j-cost[i]]+cost[i]);
            }
        }
        if( m<5)cout<<m<<endl;
        else
            cout<<m-dp[V]-cost[n]<<endl;

    }

    return 0;
}
