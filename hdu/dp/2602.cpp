
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
#define MAXV 1005
#define MAXN 1005
int N,V;
int value[MAXN];
int w[MAXN];
int dp[MAXN][MAXV];
int main()
{
	ios::sync_with_stdio(false);

    int tst;
    cin>>tst;
    while(tst--)
    {
        CLR(dp,0);
        cin>>N>>V;

        REP(i,N)
        {
            cin>>value[i];
        }
        REP(i,N)
        {
            cin>>w[i];
        }
        REP(i,V+1)
        {
            if( i>=w[0])
            dp[0][i] = value[0];
        }

        REP2(i,1,N)
        {
            REP2(wi,0,V)
            {
                dp[i][wi] = dp[i-1][wi];
                if( wi-w[i]>=0)
                    dp[i][wi] = max(dp[i-1][wi],dp[i-1][wi-w[i]]+value[i]);
            }
        }

        cout<<dp[N-1][V]<<endl;
    }
	return 0;
}
