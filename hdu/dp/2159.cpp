
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,k,s;

int dp[200][200];
int value[200],tol[200];
int main()
{
    while(cin>>n>>m>>k>>s)
    {
        for(int i=1;i<=k;i++)
        {
            cin>>value[i]>>tol[i];
        }

        memset(dp,0,sizeof(dp));

        for(int i=1;i<=k;i++){
            for(int j=tol[i];j<=m;j++){
                for(int ts = 1;ts<=s;ts++){
                    //dp[j][ts] = dp[j][ts];
                    dp[j][ts] = max( dp[j][ts],dp[j-tol[i]][ts-1]+value[i]);
                   // cout<<dp[i][j][ts]<<" ";
                }
                //cout<<endl;
            }
        }

        int flag = 0 ,loc = 0;
        for(int i=0;i<=m;i++)
        {
            for(int ts = 0;ts<=s;ts++)
            {
                if( dp[i][ts]>=n)
                {
                    flag = 1; loc = i;
                    break;
                }
            }
            if( flag )break;
        }
        if(!flag)cout<<-1<<endl;
        else
            cout<<m-loc<<endl;


    }


    return 0;
}
