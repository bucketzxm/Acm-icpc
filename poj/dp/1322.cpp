
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;


int C,N,M;
double dp[1000][1000];
int main()
{
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    while(cin>>C>>N>>M)
    {

        memset(dp,0,sizeof(dp));
        dp[0][0] =1;

        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=C;j++)
            {
                if( j==0 )
                {
                    dp[i][j] = dp[i-1][j+1]*1.0/C;
                }
                else if( j==C)
                {
                    dp[i][j] = dp[i-1][j-1]/C;
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1]*(C-j+1)/C+ dp[i-1][j+1]*(j+1)/C;
                }
            }

        }
        cout<<fixed<<setprecision(3)<<dp[N][M]<<endl;
    }

    return 0;
}
