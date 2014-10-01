#include <iostream>
#include <cstring>
using namespace std;

int num[1005];
int len = 500;
int lowbit(int x)
{
    return x&(-x);
}

int update(int x,int v)
{
    while(x<=len)
    {
        num[x] +=v;
        x+=lowbit(x);
    }
}


int sum(int x){

    int ret = 0;
    while(x>0){
        ret += num[x];
        x -= lowbit(x);

    }
    return ret;
}
int main()
{
    int n;
    int cse = 0;
    while(cin>>n){
        cout<<"Case "<<++cse<<":"<<endl;

        int ans = 0;
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            update(a,1);
            ans += i+1-sum(a);
        }
        cout<<ans<<endl;


    }


    return 0;
}
