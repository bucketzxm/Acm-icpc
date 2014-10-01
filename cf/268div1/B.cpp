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

ll n,a,b;
ll num[100000+10];
map<ll,int> M;
int ans[100000+10];

int solve(int k, int now)
{
    int sub = 0;
    if( k == 0)
        sub = a;
    else if(k==1)
        sub = b;

    int d = sub-now;

    int loc_now = M[now];

    if( M.count(d) == 0)
        return -1;
    else
    {
        int loc = M[d];
        if( ans[loc] == k)
        {
            ans[loc_now] = k;
            return k;
        }
        else if(ans[loc] == 1-k)
        {
            int tt;
            if( k==0)tt = b;
            else tt = a;

            int r1 = solve(k,tt-d);
            if ( r1 != -1 )
            {
                ans[ loc_now ] = ans[ M[tt-d]]= k;
                return k;
            }
            else
            {
                return -1;
            }
        }
        else if( ans[loc] == -1)
        {
            ans[loc_now] = ans[loc] = k;
            return k;
        }
    }
    return -1;
}


int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif

    cin>>n>>a>>b;
    memset(ans,-1,sizeof(ans));

    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        M[ num[i] ] = i;
    }

    int flag = 0;
    for(int i=0;i<n;i++)
    {
        if( ans[i] !=-1)continue;
        int r1 = solve(0,num[i]);

        if( r1 !=-1)
        {
            //cout<<i<<" "<<ans[i]<<endl;
            continue;
        }
        int r2 = solve(1,num[i]);
//
//        if(r2!=-1)
//            //cout<<i<<" "<<ans[i]<<endl;

        if( r1==-1 && r2==-1)
        {
            flag = 1;break;
        }
    }

    if( flag )
    {
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            cout << ans[i];
            if( i!=n-1)cout<<" ";
            else
                cout<<endl;
        }
    }
	return 0;
}


