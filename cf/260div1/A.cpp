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

#define MAXN 100000+10
int id[MAXN],num[MAXN];
bool cmp(int a,int b){
    if( a*num[a]==b*num[b] ){
        return (a-1)*num[a-1]+(a+1)*num[a+1]<(b-1)*num[b-1]+(b+1)*num[b+1];
    }
    return a*num[a]>b*num[b];
}
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        num[t]++;
        id[t] = t;
    }
    sort(id,id+MAXN,cmp);
    //for(int i=0;i<10;i++)cout<<id[i]<<" "<<endl;
    ll ans = 0;
    for(int i=0;i<MAXN;i++){
        if( num[id[i]]>0){
            ans+= num[ id[i]] *id[i];
            num[ id[i]-1] = 0; num[id[i]+1] = 0;
        }
    }
    cout<<ans<<endl;


	return 0;
}

