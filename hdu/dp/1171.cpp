#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[3000000];
int value[1000];
int num[1000];
int main()
{

    int n;
    while(cin>>n && n>=0)
    {
        memset(dp,0,sizeof(dp));

        int sum =0;
        for(int i=1;i<=n;i++)
        {
            cin>>value[i]>>num[i];
            sum+=value[i]*num[i];
        }

        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=num[i];k++)
            {
                for(int j = sum/2;j>=k*value[i];j--)
                {
                    dp[j] = max( dp[j], dp[j-value[i]] + value[i]);
                }
            }
        }
        cout<<max(sum-dp[sum/2],dp[sum/2])<<" "<<min(sum-dp[sum/2],dp[sum/2])<<endl;
    }

    return 0;
}
