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

int r,c;
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    int T;
    cin>>T;
    int cse = 0;
    while(T--){
        cout<<"Case "<<++cse<<": ";
        cin>>r>>c;
        cin.ignore();
        int  z= 0,o=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                char t;
                cin>>t;
                //cout<<t<<endl;
                if(t=='1')o++;
                else z++;
            }
            cin.ignore();
        }
        cout<<min(o,z)<<endl;
    }
	return 0;
}

