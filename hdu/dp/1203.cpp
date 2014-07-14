#include <iostream>
#include <iomanip>
using namespace std;

#define MAXN 10005
#define min(a,b) a<b?a:b
int mon[MAXN];
double gai[MAXN];
double dp[MAXN];
int main()
{

    int n,m;
    while(cin>>n>>m)
    {
        if( n== 0 && m==0)break;
        for(int i=1;i<=m;i++)
        {
            cin>>mon[i]>>gai[i];
            gai[i] = 1-gai[i];
        }

        for(int i=0;i<=n;i++)
        {
            dp[i] = 1;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j = n;j>=mon[i];j--)
            {
                dp[j] = min( dp[j] , dp[j-mon[i]]*gai[i]);
            }
        }
        cout<<fixed<<setprecision(1)<<100*(1-dp[n])<<"\%"<<endl;
    }


    return 0;
}
