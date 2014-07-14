
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

int main()
{
	ios::sync_with_stdio(false);

    string str;
    while(cin>>str)
    {
        int len = str.length();
        int flagz = -1,flagj = -1;
        REP(i,len)
        {
            if( str[i] == 'z')
            {
                flagz = i;break;
            }
        }
        REP(i,len)
        {
            if(str[i] == 'j'){flagj = i; break;}
        }
        if( flagz ==-1 ||flagj == -1){cout<<"Wrong Answer"<<endl;continue;}

        int a=0,b=0,c=0;
        int flag = true;
        REP(i,flagz)
        {
            if( str[i] !='o')
            {
                flag = false;break;
            }
            a++;
        }
        REP2(i,flagz+1,flagj-1)
        {
            if( str[i] !='o')
            {
                flag = false; break;
            }
            b++;
        }
        REP2(i,flagj+1,len-1)
        {
            if( str[i] !='o')
            {
                flag = false; break;
            }
            c++;
        }
        if( !flag){cout<<"Wrong Answer"<<endl;continue;}
        if( flagj-flagz>>1)
            if( a*b == c)cout<<"Accepted"<<endl;
            else
            {
                cout<<"Wrong Answer"<<endl;
            }
        else
        {
            cout<<"Wrong Answer"<<endl;
        }
    }
	return 0;
}

