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

int x[2000];

int cnt(int g)
{
    int ret =0;
    while(g)
    {
        if( g & 1)
        {
            ret++;
        }
        g>>=1;
    }
    return ret;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif


    int n,m,k;
    cin>>n>>m>>k;

    m++;
    for(int i=0;i<m;i++){
        cin>>x[i];
    }
    int ans = 0;
    for(int i=0;i<m-1;i++)
    {
        int ret = cnt( x[i] ^ x[m-1] );

        if( ret <= k)
        {
            ans ++;
        }

    }

    cout<<ans<<endl;
	return 0;
}

