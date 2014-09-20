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


int block[200][200];
int n;
void vprint()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<block[i][j]<<" ";

    cout<<endl;
    }
}


int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
    //    freopen("in","r",stdin);
    #endif

    int T;
    cin>>T;
    while(T--){

        int color = 0;
        cin>>n;

        ++color;
        for(int i=0;i<n;i++){
            block[i][0] = color;
        }
        ++color;
        for(int i=1;i<n;i++){
            block[n-1][i] = color;
        }
        block[n-2][n-1] = 2;

        int line,row;
        line = n-1;
        for(int k=2;k<=n-4+1;k++){
           ++color;
          row = 0;
          for(int c = 0;c<n;c++){
            if( block[row][line] !=0){
                row -- ; line--;
                c--;
            }else{
                block[row][line] = color;
                row++;
            }
          }
        }

        ++color;
        for(int i=0;;i++){
            cout<<i<<" "<<line<<endl;
            while( block[i][line]==0){
                block[i][line] = color;
            }
            break;
        }
        vprint();
    }


	return 0;
}

