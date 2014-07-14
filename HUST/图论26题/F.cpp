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

int G[4][4];

int dx[] = {0,1};
int dy[] = {0,1};
int Map[10][10];

int in[10];
void PRT()
{

    REP2(i,1,9)
    {

        REP2(j,1,9)
        {
            cout<<Map[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"rudu"<<endl;
    REP2(i,1,9)
    {
        cout<<in[i]<<endl;
    }
    cout<<endl<<endl;

}
bool topsort()
{
    int tmp[10][10];
    int tin[10];
    REP2(i,0,9)
    {
        tin[i]= in[i];
    REP2(j,0,9)
    {
        tmp[i][j]=Map[i][j];
    }
    }
    int cnt = 0;


    for(int q=1;q<=9;q++)
    for(int i=1;i<=9;i++)
    {
        if( tin[i] ==0)
        {
            for(int j=1;j<=9;j++)
            {
                if( tmp[ i ][ j ] )
                {
                    tin[j]--;
                    tmp[i][j]=0;
                }
            }
        }
    }
   // PRT();
    for(int i=1;i<=9;i++)
    {
        if( tin[i] !=0)
            return true;
    }

    return false;
}

bool check()
{

    int cnt = 0;
    for(int x = 0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            cnt++;
            REP(i,2)
            {
                REP(j,2)
                {
                    int ax = x+dx[i],ay = y+dy[j];
                    if(G[ax][ay] != cnt)
                    {
                        if( Map[cnt][G[ax][ay]]==0)
                            in[ G[ax][ay] ]++;
                        Map[ cnt ][ G[ax][ay] ]=1;
                        //cout<<" give "<<x<<" "<<y<<"  "<<cnt<<" "<<G[ax][ay]<<endl;

                       // PRT();
                        bool ret = topsort();
                        if( ret )
                            return false;

                    }
                }
            }
        }
    }
    return true;

}

int main()
{
	ios::sync_with_stdio(false);

    string start,ed;
    while(cin>>start)
    {
        CLR(Map,0);
        CLR(in,0);
        CLR(G,0);
        if( start == "ENDOFINPUT")break;
        REP(i,4)REP(j,4)cin>>G[i][j];
        cin.ignore();
        cin>>ed;
        bool ok = check();
        if( ok )
        {
            cout<<"THESE WINDOWS ARE CLEAN"<<endl;
        }
        else
        {
            cout<<"THESE WINDOWS ARE BROKEN"<<endl;
        }
    }

	return 0;
}

