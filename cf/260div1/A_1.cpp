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

#define MAXN 100000+10
ll num[MAXN];
ll dp[MAXN];
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        num[t]++;
    }
    memset(dp,0,sizeof(dp));
    dp[1] = num[1];
    dp[2] = num[2]*2;
    ll ans = 0;
    for(int i=3;i<MAXN;i++){
        dp[i] = max( dp[i], max(dp[i-2]+num[i]*i,dp[i-3]+num[i]*i));
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
	return 0;
}

