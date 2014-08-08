#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[105][105];
int num[105][105];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cin>>num[i][j];
            }
        }

        int ans = 0 ;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+num[i][j];
                ans = max(ans,dp[i][j]);
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
