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

#define MAXV 4000

int N;

VI G[MAXV],rG[MAXV];
int topo[MAXV],used[MAXV];
VI rec;

void dfs(int v){
    used[v] =1;
    for(int i=0;i<G[v].size();i++){
        if(!used[G[v][i]])dfs(G[v][i]);
    }
    rec.PB(v);
}
void rdfs(int v,int k){
    used[v]=1;
    topo[v] =k;
    for(int i=0;i<rG[v].size();i++){
        if(!used[rG[v][i]])rdfs(rG[v][i],k);
    }
}

void add_edge(int from,int to){
    G[from].PB(to);rG[to].PB(from);
}
int scc(){
    CLR(used,0);
    REP(i,N){
        if(!used[i])dfs(i);
    }
    CLR(used,0);
    int k=0;
    for(int i=rec.size()-1;i>=0;i--){
        if(!used[rec[i]])rdfs(rec[i],k++);
    }
    return k;
}
int S[MAXV],T[MAXV],D[MAXV];


void init(){
    for(int i=0;i<N;i++){
        G[i].clear();rG[i].clear();

    }
}

int main()
{
	//ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(scanf("%d",&N)!=EOF){
        init();
        for(int i=0;i<N;i++){
            int ha,hb,ma,mb,d;
            scanf("%d:%d %d:%d %d",&ha,&ma,&hb,&mb,&d);
            S[i]=ha*60+ma;T[i]=hb*60+mb;D[i]=d;
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<i;j++){
                //不能都在ｓ开始
                if( min(S[i]+D[i],S[j]+D[j]) > max( S[i],S[j])){
                    add_edge(i,j+N);
                    add_edge(j,i+N);
                }
                //开始结束
                if(min(S[i]+D[i],T[j])>max(S[i],T[j]-D[j])){
                    add_edge(i,j);
                    add_edge(j+N,i+N);
                }
                //结束开始
                if(min( T[i],S[j]+D[j] )>max(T[i]-D[i],S[j])){
                    add_edge(i+N,j+N);
                    add_edge(j,i);
                }
                //结束结束
                if(min(T[i],T[j])> max(T[i]-D[i],T[j]-D[j])){
                    add_edge(i+N,j);
                    add_edge(j+N,i);
                }
            }

        }
        int k = scc();

        for(int i=0;i<N;i++){
            if(topo[i]==topo[i+N]){
                printf("NO\n");
                return 0;
            }
        }
        printf("YES\n");
        for(int i=0;i<N;i++){
            if(topo[i] > topo[N+i]){
                printf("%02d:%02d %02d:%02d\n",S[i]/60,S[i]%60,(S[i]+D[i])/60,(S[i]+D[i])%60);
            }
            else{
                printf("%02d:%02d %02d:%02d\n",(T[i]-D[i])/60,(T[i]-D[i])%60,T[i]/60,T[i]%60);
            }
        }

    }
	return 0;
}

