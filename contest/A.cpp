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
#define X first
#define Y second

int a[10000];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n,n)
    {
        string s;
        int L=-INF, R=INF;
        int ok=1;
        REP(i,n)
        {
            cin>>s;
            if(s[0]=='x')
            {
                a[i]=INF;
            }else{
                a[i]=atoi(s.c_str());
            }
        }
        REP(i,n)
        {
            if(a[i]==INF)
            {
                if(i&1)
                {
                    if(i)L=max(a[i-1]+1,L);
                    if(i!=n-1)L=max(a[i+1]+1,L);
                }else{
                    if(i)R=min(a[i-1]-1,R);
                    if(i!=n-1)R=min(a[i+1]-1,R);
                }
            }else{
                if(i&&a[i-1]!=INF)
                {
                    if(i&1&&a[i]<=a[i-1]) ok=0;
                    if(!(i&1)&&a[i]>=a[i-1]) ok=0;
                }
            }
        }
        if(L>R||!ok) cout<<"none"<<endl;
        else if(L<R) cout<<"ambiguous"<<endl;
        else cout<<L<<endl;
    }
    return 0;
}
