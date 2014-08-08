
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
struct G
{
  int num;
  int bg,ed;
};

struct BIT{
	int sz;
	ll* bit;
	void init()
	{
		REP(i,sz+1) bit[i]=0;
	}
	BIT(int size)
	{
		sz=size>0?size:0;
		bit=new ll[sz+1];
		this->init(); // initialize
	}
	~BIT()
	{
		delete[] bit;
	}
	void add(int i, ll x)
	{
		while(i<=sz)
		{
			bit[i]+=x;
			i+=i&-i;
		}
	}
	ll query(int i)
	{
		ll sum=0;
		while(i>0)
		{
			sum+=bit[i];
			i-=i&-i;
		}
		return sum;
	}
};

int n;
bool cmp(G a, G b)
{
    return a.ed<b.ed;
}
int vis[10000+10];
int main()
{
	//ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    int T;
    scanf("%d",&T);
    while(T--)
    {
       BIT bit(1450);
     //  memset(vis,0,sizeof(vis));
       scanf("%d",&n);
       for(int i=0;i<n;i++)
       {
          // cout<<gp[i].bg<<" "<<gp[i].ed<<endl;
            int num;
            scanf("%d",&num);
            int sh,sm,eh,em;
            //cin>>sh>>sm>>eh>>em;
            scanf("%d:%d %d:%d",&sh,&sm,&eh,&em);

            int left  = sh*60+sm; int right=eh*60+em;
            bit.add(left,num);bit.add(right,-num);
          //  cout<<gp[i].num<< ' '<<gp[i].bg<<' '<<gp[i].ed<<endl;
       }
      // sort(gp,gp+n,cmp);
        int  ans = 0;
        for(int i = 0;i<=1440;i++)
        {
            ll d = bit.query(i);
            if( d> ans)
                ans = d;
        }
        printf("%d\n",ans);
    }


	return 0;
}
