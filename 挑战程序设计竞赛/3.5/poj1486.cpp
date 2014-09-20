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
int G[MAXV][MAXV];

int n;

struct mat{
    int lx,ly,rx,ry;
};
mat M[MAXV];
struct num{
    int x,y;
};
num N[MAXV];

int match[MAXV],used[MAXV];

bool inbox(int from,int to){
    if( N[from].x> M[to].lx && N[from].y >M[to].ly && N[from].x<M[to].rx && N[from].y<M[to].ry){
        return 1;
    }
    return 0;
}

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
int find(){
    memset(match,-1,sizeof(match));
    int res = 0;
    for(int i=0;i<n;i++){

            memset(used,0,sizeof(used));
            if( dfs(i)){

                res++;
            }

    }
    return res;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    int tst= 0;
    while(cin>>n){
        if(n==0)break;
        cout<<"Heap "<<++tst<<endl;
        memset(G,0,sizeof(G));
        for(int i=0;i<n;i++){
            cin>>M[i].lx>>M[i].rx>>M[i].ly>>M[i].ry;
        }
        for(int i=0;i<n;i++){
            cin>>N[i].x>>N[i].y;
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( inbox(j,i)){
                    G[i][j]= 1;
                }
            }
        }

        int M = find();
        int flag = 0;
        if(M==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(G[i][j]){
                    G[i][j] = 0;
                    int d = find();
                    //cout<<"d"<<d<<endl;
                    if (d<M){
                        flag = 1;
                        cout<<"("<<char(i+'A')<<","<<j+1<<")";
                    }
                    G[i][j] = 1;
                }
            }
        }}
        if(!flag)cout<<"None";
        cout<<endl<<endl;


    }


    return 0;
}

