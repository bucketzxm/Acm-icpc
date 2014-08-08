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

#define MAXV 100010
int N,M;

VI G[MAXV],rG[MAXV];
VI rec;
int topo[MAXV],used[MAXV];

int dfs(int v){
    used[v] =1;
    for(int i=0;i<G[v].size();i++){
        if(!used[G[v][i]] )dfs(G[v][i]);
    }
    rec.PB(v);
    return 0;
}
int rdfs(int v, int k){
    used[v] =1;
    topo[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(!used[rG[v][i]])rdfs(rG[v][i],k);
    }
    return 0;
}
void add_edge(int from,int to){
    G[from].PB(to);rG[to].PB(from);
}

int scc(){
    CLR(used,0);
    for(int i=0;i<N;i++){
        if(!used[i])dfs(i);
    }
    CLR(used,0);
    int k=0;
    for(int i=rec.size()-1;i>=0;i--){
        if(!used[rec[i]])rdfs(rec[i],k++);
    }
    return k;
}

int sta[MAXV];
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(cin>>N>>M){
        CLR(sta,0);
        rec.clear();
        for(int i=0;i<N;i++)
        {
            G[i].clear();rG[i].clear();
        }
        for(int i=0;i<M;i++){
            int a,b;
            cin>>a>>b;
            add_edge(a-1,b-1);
        }
        int k = scc();
        int ans = 0;
        for(int i=0;i<N;i++){
            sta[ topo[i] ] ++;
        }

        for(int i=0;i<=k;i++){
           if(sta[i]>1){
                ans++;
           }
        }
        cout<<ans<<endl;

    }


	return 0;
}

