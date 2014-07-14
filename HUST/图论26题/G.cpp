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

char org[50];
int p=0;

int G[26][26];
int in[26];

char ans[26];
int vis[26];
void dfs(int i)
{
    if( i == p)
    {
        REP(j,p)
            cout<<ans[j];
        cout<<endl;
        return;
    }
    REP(j,p)
    {
        int judge= false;
        if( !vis[org[j]-'a'])
        {
            ans[i] = org[j];
            for(int r = i;r>=0;r--)
            {
                for(int q = 0;q<r;q++)
                {
                    if( G[ ans[r]-'a'][ans[q]-'a'])
                    {
                        judge = true;
                        break;
                    }
                }
            }
            if( !judge)
            {
                vis[org[j]-'a'] = 1;
                dfs(i+1);
                vis[org[j]-'a'] = 0;
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
    string str;
    int cse = 0;
    while(getline(cin,str,'\n'))
    {
        p = 0;
        CLR(org,0);
        CLR(G,0);CLR(vis,0);CLR(ans,0);
        for(int i=0;i<str.length();i+=2)
        {
                org[p++] = str[i];
        }
        getline(cin,str,'\n');
        for(int i=0;i<str.length();i+=4)
        {
            int x = str[i]-'a', y = str[i+2]-'a';
            G[x][y] = 1;
        }
        REP(k,p)
        {
            REP(i,p)
            {
                REP(j,p)
                    if( G[org[i]][org[k]] && G[org[k]][org[j]]) G[org[i]][org[j]] =1;
            }
        }
        sort(org,org+p);
        if( cse ++)
            cout<<endl;
        dfs(0);


    }
	return 0;
}

