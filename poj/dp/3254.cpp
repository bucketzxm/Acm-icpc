#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int M,N;
int mod = 100000000;
int give[13],can[1<<20];
int pcan;
int dp[13][1<<20];

bool jud2(int a,int b)
{
    return give[a]&can[b];
}

bool jud(int x){
    return x&(x<<1);
}

int main()
{

   // freopen("in","r",stdin);

    while(cin>>M>>N)
    {
        memset(give,0,sizeof(give));
        memset(can,0,sizeof(can));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=M;i++){
            for(int j=0;j<N;j++){
                int t; cin>>t;
                if(t==0) give[i] |= (1<<j);
            }
        }

        pcan = 0;

        for(int i=0;i<(1<<N);i++){
            if( ! jud(i) ){
                can[pcan++] = i;
            }
        }
        for(int i=0;i<pcan;i++)
        {
            if(!jud2(1,i))
            {
                dp[1][i] =1;
            }
        }

        for(int i=2;i<=M;i++)
        {
            for(int j=0;j<pcan;j++){
                if( ! jud2(i,j)){
                    for(int k=0;k<pcan;k++)
                    {
                        if( !(can[j]&can[k]) && !jud2(i-1,k))
                        {
                            dp[i][j] += dp[i-1][k];
                            dp[i][j]%=mod;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0;i<pcan;i++)
        {
            ans+= dp[M][ i ];
            ans%=mod;
        }
        cout<<ans%mod<<endl;

    }
    return 0;
}
