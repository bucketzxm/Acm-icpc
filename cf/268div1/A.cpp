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

ll n;
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif

    cin>>n;

    if( n <4)
    {
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        if( n % 2 == 0)
        {
            int cnt = 0;
            for(ll k = n;k>5;k-=2)
            {
                cout<<k<<" - "<<k-1<<" = "<<1<<endl;
                cnt++;
            }

            for(int i=1;i<4;i+=2)
            {
                cout<<i<<" * "<<i+1<<" = "<<i*(i+1)<<endl;
            }
            cout<<2<<" * "<<12<<" = "<<24<<endl;

            for(int i=0;i<cnt;i++)
            {
                cout<<24<<" * "<<1<<" = 24"<<endl;
            }

        }
        else
        {
            int cnt = 0;
            for(ll k = n;k>6;k-=2)
            {
                cout<<k<<" - "<<k-1<<" = "<<1<<endl;
                cnt++;
            }

            cout<<"5 * 4 = 20"<<endl;
            cout<<"20 + 2 = 22"<<endl;
            cout<<"22 + 3 = 25"<<endl;
            cout<<"25 - 1 = 24"<<endl;
            for(int i=0;i<cnt;i++)
            {
                cout<<"24 * 1 = 24"<<endl;
            }

        }


    }

	return 0;
}

