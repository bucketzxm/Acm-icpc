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

#define MAXN 1000
int lson[MAXN],rson[MAXN];

char ans[MAXN][MAXN];
int a[MAXN];
void dfs(int u, char *c,int pc)
{

    if( lson[u] == -1)
    {
        c[pc] = '\0';
        for(int i=0;i<pc;i++)
            strcpy(ans[u], c);
        return;
    }
    c[pc] = '0';
    dfs( lson[u],c,pc+1 );
    c[pc] = '1';
    dfs( rson[u], c,pc+1);
}

void swp(int i,int j)
{
    char t[MAXN];
    strcpy(t,ans[i]);
    strcpy(ans[i],ans[j]);
    strcpy(ans[j],t);
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	int cse  = 0;
	while(T--)
    {
        cout<<"Case "<<++cse<<endl;
        priority_queue< PII,vector<PII> , greater<PII> > q;
        int n;
        int id =0;
        cin>>n;
        CLR(lson,-1);CLR(rson,-1);
        REP(i,n)
        {
            cin>>a[i];
            q.push(MP(a[i],INF-id));
            id++;
        }
        while(q.size()!=1)
        {
            PII f ,s;
            f = q.top(); q.pop();
            s = q.top(); q.pop();


            lson[id] = INF- s.second; rson[id] =INF- f.second;


            q.push(MP(f.first+s.first,INF-id));
            id++;
        }

        char c[MAXN]={0};
        dfs(id-1,c,0);






        REP(i,n)
        {
            cout<<a[i]<<" "<<ans[i]<<endl;
        }
        if(T)
            cout<<endl;

        CLR(ans,0);
    }

	return 0;
}

