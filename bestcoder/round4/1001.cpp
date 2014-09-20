#include <iostream>
#include <algorithm>
using namespace std;

int num[10];
int main(){

    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<6;i++){
            cin>>num[i];
        }
        sort(num,num+6);

        if( num[5]+num[4] > num[2]+num[3]+num[1]){
            cout<<"Grandpa Shawn is the Winner!"<<endl;
        }else {
            cout<<"What a sad story!"<<endl;
        }
    }

}
