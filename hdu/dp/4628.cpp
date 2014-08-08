#include <iostream>
#include <cstring>
using namespace std;
char str[20];
int st[1<<20];
int p;
int N;
int dp[1<<20];
bool check(int s){
    char tmp[20] ={0};
    int pt=0;

    for(int i=0;i<N;i++){
        if( s&(1<<i)){
            tmp[pt++] = str[i];
        }
    }
    for(int i=0;i<pt;i++){
        if( tmp[i]!=tmp[pt-i-1]){
            return 0;
        }
    }
    return 1;
}

int init(){
    memset(dp,0,sizeof(dp));
    memset(st,0,sizeof(st));
    for(int i=0;i<(1<<N);i++){
        if( check(i)){
            st[i] = 1;
        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>str;
        N = strlen(str);
        init();
        int all = (1<<N)-1;
        dp[all] = 0;

        for(int i=all-1;i>=0;i--){

            dp[i] = 0x3fffffff;

            for(int j=i;j<=all;j=(j+1)|i){
                if( st[i^j]){
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        cout<<dp[0]<<endl;
    }

    return 0;
}
