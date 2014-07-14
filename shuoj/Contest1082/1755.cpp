
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

#define MAXN 10000
struct tape{
    double a,b,mul;
    bool operator < (const tape& x) const{
        return mul<x.mul;
    }

};
tape T[MAXN];
int main()
{
	ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        double sump=0;
        REP(i,n)
        {
            cin>>T[i].b>>T[i].a;
            //T[i].mul = T[i].a*T[i].b;
            sump +=T[i].a;
        }
        REP(i,n)
        {
            T[i].a/=sump;
            T[i].mul = T[i].a*T[i].b;
        }
        sort(T,T+n);
        double dp[MAXN]={0};


        dp[0] = T[0].mul;
        REP2(i,1,n-1)
        {
            dp[i] = dp[i-1]+T[i].mul;
        }
        double ans=0;
        REP(i,n)
        {
            ans+=dp[i];
        }
        cout<<fixed<<setprecision(4)<<ans<<endl;
    }
	return 0;
}
