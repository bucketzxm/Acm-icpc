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
//
//map<string,int> card = {"3":3,"4":4,"5":5,"6":6,"7":7,"8":8,"9":9,"T":10,"J":11
//        , "Q":12,"K":13,"A":14,"2":15,"X":16,"Y":17 };
int me[20],he[20];
void input(){
    char str[100];
    cin>>str;
    int len = strlen(str);
    for(int i=0;i<len;i++){
        if( str[i] == 'T')me[10]++;
        if( str[i] == 'J')me[11]++;
        if( str[i] == 'Q')me[12]++;
        if( str[i] == 'K')me[13]++;
        if( str[i] == 'X')me[16]++;
        if( str[i] == 'Y')me[17]++;
        if( str[i] =='A') me[14]++;
        if(str[i]=='2')me[15]++;
        if( str[i]>='3'&& str[i]<='9') me[ str[i]-'0'] ++;

    }
    cin>>str;
    len = strlen(str);
    for(int i=0;i<len;i++){
        if( str[i] == 'T')he[10]++;
        if( str[i] == 'J')he[11]++;
        if( str[i] == 'Q')he[12]++;
        if( str[i] == 'K')he[13]++;
        if( str[i] == 'X')he[16]++;
        if( str[i] == 'Y')he[17]++;
        if( str[i] =='A') he[14]++;
        if( str[i] =='2') he[15]++;
        if( str[i]>='3'&& str[i]<='9') he[ str[i]-'0'] ++;
    }
    return ;

}

int w1(){
    int cnt = 0;
    for(int i=17;i>=3;i--){
        if( me[i]>0)cnt+=me[i];
    }
    if(cnt==1)return 1;
    for(int i=17;i>=3;i--){
        if( me[i]>0)return 1;
        else if( he[i]>0 && me[i]==0)return -1;
    }
    return -1;
}

int w2(){

    int pair = 0,cnt=0;
    for(int i=17;i>=3;i--){
        if( me[i]>=2){
            pair++;
        }
        cnt+=me[i];
    }
    if(cnt==2 && pair==1)return 1;

    for(int i=17;i>=3;i--){
        if( me[i] >= 2 )return 1;
        else if( he[i]>=2 && me[i]<2)return -1;
    }
    return -1;
}


int w3(){
    int pair = 0,cnt=0;
    for(int i=17;i>=3;i--){
        if( me[i]>=3){
            pair++;
        }
        cnt+=me[i];
    }
    if(cnt==3 && pair==1)return 1;

    for(int i=17;i>=3;i--){
        if( me[i] >= 3)return 1;
        else if( he[i]>=3 && me[i]<3)return -1;
    }
    return -1;
}
int w4(){

    int pair = 0,cnt=0;
    int ma = 0,mb = 0,ha = 0,hb = 0;
    for(int i=17;i>=3;i--){
        if( me[i] ==3)pair++;
        cnt+=me[i];
        if(me[i]>=3){
            for(int j=17;j>=3;j--){
                if( me[j]>=1 && j!=i){
                    ma = i ; mb = j;
                    break;
                }
            }
            if( mb ==0)return -1;
            break;
        }
    }
    if( pair==1 && cnt == 4)return 1;

    for(int i=17;i>=3;i--){
        if(he[i]>=3){
            for(int j=17;j>=3;j--){
                if( he[j]>=1 && j!=i){
                    ha = i ; hb = j;
                    break;
                }
            }
            if( hb ==0)return 1;
            break;
        }
    }
    if(ma==0)return -1;
    if( ma>=ha)return 1;
    else if( ma==ha && mb >= hb)return 1;
    return -1;

}

int w5(){
    int ma = 0,mb = 0, ha=0,hb=0;
    int pair = 0, cnt = 0;
    for(int i=17;i>=3;i--){
        cnt+=me[i];
        if ( me[i] >=3 ){
            if( me[i] == 3)pair++;
            ma = max(ma, i);
            for(int j=17;j>=3;j--){
                if( i!=j && me[j]>=2){
                    mb = max(mb, j);
                }
            }
        }
    }
    if( pair == 1 && cnt ==5){
        return 1;
    }
    for(int i=17;i>=3;i--){
        if ( he[i] >=3 ){
            ha = max(ha, i);
            for(int j=17;j>=3;j--){
                if( i!=j && he[j]>=2){
                    hb = max(hb, j);
                }
            }
        }
    }
    if( ma==0)return -1;
    if( ma>=ha)return 1;
    else if( ma==ha &&mb>=hb) return 1;
    return -1;
}
int w7(){
    if( me[16] && me[17])return 1;
    if( he[16]&& he[17]){
        he[2]+=4;return -1;
    }
    return -1;
}

int w8(){
    int cnt = 0,pair=0;
    for(int i=17;i>=3;i--){
        if(me[i]==4)pair++;
        cnt+=me[i];
    }
    //cout<<cnt<<" "<<pair<<endl;
    if(pair==1 && cnt==6)return 1;
    for(int i=17;i>=3;i--){
        if( me[i]==4 )return 1;
        else if( me[i]<4 && he[i]==4)return 0;
    }
    return -1;
}

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in","r",stdin);
    #endif


    int t;
    cin>>t;
    while(t--){
        memset(me,0,sizeof(me));
        memset(he,0,sizeof(he));
        input();

        int d;
        d = w7();
        if( d==1){cout<<"Yes"<<endl;continue;}
        else if( d==0 ){cout<<"No"<<endl;continue;}

        d = w8();
        if( d==1){cout<<"Yes"<<endl;continue;}
        else if( d==0 ){cout<<"No"<<endl;continue;}
//        d = w6();
//        if( d==1){cout<<"YES6"<<endl;continue;}
//        else if( d==0 ){cout<<"NO6"<<endl;continue;}
        d = w5();
        if( d==1){cout<<"Yes"<<endl;continue;}
        else if( d==0 ){cout<<"No"<<endl;continue;}


        d = w4();
        if( d==1){cout<<"Yes"<<endl;continue;}
        else if( d==0 ){cout<<"No"<<endl;continue;}


        d = w3();
        if( d==1){cout<<"Yes"<<endl;continue;}
        else if( d==0 ){cout<<"No"<<endl;continue;}


        d = w2();
        if( d==1){cout<<"Yes"<<endl;continue;}
        else if( d==0 ){cout<<"No"<<endl;continue;}

        d = w1();
        if( d==1){cout<<"Yes"<<endl;continue;}
        else if( d==0 ){cout<<"No"<<endl;continue;}

        cout<<"No"<<endl;
    }


	return 0;
}
