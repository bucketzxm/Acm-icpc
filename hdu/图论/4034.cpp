
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

int N;
int dist[105][105];
int vis[105][105];
int main()
{
	ios::sync_with_stdio(false);

    int tst;
    cin>>tst;
    int cse = 0;
    while(tst--)
    {
        CLR(dist,0);CLR(vis,0);

        cin>>N;
        REP(i,N)
        REP(j,N)
        {
            cin>>dist[i][j];
        }
        cout<<"Case "<<++cse<<": ";

        int ans = N*(N-1);
        REP(k,N)
        {
            REP(i,N)
            {
                REP(j,N)
                {
                    if( i == k || j == k)continue;
                    if(!vis[i][j] && dist[i][j] == dist[i][k]+dist[k][j])
                    {
                        ans--;
                        vis[i][j] =1;
                    }
                    if( dist[i][j] > dist[i][k]+dist[k][j])
                    {
                        ans = -1;
                        break;
                    }
                }
                if( ans ==-1)
                {
                    break;
                }
            }
            if(ans==-1)break;
        }
        if( ans == -1)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }

    }

	return 0;
}

