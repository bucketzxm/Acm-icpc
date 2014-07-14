
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

#define MAXN 1000
int sumv[MAXN*4],minv[MAXN*4],maxv[MAXN*4];
int setv[MAXN*4];
int addv[MAXN*4];
//维护节点o， 对应区间[L,R];
void maintain(int o,int L,int R)
{
    int lc = o*2,rc = o*2+1;
    sumv[o] = minv[o] = maxv[o] = 0;

    if( R>L)
    {
        sumv[o] = sumv[lc]+sumv[rc];
        minv[o] = min( minv[lc],minv[rc]);
        maxv[o] = max(maxv[lc],maxv[rc]);
    }
    minv[o] += addv[o];
    maxv[o] += addv[o];
    sumv[o] += addv[o]*(R-L+1);
    //考虑add操作
}

void pushdown(int o)
{
    int lc = o*2,rc = o*2+1;

    if( setv[o] >=0)
    {
        setv[lc] = setv[rc] = setv[o];
        setv[o] = -1;
    }
}

void update(int o,int L,int R,int y1,int y2,int v)
{
    int lc = o*2, rc = o*2+1;
    if(y1<=L &&y2>=R)
    {
        setv[o]= v;
    }
    else
    {
        pushdown(o);
        int M = L + (R-L)/2;
        if( y1<=M)
            update(lc,L,M,y1,y2,v);
        else
            maintain(lc,L,M);
        if(y2>M)
            update(rc ,M+1,R,y1,y2,v);
        else
            maintain(rc,M+1,R);
    }
    maintain(o,L,R);
}
int _sum,_min,_max;
void query(int o,int L,int R,int y1,int y2)
{
    if( setv[o]>=0)
    {
        _sum+=setv[o] * (min(R,y2)-max(L,y1)+1);
        _min = min(_min,setv[o]);
        _max = max(_max, setv[o]);
    }
    else if(y1<=L && y2>=R)
    {
        _sum+=sumv[o];
        _min = min(_min , minv[o]);
        _max = max( _max,maxv[o]);

    }
    else
    {
        int M = L +(R-L)/2;
        if( y1<=M)query(o*2,L,M,y1,y2);
        if( y2>M) query(o*2+1,M+1,R,y1,y2);
    }
}
int main()
{
	ios::sync_with_stdio(false);



	return 0;
}


