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
int N,A,B;
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
    for(int i=0;i<2*N;i++){
        if(!used[i]){dfs(i);}
    }
    CLR(used,0);
    int k=0;
    for(int i=rec.size()-1;i>=0;i--){
        if(!used[rec[i]])rdfs(rec[i],k++);
    }
    return k;
}

int sx1,sx2,sy1,sy2;
int x[MAXV],y[MAXV];
int hate[MAXV][2],like[MAXV][2];
int d1[MAXV] , d2[MAXV],D;

int dist(int a ,int b){
    return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
void build(int x){

    for(int i=0;i<2*N;i++){
        G[i].clear();
        rG[i].clear();
    }
    rec.clear();

    for(int i=0;i<A;i++){
        int u = hate[i][0],v = hate[i][1];

        add_edge(u,v+N);
        add_edge(u+N,v);
        add_edge(v,u+N);
        add_edge(v+N,u);
    }

    for(int i=0;i<B;i++){
        int u = like[i][0],v = like[i][1];

        add_edge(u,v);
        add_edge(v,u);
        add_edge(v+N,u+N);
        add_edge(u+N,v+N);
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if( d1[i]+d1[j]>x){
                add_edge(i,j+N);
                add_edge(j,i+N);
            }

            if( d2[i]+d2[j]>x){
                add_edge(i+N,j);
                add_edge(j+N,i);
            }
            if(d1[i]+d2[j]+D>x){
                add_edge(i,j);
                add_edge(j+N,i+N);
            }
            if(d2[i]+d1[j]+D>x){
                add_edge(j,i);
                add_edge(i+N,j+N);
            }
        }
    }
}

bool C(int x){
    build(x);
    int d = scc();

    for(int i=0;i<N;i++){
        if( topo[i]==topo[i+N]){
            return 0;
        }
    }
    return 1;
}


int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    while(cin>>N>>A>>B){
        cin>>x[2*N+1]>>y[2*N+1]>>x[2*N+2]>>y[2*N+2];
        for(int i=0;i<N;i++){
            cin>>x[i]>>y[i];
            d1[i] = dist(i,2*N+1);
            d2[i] = dist(i,2*N+2);
        }
        D = dist(2*N+1,2*N+2);
        for(int i=0;i<A;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            hate[i][0] = a; hate[i][1]=b;
        }
        for(int i=0;i<B;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            like[i][0]=a; like[i][1]=b;
        }
        int ans = -1,mid = 0;

        int l = 0, r = 4000000;

        while( l <=r ){
            mid = (l+r)>>1;

            if( C( mid)){
                r = mid-1;
                ans = mid;
            }else{
                l = mid+1;
            }
        }
        cout<<ans<<endl;



    }
    return 0;
}
