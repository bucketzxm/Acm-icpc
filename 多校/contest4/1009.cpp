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
int n;
int num[3005];

int gcd(int a,int b){
    if( b== 0)return a;
    return gcd(b,a%b);
}

int bs(int l,int r){

    if( l == r-2){
        return gcd( num[l],num[l+1]);
    }
    int ret = 0;
    int al,ar;
    for(int k=l; k < r;k++){
        int left = bs(l,k);
        int right = bs(k+1,r);
        int g = gcd(left,right);
        if( k>l ){
            g+= left;
        }
        if(k<r-1)g+=right;
        if( g>ret){
            ret = g;
        }
    }
    return ret;
}


int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
      //  freopen("in","r",stdin);
    #endif

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int ans = 0;
        for(int i=0;i<n;i++){
            cin>>num[i];
            ans+=num[i];
        }
        ans += bs(0,n);
        cout<<ans<<endl;
    }


	return 0;
}

