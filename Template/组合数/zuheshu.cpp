#include<iostream>
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
	int n,k,ok;
		cout<<"按1继续，按0退出\n";
	while(cin>>ok)
	{
		if(ok==0)
			break;
		cout<<"n = ";
		cin>>n;
		cout<<"k = ";
		cin>>k;
		cout<<"∴C(n,k) = "<<C(n,k)<<endl;
	}
	return 0;
}
