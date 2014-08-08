
#include <iostream>
using namespace std;
int dp[500*40000];
int main()
{
    int N,M;
    int w,d;
    cin>>N>>M;
    dp[0] = 0;
    for(int i=1;i<=N;i++)
    {
        cin>>w>>d;

        for(int j=M;j-w>=0;j--)
        {
            dp[j] = max( dp[j] , dp[j-w]+d);
        }

    }
    cout<<dp[M]<<endl;

    return 0;
}
