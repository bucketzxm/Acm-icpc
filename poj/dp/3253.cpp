#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
priority_queue<ll,vector<ll> ,greater<ll> > q;
ll plk[20000+10];
int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>plk[i];
        q.push(plk[i]);
    }
    ll ans =0;
    while(q.size()>=2)
    {
        int a =q.top();q.pop();
        int b = q.top();q.pop();
        ans+= (a+b);
        //cout<<ans<<endl;
        q.push(a+b);
    }
    cout<<ans<<endl;
    return 0;
}
