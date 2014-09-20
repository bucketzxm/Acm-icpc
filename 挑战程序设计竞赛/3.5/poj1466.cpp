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

#define MAXV 5000
struct edge{
    int to,cap,rev;
};
int G[1000][1000];
int n;
int match[MAXV];
bool used[MAXV];

bool dfs(int v){
    for(int i=0;i<n;i++){
        if(G[v][i] && !used[i]){
            used[i] = 1;
            if(match[i]<0 ||dfs(match[i]) ){
                match[i] = v;
                return true;
            }
        }
    }
    return false;

}

int solve(){

    int res = 0;
    memset(match,-1,sizeof(match));

    for(int i=0;i<n;i++){
        memset(used,0,sizeof(used));
        if( dfs(i))res++;
    }
    return res;
}


int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    while(scanf("%d",&n)!=EOF){
        memset(G,0,sizeof(G));
        int from ,to;
        for(int q=0;q<n;q++){
            scanf("%d: (",&from);
            int t;scanf("%d) ",&t);
            for(int i=0;i<t;i++){
                scanf("%d",&to);
                //if(G[to][from])continue;
                G[from][to]=1;
                //cout<<from<<" "<<to<<endl;
                //add_edge(from,to,1);
            }
        }
        int ret = solve();
        cout<<n-ret/2<<endl;

    }
    return 0;
}

