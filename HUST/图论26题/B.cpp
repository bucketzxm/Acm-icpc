
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

int N,M,T;
char Map[10][10];
int sx,sy,ex,ey;
int vis[10][10];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 0;

bool inmap(int a,int b)
{
    if( a>=0 && a< N && b>=0&&b<M && Map[a][b] !='X')
        return true;
    else
        return false;
}

int dfs(int nx,int ny,int t)
{
    //cout<<nx<<" "<<ny<<" "<<Map[nx][ny] <<" "<<t<<endl;
    vis[nx][ny] = 1;
    if(ans || nx==ex && ny == ey &&t == 0)
    {
        ans = 1;
        return 1;
    }
    if( abs( abs(nx-ex)+ abs(ny-ey)+t)%2 == 1 )
    {
        return 0;
    }

    if( abs( nx-ex)+abs(ny-ey) >t)
    {
        return 0;
    }
    for(int i=0;i<4;i++)
    {
        int ax = nx+dx[i],ay = ny+dy[i];

        if( inmap(ax,ay) && !vis[ax][ay])
        {
            dfs( ax,ay ,t-1);
            vis[ax][ay ] =0;
        }
    }
}


int main()
{
	ios::sync_with_stdio(false);

    while(cin>>N>>M>>T)
    {
        if( N==0)break;
        ans = 0;
        CLR(Map,0);
        CLR(vis,0);
        REP(i,N)
        {
            cin>>Map[i];
            REP(j,M)
            {
                if( Map[i][j] == 'S')
                {
                    sx = i ; sy = j;
                }
                if( Map[i][j] == 'D')
                {
                    ex = i ; ey = j;
                }
            }
        }
        dfs( sx,sy,T);

        if( ans == 1)cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
	return 0;
}
