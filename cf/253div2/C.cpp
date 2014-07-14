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

int n;
vector<string> card;
int fa[105];

int find(int x)
{
	if(fa[x]!=x) fa[x] = find(fa[x]);
	return fa[x];
}
int unite(int x, int y)
{
	x = find(x);
	y = find(y);

	if( x == y)
    {
        return 0;
    }
    else
    {
        fa[x] = y;
        return 1;
    }

	return 1;
}


char color[] = {'R','G','B','Y','W','1','2','3','4','5'};

int ans =0;

int main()
{
	ios::sync_with_stdio(false);


    cin>>n;
    cin.ignore();
    REP(i,n)
    {
        fa[i] = 0;
        string tmp;
        cin>>tmp;
        card.push_back(tmp);
    }
    for(int i=0;i< 1<<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if( 1<<j & i)
            {

            }
        }


    }

	return 0;
}

