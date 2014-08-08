#include <iostream>
using namespace std;

int H[50];
int dp[20*1000000];
int main()
{
    int N,B;
    cin>>N>>B;

    for(int i=1;i<=N;i++)
    {
        cin>>H[i];
    }
    dp[0] = 0;
    int ans = 20*1000000;
    for(int i=1;i<=N;i++)
    {
        for(int j=2*B;j-H[i]>=0;j--)
        {
            dp[j] = max( dp[j], dp[j-H[i]]+H[i]);
            if( dp[j]>=B && dp[j]<ans)
                ans = dp[j];
        }
    }
    cout<<ans-B<<endl;
    return 0;
}
