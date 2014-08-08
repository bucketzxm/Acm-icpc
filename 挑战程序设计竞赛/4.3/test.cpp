#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N=5100;

vector<int>map[N];
vector<int>map1[N];

bool used[N];

int d[N],id[N],path[N];
int a[N][2],b[N][2];
int m,n,cnt,color;

void Init()
{
     for(int i=0;i<4*n;i++)
     {
          map[i].clear();
          map1[i].clear();
     }
}

void addedge(int from,int to)
{
     map[from].push_back(to);
     map1[to].push_back(from);
}

void build_map(int mid)                                                                                                         //根据二分的mid值来建图
{
    int i,j,u,v;
    Init();
    for(i=0;i<n;i++)
    {
        u=a[i][0];
        v=a[i][1];
        addedge(u,v+2*n);
        addedge(v,u+2*n);
    }
    for(i=0;i<mid;i++)                                                                                                         //由于门是要按照前后顺序来打开的
    {
        u=b[i][0];
        v=b[i][1];
        addedge(u+2*n,v);
        addedge(v+2*n,u);
    }
}

void dfs1(int u)
{
     used[u]=true;
     for(int i=0;i<map[u].size();i++)
       if(!used[map[u][i]])
          dfs1(map[u][i]);
     path[cnt++]=u;
}

void dfs2(int u)
{
     used[u]=true;
     id[u]=color;
     for(int i=0;i<map1[u].size();i++)
      if(!used[map1[u][i]])
        dfs2(map1[u][i]);
}

bool sat()
{
     int i;
     memset(used,0,sizeof(used));
     color=cnt=0;
     for(i=0;i<4*n;i++)
      if(!used[i])
        dfs1(i);
     memset(used,0,sizeof(used));
     for(i=cnt-1;i>=0;i--)
      if(!used[path[i]])
      {
         color++;
         dfs2(path[i]);
      }
     for(i=0;i<2*n;i++)
      if(id[i]==id[i+2*n])
        return 0;
     return 1;
}

bool Judge(int mid)                                                                                                         //判断根据mid值所建的图是否存在可行解
{
     build_map(mid);
     if(sat())
        return true;
     else
        return false;
}



int main()
{
     #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    int i,mid,res,right,left;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         if(n==0&&m==0)
            break;
         for(i=0;i<n;i++)
            scanf("%d%d",&a[i][0],&a[i][1]);
         for(i=0;i<m;i++)
            scanf("%d%d",&b[i][0],&b[i][1]);
         left=res=0; right=m;
         while(left<=right)                                                                                                //二分求解
         {
               mid=(left+right)/2;
               if(Judge(mid))                                                                                              //存在可行解,说明该解还可能更大
               {
                    res=mid;
                    left=mid+1;
               }
               else
                    right=mid-1;
         }
         printf("%d\n",res);
    }
    //system("pause");
    return 0;
}
