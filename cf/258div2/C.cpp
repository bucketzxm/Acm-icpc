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

ll labs(ll a)
{
    if( a>0)return a;
    else return -a;
}
 ll n,k,d1,d2;
int judge(ll a, ll b, ll c)
{
    ll rm = min( a, min(b,c));
    a-=rm ,b-=rm,c-=rm;
    if( a+b+c>k || (a+b+c-k)%3)return 0;

    rm = max(a,max(b,c));
    ll d = 3*rm-a-b-c;
    if( d<=n-k&& (n-k-d)%3==0)return 1;
    return 0;

}


int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif
    int t;
    cin>>t;


    while(t--)
    {
        cin>>n>>k>>d1>>d2;
//        ll a = n-k - (d1+d2+labs(d1+d2));
//        ll b = n-k - (d1+d2+labs(d1-d2));
//        if((a>=0 && a%3==0) || b>=0 && b%3==0|| (k==0&& n%3 == 0) ) &&
//        {
//            cout<<"yes"<<endl;
//        }
//        else
//            cout<<"no"<<endl;
        int a = 0;
        if(judge(0,d1,d1+d2)|| judge(-d1,0,-d2)||judge(0,-d1,-d1-d2)||judge(d1,0,d2))
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
	return 0;
}

