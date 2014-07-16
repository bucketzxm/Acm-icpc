
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
#define MAXN 200010

struct T{
    int left , right ;
    int num;
};
T tree[5*MAXN];
int h,w,n;

void init(int o,int l,int r)
{
    tree[o].num = w;
    int mid = (l+r)/2;

    tree[o].left = l;
    tree[o].right = r;

    if( l==r)return;
    init(o*2+1,l,mid);
    init(o*2+2,mid+1,r);
    return;
}


int ans ;
int query(int l,int r,int o,int tw)
{
    if( l == r)
    {
        tree[o].num-=tw;
        ans = l;
        return tree[o].num;
    }

    int mid = (l+r)/2;

    if( tree[2*o+1].num >= tw)
    {
        tree[o].num = max( query(l,mid,2*o+1,tw), tree[2*o+2].num);
    }
    else
    {
        tree[o].num = max( query(mid+1,r,2*o+2,tw),tree[o*2+1].num);
    }
    return tree[o].num;
}

int main()
{
//	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        h = min(h,n);
        init(0,1,h);

        REP(i,n)
        {
            int tw;
            scanf("%d",&tw);
            if( tw > tree[0].num){
                printf("-1\n");
                continue;
            }
            query(1,h,0,tw);
            printf("%d\n",ans);
        }
    }

	return 0;
}
