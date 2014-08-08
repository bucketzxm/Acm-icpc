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


#define MAXV 100000

struct edge{
    int to,cap,cost,rev;
};
int V;
vector<edge> G[MAXV];
int h[MAXV];
int dist[MAXV];
int prevv[MAXV],preve[MAXV];

void add_edge(int from,int to,int cap,int cost){
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}

int min_cost_flow(int s,int t,int f){
    int res = 0;
    CLR(h,0);

    while(f>0){
        priority_queue<PII, vector<PII> , greater<PII> > que;
        for(int i=0;i<V;i++) dist[i] = INF;

        dist[s] = 0;

        que.push(MP(0,s));

        while(!que.empty()){
            PII p =que.top(); que.pop();
            int v = p.second;
            if( dist[v] <p.first) continue;

            for(int i=0;i<G[v].size();i++){
                edge& e = G[v][i];

                if( e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to] = dist[v] +e.cost+h[v]-h[e.to];
                    prevv[e.to] =v;
                    preve[e.to] = i;
                    que.push( MP(dist[e.to],e.to));
                }
            }
        }
        if(dist[t] == INF){
            return -1;
        }
        for(int v=0;v<V;v++)h[v]+=dist[v];

        int d = f;
        for(int v =t;v!=s;v=prevv[v]){
            d = min( d, G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v = t;v!=s;v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;

}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    int N,M;
    cin>>N>>M;
    V= N+1;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add_edge(a-1,b-1,1,c);
        add_edge(b-1,a-1,1,c);
    }
    cout<<min_cost_flow(0,N-1,2)<<endl;
	return 0;
}


