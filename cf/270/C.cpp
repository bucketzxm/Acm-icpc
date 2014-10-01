
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

int p[100000+10];
string test[100000+10];
struct N{

    string xing,ming;
    int id;
};

N name[100000];

bool cmp(N a,N b){
    return a.id<b.id;
}
bool cmp2(string a,string b){
    return a<b;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in","r",stdin);
    #endif

    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string a,b;
        cin>>name[i].xing>>name[i].ming;
        test[i] = name[i].xing;
    }
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        name[t-1].id = i;
    }
    sort( name,name+n,cmp);
    test[0] = min( name[0].xing , name[0].ming);

    int flag = 0;
    for(int i=1;i<n;i++){

       string Min =  min ( name[i].xing, name[i].ming );

       string Max =  max ( name[i].xing, name[i].ming );
       if ( Min > test[i-1]){
            test[i] = Min;
       }
       else if (Max >test[i-1])
       {
           test[i]= Max;
       }
       else
       {
           flag = 1;break;
       }


    }

    if( flag )cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
	return 0;
}

