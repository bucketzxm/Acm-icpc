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

#define MAXN 100
int Map[MAXN][MAXN];
int s,t;

int dist[MAXN];
int vis[MAXN];
int n;
void dj(int s)
{
    CLR(vis,0);
    REP2(i,1,n)
    {
        dist[i] = INF;
    }
    dist[s] = 0;
   // vis[s] =1;
    priority_queue<PII,vector<PII> ,greater<PII> >q;

    q.push(MP(0,s));
    while(!q.empty())
    {
        PII p = q.top(); q.pop();
        if (vis[p.second])continue;
        vis[p.second] =1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && Map[p.second][i]>0)
            {
                if( dist[i] >dist[p.second] +Map[p.second][i])
                {
                    dist[i] =dist[p.second]+Map[p.second][i];
                    q.push(MP(dist[i],i));
                }
            }
        }
    }
    cout<<dist[t]<<endl;

}

int main()
{
	ios::sync_with_stdio(false);
    int cse = 0;
    while(cin>>n)
    {
        cout<<"Case "<<++cse<<endl;
        CLR(Map,0);
        REP2(i,1,n)
        {
            REP2(j,1,n)
            {
                cin>>Map[i][j];
            }
        }
        cin>>s>>t;
        dj(s);

    }

	return 0;
}

