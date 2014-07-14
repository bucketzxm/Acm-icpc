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

char Map[200][200];

int n,m;
int vis[200][200];
bool inmap(int x,int y)
{
    return x>=0 && x<n && y>=0 &&y<m;
}

int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};
void dfs(int x,int y)
{
    if( vis[x][y])return;
    vis[x][y] =1;

    REP(i,8)
    {
        REP(j,8)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if( inmap(nx,ny) && !vis[nx][ny] && Map[nx][ny] == 'W')
            {
                dfs( nx,ny);
            }
        }
    }

}

int main()
{
	ios::sync_with_stdio(false);
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif


	while(cin>>n>>m)
	{
	    int ans = 0;
        REP(i,n)
        {
           cin>>Map[i];
        }

	    REP(i,n)
	    {
	        REP(j,m)
	        {
	            if(!vis[i][j] && Map[i][j] =='W')
	            {
	                dfs(i,j);
                    ans++;
	            }
	        }
	    }

        cout<<ans<<endl;
	}

	return 0;
}
