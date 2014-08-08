
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

string a,b;
int aph[26];
int bph[26];
int check()
{
        int lena= a.length();
        int lenb= b.length();
        for(int i=0;i<lena;i++)
        {
            aph[ a[i]-'a'] ++;
        }
        for(int i=0;i<lenb;i++)
        {
            bph[ b[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if( aph[i] <bph[i]){return 0;}
        }
        return 1;
}
bool check2()
{
    int lena = a.length();
    int lenb = b.length();

    int i=0,j=0;
    while( j< lenb)
    {
        if( i>=lena)break;

        if( a[i]==b[j])
        {
            j++;
        }
        i++;
    }
    //cout<<i<<" "<<lena<<endl;
    if(j==lenb)
    {
        return 1;
    }
    return 0;

}
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif
    cin>>a>>b;

    if( check2() )
    {
        cout<<"automaton"<<endl;
        return 0;
    }
    else
    {
        int lena= a.length();
        int lenb= b.length();
        for(int i=0;i<lena;i++)
        {
            aph[ a[i]-'a'] ++;
        }
        for(int i=0;i<lenb;i++)
        {
            bph[ b[i]-'a']++;
        }
        int flag =1;
        for(int i=0;i<26;i++)
        {
            if( aph[i] !=bph[i]){flag = 0;break;}
        }

        if( flag) {cout<<"array"<<endl;return  0;}
    }
    CLR(aph,0);
    CLR(bph,0);
        if (check())
        {
            cout<<"both"<<endl;
            return 0;
        }

    cout<<"need tree"<<endl;

	return 0;
}
