#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
#define REP(i,N) for(int i=0;i<N;i++)
#define REP2(i,L,R) for(int i=L;i<=R;i++)

double sig[60];
double mround(double x)
{
    x*=100;
    return round(x)/100.0;
}

int main()
{

    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        cout<<n<<endl;
        if(n == 1)
        {
            double x ; cin>>x;
            cout<<fixed<<setprecision(2)<<mround(x)<<endl;
            continue;
        }
        REP(i,n)
        {
            cin>>sig[i];
        }

        cout<<fixed<<setprecision(2)<<mround((sig[0]+sig[1])/2.0)<<" ";
        //cout<<fixed<<setprecision(2)<<(sig[0]+sig[1])/2.0<<" ";
        REP2(i,1,n-2)
        {
            cout<<fixed<<setprecision(2)<<mround( (sig[i-1]+sig[i]+sig[i+1])/3.0 )<<" ";
            //cout<<fixed<<setprecision(2)<<(sig[i-1]+sig[i]+sig[i+1])/3.0<<" ";
        }
        cout<<fixed<<setprecision(2)<<mround((sig[n-2]+sig[n-1])/2.0 )<<endl;
        //cout<<fixed<<setprecision(2)<<(sig[n-2]+sig[n-1])/2.0<<endl;
    }
    return 0;
}
