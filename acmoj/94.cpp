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

double num[1000];

int main()
{
	ios::sync_with_stdio(false);

    int p = 0;
    double sum =0;
    while(cin>>num[p++])
    {
        sum += num[p-1];
       // cout<<num[p-1]<<endl;
    }
    p--;
    sort(num,num+p);
    sum=sum-(num[0]+num[p-1]);
    cout<<p<<", "<<num[0]<<", "<<num[p-1]<<", "<<sum/(p-2)*1.0<<endl;

    return 0;
}





