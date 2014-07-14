/***********************************
	Floyed 求所有点对最短路
	2014.3.1
***********************************/
#define REP(X,N) for(int X=0;X<N;X++)
#define INF 0x3FFFFFFF
#define MAXN 100
int G[MAXN][MAXN];

void Floyed()
{
	REP(k,MAXN)
	REP(i,MAXN)
	REP(j,MAXN)
	if(i!=j && i!=k && j!=k)
	{
		G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	}
}
