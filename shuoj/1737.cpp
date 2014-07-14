
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

#define MAXN 15
int m,n;

int num[MAXN];
int main()
{
	ios::sync_with_stdio(false);

    vector<int> p;
    while(cin>>m>>n)
    {
        p.clear();
        REP(i,m)
        {
            int ans = 0;
            int MIN = INF;
            REP(j,n)
            {
                int t;
                cin>>t;
                if( MIN> t)
                {
                    MIN = t;
                    ans = j+1;
                }
            }
            p.push_back(ans);
        }
        for(int i=0;i<p.length();i++)
        {
            cout<<p[i]<<" "
        }
    }
	return 0;
}

