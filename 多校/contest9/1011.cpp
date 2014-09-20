// Binary Indexed Tree
// 单点更新 / 区间查询
// 复杂度 O(nlogn)
// 2014.5.4
// By Curs0r
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

#define lson t<<1,l,m
#define rson t<<1|1,m+1,r

class SEGTREE{
	private:
		ll* num;
		ll* sum;
		int sz;
		void build(int t, int l, int r)
		{
			num[t] = sum[t] = 0;
			if(l==r) return;
			int m = (l+r)>>1;
			build(lson);
			build(rson);
		}
		void seg_add(int t, int l, int r, int pl, int pr, ll inc)
		{
			sum[t]+=inc*(pr-pl+1);
			if(l==pl && r==pr){num[t]+=inc;return;}
			int m = (l+r)>>1;
			if(pl>m) seg_add(rson, pl, pr, inc);
			else if(pr<=m) seg_add(lson, pl, pr, inc);
			else seg_add(lson, pl, m, inc),seg_add(rson, m+1, pr, inc);
		}
		ll seg_query(int t, int l, int r, int pl, int pr)
		{
			if(l==pl && r==pr) return sum[t];
			ll ret = num[t] * (pr-pl+1);
			int m = (l+r)>>1;
			if(pl>m)
				return ret + seg_query(rson, pl, pr);
			else if(pr<=m)
				return ret + seg_query(lson, pl, pr);
			else
				return ret + seg_query(lson, pl, m) + seg_query(rson, m+1, pr);
		}
	public:
		SEGTREE(int size)
		{
			sz = size > 0? size : 0;
			num = new ll[sz*3+1];
			sum = new ll[sz*3+1];
			this->init(sz); // initialize
		}
		~SEGTREE()
		{
			delete[] num;
			delete[] sum;
		}
		void resize(int size)
		{
			size = size > 0? size : 0;
			if(size <= sz) return;
			else{
				ll* tmp;
				tmp = new ll[size*3+1];
				delete[] num;
				num = tmp;
				tmp = new ll[size*3+1];
				delete[] sum;
				sum = tmp;
			}
			sz = size;
		}
		void init(int size)
		{
			build(1,0,sz);
		}
		void add(int l, int r, ll inc)
		{
			seg_add(1,0,sz,l,r,inc);
		}
		ll query(int l, int r)
		{
			return seg_query(1,0,sz,l,r);
		}
};

ll Scan()     //ÊäÈëÍâ¹Ò
{
	ll res=0,ch,flag=0;
	if((ch=getchar())=='-')
	    flag=1;
	else if(ch>='0'&&ch<='9')
	    res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return flag?-res:res;
}
void Out(int a)    //Êä³öÍâ¹Ò
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}


int main()
{
    //freopen("in","r",stdin);

    int N;
    while(N = Scan()){
        if(N==0)break;
        SEGTREE tree = SEGTREE(4*N);
        //cout<<N<<endl;
        int M;
        M = Scan();
        ll sum =0;
        for(int i=0;i<M;i++){
            ll l,r,a;
            l = Scan();

            r = Scan();

            a = Scan();
            tree.add(l,r,a);
        }
        ll K;
        K = Scan();
        int ans = 0;
        for(int i=0;i<K;i++){
            ll h,x;
            h = Scan();
            x = Scan();
            ll ret = tree.query(x,N);
            if( h>ret){
                ans++;
            }
        }
        Out(ans);
        putchar('\n');
    }

	return 0;
}

