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
#include <cmath>
using namespace std;
int row,line;
int G[21][21];
int sx,sy,fx,fy;
struct P
{
    int x,y;
    int step;
    int M[21][21];
    P(){}
    P(int _x,int _y,int _step):
        x(_x),y(_y),step(_step){}
};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
#define INF 10000
int ans = INF;
int flag = 0;
int dfs(int x,int y,int step)
{
   if(step> ans  || step>10)return 0;
    for(int i=0;i<4;i++)
    {
        flag = 0;
        int nx=x,ny=y;
        while(G[nx][ny] !=1)
        {
            nx += dx[i], ny+=dy[i];
            if(nx<0 || nx>=row ||ny<0 ||ny>=line)
            {
                flag = 1;
                break;
            }
            if(G[nx][ny]==3)
            {
                ans = min(ans,step+1);
                return 0;
            }
        }
        if(abs(nx-x)+abs(ny-y)>1&&!flag)
        {
            G[nx][ny] =0;
            dfs( nx-dx[i], ny-dy[i] , step+1 );
            G[nx][ny] =1;
        }
    }
    return 1;
}
int main()
{
    //freopen("IN","r",stdin);
    while(scanf("%d%d",&line,&row)!=EOF)
    {
        if(line==0)break;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<line;j++)
            {
                scanf("%d",&G[i][j]);
                if(G[i][j] == 2)
                {
                    sx = i ; sy = j;
                }
            }
        }
       G[sx][sy] =0;
         dfs(sx,sy,0);
        if(ans>10)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
        ans =INF;
    }
    return 0;
}
