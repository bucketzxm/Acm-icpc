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
#define X first
#define Y second

ll dp[1501][1501];//i: all, j: blue

int main()
{
    ios::sync_with_stdio(false);
    ll T,n,x,y,z,t,cs=1;
    cin>>T;
    while(T--)
    {
        cin>>n>>x>>y>>z>>t;
        ll r=0;
        cout<<"Case #"<<cs++<<": ";
        ll ans=0;
        CLR(dp,0);
        REP(i,n)
        {
            REP2(j,0,i+1)
            {
                dp[i+1][j]=max(j!=i+1?dp[i][j]+y*(t+j*z)*(n-i-1):0, j?dp[i][j-1]+(i+1-j)*y*(z)*(n-i-1):0);
                //cout<<i+1<<' '<<j<<' '<<dp[i+1][j]<<endl;
            }
        }
        REP(i,n+1)
        {
            REP2(j,0,i)
            {
                ans=max(ans,dp[i][j]+x*(t+j*z)*(n-i));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

