
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

int n,ans;
char Map[600][600];
bool vis[600][600];
int sx,sy,ex,ey;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};
//  0
//3   1
//  2
const int rdx[] = {-1,0,1,0};
const int rdy[] = {0,1,0,-1};

class st
{
public:
    st(){};
    st(int _x,int _y,int _time):x(_x), y(_y), time(_time){}
    ~st(){};
    int x,y;
    int time;

};
int dir(char D)
{
    if( D == 'N'){
        return 0;
    }
    if( D=='S')
    {
        return 2;
    }
    if( D=='W')
    {
        return 3;
    }
    if(D=='E')
    {
        return 1;
    }
    if(D=='T')
    {
        return -2;
    }
    return -1;
}



int camera(int x,int y,int nx,int ny,int time){
    int ret = 1;
    int tmp = dir(Map[nx][ny]);
    int tmp2 = dir(Map[x][y]);
    if(tmp>=0 || tmp2>=0)
    {
        ret  = 3;
    }
    for(int i=0;i<4;i++){
        int tx = x +dx[i] ,ty = y+dy[i];
        int D = dir(Map[tx][ty]);
        if(D == -1 ||D == -2)continue;
        D = (D + time)%4;
        if( tx+rdx[D]==x && ty+rdy[D]==y ){
            ret = 3;
            break;
        }
    }
    for(int i=0;i<4;i++){
        int tx = nx +dx[i] ,ty = ny+dy[i];
        int D = dir(Map[tx][ty]);
        if(D == -1 ||D ==-2)continue;

        D = (D + time)%4;
        if(tx +rdx[D] == nx && ty + rdy[D] == ny){
            ret = 3;
            break;
        }
    }

    return ret;
}

bool can_go(int x,int y){
    if( x>=0 && x<n && y>=0 && y<n)
    {
        if( Map[x][y] != '#'){
            return true;
        }
        return false;
    }
    return false;
}



void bfs(){

    memset(vis,-1,sizeof(vis));
    queue<st> q;

    q.push(st(sx,sy,0));
    while(!q.empty())
    {
        if(q.size()>100000)break;
        st now = q.front();
        q.pop();
        if( now.x == ex &&now.y == ey){
            ans = min(ans, now.time);
            continue;
        }
        if(now.time >=ans ||  abs( ex - now.x)+abs(ey-now.y)+now.time>=ans)
        {
            continue;
        }
        vis[now.x][now.y ] =1;
        for(int i=0;i<4;i++){
            int nx = now.x+dx[i], ny = now.y+dy[i];
            if( can_go(nx,ny) )
            {
                int t = camera(now.x,now.y,nx,ny,now.time);
                q.push( st(nx,ny,now.time+t) );
                q.push( st(now.x,now.y,now.time+1));
                //cout<<now.x<<" "<<now.y<<" "<<nx<<" "<<ny<<" "<<now.time<<" "<<t<<endl;
                if( t==3){
                    vis[now.x][now.y]= 0;
                    for(int i=0;i<4;i++){
                        vis[now.x+dx[i]] [now.y+dy[i]] =0;
                    }
                  //  cout<<"..."<<now.x<<" "<<now.y<<" "<<now.time+1<<endl;
                    q.push( st(now.x,now.y,now.time+1));
                }
            }
        }
    }
    if( ans == INF){
        ans = -1;
    }
    return ;
}
int main()
{
	//ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    int t;
    int cse = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",++cse);
        ans = INF;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++){
            scanf("%s\n",Map[i]);
            for(int j=0;j<n;j++){
                if( Map[i][j] == 'M'){
                    sx = i ; sy = j;
                }
                if( Map[i][j] == 'T')
                {
                    ex = i; ey = j;
                }
            }
        }
        bfs();
        printf("%d\n",ans);
    }
	return 0;
}
