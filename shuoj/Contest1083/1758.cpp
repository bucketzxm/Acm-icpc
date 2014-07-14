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

int n;

#define MAXN 200001

int pa[MAXN+10]; // parent
int ra[MAXN+10]; // rank
int node[MAXN+10];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        node[i]=1;
    }
	for(int i = 0; i <= n; i++)
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

int unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return 0;
	if(ra[x] < ra[y])
	{
		pa[x] = y;
		node[y]+=node[x];
	}else{
		pa[y] = x;
		node[x]+=node[y];
		if(ra[x] == ra[y]) ra[x]++;
	}
	return 1;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	ios::sync_with_stdio(false);

    while(cin>>n)
    {

map<int,int> rel;
        int k=0;
        init(MAXN);
        int ans = 0;
        REP(i,n)
        {
            int a,b;
            cin>>a>>b;
            if(rel.count(a)==0)
            {
                rel[a] = k++;
            }
            if(rel.count(b)==0)
            {
                rel[b] = k++;
            }
            unite(rel[a],rel[b]);

            ans = max(ans, node[find(rel[a])]);
            ans = max(ans, node[find(rel[b])]);
        }
        cout<<ans<<endl;
    }

	return 0;
}

