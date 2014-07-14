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
char A[MAXN],B[MAXN];
int dp[MAXN][MAXN];
int main()
{
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    int cse =0;
    while(T--)
    {
        cout<<"Case "<<++cse<<endl;
        int lena,lenb;
        cin>>lena>>lenb;
        REP2(i,1,lena)
        {
            cin>>A[i];
        }
        REP2(i,1,lenb)
        {
            cin>>B[i];
        }


        for(int i=1;i<=lena;i++)
        {
            for(int j=1;j<=lenb;j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                if( A[i] == B[j])
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        cout<<dp[lena][lenb]<<endl;

    }
	return 0;
}

