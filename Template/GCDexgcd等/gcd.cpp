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

int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

//ax+by = gcd(a,b)
int extgcd(int a,int b,int &x,int &y)
{
    int d = a;
    if( b!=0)
    {
        d = extgcd(b,a%b,y,x);
        y-=(a/b)*x;

    }
    else
    {
        x=1;
        y = 0;
    }
    return d;

}

int main()
{
	ios::sync_with_stdio(false);

	return 0;
}



