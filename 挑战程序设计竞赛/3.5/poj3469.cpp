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

#define MAXV 50000
struct edge{
    int to,cap,rev;
};
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];

void add_edge(int from,int to,int cap){
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}


void bfs(int s){
    CLR(level,-1);
    queue<int> que;
    level[s]= 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();que.pop();
        for(int i=0;i<G[v].size();i++){
            edge& e = G[v][i];
            if( e.cap>0 && level[e.to]<0){
                level[e.to] = level[v] +1;
                que.push(e.to);
            }
        }
    }

}

int dfs(int v,int t,int f){
    if( v==t)return f;

    for(int &i = iter[v];i<G[v].size();i++){
        edge &e = G[v][i];
        if( e.cap>0 && level[v]<level[e.to]){
            int d = dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t){
    int flow = 0;
    for(;;){
        bfs(s);
        if(level[t]<0)return flow;
        CLR(iter,0);
        int f;
        while(( f= dfs(s,t,INF))>0){
            flow +=f;
        }
    }
}
int N,M;
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
          freopen("in","r",stdin);
    #endif

    while(cin>>N>>M){
        for(int i=0;i<N+2;i++){
            G[i].clear();
        }
        int s = N, t = s+1;
        for(int i=0;i<N;i++){
            int a,b;
            cin>>a>>b;

            add_edge(s,i,b);
            add_edge(i,t,a);
        }
        for(int i=0;i<M;i++){
            int a,b,w;
            cin>>a>>b>>w;
            add_edge(a-1,b-1,w);
            add_edge(b-1,a-1,w);
        }
       // cout<<s<<" "<<t<<endl;

        cout<<max_flow(s,t)<<endl;
    }


    return 0;
}
