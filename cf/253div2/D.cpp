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

double p[105];
double snp;
bool cmp(double a,double b)
{
    return a>b;
}
int main()
{
	ios::sync_with_stdio(false);

    int n;
    cin>>n;
    snp=1;
    REP2(i,1,n)
    {
        cin>>p[i];
        snp = snp*(1-p[i]);
    }
    sort(p+1,p+n+1,cmp);

    double ans = 0;
    double tmp= 0;
    for(int i=1;i<=n;i++)
    {
        double tmp = 0;
        for(int j=1;j<=i;j++)
        {
            double g = p[j];
            for(int q = 1;q<=i;q++)
            {
                if(q==j)continue;
                else
                    g*=(1-p[q]);
            }
            tmp+=g;
        }

        ans = max(ans,tmp);
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;

	return 0;
}


