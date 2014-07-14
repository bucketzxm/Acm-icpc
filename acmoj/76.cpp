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

double num[5];
int main()
{
	ios::sync_with_stdio(false);

    REP(i,5)
    {
        cin>>num[i];
    }
    double suanshu = 0;
    REP(i,5)suanshu+=num[i];
    suanshu/=5.0;
    double jihe=1;
    REP(i,5)jihe*=num[i];
    double jihe2 = pow(abs(jihe),0.2);
    if( jihe<0)
        cout<<suanshu<<", "<<-jihe2<<endl;
    else
        cout<<suanshu<<", "<<jihe2<<endl;
	return 0;
}


