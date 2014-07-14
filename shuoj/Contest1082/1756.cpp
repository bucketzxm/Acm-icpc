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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
struct Point{

    double x, y;
    Point(double x = 0, double y = 0): x(x),y(y){}
};

typedef Point Vector;
bool operator < (const Point& a,const Point& b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
Vector operator - ( Point A,  Point B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator + (Vector A,Vector B) {return Vector(A.x+B.x,A.y+B.y);}

double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}

Point p[105];
int main()
{
	ios::sync_with_stdio(false);

    int n;
    while(cin>>n)
    {
        REP(i,n)
        {
            cin>>p[i].x>>p[i].y;
        }

        Point o (0,0);
        int ans =0;
        int vis[105]= {0};
        REP(i,n)
        {
            REP(j,n)
            {
                if( i==j)continue;
                if(!vis[i] && !vis[j] &&fabs(Cross( p[i]-o,p[j]-o)) <10e-6 && p[i].x*p[j].x>=0&&p[i].y*p[j].y>=0)
                {
                    //cout<<i<<" "<<j<<" " <<Cross( p[i]-o,p[j]-o)<<endl;
                    vis[i] = 1;
                }
            }
        }
        REP(i,n)
            if(!vis[i])ans++;
        cout<<ans<<endl;
    }
	return 0;
}






