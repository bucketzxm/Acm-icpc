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


int N;
char Map[105][105];
int dp[105][105][4];
int dp2[105][105][4];
//0 - 1 | 2 left 3 right

int dx[] = {0,1,1,1};
int dy[] = {1,0,1,-1};

bool inmap(int x,int y)
{
    if( x>=1 &&x<=N &&y>=1 &&y<=N)
    {
        return true;
    }
    return false;
}

void update(int x,int y,int k)
{
    int ret = 0;
    int nx = x, ny = y;

    while(inmap(nx,ny) && Map[nx][ny]=='.')
    {
        ret++;
        dp2[nx][ny][k] = ret;
        nx += dx[k];
        ny += dy[k];
    }
    nx = x;ny = y;
    while(inmap(nx,ny) &&Map[nx][ny]=='.')
    {
        dp[nx][ny][k] = max( ret-dp2[nx][ny][k]+1, dp2[nx][ny][k]);
        nx+=dx[k];
        ny+=dy[k];
    }
}

int ty[] = {1,0,3,2};

int ans;

void gao2(int x,int y,int k)
{
    int nx= x, ny = y;
    while(inmap(nx,ny) && Map[nx][ny]=='.')
    {
        if( nx == x && ny==y)
        {
            ans = max( ans,  dp[nx][ny][k]+ dp[nx][ny][ty[k]]-1);
        }else{
            ans = max( ans,  dp[nx][ny][k]+ dp[nx][ny][ty[k]]-1);
        }
        nx+=dx[k];
        ny+=dy[k];
    }
}


void gao()
{

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if( Map[i][j]=='.')
            {
                for(int k=0;k<4;k++)
                {
                    ans = max(ans, dp[i][j][k]);
                    gao2(i,j,k);
                }
            }

        }

    }



}


void solve(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if( Map[i][j] == '.')
            {
                if( dp[i][j][0]==0)
                    update(i,j,0);
                if( dp[i][j][1]==0)
                    update(i,j,1);
                if( dp[i][j][2]==0)
                    update(i,j,2);
                if( dp[i][j][3]==0)
                    update(i,j,3);
            }
        }
    }
    gao();

//    for(int k=0;k<4;k++)
//    {
//        for(int i=1;i<=N;i++)
//        {
//            for(int j=1;j<=N;j++)
//            {
//                printf("%d ",dp[i][j][k]);
//            }
//            printf("\n");
//        }
//        printf("\n\n");
//    }
}

int main()
{
	//ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif

    while(scanf("%d\n",&N),N!=0){
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        ans = 0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                scanf("%c",&Map[i][j]);
            }
            getchar();
        }
        solve();

        printf("%d\n",ans);
    }


	return 0;
}


