
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

double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){ return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){ return acos(Dot(A,B))/Length(A)/Length(B);}

double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}

//red 弧度 逆时针旋转
Vector Rotate(Vector A,double rad)
{
    return Vector( A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

//求法向量，确保A不是零向量
Vector Normal(Vector A)
{
    double L = Length(A);
    return Vector(-A.y/L,A.x/L);
}


int main()
{
	ios::sync_with_stdio(false);

	return 0;
}

