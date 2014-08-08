#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int E,F,n;
int dp[1000000];
int v[600],w[600];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>E>>F>>n;
        for(int i=1;i<=n;i++)
            cin>>v[i]>>w[i];
        memset(dp,-1,sizeof(dp));
        int W = F-E;
        for(int i=0;i<=W;i++)dp[i]=0x7ffffff;

        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j = w[i];j<=W;j++)
            {
                dp[j] = min( dp[j], dp[j-w[i]]+v[i]);
            }
        }
        if(dp[W]!=0x7ffffff)
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<<endl;
        else
            cout<<"This is impossible."<<endl;
    }

    return 0;
}
