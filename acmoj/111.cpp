
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

int dp[10000+100];

int main()
{
	ios::sync_with_stdio(false);

    int n;
    int cse = 0;
    int money[3] = {1,2,5};
    CLR(dp,0);
    dp[0]=1;
    REP(i,3)
    {
        REP(j,10000)
        {
            dp[j+money[i]]+=dp[j];
        }
    }
    while(cin>>n)
    {
        cout<<"Case "<<++cse<<": "<<n<<", ";
        cout<<dp[n]<<endl;
        //solve(n);

    }

	return 0;
}
