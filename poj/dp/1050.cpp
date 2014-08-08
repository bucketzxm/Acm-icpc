
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int num[1000][1000];
//int sum[1000][1000];
int dp[1000][1000];
int main()
{
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(cin>>N)
    {
        memset(num,0,sizeof(num));
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                int t ;
                cin>>t;
                num[i][j] = num[i-1][j]+t;
                //sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+num[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<=N;j++)
            {
                int mx = 0,res=0;
                for(int k = 1;k<=N;k++)
                {
                    int sum = num[j][k] - num[i][k];

                    if( mx > 0)mx+=sum;
                    else
                        mx = sum;

                    res = max( res, mx);
                }
                ans = max(ans, res);
            }
        }
        cout<<ans<<endl;
    }



    return 0;
}
