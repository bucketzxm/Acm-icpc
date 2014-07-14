
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
	//ios::sync_with_stdio(false);
    char c;
    int p=0;
    int cse = 0;
    while(scanf("%lf%c",&num[p++],&c)!=EOF)
    {
         if( c == '\n')
        {
            cout<<"Case "<<++cse<<":"<<endl;

            REP(i,p)
            {
                int cnt = 0;
                REP(j,p)
                {
                    if( num[j]>num[i])cnt++;
                }
                cout<<cnt+1;
                if( i==p-1)
                    cout<<endl;
                else
                    cout<<", ";
            }

            p=0;
            CLR(num,0);
        }
    }

	return 0;
}

