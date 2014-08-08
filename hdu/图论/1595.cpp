/***********************************
	Dijkstra 求单源最短路
	邻接表 + 优先队列 优化
	2014.3.1
***********************************/
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
#define MAXN 2000
vector<PII> Map[MAXN];

//清空邻接表

//求以s为源点的最短路 结果保存在dis中
int dis[MAXN];
int pre[MAXN];
void init() { CLR(pre,-1);REP(i,MAXN) Map[i].clear(); }

void dijkstra(int s,int from,int to,int del)
{
    //cout<<from<<" "<<to<<endl;
	REP(i,MAXN){dis[i]=i==s?0:INF;}
	int vis[MAXN] = {0};
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(MP(0,s));
	pre[0] = 0;
	while(!q.empty())
	{
		PII p = q.top(); q.pop();
		int x = p.second;
		if(vis[x])continue;
		vis[x] = 1;
		for(vector<PII>::iterator it = Map[x].begin(); it != Map[x].end(); it++)
		{
			int y = it->first;
			int d = it->second;
			if(!vis[y] && dis[y] > dis[x] + d )
			{
			    if( x==from && y == to )continue;
			    if( x==to && y == from )continue;
				dis[y] = dis[x] + d;
                if(!del)
                    pre[y] = x;
				q.push(MP(dis[y],y));
			}
		}
	}
}
int N,M;
int main(){
        #ifdef LOCAL
            freopen("in","r",stdin);
        #endif
        while(cin>>N>>M){
            init();
            for(int i=0;i<M;i++){
                int a,b,c;
                cin>>a>>b>>c;
                Map[a-1].PB(MP(b-1,c));
                Map[b-1].PB(MP(a-1,c));
            }

            dijkstra(0,-1,-1,0);
            //cout<<dis[N-1]<<endl;
            int ans = 0;

            for(int i=N-1;pre[i]!=i;i = pre[i]){
                CLR(dis,0);
                dijkstra(0,pre[i],i,1);

                //cout<<dis[N-1]<<endl;
                ans = max(ans,dis[N-1]);
            }
            cout<<ans<<endl;

        }
    return 0;
}
