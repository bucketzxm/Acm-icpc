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

typedef pair<int,int> P;
struct edge{ int to,cap,cost,rev;};

#define MAX_V 3000
int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}

int min_cost_flow(int s,int t,int f)
{
    int res = 0;
    memset(h,0,sizeof(h));
    while(f>0)
    {
        priority_queue<P, vector<P>,greater<P> >que;
        for(int i=0;i<V;i++)
            dist[i] = INF;
        dist[s] = 0;
        que.push(P(0,s));

        while(!que.empty())
        {
            P p = que.top();que.pop();

            int v = p.second;

            if( dist[v]<p.first) continue;

            for(int i=0;i<G[v].size();i++)
            {
                edge& e = G[v][i];
                if( e.cap>0 && dist[e.to]>dist[v] +e.cost+h[v]-h[e.to]){
                    dist[e.to] = dist[v] +e.cost+h[v] -h[e.to];
                    prevv[e.to] =v;
                    preve[e.to] =i;
                    que.push( P(dist[e.to],e.to));
                }
            }
        }

        if(dist[t] == INF)
        {
            return -1;
        }
        for(int v=0;v<V;v++)h[v]+=dist[v];

        int d = f;
        for(int v = t;v!=s;v=prevv[v])
        {
            d = min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e = G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap +=d;
        }
    }
    return res;

}

int main()
{
	ios::sync_with_stdio(false);

    int k,n1,n2,n3,t1,t2,t3;

    cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;

    for(int t=1;t<=n1;t++)
    {
        add_edge(0,t,1,t1);
    }
    for(int j=1;j<=n1;j++)
        for(int t=n1+1;t<=n1+n2;t++)
        {
            add_edge(j,t,1,t2);
        }

    for(int j=n1+1;j<=n1+n2;j++)
    {
        for(int t = n1+n2+1;t<=n1+n2+n3;t++)
        {
            add_edge(j,t,1,t3);
        }
    }
    for(int j=n1+n2+1;j<=n1+n2+n3;j++)
    {
        add_edge(j,n1+n2+n3+1,1,0);
    }
    V = n1+n2+n3+2;

    int ans = min_cost_flow(0,n1+n2+n3+1,k);

    cout<<ans<<endl;

    return 0;
}



