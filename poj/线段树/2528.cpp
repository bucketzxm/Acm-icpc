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
#define MAXN 50010
int n;
int dim[MAXN*12];
int l[MAXN*2];//r[MAXN*2];

struct T
{
  int l,r;
  int color;
};
T tree[MAXN*12];

void build(int o,int l,int r)
{
    tree[o].l = l;
    tree[o].r = r;
    tree[o].color = 0;
    if( l== r)return;
    int mid = (l+r)/2;
    build(o*2,l,mid);
    build(o*2+1,mid+1,r);
}
void insert(int o,int l,int r,int c)
{
    //cout<<o<<" "<<l<<" "<<r<<" "<<c<<endl;
    if( tree[o].l==l && tree[o].r == r)
    {
        tree[o].color = c;
        return ;
    }
    if( tree[o].color>0)
    {
        tree[o*2].color = tree[o].color;
        tree[o*2+1].color = tree[o].color;
        tree[o].color =0;
    }
    int mid = (tree[o].l+tree[o].r)/2;
    if( l > mid)
    {
        insert( o*2+1,l,r,c);
    }
    else if( r<=mid)
    {
        insert(o*2,l,r,c);
    }
    else
    {
        insert(o*2,l,mid,c);
        insert(o*2+1,mid+1,r,c);
    }

}
int rec[MAXN*12];
int id[MAXN*2];
int total = 0;
void query(int o)
{

    if( tree[o].color !=0)
    {
        if( !rec[tree[o].color])
        {
            rec[ tree[o].color ] ++;
            total ++;
        }
        return ;
    }
    if( tree[o].l == tree[o].r)return;
    query(o*2);
    query(o*2+1);
    return;
}
bool cmp(int a,int b)
{
    return l[a]<l[b];
}
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif


    int T;
    cin>>T;
    while(T--)
    {
       cin>>n;
       REP(i,2*n)
       {
           cin>>l[i];
           id[i] = i;
       }
       sort(id,id+n*2,cmp);
       int j = 0 , len = 0;

       for(int i=0;i<2*n;i++)
       {
           if( i==0)
           {
               dim[id[i]] = 1;
           }
           else
           {
               if( l[id[i]] == l[id[i-1]])
               {
                   dim[id[i]] = dim[id[i-1]];
               }
               else if( l[id[i]] == l[id[i-1]]+1)
               {
                   dim[id[i]] = dim[id[i-1]]+1;
               }
               else
               {
                   dim[id[i]] = dim[id[i-1]]+2;
               }
           }
       }
       len = dim[id[2*n-1]];
       build(1,1,len);
       for(int i=0;i<n;i++)
       {
           //  cout<<left<<" "<<right<<endl;
           insert(1,dim[2*i],dim[2*i+1],i+1);
       }

       total = 0;
        CLR(rec,0);
       query(1);

       cout<<total<<endl;

    }
	return 0;
}

