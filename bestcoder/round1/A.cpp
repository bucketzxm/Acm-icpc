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

#define MAXN 50000
int n,m;

int in[MAXN];
int vis[MAXN];
VI G[MAXN];
vector<int> ans;
void topo()
{
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;i++)
    {
        if( in[i] == 0)q.push(i);
    }
    while(!q.empty())
    {
        int i = q.top();q.pop();
        if( in[i] == 0 && !vis[i])
        {
            ans.PB(i);
            vis[i]=1;
            int len = G[i].size();
            for(int j=0;j<len;j++)
            {
                in[ G[i][j] ] --;
                if( in[G[i][j]]==0)q.push(G[i][j]);
            }
            i=0;
        }
    }

}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    int T;
    cin>>T;
    while(T--)
    {
        ans.clear();
        CLR(vis,0);
        CLR(in,0);
        cin>>n>>m;

        for(int i=0;i<=n;i++)
            G[i].clear();
        REP(i,m)
        {
            int a,b;
            cin>>a>>b;
            G[a].PB(b);
            in[b]++;
        }

        topo();
        int len =ans.size();
        for(int i=0;i<len;i++)
        {
            cout<<ans[i];
            if( i==ans.
               size()-1)cout<<endl;
            else cout<<" ";
        }
    }

	return 0;
}

