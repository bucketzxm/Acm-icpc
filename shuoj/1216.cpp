#include <iostream>
using namespace std;
#define ll long long
ll dp[1000][1000];
ll C(int m, int n)
{
	if(m<1000&&n<1000&&dp[m][n]) return dp[m][n];
	if(m==n||n==0)   return 1;
	if(n==1)   return m;
	ll ret = C(m-1,n-1)*m/n;
	if(m<1000&&n<1000)
		dp[m][n]=ret;
	return ret;
}
int main()
{

    ll m,n;
    while(cin>>m>>n)
    {
        cout<<C(m,n)<<endl;
    }

}
