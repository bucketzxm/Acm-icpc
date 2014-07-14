
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

#define MAXN 2500
struct Point{
    double x,y;
    Point(double x = 0 , double y = 0):x(x),y(y) {}

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

Vector Rotate(Vector A,double rad)
{
    return Vector( A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double torad(double deg)
{
    return deg/180*acos(-1); //acos(-1) = pi
}

int n;


int ConvecHull(Point *p,int n,Point* ch)
{
    sort(p,p+n);

    int m = 0;

    for (int i=0;i<n;i++)
    {
        while(m>1 && Cross( ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++] = p[i];
    }
    if( n > 1) m--;
    return m;
}
double PolygonArea(Point* p,int n)
{
    double area = 0;
    for(int i=1;i<n-1;i++)
    {
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2;
}
int main()
{
	ios::sync_with_stdio(false);
    Point P[MAXN];
    Point ch[MAXN];
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int  pc = 0;
        scanf("%d",&n);
        double x,y,w,h,j,ang;
        double area1= 0;
        REP(i,n)
        {
            scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&j);
            Point o(x,y);

            ang = -torad(j);
            P[pc++] = o + Rotate(Vector(-w/2,-h/2),ang);
            P[pc++] = o + Rotate(Vector(w/2,-h/2),ang);
            P[pc++] = o + Rotate(Vector(-w/2,h/2),ang);
            P[pc++] = o + Rotate(Vector(w/2,h/2),ang);

            area1+=w*h;
        }
        int  m = ConvecHull(P,pc,ch);
        double area2 = PolygonArea(ch,m);
        printf("%.1lf %%\n",area1*100/area2);
    }

	return 0;
}
