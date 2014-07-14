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

int N;
int num[20];
int id[20];
int ans[20][20];
bool cmp(int a,int b)
{
    if( num[a]== num[b])
    {
        return a<b;
    }
    return num[a]>num[b];
}

int main()
{
	ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--)
    {
        CLR(ans,0);
      cin>>N;
      REP(i,N)
      {
        cin>>num[i];
        id[i] = i;
      }

      sort(id,id+N,cmp);
      int flag = 0;
      for(int i=0;i<N;i++)
      {
          for(int j=1;j<=num[id[0]];j++)
          {
              num[id[j]] --;
              if(j>=N || num[id[j]] <0 )
              {
                    flag = 1;
                    break;
              }
              else
              {
                  ans[id[0]][id[j]]=1;
                  ans[id[j]][id[0]]=1;
              }
          }
          num[id[0]] = 0;
          if( flag )break;
          sort(id,id+N,cmp);
      }
      if( flag )cout<<"NO"<<endl;
      else
      {
          cout<<"YES"<<endl;
          REP(i,N)
          {
              REP(j,N)
              {
                  cout<<ans[i][j]<<" ";
              }
              cout<<endl;
          }
      }
      if(T)
      cout<<endl;
    }

	return 0;
}

