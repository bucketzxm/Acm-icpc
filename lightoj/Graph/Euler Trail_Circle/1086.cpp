#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 111111111
int fy[40][40],du[40];
int sum,dp[1<<20];

int n,m;

void init()
{
    for(int i=0;i<n;i++){
        du[i] = 0;
        for(int j=0;j<n;j++){
            if( i == j) fy[i][j] = 0;
            else
                fy[i][j] = INF;
        }
    }
}

void floyd(){

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                fy[i][j] = min( fy[i][j], fy[i][k]+fy[k][j]);
            }
        }
    }
}

int main(){

    int T;
    cin>>T;

    int cse = 0;
    while(T--){
        cout<<"Case "<<++cse<<": ";
        cin>>n>>m;

        init();

        sum = 0;
        for(int i=0;i<m;i++){
            int a,b,len;
            cin>>a>>b>>len;
            a--;b--;
            du[a] +=1;
            du[b] +=1;
            fy[a][b] = fy[b][a] = min( fy[a][b], len);
            sum += len;
        }
        floyd();

        //print();
        int p = 0;
        for(int i=n-1;i>=0;i--){
            p <<=1;
            if( du[i] %2==1){
                p |= 1;
            }
        }
        for(int i=0;i<(1<<n);i++)dp[i]=INF;

        dp[p] = sum;
        for(int t = (1<<n-1);t>=0;t--){
            for(int i=0;i<n;i++){

                if( t & (1<<i) == 0 )continue;

                for(int j=0;j<n;j++){
                    if( i== j || (t& (1<<j)==0))continue;

                    dp[ t^(1<<i)^(1<<j) ] = min( dp[t^(1<<i)^(1<<j)], dp[t] + fy[i][j]);
                }
            }
        }
        cout<<dp[0]<<endl;
    }


    return 0;
}
