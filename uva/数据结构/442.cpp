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
struct mat{
    int row,line;
};
mat M[30];
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    int n;
    cin>>n;
    cin.ignore();

    REP(i,n){
        char alp; int r,l;
        cin>>alp>>r>>l;
        int d = alp-'A';
        M[d].row = r, M[d].line =l;
    }
    cin.ignore();
    strin   g exp;
    while(getline(cin,exp,'\n'))
    {
       // cout<<exp<<endl;
        int ans = 0;

        stack<mat> s;
        for(int i=0;i<exp.length();i++)
        {
            if( isalpha( exp[i]))s.push( M[exp[i]-'A']);

            if( exp[i] ==')')
            {
                mat b = s.top();s.pop();
                mat a = s.top();s.pop();
                if( a.line != b.row)
                {
                    ans =-1;break;
                }
                else
                {
                    ans+= a.row*a.line*b.line;
                    mat c  = a; c.line = b.line;
                    s.push(c);
                }
            }
        }

        if( ans ==-1)cout<<"error"<<endl;
        else{
                cout<<ans<<endl;
            }
    }


	return 0;
}

