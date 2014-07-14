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

#define MAXN 500
int n;
vector<int> G[MAXN];
int parent[MAXN][MAXN];//第一维可以开log
int depth[MAXN];

int MAX_LOG;

void dfs(int v,int p,int d)
{
    parent[0][v] = p;
    depth[v] = d;
    for(int i=0;i<G[v].size();i++)
    {
        if( G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1);
        }
    }
}

void init(int V)
{
    //for parent[0] and depth
    dfs(0,-1,0);
    //for parent

    int cnt = 1;
    MAX_LOG= 0;
    while(cnt<V)
    {
        cnt*=2;
        MAX_LOG++;
    }
    MAX_LOG-=1;
    for(int k=0;k+1<MAX_LOG;k++)
    {
        for(int v=0;v<=V;v++)
        {
            if( parent[k][v] < 0) parent[k+1][v] =-1;
            else
                parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}
int lca(int u,int v)
{
        if( depth[u]>depth[v]) swap(u,v);

        for(int k=0;k<MAX_LOG;k++)
        {
            if( (depth[v]-depth[u])>>k & 1 )
            {
                v = parent[k][v];
            }
        }

        if(u==v)return u;

        for(int k=MAX_LOG;k>=0;k--)
        {
            if( parent[k][u]!=parent[k][v])
            {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
}
void print()
{

    for(int k=0;k<3;k++)
    {
        for(int v = 0;v<=n;v++)
        {
            cout<<parent[k][v]<<" ";

        }
        cout<<endl;
    }
}
int main()
{
	ios::sync_with_stdio(false);

    int T;
    cin>>T;
    int cse = 0;
    while(T--)
    {
        REP(i,MAXN)G[i].clear();
        cin>>n;
        REP(i,n)
        {
            int a,b;
            cin>>a>>b;
            G[a].PB(b);

        }
        cout<<"Case "<<++cse<<":"<<endl;
        init(n);
        int m;
        cin>>m;
        //print();
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            int ans = lca(u,v);
            cout<<ans;
            if(m)
                cout<<" ";
        }
        cout<<endl;

    }
	return 0;
}



