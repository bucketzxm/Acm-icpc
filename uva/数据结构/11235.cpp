#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100000
int value[MAXN],count[MAXN],num[MAXN],lft[MAXN],rht[MAXN];
int N[MAXN];
int main(){
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    int n, q;
    while(scanf("%d%d",&n,&q),n){
        memset(value,0,sizeof(value));
        memset(count,0,sizeof(count));
        for(int i=0;i<n;i++){
            scanf("%d",&N[i]);
        }
        N[n] = N[0]-1;
        int p=0;
        value[p] = N[0];
        int l =0, r= 0;
        for(int i=0;i<=n;i++){
            if(N[i]==value[p]){
                count[p]++;
                r = i;
            }else{
                for(int k=l;k<=r;k++){
                    lft[k] = l;
                    rht[k] = r;
                    num[k] = p;
                }
                l = r = i;
                p++;
                value[p] = N[i];
                count[p]++;
            }
        }
        for(int i=0;i<q;i++){

            int a,b,ans = 0;
                scanf("%d%d",&a,&b);

            a-=1;b-=1;
            ans = 0;
            if( num[a] == num[b]){
                ans = b-a+1;
            }else{
                ans = max( rht[a]-a+1, b-lft[b]+1);

                for(int k = num[a]+1;k<=num[b]-1;k++){
                    ans = max(ans, count[k]);
                }
            }
            printf("%d\n",ans);
        }

    }

    return 0;
}
