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
double a[110];
double b[110];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n;i++)
		{
			b[i]=a[i]-a[i-1];
		}
		sort(b+1,b+n);
		double len;
		bool flag=1;
		for(int i=n-1;i>0;i--)
		{
			len=b[i];
			flag=1;
			double l=a[0];
			for(int j=1;j<n-1;j++)
			{
				if(a[j]-a[j-1]-len<-1e-8&&a[j+1]-a[j]-len<-1e-8)
				{
					flag=0;
					break;
				}
			}
			if(flag)break;
		}
		cout<<fixed<<setprecision(3)<<len<<endl;
	}


	return 0;
}
