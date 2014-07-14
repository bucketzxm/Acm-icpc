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

int V[55];
int W[55];
int dp[505];
Point p[4];
int main()
{
	ios::sync_with_stdio(false);

    int cse = 0;
    int T;
    cin>>T;
    while(T--)
    {
        cout<<"Case "<<++cse<<":"<<endl;

        double a,b;
        REP(i,4)
        {
            cin>>a>>b;
            p[i].x= a; p[i].y=b;
        }
        cin>>a>>b;
        Point q(a,b);
        int flag = 1;
        double area1 = 0;

        for(int i=0;i<4;i++)
        {
            area1 += fabs(Cross(p[i]-q,p[(i+1)%4]-q))/2;
        }
        double area2 = fabs(Cross(p[1]-p[0],p[2]-p[0])/2)+fabs(Cross(p[2]-p[0],p[3]-p[0])/2);
        if(fabs(area1-area2)> 10e-6)
        {
            flag =0;
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                double area = fabs(Cross(q-p[i],q-p[(i+1)%4])/2);
                if( area < 10e-6)
                {
                   flag = 0;
                   break;
                }
            }
        }


        if( flag )
            cout<<"In"<<endl;
        else
            cout<<"No"<<endl;

    }

	return 0;
}





