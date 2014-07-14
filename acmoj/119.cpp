
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

int dp[MAXN][MAXN];
int main()
{
	ios::sync_with_stdio(false);

    int a,b;
    int cse = 0;
    while(cin>>a)
    {
        cout<<"Case "<<++cse<<":"<<endl;
        CLR(dp,0);
        int sx = 0,sy = (a)/2;
        int tx = sx, ty = sy;
        for(int i=1;i<=a*a;i++)
        {
                if( dp[sx][sy] == 0)
                {
                    dp[sx][sy] = i;
                }
                else
                {
                    tx ++;
                    tx%=a;
                    dp[tx][ty] = i;
                    sx = tx; sy = ty;
                }
                tx = sx; ty=sy;
                sx= (sx-1+a)%a;
                sy = (sy+1)%a;
        }
        REP(i,a)
        {
            REP(j,a)
            {
                cout<<fixed<<setw(5)<<dp[i][j];

            }
            cout<<endl;
        }

    }
	return 0;
}




