
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

int num[5000];
ll last[5000];
ll dp[5050][5050];

int n,m,k;

ll sum(int s)
{

    ll ret = 0;
    for(int i=s;i<s+m;i++)
    {
        ret+=num[i];
    }
    return ret;
}
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.c","r",stdin);
    #endif

    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<=n;i++)
    {
        last[i] = sum(i);
        if(i>=m-1)
            dp[i][1] = max(dp[i][1],last[i-m+1]);
    }

     for(int tk=1;tk<=k;tk++)
     {
        for(int i=0;i<=n;i++)
        {
            for(int j=i+m;j<=n;j++)
            {
                dp[j][tk] = max( dp[j-m][tk-1]+last[j-m],
                                dp[j-m][tk]);
            }
        }
    }

    ll ans = -0x7ffffff;
    for(int i=m-1;i<=n;i++)
        ans = max( ans, dp[i][k]);

    cout<<ans<<endl;
	return 0;
}
