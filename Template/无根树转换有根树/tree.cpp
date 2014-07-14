#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000;
vector<int> G[MAXN];
int p[MAXN];
void readin()
{
    int u,v;
    int n;
    cin>>n;         //树有n个点，n-1条边，无自环
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}


void dfs(int u,int fa)
{
    int d = G[u].size();

    for(int i=0;i<d;i++)
    {
        int v = G[u][i];
        if( v != fa)
        {
            dfs( v, p[v] = u);
        }
    }

}

int main()
{

    readin();

    int root ;
    cin>>root;
    p[root] = -1;

    dfs(root,-1);


}

