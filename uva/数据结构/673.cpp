
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

bool check(char a, char b)
{
    return a=='('&&b==')' || a=='['&&b==']';
}
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    int T;
    cin>>T;
    cin.ignore();

    char q[1000];
    int pq=0;
    string tex;
    while(T--)
    {
        pq=0;
        getline(cin,tex);
        //cout<<tex<<endl;
        for(int i=0;i<tex.length();i++)
        {
            q[pq++] = tex[i];
            while( pq>1 && check(q[pq-2],q[pq-1]))
            {
                pq-=2;
            }


        }
        if(pq==0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }


    }
	return 0;
}
