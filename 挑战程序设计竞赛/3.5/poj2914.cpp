#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAXV 1000

vector<int> G[MAXV];
int dfn[MAXV], low[MAXV],vis[MAXV];
int cnt = 0;
void dfs(int u){

    vis[u] =1;
    dfn[u] = low[u] = cnt++;

    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];


    }

}

int main(){

    return 0;
}
