
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

int num[20];
int vis[20];
int pn;
map<ll ,ll > qq;
int ans ;
void solve(int sum)
{
    int b[20];
    int len = 0;
    for(int i=0;i<pn;i++)
    {
        if( !vis[i] )
        {
            b[len++] = num[i];
        }
    }
    do
    {
        int bb = 0;
        for(int i=0;i<len;i++)
        {
            bb*=10;
            bb+=b[i];
        }
        if(b[0]!=0 || len ==1)
            ans = min(ans, abs(sum-bb));
    }while(next_permutation(b,b+len));
}

void dfs(int k,int sum)
{
    if( k==pn/2)
    {
        solve(sum);
        return;
    }
    REP(i,pn)
    {
        if(!vis[i])
        {
            if( num[i] == 0 && k==0 && pn>3)continue;
            vis[i] =1;
            dfs(k+1,sum*10+num[i]);
            vis[i]=0;
        }
    }


}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    int T;
    cin>>T;
    cin.ignore();
    while(T--)
    {
        pn = 0;
        string str;
        getline(cin,str);
        stringstream iss(str);
        while(iss>>num[pn])
        {
            pn++;
        }
        sort(num,num+pn);
        ll total = 0;
        for(int i=0;i<pn;i++)
        {
            total*=11;
            total = total + num[i]+1;
        }
        if( qq.count(total))
        {
           cout<<qq[total]<<endl;
            continue;
        }
        ans = INF;
        CLR(vis,0);
        dfs(0,0);
        qq[total]=ans;
        cout<<ans<<endl;
    }
	return 0;
}
