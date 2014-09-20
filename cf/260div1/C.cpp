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

ll n , k;
int alp[26];
string rec[26];
string all;
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif
    cin>>n>>k;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        int len = str.length();

        all.append(str);
        int tmp[26] ={0};
        for(int i=0;i<len;i++){
            int sz = all.find(str,i,len);
            if( sz == -1){
                alp[ str[i]-'a'] = len;
                rec[ str[i]-'a'] = str;
            }else{
                if( len > alp[str[i]-'a']){
                    alp[ str[i]-'a' ] = len;
                    rec[str[i]-'a' ] = str;
                }
            }
        }
    }

    for(int i=0;i<26;i++){
        if(alp[i]==0){
            continue;
        }
        if( alp[i]%2==0){
            alp[i]=-1;
        }else if(alp[i]%2==1){
            alp[i]=1;
        }
    }

    int one = 0, two = 0;
    for(int i=0;i<26;i++){
        if(alp[i] == -1) two ++;
        else if( alp[i] == 1) one++;
    }
    if(one>0 && two == 0 ){
        if( k%2==0)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }else if( one ==0 && two>0){
        cout<<"Second"<<endl;
    }else{
        cout<<"First"<<endl;
    }
	return 0;
}

