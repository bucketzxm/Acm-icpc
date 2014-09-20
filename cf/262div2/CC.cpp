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

ll a[200000];
ll b[200000];
ll n,m,w;
bool C(ll d){

    for(int i=0;i<n;i++)
        b[i] = a[i];
    ll tm = m;
    for(int i=0;i<n;i++){
        while(b[i] < d && tm>0){
            for(int j=0;j<w;j++){
                b[i+j]+=1;
            }
            tm--;
        }
        if( b[i]<d){
            return false;
        }
    }

    return true;
}

int main(int argv,char **args)
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen(args[1],"r",stdin);
        freopen("out2","w",stdout);
    #endif

    cin>>n>>m>>w;

    ll l = INF, r = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if( a[i]<l )l=a[i];
        if( a[i]>r )r=a[i];
    }
    //sort(a,a+n);
    r = r+m;
    ll ans = l;
    while(l<=r){
        ll mid = (l+r)/2;
        if(C(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<ans<<endl;

	return 0;
}

