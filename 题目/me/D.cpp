#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int N;
    cin>>N;

    while(N--){
        long long a;
        cin>>a;

        int flag = 1;
        while(a){
            if( a%1000==188){
                a/=1000;
            }else if(a%100==18){
                a/=100;
            }else if(a%10 == 1){
                a/=10;
            }else{
                flag =0;break;
            }
        }
        if( flag )cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
