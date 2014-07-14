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

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    int n,sum;
    int num[20];
    int tri[20][20];
    while(cin>>n>>sum)
    {
        REP(i,n)
        {
            num[i] = i+1;
        }
        CLR(tri,0);
        do
        {
            for(int i=0;i<n;i++)
            {
                tri[0][i] = num[i];
            }
            for(int i=1;i<n;i++)
            {

                for(int j=0;j<n-i;j++)
                {
                    tri[i][j]  = tri[i-1][j]+tri[i-1][j+1];
                }
            }
            if( tri[n-1][0] == sum)break;
        }while(next_permutation(num,num+n));

        for(int i=0;i<n;i++)
        {
            cout<<num[i];
            if( i==n-1)cout<<endl;
            else cout<<" ";
        }
    }
	return 0;
}

