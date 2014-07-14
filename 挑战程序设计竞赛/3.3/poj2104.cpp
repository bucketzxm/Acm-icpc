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
#define MAXN 100010
const int B = 1000;
int N,M;
int num[MAXN];
int A[MAXN];
vector<int> bucket[MAXN/B];
int main()
{
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    while(cin>>N>>M)
    {
        REP(i,N)
        {
            scanf("%d",&A[i]);
            num[i] = A[i];
            bucket[i/B].PB(num[i]);
        }
        sort(num,num+N);
        REP(i,N/B)
            sort(bucket[i].begin(), bucket[i].end());

        for(int i=0;i<M;i++)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            l--;r --;
            int lb = -1, ub = N-1;
            while(ub-lb>1)
            {
                int mid = (lb+ub)/2;
                int x = num[mid];

                int tl = l, tr = r+1, c= 0;

                while( tl<tr && tl%B!=0) if( A[tl++] <= x ) c++;
                while( tl<tr && tr%B!=0) if( A[--tr] <= x) c++;

                while(tl<tr)
                {
                    int b = tl/B;
                    c += upper_bound(bucket[b].begin(),bucket[b].end(),x)- bucket[b].begin();
                    tl+=B;
                }
                //cout<<c<<" "<<k<<endl;
                if( c >=k)
                    ub=mid;
                else
                    lb = mid;
            }
            cout<<num[ub]<<endl;
        }
    }
	return 0;
}

