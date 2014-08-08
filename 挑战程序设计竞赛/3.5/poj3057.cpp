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

#define MAXV 50000
#define MAXX 15
#define MAXY 15
vector<int> G[MAXV];
int X,Y;
char Map[MAXX][MAXY];
bool used[MAXV];
int match[MAXV];


void add_edge(int from,int to){
    G[from].push_back(to);
    G[to].push_back(from);
}

bool dfs(int v){

    used[v] = true;
    for(int i=0;i<G[v].size();i++){
        int u = G[v][i] , w = match[u];
        if( w <0 || !used[w]&&dfs(w)){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;

}

int dist[MAXX][MAXY][MAXX][MAXY];//距离
VI dX,dY,pX,pY;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

bool inmap(int a,int b){
    return a>=0&& a<X &&b>=0 &&b<Y;
}

void bfs2(int x,int y,int d[MAXX][MAXY]){
    queue<int> qx;
    queue<int> qy;
    d[x][y] = 0;
    qx.push(x);qy.push(y);
    while(!qx.empty()){
        int nx = qx.front();qx.pop();
        int ny = qy.front();qy.pop();

        for(int i=0;i<4;i++){
            int ax = nx+dx[i],ay = ny+dy[i];

            if( inmap(ax,ay) && Map[ax][ay]=='.' && (d[ax][ay]<0 || d[ax][ay]>d[nx][ny]+1)){
                d[ax][ay] = d[nx][ny]+1;
                qx.push(ax);qy.push(ay);
            }
        }
    }

}

void solve(){
    int N = X*Y;

    dX.clear();dY.clear();pX.clear();pY.clear();
    for(int i=0;i<MAXV;i++){
        G[i].clear();
    }
    CLR(dist,-1);

    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            if( Map[i][j]=='D'){
                dX.PB(i);dY.PB(j);
                bfs2(i,j,dist[i][j]);
            }else if(Map[i][j]=='.'){
                pX.PB(i);pY.PB(j);
            }
        }
    }

    int d = dX.size() , p = pX.size();

    for(int i=0;i<d;i++){
        for(int j=0;j<p;j++){
            //cout<<" i : "<<i<< " j: "<<j<<endl;
            int dis = dist[dX[i]][dY[i]][pX[j]][pY[j]];
            if( dis>0){
                //0~d-1 t1
                //
                for(int m=dis;m<=N;m++){
                    int from = (m-1)*d+i,to = N*d+j;
                    //G[from].PB(to);G[to].PB(from);
                    add_edge(from ,to);
                   // cout<<from<<" "<<to<<endl;
                   // cout<<dis<<" xxx"  <<N<<endl;
                }
               // cout<<"xxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
            }
        }
    }
    //cout<<"okokokokokoko"<<endl;

    if( p == 0){
        cout<<0<<endl;
        return;
    }

    int num = 0;
    CLR(match,-1);
    for(int v=0;v<N*d;v++){
        CLR(used,0);
        if(dfs(v)){
            if( ++num==p){
                cout<<v/d+1<<endl;
                return;
            }
        }
    }
    cout<<"impossible"<<endl;

}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    int T;cin>>T;
    while(T--){
        CLR(Map,0);
        cin>>X>>Y;
        REP(i,X){
            cin>>Map[i];
        }
        solve();
    }

    return 0;
}
