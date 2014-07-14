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


int n,m;
int in[26];
int G[26][26];
int pt[26];
int p=0;
int topsort()
{
    int flag =0;
    CLR(pt,0);
    p=0;
    int cnt[26];
    REP(i,26)cnt[i]=in[i];
    int num=0;
    int rec= 0;
    REP(i,n)
    {
        num=0;
        REP(k,n)
        if( cnt[k]==0 )
        {
            num++;
            rec= k;
        }

        if ( num == 0)
            return 0;
//        cout<<rec<<" recrec "<<num<<endl;
        if(num>1)
            return -1;
        pt[p++] = rec;
  //      cout<<"ddd"<<rec<<endl;
        cnt[rec]=-1;
        REP(j,n)
        {
            if( G[rec][j])
            {
                cnt[j]--;
            }
        }
    }

    //cout<<"1111111111"<<endl;
    if(flag)return -1;
    //cout<<"2222"<<endl;
    return 1;
}
int main()
{
	ios::sync_with_stdio(false);

    while(cin>>n>>m)
    {
        CLR(G,0);
        CLR(in,0);
        cin.ignore();
        if(n==0)break;
        string str;
        int ret = 0;
        int flag = 1;
        REP(M,m)
        {
            cin>>str;
            if(!flag)continue;
            int a = str[0]-'A';
            int b = str[2]-'A';
            if( G[b][a])
            {
                cout<<"Inconsistency found after "<<M+1<<" relations."<<endl;
                flag = 0;
            }
            else
            {
                G[a][b]=1;
                in[b]++;
                ret = topsort();
                if( ret == 0)
                {
                    cout<<"Inconsistency found after "<<M+1<<" relations."<<endl;
                    flag = 0;
                }
                if(ret==1)
                {
                    cout<<"Sorted sequence determined after "<<M+1<<" relations: ";
                    REP(k,p)
                    {
                        cout<<char(pt[k]+'A');
                    }
                    cout<<"."<<endl;
                    flag= 0;
                }
            }
        }
        if(flag==1)
        {
            cout<<"Sorted sequence cannot be determined."<<endl;
        }
    }
	return 0;
}

