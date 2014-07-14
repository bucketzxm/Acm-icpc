#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

#define MAXN 50
int row[MAXN],col[MAXN];
int dp[MAXN][MAXN];
int rec[MAXN][MAXN];
int n;
void dfs(int i,int j)
{
   // cout<<"#"<<i<<" "<<j<<endl;
    if( i==j)
    {
        cout<<"A"<<i+1;
        return;
    }
    else if( i == j-1 && (i!=0 || j!=n-1))
    {
        cout<<"(A"<<i+1<<"A"<<j+1<<")";
        return;
    }
    else if( i==0 && j==n-1)
    {
        dfs(i,rec[i][j]);
        dfs(rec[i][j]+1,j);
        return;
    }
    else
    {
        cout<<"(";
       // cout<<i <<" "<<j<<" "<<rec[i][j]<<endl;
        dfs(i,rec[i][j]);
        dfs(rec[i][j]+1,j);
        cout<<")";
    }
}
int main()
{

	ios::sync_with_stdio(false);

   // freopen("out.txt","w",stdout);
    int cse = 0;
    while(cin>>n)
    {
        CLR(rec,0);
        cout<<"Case "<<++cse<<endl;
        int a;
        cin>>a;
        row[0] =a;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            col[i] = a; row[i+1] =a;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j] = INF;
            }
        }
        CLR(rec,0);
        for(int i=0;i<n;i++)
            dp[i][i] = 0;
        for(int i=0;i<n-1;i++)
        {
            dp[i][i+1] = row[i]*col[i]*col[i+1];
        }
        for(int len = 2;len<n;len++)
        {
            for(int s= 0 ; s+len<n;s++)
            {
                for(int k=s;k<=s+len;k++)
                {
                    int d = dp[s][k]+dp[k+1][s+len]+row[s]*col[k]*col[s+len];
                    if( dp[s][s+len]>d)
                    {
                        dp[s][s+len] = d;
                        rec[s][s+len] = k;
                    }
                    //cout<<s<<" "<<s+len<<" "<<k<<" "<<dp[s][k]+dp[k+1][s+len]+row[s]*col[k]*col[s+len]<<endl;
                }
            }
        }
        cout<<dp[0][n-1]<<" ";
        dfs(0,n-1);
        cout<<endl;
    }
	return 0;
}



