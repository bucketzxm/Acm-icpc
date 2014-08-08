#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m;
int p[1000000+10];

int dp[][];

void dfs(int l,int r,int tm)
{
    if( tm == 1)
    {
        int tmp = 0,ret = 0;
        for(int i=l;i<=r;i++)
        {
            if(tmp+p[i]<p[i])tmp=p[i];
            else
            {
                tmp+=p[i];
            }
            ret = max(ret ,tmp);
        }
        return ret;
    }




}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {

        for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&p[i]);
        //    p[i] = p[i-1]+t;
        }

        dfs(1,n,m);

    }

    return 0;
}
