
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
    double sp;
    int id;
    bool ck;
    Point(double x = 0, double y = 0,double sp=0,int id=0,bool ck=true) : x(x),y(y),sp(sp),id(id),ck(ck){}
};

typedef Point Vector;
int n;
Point p[600],ch[600];
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

//Í¹°ü
int ConvexHull(Point* p, int n,Point* ch)
{
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1 && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0)m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0) m--;
        ch[m++] = p[i];
    }
    if(n>1) m--;
    return m;
}

bool cmp(Point a,Point b){
    return a.sp>b.sp;
}
bool cmp2(Point a,Point b){
    return a.id<b.id;
}

int cse = 0;
int main()
{
	ios::sync_with_stdio(false);
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    while(cin>>n){
        if(n==0)break;
        cout<<"Case #"<<++cse<<": ";
        memset(p,0,sizeof(p));
        memset(ch,0,sizeof(ch));
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y>>p[i].sp;
            p[i].id = i;
            p[i].ck = true;
        }
        sort(p,p+n,cmp);

        if(p[0].sp == 0){
            for(int i=0;i<n;i++){
                cout<<0;
            }
            cout<<endl;
            continue;
        }

        int nn = 1;
        while(p[nn].sp==p[nn-1].sp){
            nn++;
        }
        int d = ConvexHull(p,nn,ch);
        sort(ch,ch+d,cmp2);

        int pp =0 ;
        for(int i=1;i<d;i++){
            if( ch[pp].id != ch[i].id){
                pp++;
                ch[pp] = ch[i];
            }
        }
        d = pp+1;
        for(int i=0;i<d;i++){
            for(int j=i+1;j<d;j++){
                if( ch[i].x==ch[j].x && ch[i].y==ch[j].y){
                    ch[i].ck = false; ch[j].ck=false;
                    //cout<<i<<"xxx "<<j<<endl;
                }
            }
        }

        int pch=0;
        for(int i=0;i<n;i++){
            while(pch<d && ch[pch].ck == false)pch++;
            if(pch<d && i ==ch[pch].id ){
                cout<<1;
                pch++;
            }else{
                cout<<0;
            }
        }
        cout<<endl;


    }

	return 0;
}

