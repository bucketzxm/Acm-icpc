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

typedef long long ll;
#define MAXN 100
int N,M;
int MM[MAXN][MAXN][MAXN];
int Map[MAXN][MAXN];


int C[MAXN][MAXN];

int main()
{
  //  ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    int tst= 0 ;

    while(scanf("%d%d",&N,&M)){
        if(N==0&&M==0)break;
        CLR(MM,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j)Map[i][j]=0;
                else Map[i][j] = INF;
            }
        }
        for(int i=0;i<N;i++){
        //mat tmp(M,vec(M));
        for(int j=0;j<M;j++){
            for(int q=0;q<M;q++){
                scanf("%d",&MM[i][j][q]);
             //   cout<<tmp[j][q]<<" ";
            }
           // cout<<endl;
        }
    }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j){
                    CLR(C,0);
                    for(int p=0;p<M;p++){
                        for(int q=0;q<M;q++){
                            for(int r=0;r<M;r++){
                                C[p][r] += MM[i][p][q]*MM[j][q][r];
                            }
                        }
                    }
                    for(int k=0;k<N;k++){
                        if(k==i  || k==j)continue;
                            int flag = 0;
                            for(int p=0;p<M;p++){
                                for(int q=0;q<M;q++){
                                    if( C[p][q] != MM[k][p][q]){
                                        flag =1;
                                        break;
                                    }
                                }
                                if(flag)break;
                            }
                            if(!flag )
                                Map[i][k] =1;
                    }
                }
            }
        }
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if( Map[i][j]>Map[i][k]+Map[k][j]){
                        Map[i][j] = Map[i][k]+Map[k][j];
                    }
                }
            }
        }
        int Q;
        scanf("%d",&Q);
        while(Q--){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            if( Map[a][b]<INF)printf("%d\n",Map[a][b]);
            else printf("Sorry\n");
        }
    }
    return 0;
}
