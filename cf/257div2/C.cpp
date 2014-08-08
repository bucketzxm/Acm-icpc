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
        if( x/i*i!=x)continue;
            ll j = x/i;
            if( j>m)continue;
            if( i*j==x)cnt++;
            if( i*j == x && ((n-i)/i)+((m-j)/j) >=k)
            {
                cout<<i<<' '<<j<<endl;
                return false;
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
//    ll a = n, b= m;
//    n = min(a,b); m = max(a,b);
    ll left = 1, right = n*m;
    ll ans = 0;
    int add = 0;
    while(left<=right)
    {
       ll mid = (left+right)/2;
       cout<<left <<" "<<right<<" "<<mid<<endl;
       if(C(mid))
       {
            right = mid-1;
       }
       else
       {
           left = mid+1;
           if(cnt>0)
           ans = mid;
       }
    }
    if( ans == 0 )cout<<-1<<endl;
    else
        cout<<ans<<endl;

	return 0;
}

