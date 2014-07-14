
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
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
bool isprime(int x)
{
    if( x==1)return false;
    for(int i=2;i<x;i++)
    {
        if( x%i==0)return false;
    }
    return true;
}
int main()
{
	ios::sync_with_stdio(false);

    int n;
    int cse = 0;
    while(cin>>n)
    {
        cout<<"Case "<<++cse<<": "<<n<<", ";

        int d = n*n;
        int m=n;
        int w =1;
        while(m)
        {
            m/=10;
            w*=10;
        }
        if( d%w == n)
        {

            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }

    return 0;
}







