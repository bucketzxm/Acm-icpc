#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

#define MAXV 501

vector<int> G[MAXV];
int dfn[MAXV],low[MAXV];
int par[MAXV];

int vis[MAXV];

void add_edge(int from,int to){
    G[from].push_back(to);
    G[to].push_back(from);
}
int cnt;

void dfs(int u,int fa){
    vis[u] = 1;
    dfn[u] = low[u] = ++cnt;
    par[u] = fa;
    for(int i=0;i<G[u].size();i++){

        int v = G[u][i];
        if(vis[v] == 2)continue;
        if( vis[v] == 0){
                dfs( v, u);
                low[u] = min(low[u],low[v]);
        }else if(v!=fa && vis[v]==1){
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int N,M;

void input(){
    for(int i=0;i<N;i++){
        G[i].clear();
    }
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        add_edge(a,b);
    }
}

int main(){
    freopen("in","r",stdin);
    while(cin>>N>>M){
        if(N==0 && M==0)break;

        input();
        int flag = 0;int rc = 0;
        for(int i=0;i<N;i++){

            memset(dfn,0,sizeof(dfn));
            memset(low,0,sizeof(low));
            memset(vis,0,sizeof(vis));
            cnt = 0;
            vis[i] =2;
            if( i == 0){
                dfs( 1,1);
            }else {
                dfs( 0, 0);
            }
            flag = 0;
            rc = 0;
            for(int j=0;j<N;j++){

              //  cout<<"j"<<" "<<j<<endl;
                if( j== i)continue;
                //cout<<i<<" "<<j<<" "<<dfn[j]<<" "<<low[j]<<endl;
               // cout<<"pppp"<<par[j]<<endl;
                if(i!=0 &&par[j] == 0 || i==0&&par[j]==1){
                    rc++;
                }
                else if( dfn[par[j]]<=low[j]){
                  //  cout<<".."<<j<<endl;
                    flag = 1;break;
                }
                if( rc-1>=2)break;
            }

            if(flag || rc-1>=2)break;
        }
      //  cout<<rc<<endl;
       // cout<<flag <<" "<<rc<<endl;
        if(flag || rc-1>=2)cout<<"NO"<<endl;
        else  cout<<"YES"<<endl;

    }


    return 0;
}
