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

ll a[100000+10];
ll b[100000+10];

ll c[100000+10];

int check(int s,int e)
{
    if (s > e )swap(s,e);
    int j = e;
    for(int i=s;i<=e;i++)
    {
        if( a[i]==b[j])
        {
            j--;
        }
    }
    if( j==s-1)return 1;
    return 0;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in","r",stdin);
    #endif

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    sort( b,b+n);

    int cnt = 0;
    int flag = 1;
    int s=0,e=0;
    for(int i=0;i<n;i++)
    {
        if( a[i] != b[i])
        {
            s = i;
            int j=i+1;
            for(;j<n;j++)
            {
                if( a[i]==b[j])
                {
                    e = j;
                }
            }
            break;
        }
    }

    for(int i=0;i<n;i++)
    {
        c[i] = a[i];
    }
    int j=s;
    for(int i = e;i>=s;i--)
    {
        c[j++] = a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(c[i]!=b[i])
        {
            flag = 0;
            break;
        }
    }

    if( flag)
    {
        cout<<"yes"<<endl;
        if(s>e)swap(s,e);
        cout<<s+1<<" "<<e+1<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
	return 0;
}

