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

#define MAXN 1000000+10
int dp[MAXN];
int num[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in","r",stdin);
    int n;
    cin>>n;
    dp[0]=0;
    REP2(i,1,n)
    {
        cin>>num[i];
    }
    REP2(i,1,n)
    {
        if( num[i]>num[i-1])
        {
            dp[i][0] = max(dp[i][0],dp[i-1][0]+1);
        }
        else
        {
            dp[i][1] = max( dp[i][1], dp[i-1][0]+1);
        }

        if( num[i]>num[i-1])
        {
            dp[i][1] = max(dp[i][1],dp[i-1][1]);
        }
        else
        {

        }

    }
	return 0;

}




