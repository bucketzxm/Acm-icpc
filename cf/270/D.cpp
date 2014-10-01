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
#define MAXN 3000

ll mat[2005][2005];
ll testmat[2005][2005];
ll n;

class E{
public:
    E(int from,int to,int w):from(from),to(to),w(w){}
    int from,to,w;
};
struct cmp{
    bool operator () (const E& A,const E& B) const
    {
        return A.w < B.w;
    }
};
priority_queue< E , vector<E> ,cmp> que;


//============================
// union-find
int pa[MAXN]; // parent
int ra[MAXN]; // rank

void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		pa[i] = i;
		ra[i] = 0;
	}
}

int find(int x)
{
	if(pa[x]!=x) pa[x] = find(pa[x]);
	return pa[x];
}

// 0: already united;  1: successfully united;
int unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return 0;
	if(ra[x] < ra[y])
	{
		pa[x] = y;
	}else{
		pa[y] = x;
		if(ra[x] == ra[y]) ra[x]++;
	}
	return 1;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}
//============================

struct Edge{
	int u, v;
	int l;
	Edge(){};
	Edge(int _u, int _v, int len):u(_u),v(_v),l(len){}
	bool operator<(const Edge &e) const
	{
		return this->l > e.l;
	}
}edge[MAXN*MAXN];

vector<Edge> test[MAXN*2];

int e;

void addEdge(int u, int v, int len)
{
	edge[e++] = Edge(u, v, len);
}

int flag = 0;


int vis[2000];
void dfs(int u,int v,int d){
    vis[u] =vis[v] = 1;
   //; cout<<u<<" "<<v<<" "<<d<<endl;
    int len = test[v].size();
    for(int i=0;i<len;i++){
        int w = test[v][i].v;
        if(!vis[w]){
            testmat[u][w] = testmat[w][u] = d+test[v][i].l;
            dfs(u,w,testmat[u][w]);
        }
    }
}
bool check()
{

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            //cout<<testmat[i][j]<<" ";
            if( testmat[i][j] != mat[i][j]){
                return false;
            }

        }
      //  cout<<endl;
    }
    return true;

}


void solve(){
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        dfs(i,i,0);
    }

    if( check() )
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}

int Kruskal(int n)
{
	init(n);
	priority_queue<Edge> q;
	for(int i = 0; i < e; i++)
		q.push(edge[i]);
	int ans = 0;
	int u,v;
	for(int i = 0; i < n-1; i++)
	{
		Edge e = q.top();
		while(same(e.u, e.v) && !q.empty())
		{
			q.pop();
			e = q.top();
		}
		unite(e.u,e.v);

		test[e.u].push_back( Edge(e.u,e.v,e.l) );
		test[e.v].push_back( Edge(e.v,e.u,e.l) );
		ans += e.l;
	}

    solve();
	return ans;
}



int main()
{
	//ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif


    scanf("%I64d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%I64d",&mat[i][j]);
            //cout<<mat[i][j]<<endl;
            if( mat[i][j] != 0 ){
                addEdge(i,j,mat[i][j]);
                //que.push( E(i,j,mat[i][j]));
            }
        }
    }

    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
        if(i==j && mat[i][j]!=0){
            cout<<"NO"<<endl;
            return 0;
        }
        else if(i!=j &&mat[i][j] == 0){
            cout<<"NO"<<endl;
            return 0;
        }
       }
    }



    Kruskal(n);


	return 0;
}


