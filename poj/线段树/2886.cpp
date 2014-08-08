
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

#define MAXN 500005
int N,K;

struct T
{
    int left,right;
    int num;
};

T tree[4*MAXN];
void build(int l,int r ,int o)
{
    tree[o].left = l;
    tree[o].right = r;
    tree[o].num = (r-l+1);
    if( l==r){ tree[o].num=1; return;}

    int mid = (l+r)/2;
    build(l,mid,2*o);
    build(mid+1,r,2*o+1);

    return;
}
int a[37]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,
           55440,83160,110880,166320,221760,277200,332640,498960,500001};
int b[37]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200,1314521};
char name[MAXN][11];
int k[MAXN];

int query(int o,int s)
{
    tree[o].num--;
    if(tree[o].left == tree[o].right)
    {
        return tree[o].left;
    }

    int left = 2*o;
    int right = 2*o+1;
    if(s<=tree[left].num)
    {
        return query(left,s);
    }
    else
    {
        return query(right,s-tree[left].num);
    }
}
int main()
{
	//ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(scanf("%d%d",&N,&K)==2)
    {
        build(1,N,1);

        for(int i =1;i<=N;i++){
            scanf("%s %d",name[i],&k[i]);
        }

        int num=0,i=0;
        while(a[i]<=N)i++;

        num =a[i-1];

        int ans = b[i-1];
        int id;
        for(int i=0;i<num;i++)
        {
            N = N-1;
            id = query(1,K);
            if( N==0 )break;

            if( k[id]>0)
            {
                K = (K-1+k[id]-1)%N+1;
            }
            else
            {
                K = ((K-1+k[id])%N+N)%N+1;
            }
        }
        printf("%s %d\n",name[id],ans);
    }
	return 0;
}
