
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

#define MAXN 200000
struct node
{
    ll num;
    ll sum;
    int left,right;
    node* lson,*rson;
    node():num(0),sum(0),left(0),right(0),lson(NULL),rson(NULL){}
};

node tree[MAXN*4];

int N,Q;

void build(node* p ,int l,int r)
{

    p->left = l ;
    p->right = r;

    if( l==r) return;
    int mid = (l+r)/2;

    p->lson = tree+2*(p-tree)+1;
    p->rson = tree+2*(p-tree)+2;
    build(p->lson,l,mid);
    build(p->rson,mid+1,r);
}

void add(node* p,int l,int r,int t)
{
    p->sum += t *(r-l+1);

    if( p->left == l && p->right ==r)
    {
        p->num += t;
        return;
    }

    int mid = (p->left + p->right)/2;

    if( l > mid)
    {
        add( p->rson,l,r,t);
    }
    else if( r <= mid)
    {
        add ( p->lson,l,r,t);
    }
    else
    {
        add( p->lson,l,mid,t);
        add(p->rson,mid+1,r,t);
    }
    return ;
}

ll query( node* p,int l,int r)
{
  //  cout<<p->left<<" "<<p->right<<endl;
    ll ret = p->num*(r-l+1);

    if( l== p->left && r==p->right)
    {
        return p->sum;
    }

    int m = (p->left + p->right)/2;

    if( l>m)
    {
        return ret + query( p->rson,l,r);
    }
    else if( r<= m)
    {
        return ret + query( p->lson,l,r);
    }
    else
    {
        return ret+ query(p->lson ,l,m) + query( p->rson,m+1,r);
    }
}

int main()
{
	//ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(cin>>N>>Q)
    {
        build(tree,1,100000);
        for(int i=1;i<=N;i++)
        {
            int t;
            scanf("%d",&t);
            add(tree,i,i,t);
        }
        for(int i=0;i<Q;i++)
        {
            getchar();
            char cmd;int x,y;
            scanf("%c %d %d",&cmd,&x,&y);
            if( cmd== 'Q')
            {
                printf("%lld\n",query(tree,x,y));
            }
            else
            {
                int t;
                scanf("%d",&t);
                add(tree,x,y,t);
            }
        }
    }
	return 0;
}
