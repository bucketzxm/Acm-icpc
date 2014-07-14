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


//点修改
int A[MAXN*4];
int minv[MAXN*4];
int N;
void init(int _n)
{
    N=1;
    while(N<_n)
    {
        N*=2;
    }
    for(int i=0;i<=N;i++)
    {
        A[i] = 0;
        minv[i] = INF;
    }
}
//rmq

//查询ql,qr中最小值
int query(int o,int L,int R,int ql,int qr)
{
    int M = L+(R-L)/2 ,ans =INF;
    if( ql<=L && R<=qr)return minv[o];
    if( ql<=M)ans = min(ans,query(o*2,L,M,ql,qr));
    if(M<qr)ans = min(ans,query(o*2+1,M+1,R,ql,qr));

    return ans;
}

//修改; A[p] = v;
void update(int o,int L,int R,int p,int v)
{
    int M = L+(R-L)/2;
    if(L==R)minv[o] =v;

    else
    {
        if( p<=M)update(o*2,L,M,p,v);
        else
            update(o*2+1,M+1,R,p,v);
        minv[o]= min(minv[o*2],minv[o*2+1]);
    }
}


int main()
{
	ios::sync_with_stdio(false);


    int n;
    cin>>n;
    init(n);
    for(int i=0;i<N;i++)
    {
        cin>>A[i+1];
        update(1,1,N,i+1,A[i+1]);
    }
    int L,R;
    while(cin>>L>>R)
    {
        int ans = query(1,1,N,L,R);
        cout<<ans<<endl;
    }

	return 0;
}



