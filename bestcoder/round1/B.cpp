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
VI G[MAXN];
int value[MAXN];
int n,m;
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("data.in","r",stdin);
    #endif

    int T;
    cin>>T;
    while(T--)
    {

        cin>>n>>m;
        CLR(value,0);
        REP2(i,0,n)G[i].clear();

        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a].PB(b);G[b].PB(a);
        }

        int Q;
        cin>>Q;
        while(Q--)
        {
            int cmd;
            cin>>cmd;
            if(cmd==0)
            {
                int u,v;
                cin>>u>>v;
                value[u]+=v;
            }
            else if( cmd==1)
            {
                int u;
                cin>>u;

                ll ans = 0;
                int len = G[u].size();
                for(int i=0;i<len;i++)
                {
                    ans+=value[ G[u][i] ];
                }
                cout<<ans<<endl;
            }
        }

    }

	return 0;
}

