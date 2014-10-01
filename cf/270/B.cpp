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

bool cmp(int a,int b){

    return a>b;
}
bool vis[2005];
int f[2005];
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in","r",stdin);
    #endif


    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    sort(f,f+n,cmp);

    int Min =INF,Max = 0;

    ll ret = 0;

    for(int i=0;i<n;i+=k){
        ret += (f[i]-1)*2;
    }

    cout<<ret<<endl;
	return 0;
}


