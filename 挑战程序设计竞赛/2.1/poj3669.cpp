#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include <deque>
#include <map>
#include <set>
#include <cstring>
using namespace std;
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
struct P
{
    int x,y;
    int time;
    P(){}
    P(int _x,int _y,int _time):
        x(_x),y(_y),time(_time){}
};
int G[500][500][1];
int dx[]= {0,1,-1,0,0};
int dy[] = {0,0,0,1,-1};
int vis[500][500];
inline bool inmap(int x,int y)
{
    if(x>=0  && y>=0)
        return true;
    return false;
}
int tmax=0;
void bfs()
{
    queue<P> que;
    que.push(P(0,0,0));
    vis[0][0] =1;
    if(G[0][0][0] <= 0)
    {
        cout<<"-1"<<endl;
        return;
    }
    while(!que.empty())
    {
        P now = que.front(); que.pop();
        if(G[now.x][now.y][0] ==-1)
        {
            cout<<now.time<<endl;
            return;
        }
        int t = now.time;
        for(int i=1;i<5;i++)
        {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if(nx>=0 && ny>=0)
            {
                int &boom = G[nx][ny][0];
                if( (t+1<boom || boom == -1) && !vis[nx][ny])
                {
                    vis[nx][ny] =1;
                    que.push(P(nx,ny,t+1));
                }
            }
        }
    }
    cout<<"-1"<<endl;
    return;
}
int main()
{
   // freopen("IN","r",stdin);
    int M;
    memset(G,-1,sizeof(G));
    ios::sync_with_stdio(false);
    cin>>M;
        for(int i=0;i<M;i++)
        {
            int x,y,t;
            cin>>x>>y>>t;
            tmax = max(tmax,t);
            for(int i=0;i<5;i++)
            {
                int nx = x+dx[i], ny = y +dy[i];
                if(nx>=0 && ny>=0)
                G[nx][ny][0] = (G[nx][ny][0]==-1)?t:min(G[nx][ny][0],t);
            }
        }
        bfs();

    return 0;
}
