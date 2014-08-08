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

#define MAXV 3000*5
int N,M;

int key1[MAXV],key2[MAXV];
int door1[MAXV],door2[MAXV];

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
    for(int i=0;i<4*N;i++){//fuck 这里查了好久是４＊Ｎ
        if(!used[i]){dfs(i);}
    }
    CLR(used,0);
    int k=0;
    for(int i=rec.size()-1;i>=0;i--){
        if(!used[rec[i]])rdfs(rec[i],k++);
    }
    return k;
}

void input(){
    for(int i=0;i<N;i++){
       scanf("%d%d",&key1[i],&key2[i]);
    }
    for(int i=0;i<M;i++){
        scanf("%d%d",&door1[i],&door2[i]);
    }
}

bool C(int x){
     for(int i=0;i<4*N;i++){
        G[i].clear();
        rG[i].clear();
    }
    rec.clear();
    CLR(topo,0);
    for(int i=0;i<N;i++){
        add_edge(key1[i],key2[i]+2*N);
        add_edge(key2[i],key1[i]+2*N);
    }
    for(int i=0;i<x;i++){
        add_edge( door1[i]+2*N,door2[i]);
        add_edge( door2[i]+2*N,door1[i]);
    }

    int d = scc();
    for(int i=0;i<2*N;i++){
        if( topo[i] == topo[i+2*N]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    //ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(scanf("%d%d",&N,&M)!=EOF){
        if(N==0 && M==0)break;

        input();
        int l = 0, r= M;
        int mid = 0,ans=0;
        while( l<=r){
            mid = (l+r)>>1;
            //cout<<mid<<endl;
            if( C(mid)){
                l = mid+1;
                ans = mid;
              //  cout<<"ok"<<endl;
            }else{
                r = mid-1;
            }
        }
        printf("%d\n",ans);
    }



    return 0;
}
