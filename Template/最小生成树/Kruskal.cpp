
#define MAXN 100

//============================
// union-find
int pa[MAXN]; // parent
int ra[MAXN]; // rank
 
void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		pa[i] = i;
		ra[i] = 0;
	}
}

int find(int x)
{
	if(pa[x]!=x) pa[x] = find(pa[x]);
	return pa[x];
}

// 0: already united;  1: successfully united;
int unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return 0;
	if(ra[x] < ra[y])
	{
		pa[x] = y;
	}else{
		pa[y] = x;
		if(ra[x] == ra[y]) ra[x]++;
	}
	return 1;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}
//============================

struct Edge{
	int u, v;
	int l;
	Edge(){};
	Edge(int _u, int _v, int len):u(_u),v(_v),l(len){}
	bool operator<(const Edge &e) const
	{
		return this->l > e.l;
	}
}edge[MAXN*MAXN];
int e;

void addEdge(int u, int v, int len)
{
	edge[e++] = Edge(u, v, len);
}

int Kruskal(int n)
{
	init(n);
	priority_queue<Edge> q;
	for(int i = 0; i < e; i++)
		q.push(edge[i]);
	int ans = 0;
	int u,v;
	for(int i = 0; i < n-1; i++)
	{
		Edge e = q.top();
		while(same(e.u, e.v) && !q.empty())
		{
			q.pop();
			e = q.top();
		}
		unite(e.u,e.v);
		ans += e.l;
	}
	return ans;
}
