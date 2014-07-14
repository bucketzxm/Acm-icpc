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

int r[1000], l[1000];

int main()
{
	ios::sync_with_stdio(false);
	int n,m,k;
	while(cin>>n>>m>>k)
	{
		REP(i,n)
		{
			r[i]=(i+1)%n;
			l[r[i]]=i;
		}
		int p=(k+n-2)%n;
		REP(i,n-1)
		{
			int ls=p;
			REP(i,m)
			{
				ls=p;
				p=r[p];
			}
			r[ls]=r[p];
			l[r[p]]=ls;
		}
		cout<<r[p]+1<<endl;
	}
	return 0;
}
