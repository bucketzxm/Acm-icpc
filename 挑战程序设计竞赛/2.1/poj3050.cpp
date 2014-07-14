
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

int G[10][10];
set<int> s;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool inmap(int x,int y)
{
    return x>=0 && x<5 && y>=0 &&y<5;
}
void dfs(int x,int y,int num,int k)
{
    if(k==6 )
    {
        s.insert(num);
        return;
    }

    for(int i=0;i<4;i++)
    {
        int nx =x+dx[i] , ny = y+dy[i];
        if( inmap(nx,ny))
        {
            dfs(nx,ny,num*10+G[nx][ny],k+1);
        }
    }


}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    REP(i,5)
    {
        REP(j,5)
        {
            cin>>G[i][j];
        }
    }
    REP(i,5)
    {
        REP(j,5)
        {
            dfs(i,j,G[i][j],1);
        }
    }
    cout<<s.size()<<endl;

	return 0;
}
