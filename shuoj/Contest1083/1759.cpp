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

int Map[15][15];
int vis[15];

bool ok = 0;


void dfs(int x ,int y,int step)
{
    if( step == 10)
    {
        int cnt = 0;
        for(int i=1;i<=9;i++)
        {
            if(vis[i])cnt++;
        }
        if(cnt==9)ok =1;
       // REP2(i,1,9)cout<<vis[i]<<" ";
       // cout<<endl;
        return;
    }
    if(vis[Map[x][y]] ==1)return;

    vis[Map[x][y]] =1;

    dfs( x+1,y,step+1);

    if(ok)return;

    dfs(x+1,y+1,step+1);
    if(ok)return;
    vis[Map[x][y]]=0;

}
int main()
{
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    int cse = 0;
    while(T--)
    {
        ok=0;
        CLR(Map,0);
        cout<<"Case "<<++cse<<":"<<endl;
        REP2(i,1,9)
        {
            REP2(j,1,i)
            {
                cin>>Map[i][j];
            }
        }

       // bfs();

        dfs(1,1,1);
        CLR(vis,0);
        if(ok)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }


	return 0;
}

