
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


const int MAXN = 1000;

struct Edge{
    int from ,to ,cap, flow;
    Edge(int u,int v,int c,int f) : from(u),to(v),cap(c),flow(f){}
};
struct EdmondsKarp
{
    int n,m;
    vector<Edge> edges;
    vector<int> G[MAXN];

    int a[MAXN],p[MAXN];

    void init(int n)
    {
        for(int i=0;i<n;i++)G[i].clear();
        edges.clear();
    }

    void AddEdge(int from ,int to ,int cap)
    {
        edges.PB(Edge(from,to,cap,0));
        edges.PB(Edge(to,from,0,0));
        m = edges.size();
        G[from].PB(m-2);
        G[to].PB(m-1);
    }

    int MaxFlow(int s,int t)
    {
        int flow = 0;

        for(;;)
        {
            CLR(a,0);
            queue<int> Q;
            Q.push(s);
            a[s] = INF;

            while(!Q.empty())
            {
                int x = Q.front();Q.pop();
                for(int i=0;i<G[x].size();i++)
                {
                    Edge &e = edges[G[x][i]];
                    if( !a[e.to] && e.cap> e.flow)
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x],e.cap-e.flow);
                        Q.push(e.to);
                    }
                }
                if( a[t]) break;
            }
            if(!a[t]) break;
            for(int u=t;u!=s;u=edges[p[u]].from)
            {
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow += a[t];

        }
        return flow;
    }
};
int main()
{
	ios::sync_with_stdio(false);




	return 0;
}
