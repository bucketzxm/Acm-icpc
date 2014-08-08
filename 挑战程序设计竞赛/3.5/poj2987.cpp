#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define INF 0x3fffffff
#define MAXV 10000
#define ll long long
struct edge{

    int to,cap,rev;

    edge(int _to,int _cap,int _rev) : to(_to),cap(_cap),rev(_rev){}
    edge(){}
};
vector<edge> G[MAXV];

int level[MAXV];
int iter[MAXV];

void add_edge(int from ,int to,int cap){
    G[from].push_back(edge(to,cap,G[to].size()));
    G[to].push_back(edge(from,0,G[from].size()-1));
}

void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s] = 0;

    que.push(s);
    while(!que.empty()){
        int  v = que.front();que.pop();

        for(int i=0;i<G[v].size();i++){
            edge& e = G[v][i];
            if( e.cap > 0 && level[e.to]<0 ){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }

}

ll dfs(int v,int t,int f){
    if( v ==t )return f;

    for(int &i = iter[v];i<G[v].size();i++){
        edge &e = G[v][i];
        if( e.cap>0 && level[e.to]> level[v]){
            ll d = dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }

    return 0;
}

ll max_flow(int s,int t){

    ll flow = 0;
    for(;;){
        bfs(s);
        if( level[t]<0)return flow;
        memset(iter,0,sizeof(iter));

        ll f;
        while((f=dfs(s,t,INF))>0){
            flow+=f;
        }
    }
}


int n,m;ll value[MAXV];
int vis[MAXV];
void dfs2(int v){

    vis[v] = 1;
    for(int i=0;i<G[v].size();i++){
        edge& e = G[v][i];
        if(!vis[e.to] && e.cap>0)dfs2(e.to);
    }

}

int main(){

    #ifdef LOCAL
    freopen("in","r",stdin);
    #endif
    while(cin>>n>>m){
        int s = n ,t = n+1;
        ll sum = 0;
        for(int i=0;i<n;i++){
            cin>>value[i];
            if(value[i]>0){
                add_edge(s,i,value[i]);
                sum+= value[i];
            }else if(value[i]<0){
                add_edge(i,t,-value[i]);
            }

        }
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            add_edge(a-1,b-1,INF);
        }
        ll ret = max_flow(s,t);
        //cout<<ret<<endl;


        memset(vis,0,sizeof(vis));

        dfs2(n);
        int ans =0 ;
        for(int i=0;i<n;i++){
            if(vis[i])ans++;
        }
         cout<<ans<<" "<<sum-ret<<endl;
    }

    return 0;
}
