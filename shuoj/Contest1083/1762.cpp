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

#define MAXN 100
struct obj
{
    double v,w;
    double m;
    bool operator <(const obj& x)const
    {
        return m>x.m;
    }
}th[MAXN];


int main()
{
	ios::sync_with_stdio(false);

    int n;
    double c;
    int cse = 0;
    while(cin>>n>>c)
    {
        cout<<"Case "<<++cse<<": ";
        REP(i,n)
        {
            cin>>th[i].v;
        }
        REP(i,n)
        {
            cin>>th[i].w;
         }
        REP(i,n)
        {
            th[i].m = th[i].v*1.0/th[i].w;
        }
        sort(th,th+n);
        double ans =0;
        REP(i,n)
        {
            if( c>0)
            {
                if( c > th[i].w)
                {
                    c-= th[i].w;
                    ans += th[i].w*th[i].m;
                }
                else
                {
                    ans+= c*th[i].m;
                    c = 0;
                }
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;

    }
	return 0;
}

