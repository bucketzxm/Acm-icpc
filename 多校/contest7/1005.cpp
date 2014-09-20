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


int n,x,y,z,t;
int dp[2000][2000];
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif

    int cse = 0;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>x>>y>>z>>t;
        int ans = 0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n-i;j++){
                int d1 = dp[i-1][j]+(i-1)*y*(z*j+t);
                int d2 = dp[i][j-1]+i*y*(z*j+t);

                if( d1>d2){
                    dp[i][j] = d1;
                    ans = max( ans, d1+ (n-i-j+1)*(z*j+t)*x + i*y*(z*j+t)*(n-i-j+1) );
                }else
                {
                    dp[i][j] = d2;
                    ans = max( ans,d2+ (n-i-j+1)*(z*j+t)*x+ i*y*(z*j+t)*(n-i-j+1) );
                }
            }
        }
        cout<<"Case #"<<++cse<<": "<<ans<<endl;
    }
	return 0;
}

