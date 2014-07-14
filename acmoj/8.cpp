#include <iostream>
using namespace std;

int main()
{
    int  n;
    while(cin>>n)
    {
        int ans = 1;
        for(int i=1;i<=n;i++)
        {
            ans*=i;
            while( ans%10==0)
            {
                ans/=10;
              //  cout<<i<<" "<<ans<<endl;
            }
            ans = ans%1000;
           // cout<<"ans"<<ans<<endl;*

        }
        while(ans%10==0)
        {
            ans/=10;
        }
        cout<<n<<"!:"<<ans%10<<endl;
    }


    return 0;
}
