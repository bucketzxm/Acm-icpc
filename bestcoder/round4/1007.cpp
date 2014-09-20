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

int n,m,w;
map<int,int> col;
map<int,int> row;
map<double ,int >W;
int main()
{
	//ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif

    int t;
    while(scanf("%d",&t)){
        printf("Case #%d:\n",t);
        scanf("%d%d%d",&n,&m,&w);

        for(int i=0;i<w;i++){
            int x,y,t;
            scanf("%d%d%d",&x,&y,&t);
            W[x*10e9+y] =t;
            row[x] = x;
            col[y] = y;
        }
        int T;
        scanf("%d",&T);
        for(int i=0;i<T;i++){

            int type, x,y;
            scanf("%d%d%d",&type,&x,&y);
            if( type == 1){
                row[x] = y;
                row[y] = x;
            }else if( type==2){
                col[x] = y;
                col[y] = x;
            }else if( type ==3){

                double d = row[x]*10e9+col[y];
                if( W.count(d) == 0){
                    printf("%d\n",0);
                }else{
                    printf("%d\n",W[d]);
                }
            }
        }
    }
	return 0;
}

