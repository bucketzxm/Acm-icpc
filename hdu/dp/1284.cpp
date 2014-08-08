#include <iostream>
#include <cstring>
using namespace std;

#define ll long long
ll dp[32768+100];
int main()
{

    ll N;
    while(cin>>N)
    {
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i=1;i<=3;i++)
        {
            for(int j=0;j+i<=N;j++)
            {
                dp[j+i] += dp[j];
            }
        }
        cout<<dp[N]<<endl;
    }
    return 0;
}
