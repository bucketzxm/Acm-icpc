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

int main()
{
	ios::sync_with_stdio(false);
    double n;
    int cse = 0;
    while(cin>>n)
    {
        cout<<"Case "<<++cse<<": "<<n<<", ";
        double ans = 1;
        int time = 0;
        while(n*ans<=8844430)
        {
            ans*=2;
            time++;
        }
        double s = n*ans/1000;
        cout<<time<<", "<<fixed<<setprecision(1)<<s<<endl;
        cout.unsetf(ios_base::fixed);
    }
	return 0;
}


