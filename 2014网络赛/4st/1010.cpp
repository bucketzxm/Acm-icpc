
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

int N,M;
int tMat[100][100];
int Mat[100][100];
int dx[500],dy[500];
int len;


void pre()
{
    len = 0;

    for(int i=1;i<=50;i++)
    {
        for(int j=0;j<=50;j++)
        {
            dx[len] = i;
            dy[len] = j;
            len++;
        }
    }

    for(int i=1;i<=50;i++)
    {
        for(int j=0;j<=50;j++)
        {
            dx[len] = j;
            dy[len] = i;
            len++;
        }
    }

}

bool inmap(int x,int y)
{
    if( x>=0 && x<N &&y>=0 && y<M)return true;
    return false;

}

int rope = 0;
void check(int x,int y,int k)
{
    int nx = x, ny = y;

    while( inmap(nx,ny) )
    {
        if( Mat[nx][ny] <= 0)return;

        nx-=dx[k]; ny-=dy[k];
        //cout<<"..."<<k<<" "<<dx[k]<<" "<<dy[k]<<" "<<nx<<ny<<endl;
    }
    nx+=dx[k] ; ny+=dy[k];


    while( inmap(nx,ny))
    {
        if( Mat[nx][ny] <= 0)
        {
            return;
        }
        nx+=dx[k]; ny+=dy[k];
    }
    nx-=dx[k];ny-=dy[k];

    int c = 0;
    while(inmap(nx,ny))
    {
        Mat[nx][ny]--;
        c++;
        nx-=dx[k];ny-=dy[k];
    }
    if(c>=3){
        cout<<x<<" "<<y<<" "<<dx[k]<<" "<<dy[k]<<endl;

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
            {
                if( Mat[i][j]>0)
                {
                    for(int k=0;k<len;k++ )
                    {
                        check(i,j,k);
                    }
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
            {
                cnt+=Mat[i][j];
            }
        }
        if( cnt>0){

            nx+=dx[k];ny+=dy[k];
            while(inmap(nx,ny))
            {
                Mat[nx][ny]++;
                c++;
                nx+=dx[k];ny+=dy[k];
            }

            return ;
        }
        else if(cnt==0)
            rope++;
    }
    return;
}



void solve()
{

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(Mat[i][j]>0)
            for(int k=0;k<len;k++)
            {
                    check(i,j,k);
                //cout<<i<<j<<k<<endl;
            }
        }
    }

}

void print()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout<<Mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


}


int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    int T;
    cin>>T;
    pre();


    while(T--)
    {
        cin>>N>>M;
        rope = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cin>>Mat[i][j];
            }
        }
        solve();
        print();
        cout<<rope<<endl;
    }


	return 0;
}
