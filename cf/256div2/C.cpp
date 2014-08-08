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

int h[5005];
int n;
int ans = 0;
void print()
{
    for(int i=0;i<n;i++)
    {
        cout<<h[i]<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
}
void dfs(int l,int r,int w,int deep)
{
    //cout<<l<<' '<<r<<' '<<w<<endl;
    //print();
    //if( deep > 5000)return ;

    for(int i=l;i<=r;i++)
    {
        if( h[i]>w)
        {
            ans++; h[i]=-1;
        }
    }
    int cnt = 0;
    for(int i=l;i<=r;i++)
    {
        if( h[i]<=0)cnt++;
    }
    if( cnt == r-l+1)return;

    int left = l, right = r;
    int i=l;
    while(i<=r)
    {
        int x=0;
        while(h[i]==1)i++;
            left = i;
        while(h[i]!=1&& i<=r){i++;}
            right = i-1;

        int ww =0;
        for(int k=left;k<=right;k++){
            if(h[k]>0) x++;
            h[k]--;
        }

        dfs( left,right,x,deep+1);

    }

    ans++;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif


    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    ans=0;
    dfs(0,n-1,n,0);

    cout<<ans<<endl;

	return 0;
}

