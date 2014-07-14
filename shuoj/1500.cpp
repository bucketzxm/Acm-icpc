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

#define MAXN 1000
int V[MAXN];
int W[MAXN];
int dp[MAXN];
int main()
{
	ios::sync_with_stdio(false);
    string str;
    int cse = 0;
    stack<int> s;
    queue<string> d;
    while(getline(cin,str))
    {
        cout<<"Case "<<++cse<<":"<<endl;
        d.push(str);
        while(str!="#")
        {
            getline(cin,str);
            d.push(str);
        }
        while(!d.empty())
        {
            stringstream iss( d.front());
            d.pop();
            string cmd;
            iss>>cmd;
            if(cmd=="PUSH")
            {
                int d;
                iss>>d;
                s.push(d);
            }
            if(cmd=="POP")
            {
                if(s.empty())
                {
                    cout<<"Error"<<endl;
                    break;
                }
                else
                {
                    int e = s.top();
                    s.pop();
                    cout<<e<<endl;
                }
            }
            if(cmd=="#")
            {
                break;
            }

        }
        while(!d.empty())
            d.pop();
        while(!s.empty())
        {
            s.pop();
        }
    }

	return 0;
}




