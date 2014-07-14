
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


int num[30][30];

int main()
{
	ios::sync_with_stdio(false);
	num[1][1]=1;
	for(int i=2;i<30;i++)
    {
        for(int j=1;j<=i;j++)
        {
            num[i][j] = num[i-1][j-1]+num[i-1][j];
        }
    }

    int n;
    int cse = 0;
    while(cin>>n)
    {

        cout<<"Case "<<++cse<<":"<<endl;
        for(int i=1;i<=n+1;i++)
        {
            for(int q=0;q<(n+1-i);q++)
                cout<<"   ";
            for(int j=1;j<=i;j++)
            {
                cout<<fixed<<setw(6)<<num[i][j];
            }
            cout<<endl;
        }
    }
	return 0;
}


