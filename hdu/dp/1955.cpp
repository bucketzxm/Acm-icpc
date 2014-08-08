#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//dp[i][j] 用a监狱的i个人换b监狱的j 个人是否可以
bool dp[300][300];
//map[a][b]=1　表示aｂ不能在一起
bool map[300][300];
bool vis[2][300];

int n, k;
void input()
{
    memset(map,0,sizeof(map));
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        map[a][b]=1;
    }
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));

}
void dfs(int u,int prison,int& as,int &bs)
{
    vis[prison][u] =1;
    if (prison == 0)
    {
        as ++ ;
        for(int i=1;i<=n;i++)
        {
            if( map[u][i] && !vis[1][i])
            {
                dfs( i,1,as,bs);
            }
        }
    }
    else if( prison==1)
    {
        bs++;
        for(int i=1;i<=n;i++)
        {
            if( map[i][u] && !vis[0][i])
            {
                dfs(i,0,as,bs);
            }
        }
    }
}

void package(int &as,int &bs)
{
    dp[0][0]=1;
    for(int i=n/2;i>=as;i--)
    {
        for(int j=n/2;j>=bs;j--)
        {
            dp[i][j] |= dp[i-as][j-bs];
        }
    }
}

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;

        input();


        for(int i=1;i<=n;i++)
        {

            int as= 0 ,bs= 0;
            if( !vis[0][i])
            {
                dfs( i , 0,as,bs);

                package(as,bs);
            }
        }
        for(int i=1;i<=n;i++)
        {
            int as=0,bs=0;
            if( !vis[1][i])
            {
                dfs(i,1,as,bs);
                package(as,bs);
            }
        }

        for(int i=n/2;i>=0;i--)
        {
            if( dp[i][i])
            {
                cout<<i<<endl;break;
            }
        }
    }

    return 0;
}
