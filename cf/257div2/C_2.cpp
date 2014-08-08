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

ll n,m,k;

int cnt ;
bool C(ll x)
{
    cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if( i*j==x)cnt++;
            if( i*j == x && ((n-i)/i)+((m-j)/j) >=k)
            {
              //  cout<<i<<' '<<j<<endl;
                return false;
            }
        }
    }
    if( cnt == 0)return false;
    return true;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif


    cin>>n>>m>>k;

    if( k> n-1+m-1)
    {
        cout<<-1<<endl;
        return 0;
    }

    ll t1,t2 ,t3= 0,t4= 0;
    ll ans = 0;

    if(k<n) ans = max( ans,n/(k+1)*m);
    else ans = max(ans,m/(k-n+2));
    if(k<m) ans = max(ans,m/(k+1)*n);
    else ans = max(ans,n/(k-m+2));
    cout<<ans<<endl;
	return 0;
}


