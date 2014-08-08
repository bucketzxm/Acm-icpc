#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 100010
int value[100], num[MAXN];
int dp[MAXN];
int main()
{

    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF,n!=0){
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&value[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=m;i++)
        dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j= 0;j<=m;j++){
            if( dp[j] >=0)
            {
                dp[j] = num[i];
            }
            else if( j<value[i] || dp[j-value[i]]<0)
            {
                dp[j] = -1;
            }
            else
            {
                dp[j] = dp[j-value[i]]-1;
            }
        }
    }
    int ans =0;
    for(int i=1;i<=m;i++)if( dp[i]>=0)ans++;
    printf("%d\n",ans);
    }
    return 0;
}
