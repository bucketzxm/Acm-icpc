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

stack <int> s;
int st[1005];
int main()
{
	ios::sync_with_stdio(false);

    int n;
    while(cin>>n)
    {
        while(!s.empty())
            s.pop();
        int t;
        REP(i,n)
        {
            cin>>st[i];
        }
        int now = n;
        int flag = 1;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty()&&s.top()==now)
            {
                s.pop();now--;
            }
            if( st[i]!=now)
            {
                if(!s.empty()&& st[i]<s.top())
                {
                    flag =0;break;
                }
                s.push(st[i]);
            }
            else
            {
                now--;
            }
        }
        if( flag )cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}


