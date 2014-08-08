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
struct st
{
    ll x,y;
   // ll delta;
};
st gas[2000];
int n;
ll l;
ll sx,sy,ex,ey;

int vis[2000];
vector<int> G[2000];
int bfs()
{
    queue<int> que;
    queue<int> at;
    que.push(0);
    vis[0] =1;
    at.push(0);
    int flag = -1;
    int step =0;
    while(!que.empty())
    {
        int v = que.front();que.pop();
        step = at.front();at.pop();
        //cout<<v<<" "<<step<<endl;
        if( gas[v].x==ex&&gas[v].y==ey)
        {
            flag = step;break;
        }
        for(int i=0;i<G[v].size();i++)
        {
            if( vis[G[v][i]] == -1)
            {
                vis[G[v][i]]=1;
                que.push(G[v][i]);
                vis[G[v][i]] = 1;
                at.push(step+1);
            }
        }
    }
    if( flag ==-1 )
        return -1;
    else
        return flag-1;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    int T;
    cin>>T;
    while(T--)
    {
        memset(vis,-1,sizeof(vis));

        cin>>n>>l;

        for(int i=0;i<=n+2;i++)G[i].clear();
        cin>>sx>>sy>>ex>>ey;
        gas[0].x=sx ; gas[0].y=sy;
        gas[1].x=ex ;gas[1].y=ey;
        ll d= (sx-ex)*(sx-ex)+(sy-ey)*(sy-ey);
        if( d<=l*l)
        {
            G[0].push_back(1);
            G[1].push_back(0);
        }
        for(int i=2;i<n+2;i++)
        {
            cin>>gas[i].x>>gas[i].y;
            for(int j=0;j<i;j++)
            {
                ll d=  (gas[i].x-gas[j].x)*(gas[i].x-gas[j].x) + (gas[i].y-gas[j].y)*(gas[i].y-gas[j].y);
                if( d<=l*l)
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                    //cout<<i<<" "<<j<<endl;
                }
            }

        }
        //sort(gas,gas+n+2,cmp);
//        for(int i=0;i<n+2;i++)
//            cout<<gas[i].x<<" "<<gas[i].y<<endl;
        int ans = bfs();
        if( ans ==-1)cout<<"impossible"<<endl;
        else
            cout<<ans<<endl;
    }
	return 0;
}

