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

#define MAXN 1005
int T,S,D;
int G[MAXN][MAXN];

int dist[MAXN];
void dj(int s)
{
    REP(i,MAXN)dist[i]=INF;
    dist[s] = 0;
    int vis[MAXN]={0};
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push( MP(0,s) );

    while( !q.empty())
    {
        PII p = q.top();q.pop();
        int x = p.second;
        if( vis[x] )continue;

        vis[x] =1;
        REP(i,MAXN)
        {
            if(G[x][i]!=-1 &&!vis[i]  && dist[i] > dist[x] + G[x][i])
            {
                dist[i] = dist[x]+G[x][i];
                q.push(MP(dist[i],i));
            }
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);

    while(cin>>T>>S>>D)
    {
        CLR(G,-1);
        REP(i,T){
            int a,b,t;
            cin>>a>>b>>t;
            if( G[a][b] ==-1)
            {
                G[a][b]= G[b][a] = t;
            }
            else
            {
                G[a][b] = G[b][a] = min(G[a][b],t);
            }
        }
        int ans = INF;

        int src[MAXN];int psrc;
        int des[MAXN];int pdes;
        psrc = 0; pdes=0;
        REP(i,S)
        {
            cin>>src[psrc++];
        }
        REP(i,D)
        {
            cin>>des[pdes++];
        }
        REP(i,S)
        {
            dj(src[i]);
            //REP(i,11)cout<<i<<" "<<dist[i]<<endl;
            REP(j,D)
            {
                ans = min(ans, dist[des[j]]);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}


