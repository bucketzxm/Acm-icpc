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
#define MAXV 1000
int girl,boy;
int G[1000][1000];
int match[MAXV];
bool used[MAXV];

bool dfs(int v){
    for(int i=0;i<boy;i++){
        if(G[v][i] && !used[i]){
            used[i] = 1;
            if(match[i]<0 ||dfs( match[i]) ){
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

    for(int i=0;i<girl  ;i++){
        memset(used,0,sizeof(used));
        if( dfs(i))res++;
    }
    return res;
}

int main(){

    int tst= 0;
    freopen("in","r",stdin);
    int n;
    while(cin>>girl>>boy>>n,girl!=0&&boy!=0&&n!=0){
        for(int i=0;i<girl;i++)
            for(int j=0;j<boy;j++)
                G[i][j] = 1;
        for(int i=0;i<n;i++){
            int f,t;
            cin>>f>>t;
            G[f-1][t-1] =0;
        }

        int res = solve();
        cout<<"Case "<<++tst<<": "<<girl+boy-res<<endl;
    }


}
