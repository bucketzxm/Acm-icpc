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

int n,m;
char Map[205][205];
vector<PII> F;
int ex,ey;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int vis[205][205];
int ans = INF;
bool inmap(int x,int y)
{

    if( x>=0 && x<n && y>=0 &&y<m )
        return true;
    else
        return false;
}

void dj(int u)
{
    int dist[50000] ;
    REP(i,50000)
        dist[i] = INF;
    int vis[50000] = {0};
    //int sx =1 ,sy=6;
    int sx = F[u].first,sy = F[u].second;
    dist[sx*m+sy] = 0;
    priority_queue<PII, vector<PII> , greater<PII> >q;

    q.push(MP(0,sx*m+sy));
    while(!q.empty())
    {
        PII p = q.top();q.pop();
        int x = p.second/m, y = p.second%m;
        int step  = p.first;
  //      cout<<"loop "<<x<<" "<<y<<" "<<step<<" "<<Map[x][y]<<endl;
        if( vis[x*m+y])
        {
            continue;
        }
        vis[x*m+y]=1;
        REP(i,4)
        {
            int nx = x+dx[i],ny= y+dy[i];
            if(inmap(nx,ny) &&!vis[nx*m+ny] && Map[nx][ny] !='#' )
            {
                if( Map[nx][ny] == 'x' &&dist[nx*m+ny]>dist[x*m+y]+2)
                {

                    dist[nx*m+ny]=dist[x*m+y]+2;
                    q.push(MP(step+2,nx*m+ny));
                }
                if( Map[nx][ny] == '.' && dist[nx*m+ny]>dist[x*m+y]+1)
                {
                    dist[nx*m+ny]=dist[x*m+y]+1;
                    q.push(MP(step+1,nx*m+ny));
                }
            }
        }
    }
    ans = min(ans, dist[ex*m+ey]);
//    cout<<"ok"<<sx<<" "<<sy<<endl;
//
//    REP(i,n)
//    {
//        REP(j,m)
//        {
//            cout<<i<<" "<<j<<" "<<dist[i*m+j]<<endl;
//        }
//    }
}




int main()
{
	ios::sync_with_stdio(false);

    while(cin>>n>>m)
    {
        CLR(Map,0);
        F.clear();
        REP(i,n)
        {
            cin>>Map[i];
            REP(j,m)
            {
                if( Map[i][j] == 'r')
                {
                    F.PB(MP(i,j));
                    Map[i][j] = '.';
                }
                if( Map[i][j] == 'a')
                {
                    ex= i ; ey = j;
                    Map[i][j] = '.';
                }
            }
        }
        for(int i=0;i<F.size();i++)
        {
            dj(i);
        }
        if(ans==INF)
        {
            cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        }
        else
            cout<<ans<<endl;
        ans = INF;
    }
	return 0;
}
