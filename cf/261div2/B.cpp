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

long long be[4*100000];
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in","r",stdin);
    #endif

    long long n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>be[i];
    }
    sort(be,be+n);

    cout<<be[n-1]-be[0]<<" ";

    long long a = 1,b=1;
    for(int i=1;i<n;i++){
        if( be[i] == be[i-1] ){
            a++;
        }else{
            break;
        }
    }
    for(int i = n-2;i>=0;i--){
        if( be[i] == be[i+1]){
            b++;
        }else{
            break;
        }
    }

    if( a==n){
        long long ret = a*(a-1)/2;
        cout<<ret<<endl;
    }else{
        long long ret = a*b;
        cout<<ret<<endl;
    }
	return 0;
}

