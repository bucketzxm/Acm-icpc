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

vector<int> Map[MAXN];

int big=0;
void dfs(int u,int n)
{

    if( n>big)
    {
       // cout<<u<<" "<<n<<endl;
        big= n;
    }
    for(int i=0;i<Map[u].size();i++)
    {
       // cout<<"now"<<u<<" "<<"next" <<Map[u][i]<<" "<<n+1<<endl;
        dfs(Map[u][i],n+1);
    }
}

int main()
{
	ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--)
    {
        map<int,int> q;
        for(int i=0;i<MAXN;i++)Map[i].clear();
        big =0;
        int m=0;
        cin>>m;
        int  num =0;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            if( q.count(a)==0)
            {
                num++;
                q[a] = 1;
            }
            if(q.count(b)==0)
            {
                num++;
                q[b] =1;
            }

            Map[a].PB(b);
        }
        dfs(0,1);
        cout<<big<<" "<<num<<endl;

    }
	return 0;
}



