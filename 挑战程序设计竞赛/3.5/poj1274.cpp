#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

#define MAXV 1000
#define INF 0x3FFFFFFF
struct edge{
    int to,cap,rev;
};
vector<edge> G[MAXV];
int N,M;
int level[MAXV];
int iter[MAXV];

void add_edge(int from,int to,int cap){
    G[from].push_back( (edge){to,cap,G[to].size()});
    G[to].push_back( (edge){from,0,G[from].size()-1});
}

void bfs(int s){

    memset(level,-1,sizeof(level));
    queue<int> que;
    que.push(s);
    level[s] = 0;
    while(!que.empty()){

        int u = que.front();que.pop();

        for(int i=0;i<G[u].size();i++){
            edge &e = G[u][i];
            if( level[e.to]<0 && e.cap>0){
                level[e.to] = level[u]+1;
                que.push(e.to);
            }
        }
    }
}


int dfs(int v,int t,int f){

    if( v==t )return f;
    for(int &i=iter[v];i<G[v].size();i++){
        edge& e = G[v][i];
        if(e.cap>0 && level[v] < level[e.to]){
            int d = dfs(e.to,t,min(e.cap,f));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap +=d;
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
        if( level[t]<0)return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while( (f=dfs(s,t,INF))>0){
            flow+=f;

        }
    }

}


int main(){

    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(cin>>N>>M){
        for(int i=0;i<N+M+2;i++)G[i].clear();
        int s = N+M,t = s+1;
        for(int i=0;i<N;i++){
            int t;cin>>t;
            for(int j=0;j<t;j++){
                int m ; cin>>m;
                add_edge(i,N+m-1,1);
            }
            add_edge(s,i,1);
        }
        for(int i=0;i<M;i++){
            add_edge(N+i,t,1);
        }
        int ret = max_flow(s,t);
        cout<<ret<<endl;
    }


    return 0;
}
