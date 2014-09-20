/*
    yao哥最近得了一种不吃鸡排会死的病，一天他一口气买了N块鸡排（编号1~N），但是他考虑到自己减肥的目标
    还没有实现，所以只能考虑把这N块鸡排分成很多堆，现在有两种操作，第一种 给出i j ，合并i和j 这两块鸡排所在
    的堆，第二种操作是查询第k多的鸡排堆中有多少块鸡排。


    0< N,M <100000

    hint: 2 2 1 第1大是2，第2大是2，第3大是1

    input:
        5 4
        0 1 2
        1 2
        0 3 4
        1 2
    ouput:
        1
        2
*/


#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

#define MAXN 500000

int fa[MAXN],a[MAXN],bit[MAXN];

int ufind(int x){
    return x==fa[x]?x:fa[x] = ufind(fa[x]);
}
int lowbit(int x){
    return x&-x;
}
int add(int x,int d){
    while(x<=MAXN){
        bit[x] +=d;
        x+=lowbit(x);
    }
    return 0;
}

int find_k(int k){
    int now = 0;
    int ret = 0;
    for(int i = 20;i>=0;i--){
        now += (1<<i);
        if( now >= MAXN || ret+bit[now]>=k){
            now-=(1<<i);
        }else{
            ret+=bit[now];
        }
    }
    return now+1;
}

int main(){
    freopen("in","r",stdin);

    freopen("out","w",stdout);
    int N,M;
    int tN;
    while(scanf("%d%d",&N,&M)!=EOF){
        for(int i=0;i<=N;i++)fa[i]=i;
        for(int i=0;i<=N;i++)a[i] = 1;
        tN = N;
        add(1,N);

        for(int i=0;i<M;i++){
            int op;
            scanf("%d",&op);
            if(op==0){
                int x,y;
                scanf("%d %d",&x,&y);
                if((x>tN || y>tN)){
                    cout<<x<<" "<<y<<" "<<tN<<endl;
                }
                assert (! (x > tN || y > tN));
                int fx = ufind(x),fy = ufind(y);
               // cout<<fx<<" "<<fy<<endl;
                if( fx == fy) continue;
                else{
                    add( a[fx] , -1 );
                    add( a[fy] , -1 );
                    add( a[fx]+ a[fy] ,1);
                    a[fx] += a[fy];
                    fa[fy] = fx;
                    N--;
                    //cout<<N<<endl;
                }
            }else{
                int k;
                scanf("%d",&k);
                k = N - k+1;
                int ans = find_k(k);
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}
