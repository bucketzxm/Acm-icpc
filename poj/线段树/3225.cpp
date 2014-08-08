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

#define MAXN 1<<18

struct T
{
    int xr, num;
    int left,right;
};
T tree[4*MAXN];

//需要翻转xr =1 ,  否则xr = 0;

void build(int o,int l,int r)
{
    //cout<<o<<' '<<l<<' '<<r<<endl;
    tree[o].xr = 0;
    tree[o].num = -1;
    tree[o].left = l;
    tree[o].right =r;
    if( tree[o].left == tree[o].right)
    {
        return ;
    }
    int mid = (l+r)/2;
    build(o*2,l,mid);
    build(o*2+1,mid+1,r);
}

//method = 0, 区间　０　
//method = 1　区间１
//method = 2 区间反转

void update( int l,int r,int method,int o)
{

    //cout<<l<<' '<<r<<' '<<method<<endl;
    l = max(l,0);
    r = min( r, MAXN-1);
    if( tree[o].left==l && tree[o].right==r)
    {
        if( method ==0)tree[o].num = 0;
        if( method ==1)tree[o].num = 1;
        if( method == 2)tree[o].xr = 1- tree[o].xr;
        return ;
    }
    if( tree[o].num!=-1)
        tree[o*2].num = tree[o*2+1].num = tree[o].num;
    if( tree[o].xr!=0)
        tree[o*2].xr = tree[o*2+1].xr = tree[o].xr;

    int mid = (tree[o].left + tree[o].right)/2;
    if( l>mid)
    {
        update(l,r,method,o*2+1);
    }
    else if( r<=mid)
    {
        update(l,r,method,o*2);
    }
    else
    {
        update(l,mid,method,o*2);
        update(mid+1,r,method,o*2+1);
    }
}
void query(int o,int l, int r)
{

}
void output()
{

    query(1,0,MAXN-1);



}

char s1[] = {'.','[','('};
char s2[] = {')',']','.'};

int main()
{
	//ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    char cmd, ltex,rtex;
    int l,r;

    build(1,0,MAXN-1);
    while(scanf("%c %c%d,%d%c\n",&cmd,&ltex,&l,&r,&rtex)!=EOF)
    {
        l*=3;r*=3;
        if(ltex =='[')l++;else l+=2;
        if( rtex == ']') r++;

        //cout<<"ok"<<endl;
        switch(cmd)
        {
            case 'U':
                update(l,r,1,1);
                break;
            case 'I':
                update(0,l-1,0,1);
                update(r+1,MAXN-1,0,1);
                break;
            case 'D':
                update(l,r,0,1);
                break;
            case 'C':
                update(0,l-1,0,1);
                update(r+1,MAXN-1,0,1);
                update(l,r,2,1);
                break;
            case 'S':
                update(l,r,2,1);
                break;
        }
    }

	return 0;
}

