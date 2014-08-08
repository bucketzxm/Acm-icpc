#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAXV 500
#define INF 0x3fffffff

#define CLR(A,X) memset(A,X,sizeof(A))
int K,C,M;
int N;
int Map[500][500];

void floyd(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                Map[i][j] = min( Map[i][j], Map[i][k]+Map[k][j]);
            }
        }
    }
}
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
        while( (f= dfs(s,t,INF))>0){
            flow +=f;
        }
    }
}

int s,t;
bool jd(int x){
    for(int i=0;i<N+2;i++){
        G[i].clear();
    }

    for(int i=0;i<K;i++)add_edge(i,t,M);
    for(int i=0;i<C;i++)add_edge(s,K+i,1);

    for(int i=K;i<K+C;i++){
        for(int j=0;j<K;j++){
            if( Map[i][j] <=x){
                add_edge(i,j,1);
            }
        }
    }
    int ret = max_flow(s,t);
    if( ret >= C)return 1;
    return 0;

}

int main(){
   #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    while(cin>>K>>C>>M){
       N = K+C;
        s = N,t = s+1;
       for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>Map[i][j];
                if(Map[i][j]==0)Map[i][j]=INF;
            }
       }
       floyd();
       int l=0,r=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(Map[i][j]!=INF)
                    r = max(r ,Map[i][j]);
            }
        }
        int ans = 0;
        while(l<=r){
            int mid = (l+r)>>1;

            if(jd(mid)){
                r = mid-1;
                ans = mid;
            }else {
                l = mid+1;
            }
        }
        cout<<ans<<endl;

    }
    return 0 ;
}
