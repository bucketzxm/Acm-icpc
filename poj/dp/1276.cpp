#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
using namespace std;
#define ll long long

int cash = 0,n;
int value[20];
int num[20];
int dp[100000];
int cnt[100000];
int main()
{
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(scanf("%d",&cash)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&num[i],&value[i]);
        }

        for(int i=1;i<=n;i++)
        {
            memset(cnt,0,sizeof(cnt));
            for(int j=value[i];j<=cash;j++)
            {
                if( dp[j]<dp[j-value[i]]+value[i] && cnt[j-value[i]]<num[i])
                {
                    dp[j] = dp[j-value[i]]+value[i];
                    cnt[j] = cnt[j-value[i]] + 1;
                }
            }
        }
        printf("%d\n",dp[cash]);
    }



    return 0;
}
