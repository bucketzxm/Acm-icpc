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
double gpa[105] ;
double dpMax[15][2000];
double dpMin[15][2000];

double max(double a,double b){
    if( a> b)return a;
    else return b;
}

double min(double a,double b){
    if( a< b)return a;
    else return b;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
        //freopen("out","w",stdout);
    #endif

    for(int i=60;i<=69;i++){
        gpa[i] = 2.0;
    }
    for(int i=70;i<=74;i++){
        gpa[i]= 2.5;
    }
    for(int i=75;i<=79;i++){
        gpa[i]= 3.0;
    }
    for(int i=80;i<=84;i++){
        gpa[i]= 3.5;
    }
    for(int i=85;i<=100;i++){
        gpa[i]= 4.0;
    }


    int T;
    cin>>T;
    int total;
    while(T--){
        int avg,n;
        cin>>avg>>n;
        total = n*avg;

        CLR(dpMax,0);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=total;j++){
                dpMin[i][j] = INF;
            }
        }
        for(int i=60;i<=100;i++){
            dpMax[1][i] = gpa[i];
            dpMin[1][i] = gpa[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i*60;j<=i*100;j++){
                for(int k=60;k<=100;k++){
                    if(j+k>total)break;
                    dpMax[i+1][j+k] = max(dpMax[i+1][j+k],dpMax[i][j] + gpa[k]);
                    dpMin[i+1][j+k] = min(dpMin[i+1][j+k],dpMin[i][j] + gpa[k]);
                }
            }
        }
        cout<<fixed<<setprecision(4)<<dpMin[n][total]/n<<" "<<dpMax[n][total]/n<<endl;
    }
	return 0;
}

