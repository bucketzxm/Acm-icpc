
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

#define MAXN 100000+100
struct Point{
    int x,y;
    Point(int x = 0,int y=0):x(x),y(y){}
};

Point P[MAXN];
double A[MAXN],B[MAXN];

int ax,ay ,bx, by;

double dist(int i, int x, int y)
{
    return sqrt((P[i].x-x)*(P[i].x-x)+(P[i].y-y)*(P[i].y-y));
}

int main()
{
	ios::sync_with_stdio(false);


    cin>>ax>>ay>>bx>>by;

    int n;
    cin>>n;
    REP(i,n)
    {
        cin>>P[i].x>>P[i].y;
    }

    for(int i=0;i<n;i++)
    {
        A[i] = dist(i,ax,ay);
        B[i] = dist(i,bx,by);
    }
    sort(A,A+n);sort(B,B+n);
    int m;
    cin>>m;

    while(m--)
    {
        int r1,r2;


    }

	return 0;
}
