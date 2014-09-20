/*
    yao哥每天吃鸡排锻炼出了非常强壮的鸡肉，于是他找来很多强壮的公鸡玩叠罗汉的游戏。
    每只公鸡有力量值s和体重w。yao哥定义危险值是等于一只公鸡上面所有公鸡体重之和减去这只公鸡的
    力量值，现在yao哥想让你帮他最小化最大危险值

    input:
        3
        10 3
        2 5
        3 3
    output:
        2
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 50000+10
#define LL long long
#define min(x,y) x<y?x:y
#define max(x,y) x<y?y:x
int N;

struct P
{
    LL w,s;
    bool operator < (const P& x) const
    {
        return (w+s)<(x.w+x.s);
    }
};

P cow[MAXN];


int main()
{
    //freopen("bin","r",stdin);
    //freopen("bout","w",stdout);
    while(cin>>N){
        //cout<<N<<endl;
        LL l =0 , r= 0;
        for(int i=0;i<N;i++)
        {
            cin>>cow[i].w>>cow[i].s;
           // scanf("%lld%lld",&cow[i].w,&cow[i].s);
        }
        sort( cow,cow+N);
        LL ans = -10000000000;
        LL sum =0;
        for(int i=0;i<N;i++)
        {
            ans = max( sum - cow[i].s, ans);
            sum+= cow[i].w;
        }
        cout<<ans<<endl;
        //printf("%lld\n",ans);
    }
    return 0;
}
