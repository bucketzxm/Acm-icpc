#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MAX 1000
int map[MAX][MAX],path[MAX];
int visit[MAX],result[MAX];
struct cam
{
	int x1,x2,y1,y2;
}list[MAX];
int n;
int find(int a)
{
	int i;
	for(i=0;i<n;i++)
	if(!visit[i]&&map[a][i])
	{
		visit[i]=1;
		if(result[i]==-1||find(result[i]))
		{
			result[i]=a;
			return 1;
		}
	}
	return 0;
}
int solve()
{
	int i,ans;
	ans=0;
	memset(result,-1,sizeof(result));
	for(i=0;i<n;i++)
	{
		memset(visit,0,sizeof(visit));
		if(find(i))
		ans++;
	}
	return ans;
}
int main()
{
    freopen("in","r",stdin);
	int x1,x2,y1,y2,i,j,flag;
	int x,y;
	int cas=1,ans;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		scanf("%d%d%d%d",&list[i].x1,&list[i].x2,&list[i].y1,&list[i].y2);
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			for(j=0;j<n;j++)
			{
				if(x>list[j].x1&&x<list[j].x2&&y>list[j].y1&&y<list[j].y2)
				map[i][j]=1;
			}
		}
		ans=solve();
		flag=0;
		printf("Heap %d\n", cas++);
		if(ans==n)
		{
			for(i=0;i<n;i++)
			path[i]=result[i];
			for(i=0;i<n;i++)
			{
				map[path[i]][i]=0; //删边
				int d = solve();
			//	cout<<d<<endl;;
				if(d==n)  //再做一次二分匹配
				continue;
				else
				{
					if(flag)
					printf(" ");
					printf("(%c,%d)",'A'+i,path[i]+1);
				    flag=1;
				}
				map[path[i]][i]=1;
			}
		}
		if(!flag)
		printf("none");
		printf("\n\n");
	}
	return 0;
}

