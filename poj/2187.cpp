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

struct Point{

    double x,y ;
    Point(double x = 0, double y = 0) : x(x),y(y){}
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Point A,Point B) {return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double p) { return Vector(A.x*p,A.y*p);}
Vector operator / (Vector A,double p) {return Vector(A.x/p,A.y/p);}

bool operator < (const Point& a, const Point &b){
    return a.x < b.x || (a.x== b.x && a.y<b.y);
}


const double eps = 1e-10;

int dcmp(double x)
{
    if( fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
bool operator == (const Point& a, const Point& b){
    return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y) == 0;
}

double Cross(Point A,Point B)
{
    return A.x*B.y-A.y*B.x;
}

#define MAXN 50005

Point P[MAXN],ch[MAXN];

int ConvexHull(Point* p, int n,Point* ch)
{
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++] = p[i];
    }
    if( n>1) m--;
    return m;
}
double Dot(Vector A,Vector B)
{
    return A.x*B.x+A.y*B.y;
}
//square dist
double dist(Point p,Point q)
{
    return Dot(p-q,p-q);
}

bool cmpx(Point p, Point q)
{
    if(p.x != q.x )return p.x<q.x;
    return p.y<q.y;
}
void solve(Point* P,int n,Point* ch)
{

    if( n==2)
    {
        cout<<fixed<<setprecision(0)<<dist(ch[0],ch[1])<<endl;
        return ;
    }
    double ans = 0;
//    int i=0,j=0;
//    for(int k=0;k<n;k++)
//    {
//        if( !cmpx(ch[i],ch[k]))i=k;
//        if( cmpx(ch[j],ch[k]))j=k;
//    }
//
//    int si = i,sj=j;
//    while(i!=sj || j!=si)
//    {
//        ans = max(ans, dist(ch[i],ch[j]));
//
//        if( Cross(ch[(i+1)%n]-ch[i], ch[(j+1)%n]-ch[j])<0)
//        {
//            i = (i+1)%n;
//        }
//        else
//        {
//            j = (j+1)%n;
//        }
//    }

    int q =1;
    for(int p = 0;p<n;p++)
    {
        while( fabs(Cross( ch[q]- ch[(p+1)%n] , ch[(p)]-ch[(p+1)%n] )) < fabs(Cross(ch[(q+1)%n]-ch[(p+1)%n],ch[p]-ch[(p+1)%n] )))
            q=(q+1)%n;
        ans = max( ans, max(dist(ch[p],ch[q]),dist(ch[(p+1)%n],ch[q])));
    }
    cout<<fixed<<setprecision(0)<<ans<<endl;
}


int main()
{
	ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        REP(i,n)
        {
            cin>>P[i].x>>P[i].y;
        }
        int m = ConvexHull(P,n,ch);
        solve(P,m,ch);
    }
	return 0;
}
