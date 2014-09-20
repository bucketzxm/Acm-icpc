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

int n;
int ans;

void clean(int hurt,priority_queue<int,vector<int> ,greater<int> >& even,priority_queue<int,vector<int>,greater<int> >& odd){
    while(!even.empty() && even.top()-hurt<=0){
        even.pop();
    }
    while(!even.empty() &&odd.top()-hurt<=0){
        odd.pop();
    }
}

void dfs(int turn,int hurt,priority_queue<int,vector<int> ,greater<int> >& even,priority_queue<int,vector<int>,greater<int> >& odd){
    if( odd.empty() && even.empty()){
        return;
    }
//    cout<<hurt<<" ";
//    if(!odd.empty())
//        cout<<"odd "<<odd.top()<<" ";
//    if(!even.empty())
//        cout<<"even "<<even.top()<<" ";
//    cout<<endl;

    if( odd.empty()){
        int f = even.top();even.pop();
        //f-=hurt;
        if(f-hurt-1>0)
            odd.push(f-1);
        clean(hurt,even,odd);
        dfs(1-turn,hurt+1,odd,even);
    }else{
        int f = odd.top(); odd.pop();
        if( f-hurt == 1){
            ans++;
            clean(hurt,even,odd);
            dfs(1-turn,hurt+1,odd,even);
        }else{
            if(f-hurt-1>0)
                even.push(f-1);
            clean(hurt,even,odd);
            dfs(1-turn,hurt+1,odd,even);
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
       // freopen("out","w",stdout);
    #endif

    int t;
    cin>>t;
    int cse = 0;
    while(t--){
        int pe = 0, po = 0;
        cin>>n;
        cout<<"Case #"<<++cse<<": ";
        priority_queue<int,vector<int> ,greater<int> > even;
        priority_queue<int,vector<int>,greater<int> > odd;

        REP(i,n){
            int num;cin>>num;
            if( num %2 == 0){
                even.push(num);
            }else{
                odd.push(num);
            }
        }

        ans = 0;

        int hurt = 0;
        dfs(1,hurt,even,odd);
        cout<<ans<<endl;
    }

	return 0;
}

