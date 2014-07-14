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

#define MAXN 105
int N,M;
vector<PII> G[MAXN];

void init(){ REP(i,MAXN) G[i].clear();}
int vis[105];
int dist[105];
void dj(int s)
{
    CLR(vis,0);
    REP(i,105)dist[i] = INF;
    dist[s] = 0;

    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push(MP(0,s));
    while(!q.empty())
    {
        PII p = q.top();q.pop();
        int x = p.second;
        if( vis[x] )continue;
        vis[x] =1;
        for(vector<PII>::iterator it = G[x].begin();it!=G[x].end();it++)
        {
            int y = it->second;
            int d = it->first;
            if(!vis[y] && dist[y] > dist[x]+d)
            {
                dist[y] = dist[x] +d;
                q.push(MP(dist[y],y));
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
    while(cin>>N>>M)
    {
        if(N==0 && M==0)break;
        init();
        REP(i,M)
        {
            int x,y,t;
            cin>>x>>y>>t;

            G[x].push_back(MP(t,y));
            G[y].push_back(MP(t,x));
        }
        dj(1);
        cout<<dist[N]<<endl;
    }
	return 0;
}


