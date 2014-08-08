#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int N,M;
char Map[105][15];
int st[1<<10];
int p;
int pre[1<<10];
int dp[105][2129];
int id[1<<20];
int pid = 0;
void init(){
    p=0;
    for(int i=0;i<(1<<M);i++){
        if( (i& (i<<1))  || (i& (i<<2)))
            continue;
        pre[p++] = i;
    }

    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            int s1= pre[i],s2=pre[j];
            if( s1&s2)continue;
            id[(s1<<M)+s2]  = pid++;
        }
    }

    return ;
}

int bit(int s){

    int ret= 0;
    while(s){
        if( (s & 1) )ret++;
        s= s>>1;
    }
    return ret;

}
int main()
{
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    while(cin>>N>>M){
        cin.ignore();
        init();
        for(int i=0;i<N;i++){
            cin>>Map[i];
            for(int j=0;j<M;j++){
                if(Map[i][j]=='P') st[i] |= (1<<j);
                //cout<<i<<" "<<st[i]<<endl;
            }
        }
        //cout<<"----"<<endl;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<p;i++){
            int s = pre[i];
            int d1 = id[(0<<M)+s];
            if ( (s & st[0]) == s)
                dp[0][d1] = bit(s);
        }
        for(int i=0;i<p;i++){
            int s1 = pre[i];
            for(int j=0;j<p;j++){
                int s2 = pre[j];
                if ( (s1 & s2) || (s1&st[0])!=s1 || (s2&st[1])!=s2)continue;

                int d1 = id[(s1<<M)+s2];
                int d2 = id[(0<<M)+s1];
                dp[1][d1] =max(dp[1][d1], bit(s2) + dp[0][d2]);
            }
        }

        for(int l=2;l<N;l++){
            for(int i=0;i<p;i++){
                int s1 = pre[i];
                for(int j=0;j<p;j++){
                    int s2 = pre[j];
                    for(int k=0;k<p;k++){
                        int s3 = pre[k];

                        if( s1&s2 || s1&s3 || s2&s3)continue;
                        if( (s1&st[l-2])!=s1 || (s2&st[l-1])!=s2 || (s3&st[l])!=s3) continue;

                        int a = id[(s1<<M)+s2];
                        int b = id[(s2<<M) +s3];
                        dp[l][b] = max(bit(s3)+ dp[l-1][a], dp[l][b]);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<p;i++){
            for(int j=0;j<p;j++){
                int s1 = pre[i], s2 = pre[j];

                if( (s1&s2) || (s1&st[N-2])!=s1 || (s2&st[N-1])!=s2 )continue;

                int d1 = id[ (s1<<M)+s2];
                ans= max(ans, dp[N-1][d1]);
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}
