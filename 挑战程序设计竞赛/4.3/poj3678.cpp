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

#define MAXV 10000

int N,M;
VI G[MAXV],rG[MAXV];
VI rec;
int topo[MAXV],used[MAXV];

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

    while(cin>>N>>M){
        for(int i=0;i<N;i++){
            G[i].clear(); rG[i].clear();
        }
        rec.clear();
        for(int i=0;i<M;i++){
            int a,b,c;string str;
            cin>>a>>b>>c>>str;
            if( str == "AND"){
                if( c==1){
                    add_edge(a+N,a);
                    add_edge(b+N,b);
                    add_edge(a,b);
                    add_edge(b,a);
                }else{
                    add_edge(a,b+N);
                    add_edge(b,a+N);
                }
            }else if(str=="OR"){
                if(c==1){
                    add_edge(a+N,b);
                    add_edge(b+N,a);
                }else{
                    add_edge(a,a+N);
                    add_edge(b,b+N);
                    add_edge(a+N,b+N);
                    add_edge(b+N,a+N);
                }
            }else if(str=="XOR"){
                if(c==1){
                    add_edge(a+N,b);
                    add_edge(a,b+N);
                    add_edge(b,a+N);
                    add_edge(b+N,a);
                }else{
                    add_edge(a,b);
                    add_edge(b,a);
                    add_edge(a+N,b+N);
                    add_edge(b+N,a+N);
                }
            }
        }
        N*=2;
        int d = scc();
        N/=2;
        int flag = 0;
        for(int i=0;i<N;i++){
            if( topo[i]==topo[i+N]){
                cout<<"NO"<<endl;
                flag = 1;
                break;
            }
        }
        if(!flag)
            cout<<"YES"<<endl;
        CLR(topo,0);
    }

    return 0;
}


