#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iomanip>
using namespace std;

int N;
double p[50];
double dp[1<<20];
int main()
{
    //freopen("in","r",stdin);
    while(scanf("%d",&N)!=EOF)
    {

        for(int i=0;i<N;i++)
        {
            scanf("%lf",&p[i]);
        }
        //状态压缩里面
        // 0 表示没拿　1表示拿了
        //11111表示全拿了。。
        int full = (1<<N)-1;
        dp[full] = 0;
        for(int i=full-1;i>=0;i--) // 倒着推
        {
            double sum = 1; //自己当前这一张卡片要拿
            double had = 0;
            for(int j=0;j<N;j++)
            {
                if( (i & (1<<j))==0)
                {
                    sum += p[j]*dp[ i | (1<<j) ];
                    had+=p[j];
                }
            }
            dp[i] = sum/had;
        }
        cout<<fixed<<setprecision(20)<<dp[0]<<endl;
        //ntf("%lf\n",dp[0]);
    }
    return 0;
}
