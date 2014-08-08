
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
using namespace std;

#define INF 100000000
int n;
string op[1000];
int num[1000];
int len=0;

int dp_max[1000][1000];
int dp_min[1000][1000];

void dfs(int s, int e)
{
    if( s == e)
    {
        dp_max[s][e] = dp_min[s][e] = num[s%len];
        return;
    }

    int ret = 0;
    for(int i=s;i<e;i++)
    {
        if( dp_max[s][i] == -INF)
        {
            dfs( s,i);
        }
        if( dp_max[i+1][e] == -INF)
        {
            dfs(i+1,e);
        }

        if( op[ (i+1)%len] == "t")
        {
            dp_max[s][e] = max(dp_max[s][e], dp_max[s][i]+dp_max[i+1][e]);
            dp_min[s][e] = min(dp_min[s][e], dp_min[s][i]+dp_min[i+1][e]);
        }
        else if( op[(i+1)%len] == "x")
        {

            dp_max[s][e] = max( dp_max[s][e], dp_max[s][i]*dp_max[i+1][e] );

            dp_max[s][e] = max( dp_max[s][e],dp_min[s][i]*dp_min[i+1][e] );

            dp_max[s][e] = max( dp_max[s][e],dp_max[s][i]*dp_min[i+1][e] );

            dp_max[s][e] = max( dp_max[s][e], dp_min[s][i]*dp_max[i+1][e]);

            dp_min[s][e] = min(dp_min[s][e],dp_min[s][i]*dp_min[i+1][e]);

            dp_min[s][e] = min(dp_min[s][e],dp_max[s][i]*dp_max[i+1][e]);

            dp_min[s][e] = min(dp_min[s][e],dp_max[s][i]*dp_min[i+1][e]);

            dp_min[s][e] = min(dp_min[s][e],dp_min[s][i]*dp_max[i+1][e]);

        }
    }
}

int main()
{
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif
    while(cin>>n)
    {
        memset(num,0,sizeof(num));
        //memset(op,"",sizeof(op));
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                dp_max[i][j] = -INF;
                dp_min[i][j] = INF;
            }
        }
        cin.ignore();
        string str;
        getline(cin,str);


        stringstream ss( str);
        len = 0;
        while(ss>>op[len]>>num[len])
        {
            len++;
        }

        int t = -INF;
        int pt = -INF;
        vector<int> ans;
        for(int i=0;i<len;i++){
            dfs(i,i+len-1);
            t = dp_max[i][i+n-1];
            if( t>pt)
            {
                ans.clear();
                ans.push_back(i+1);
                pt = t;
            }
            else if( t==pt)
            {
                ans.push_back(i+1);
            }
           // cout<<i<<' '<<t<<endl;
        }
        cout<<pt<<endl;
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
            if( i == ans.size()-1)cout<<endl;
            else
                cout<<' ';
        }

    }

    return 0;
}
