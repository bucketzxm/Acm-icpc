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

#define MAXN 501
int vnode[MAXN];
int Map[MAXN][MAXN];
int vsum,esum;

double ans;
int n,m;
int vis[MAXN];
int mark[MAXN];
double removenode(int i)
{
    int enode =0;
    for(int j=1;j<=n;j++)
    {
        if ( Map[i][j] && mark[j])
        {
            enode+=Map[i][j];
        }
    }
    return enode;
}

void checkdfs(int u)
{
    if( vis[u])return;
    vis[u] = 1;
    for(int i=1;i<=n;i++)
    {
        if( Map[u][i] && mark[i])
        {
            checkdfs(i);
        }
    }
}
bool check()
{
    CLR(vis,0);
    for(int i=1;i<=n;i++)
    {
        if( mark[i])
        {
            checkdfs(i);
            for(int i=1;i<=n;i++)
                if( mark[i] &&!vis[i])
            {
                return false;
            }
            return true;
        }
    }
}

double dens(int esum,int vsum)
{
    if (esum ==0)return 0;
    return vsum*1.0/esum;

}
void dfs( int esum,int vsum)
{
    double Max = dens(esum,vsum);
    if (check())
    {
        if(ans<Max) {ans =Max;}
        int rec = 0, mmm=0,mme=0,tmme;
        for(int j=1;j<=n;j++)
        {
            if( mark[j]==0)
            {
                tmme = removenode(j);
                double e = fabs(Max - dens(esum+tmme,vsum+vnode[j]));
                if(mmm<e)
                {
                    mme  = tmme;
                    mmm =e; rec = j;
                }
            }
        }
        if( fabs(mmm-0)<10e-6)return ;

            //Max = dens( esum+mme,vsum+vnode[rec]);
        mark[rec]=1;
        dfs( (esum+mme),(vsum+vnode[rec]));
        mark[rec] =0;
    }
}


int main()
{
	ios::sync_with_stdio(false);

    while(cin>>n>>m)
    {
        REP2(i,1,n)
        {
            cin>>vnode[i];
           // vsum+=vnode[i];
        }
        REP(i,m)
        {
            int a,b,e;
            cin>>a>>b>>e;
            Map[a][b]=e;
            Map[b][a]=e;
           // esum+=e;
        }
//        if( esum ==0 )ans =0;
//        else
//            ans = vsum*1.0/esum;
        ans =0;

        esum = vsum = 0;
        for(int i=0;i<=n;i++)
            mark[i]=0;
        for(int i=1;i<=n;i++)
        {
            mark[i]=1;
            int enode = removenode(i);
            dfs(esum+enode,vsum+vnode[i]);
            mark[i]=0;
        }
        cout<<fixed<<setprecision(15)<<ans<<endl;
    }
	return 0;
}



