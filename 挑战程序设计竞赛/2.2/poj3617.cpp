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
    int n;
    cin>>n;
    char str[3000];
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
       // cout<<str[i]<<endl;
    }
    int a = 0, b = n-1;
    int count=0;
    while(a<=b)
    {
        int left  = 0;
        for(int i=0;a+i<=b;i++)
        {
            if( str[a+i]< str[b-i])
            {
                left = 1;break;
            }
            else if( str[a+i]>str[b-i])
            {
                left = 0;break;
            }
        }
        if( left )
        {
            putchar(str[a]);a++;
        }
        else
        {
            putchar(str[b]);b--;
        }
        count++;
        if(count%80==0)
            putchar('\n');
     }
    if( count%80)
        putchar('\n');
	return 0;
}

