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

    #define MAXV 200


    struct edge{
        int to,cap,cost,rev;
    };
    int V;//不要忘记设置
    vector<edge> G[MAXV];
    int h[MAXV];
    int dist[MAXV];
    int prevv[MAXV],preve[MAXV];

    void add_edge(int from,int to,int cap,int cost){
        G[from].push_back((edge){to,cap,cost,G[to].size()});
        G[to].push_back((edge){from,0,-cost,G[from].size()-1});
    }

    int min_cost_flow(int s,int t,int f){
        int res = 0;
        CLR(h,0);

        while(f>0){
            priority_queue<PII, vector<PII> , greater<PII> > que;
            for(int i=0;i<V;i++) dist[i] = INF;

            dist[s] = 0;

            que.push(MP(0,s));

            while(!que.empty()){
                PII p =que.top(); que.pop();
                int v = p.second;
                if( dist[v] <p.first) continue;

                for(int i=0;i<G[v].size();i++){
                    edge& e = G[v][i];

                    if( e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                        dist[e.to] = dist[v] +e.cost+h[v]-h[e.to];
                        prevv[e.to] =v;
                        preve[e.to] = i;
                        que.push( MP(dist[e.to],e.to));
                    }
                }
            }
            if(dist[t] == INF){
                return -1;
            }
            for(int v=0;v<V;v++)h[v]+=dist[v];

            int d = f;
            for(int v =t;v!=s;v=prevv[v]){
                d = min( d, G[prevv[v]][preve[v]].cap);
            }
            f-=d;
            res+=d*h[t];
            for(int v = t;v!=s;v=prevv[v]){
                edge &e = G[prevv[v]][preve[v]];
                e.cap-=d;
                G[v][e.rev].cap+=d;
            }
        }
        return res;

    }

    int X[MAXV],Y[MAXV],B[MAXV];
    int P[MAXV],Q[MAXV],C[MAXV];
    int give[MAXV][MAXV];

    int main()
    {
        #ifdef LOCAL
            freopen("in","r",stdin);
        #endif

        int N,M;
        while(scanf("%d%d",&N,&M)!=EOF){
            for(int i=0;i<N+M+2;i++){
                G[i].clear();
            }
            int s = N+M ,t = s+1;
            V = t+1;
            int F = 0;
            for(int i=0;i<N;i++){
                scanf("%d%d%d",&X[i],&Y[i],&B[i]);
                F+=B[i];
            }
            for(int i=0;i<M;i++){
                scanf("%d%d%d",&P[i],&Q[i],&C[i]);
            }
            int givecost = 0;
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    scanf("%d",&give[i][j]);
                }
            }
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    int c = abs( X[i]-P[j])+abs(Y[i]-Q[j])+1;
                    add_edge(i,N+j,INF,c);
                    givecost += give[i][j]*c;
                }
            }
            for(int i=0;i<N;i++){
                add_edge(s,i,B[i],0);
            }

            for(int i=0;i<M;i++){
                add_edge(N+i,t,C[i],0);
            }
            int ret = min_cost_flow(s,t,F);
            if(ret < givecost){
                printf("SUBOPTIMAL\n");
                for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        printf("%d",G[N+j][i].cap);
                        if(j==M-1){
                            printf("\n");
                        }
                        else{
                            printf(" ");
                        }
                    }
                }
            }else{
                printf("OPTIMAL\n");
            }
        }
        return 0;
    }


