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

int num[5];

int de[5];
int in[5];

int main()
{
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        CLR(de,0);
        CLR(in,0);
        REP(i,5)
        {
            cin>>num[i];
        }
        de[0] = 1;
        in[0] = 1;

        REP(i,5)
        {
            de[i] =1;
            in[i] = 1;
            REP(j,5)
            {
                if(num[j]>num[i])
                {
                    de[i] = max(de[i],de[j]+1);
                }

                if(num[j]<num[i])
                {
                    in[i] = max(in[i],in[j]+1);
                }
            }

        }
        int a1=0;
        REP(i,5)
        {
            a1 = max(a1,de[i]);
            a1 = max(a1,in[i]);
        }
        cout<<a1<<endl;

    }

	return 0;
}



