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

#define MAXN 505
int a[MAXN],b[MAXN],c[MAXN];
int ab[MAXN*MAXN];




int main()
{
	ios::sync_with_stdio(false);


	int cse = 0;
	int L,M,N,S;
	while(cin>>L>>M>>N)
    {
        cout<<"Case "<<++cse<<":"<<endl;
        REP(i,L)cin>>a[i];
        REP(i,M)cin>>b[i];
        REP(i,N)cin>>c[i];

        int p=0;
        REP(i,L)
        {
            REP(j,M)
            {
                ab[p++] = a[i]+b[j];
            }
        }
        sort( c,c+N);
        sort(ab,ab+M*L);
        cin>>S;
        while(S--)
        {
            int x;
            cin>>x;

            int flag = 0;
           REP(i,N)
           {
               int af = x-c[i];

                if( binary_search(ab,ab+M*L,af) )
                {
                    flag = 1;
                    cout<<"YES"<<endl;
                    break;
                }

           }
           if( !flag )
           {
               cout<<"NO"<<endl;
           }

        }
    }

	return 0;
}

