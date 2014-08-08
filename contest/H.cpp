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

#define PI acos(-1)
double A,B,AB;
double ra,rb,d;
double W,H;
void solver()
{
    ra = sqrt( A/PI);
    rb = sqrt(B/PI);
    d = sqrt(  (H-ra-rb)*(H-ra-rb)+ (W-ra-rb)*(W-ra-rb)  );
}

bool C(double x)
{
    double bt = acos((rb*rb+x*x-ra*ra)/(2*rb*x));
    double at = acos((ra*ra+x*x-rb*rb)/(2*ra*x));
    double tsb = rb*rb*cos(bt)*sin(bt);


    double ret1 = bt*rb*rb - tsb;

    double tsa = ra*ra*cos(at)*sin(at);

    double ret2 = at*ra*ra - tsa;
    cout<<"..."<<x<< " "<< ret1+ret2<< " "<< AB<<endl;
    if( ret1+ ret2 - AB > 10e-5)return true;
    else
        return false;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    while(cin>>W>>H)
    {
        if( W==0 && H==0)break;

        cin>>A>>B>>AB;
        solver();
        double left = 0 ,  right = d;
        double mid ,ans;
        while( right - left > 10e-5)
        {
            mid = (left + right)/2;
            //cout<<mid<<endl;
            if( C(mid))
            {
                right = mid;
                ans = right;
            }
            else
            {
                left =mid;
            }
        }
       // cout<<ra<<" "<<rb<<" "<<ans<<endl;
        if( fabs(ans-AB)> 10e-5)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<ra<<" "<<rb<<endl;
        }
    }
	return 0;
}

