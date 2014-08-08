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

int num[100000+10];
int ne[100000+10];
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int k = -1;
    for(int i=0;i<n-1;i++){
        if( num[i]>num[i+1]){
            k = i;break;
        }
    }
    if(k==-1){
        cout<<0<<endl;return 0;
    }
    int pn=0;
    for(int i=k+1;i<n;i++){
        ne[pn++] = num[i];
    }
    for(int i=0;i<=k;i++){
        ne[pn++] = num[i];
    }
    sort(num,num+n);
    for(int i=0;i<n;i++){
        if(num[i]!=ne[i]){
            cout<<-1<<endl;return 0;
        }
    }
    cout<<n-k-1<<endl;

	return 0;
}

