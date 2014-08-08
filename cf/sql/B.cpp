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

struct point
{
    int x,y;

};
point P[8];
int n,m;
double dist(int a,int b)
{
    double e = (P[a].x-P[b].x)*(P[a].x-P[b].x)+(P[a].y-P[b].y)*(P[a].y-P[b].y);
    return sqrt(e);
}

double ans = 0;
int a1,a2,a3,a4;

bool c2(int d)
{
    if( P[d].x>=0 &&P[d].x<=n && P[d].y>=0 &&P[d].y<=m)return true;
    return false;
}
bool c3(int a,int b)
{
    if(P[a].x==P[b].x && P[a].y==P[b].y)return true;
    else return false;
}
void check(int a,int b,int c,int d)
{
    if(c2(a)==false || c2(b)==false || c2(c)==false || c2(d)==false)return ;

    if( c3(a,b) || c3(a,c)|| c3(a,d) || c3(b,c) || c3(b,d) || c3(c,d))return;




    double f= 0;

    f+=dist(a,b)+dist(b,c)+dist(c,d);

    if( f+10e-8> ans)
    {
        ans = f+10e-8;
        a1 =a ; a2 = b; a3 =c ;a4 =d;
    }
}

int main()
{
	ios::sync_with_stdio(false);

    cin>>n>>m;

    P[0].x = 0; P[0].y =0;
    P[1].x = n; P[1].y = m;
    P[2].x = n; P[2].y = 0;
    P[3].x = 0 ; P[3].y = m;
    P[4].x  = n-1;P[4].y =0;
    P[5].x = n; P[5].y=1;
    P[6].x = 0;P[6].y = m-1;
    P[7].x = 1;P[7].y=m;


    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            for(int p=0;p<8;p++)
            {
                for(int q=0;q<8;q++)
                {
                    if(i==j || i==p || i==q || j==p || j==q || p==q)continue;
                    check(i,j,p,q);
                }
            }
        }
    }
   // cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
    cout<<P[a1].x<<" "<<P[a1].y<<endl;

    cout<<P[a2].x<<" "<<P[a2].y<<endl;

    cout<<P[a3].x<<" "<<P[a3].y<<endl;

    cout<<P[a4].x<<" "<<P[a4].y<<endl;

	return 0;
}




