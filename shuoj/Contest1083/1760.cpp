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

int num[40];
int vis[40];
void  dfs(int u)
{
    if( vis[u])return;
    vis[u]=1;
    dfs( num[u]);
    return ;
}
int main()
{
	ios::sync_with_stdio(false);

    int n;
    while(cin>>n)
    {
        CLR(vis,0);
        REP2(i,1,n)
        {
            cin>>num[i];
        }
        int ans =0;


            for(int j=1;j<=n;j++)
            for(int i=1;i<=n;i++)
            {
                if(!vis[i])
                {
                    dfs(i);
                    ans++;
                }
            }

        cout<<ans<<endl;
    }
	return 0;
}

