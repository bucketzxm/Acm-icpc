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
const double eps = 10e-9;

int dcmp(double x)
{
    if( fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
bool operator < (const Point& a, const Point &b){
    return a.x < b.x || (a.x== b.x && a.y<b.y);
}
bool operator == (const Point& a,const Point &b)
{
    return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y)==0;
}

double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
double Dot(Vector A,Vector B)
{
    return A.x*B.x+A.y*B.y;
}

#define MAXN 1005
Point P[MAXN],ch[MAXN];

bool OnSegment(Point p,Point a1,Point a2)
{
//    cout<<Cross(a1-p,a2-p)<<endl;
//    cout<<Dot(a1-p,a2-p)<<endl;
//    cout<<dcmp(Dot(a1-p,a2-p))<<endl;
//    cout<<endl;
    if( p==a1 || p == a2) return -1;
    return dcmp(Cross(a1-p,a2-p))==0 && dcmp(Dot(a1-p,a2-p))<0;
}

int isPointInPolygon(Point o,Point* p,int n)
{
    int wn =0 ;
    for(int i=0;i<n;i++)
    {
        if( OnSegment(o,p[i],p[(i+1)%n])) return -1;
        //cout<<i<<" "<<p[(i+1)%n].x<<endl;
       // cout<<Cross(p[(i+1)%n]-p[i],o-p[i])<<endl;
        int k=dcmp(Cross(p[(i+1)%n]-p[i],o-p[i]));
        int d1 = dcmp( p[i].y-o.y);
        int d2 = dcmp( p[(i+1)%n].y-o.y );
        //cout<<k<<" "<<d1<<" "<<d2<<endl;

        if( k> 0 && d1<=0 && d2>0)
        {
            wn++;
        }
        if( k<0 && d2<=0 && d1>0)
        {
            wn--;
        }
    }
        if( wn!=0)return 1;//inside;
        return 0; //outside;
}


int main()
{
	ios::sync_with_stdio(false);
    int cse = 0;
	int n;
    //cout<<OnSegment(Point(0,0.5),Point(0,0),Point(0,1));
	while(cin>>n)
    {
        cout<<"Case "<<++cse<<":"<<endl;
        REP(i,n)
        {
            cin>>P[i].x>>P[i].y;
        }

        Point o;
        cin>>o.x>>o.y;
        int ans = isPointInPolygon(o,P,n);
       // int ans = 0;
      // cout<<ans<<endl;
        if( ans == 0 || ans==-1)
            cout<<"No!"<<endl;
        else
            cout<<"Yes!"<<endl;

    }
	return 0;
}

