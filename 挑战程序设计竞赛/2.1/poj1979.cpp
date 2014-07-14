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
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;


char Map[30][30];
int sx,sy;
int n,m;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
bool inmap(int x,int y)
{
    return x>=0 && x<m && y>=0 &&y<n;
}

void bfs()
{
    int vis[30][30] ={0};
    queue<PII> q;
    q.push(MP(sx,sy));
    vis[sx][sy] =1;
   // cout<<sx<<" "<<sy<<endl;
    int ret = 0;
    while(!q.empty())
    {
        PII d = q.front(); q.pop();
        //cout<<"now"<<d.X<<" "<<d.Y<<endl;
        ret++;
        REP(i,4)
        {
                int nx = d.X+dx[i], ny = d.Y+dy[i];
                //cout<<nx<<" "<<ny<<endl;
                if(inmap(nx,ny) &&!vis[nx][ny] && Map[nx][ny] =='.')
                {
                    q.push(MP(nx,ny));
                    vis[nx][ny]=1;
                }
        }
    }
    cout<<ret<<endl;

}
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("in","r",stdin);
    #endif

    while(cin>>n>>m,n!=0&&m!=0)
    {
        //cout<<n<<" "<<m<<endl;
        cin.ignore();
        REP(i,m)
        {
            cin>>Map[i];
            //cout<<Map[i]<<endl;
            REP(j,n)
            {
                if( Map[i][j] == '@'){Map[i][j] == '.';sx= i; sy =j;}
            }
        }
        bfs();
    }

	return 0;
}

