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
#define num 30000
double lml;
double a[num];
int main()
{

    int k=1;
    int flag;
    int t=1024;
    while(cin>>lml)
    {
        t=1024;
        cout<<"Case "<<k++<<": "<<setprecision(8)<<lml<<", ";
        a[0]=0.5;
        for(int i=1;i<30000;i++)
        {
                a[i]=lml*a[i-1]*(1-a[i-1]);
        }

        int i=20000;
        for(int j=i+1;j<i+1024;j++)
        {
                if(fabs(a[j]-a[i])<=1e-8)
                {
                    flag=0;
                    for(int k=1;k<j-i;k++)
                    {
                        if(fabs(a[i+k]-a[k+j])>=1e-6)
                            flag=1;
                    }
                    if(!flag)t=min(t,j-i);
                }
        }
        if(t<1024) cout<<t<<endl;
        else cout<<"-1"<<endl;
   }
   return 0;
}

