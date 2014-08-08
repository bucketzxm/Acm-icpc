
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

#define MAXV 105
int N,M;

VI G[MAXV],rG[MAXV];
VI rec;
int ans;
int topo[MAXV],used[MAXV];
int in[MAXV],out[MAXV];
bool S[MAXV][MAXV];
int dfs(int v){
    used[v] =1;
    for(int i=0;i<G[v].size();i++){
        if(!used[G[v][i]] ){dfs(G[v][i]);}
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
        if(!used[i]){dfs(i);}
    }
    CLR(used,0);
    int k=0;
    for(int i=rec.size()-1;i>=0;i--){
        if(!used[rec[i]])rdfs(rec[i],k++);
    }
    return k;
}



int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(cin>>N){
        for(int i=0;i<N;i++){
            G[i].clear();rG[i].clear();
        }
        rec.clear();

        ans = 0;
        for(int i=0;i<N;i++){
            int t;
            cin>>t;
            while(t!=0){
                add_edge(i,t-1);
                cin>>t;
            }
        }
        int d = scc();

        if(d==1){
            cout<<1<<endl;
            cout<<0<<endl;
            continue;
        }

        CLR(S,0);
        for(int i=0;i<N;i++){
            int v = topo[i];
            for(int j=0;j<G[i].size();j++){
                if( topo[G[i][j]] != v){
                    S[v][ topo[G[i][j]]] =1;
                }
            }
        }

        CLR(in,0);
        CLR(out,0);
        for(int i=0;i<d;i++){
            int cnt = 0;
            for(int j=0;j<d;j++)
            {
                if(S[i][j]){
                    out[i]++;
                    in[j]++;
                }
            }
        }
        int m_in=0,m_out=0;
        for(int i=0;i<d;i++){
        //    cout<<in[i]<<' ';
            if(in[i]==0)m_in++;
            if(out[i]==0)m_out++;
        }
      //  cout<<endl;
        cout<<m_in<<endl;
        cout<<max(m_in,m_out)<<endl;
    }
    return 0;
}
