#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
using namespace std;
#define ll long long
ll a[60][60]; // fen zi
ll b[60][60]; // fen mu

int ring[60][60];
int n,m;

ll gcd(ll a,ll  b)
{
    if( b==0)return a;
    return gcd(b,a%b);
}

int main()
{
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    cin>>n>>m;

    cin.ignore();

    memset(ring,-1,sizeof(ring));
    for(int i=1;i<=n;i++)
    {
        string s;
        for(int j=1;j<=i;j++)
        {
            cin>>s;
            if( s=="*")ring[i][j] = 1;
            else if( s== ".") ring[i][j] =0 ;
        }
    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=i;j++)
//        {
//            cout<<ring[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    a[1][1] =1;
    //b[1][1] =1;

    for(int i=1;i<=n;i++)
    {
        a[1][1]<<=1;
    }
    for(int i=2;i<=n+1;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if( ring[i-2][j-1]==0)
            {
                a[i][j] += a[i-2][j-1];
            }
            if( ring[i-1][j] ==1)
            {
                a[i][j]+= a[i-1][j]>>1;
            }
            if( ring[i-1][j-1] ==1)
            {
                a[i][j] += a[i-1][j-1]>>1;
            }
        }
    }

    ll fenmu = 0;
    for(int i=1;i<=n+1;i++)
    {
        fenmu+= a[n+1][i];
    }
    if( a[n+1][m+1] == 0)
    {
        cout<<"0/1"<<endl;
        return 0;
    }

    ll g = gcd(fenmu,a[n+1][m+1]);
    cout<<a[n+1][m+1]/g<<"/"<<fenmu/g<<endl;


    return 0;
}
