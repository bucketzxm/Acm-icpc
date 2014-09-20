#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int n;
int five[30],ten[30],tw[30];
int ok[30];
int main(){

    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>five[i]>>ten[i]>>tw[i];
        }
        memset(ok,0,sizeof(ok));
        flag = 1;
        for(int i=0;i<n;i++){
            if (five[i]>=1 && ten[i]>=1){
                five[i]-=1;
                ten[i]-=1;
                ok[i] = 1;

                five[n+1]+=five[i];
                ten[n+1]+=ten[i];
                tw[n+1] +=tw[i];
            }else if(five[i]>=3){
                five[i]-=3;
                ok[i]=1;

                five[n+1] += five[i];
                ten[n+1]+=ten[i];
                tw[n+1]+=tw[i];
            }else if( five[i]*5+ten[i]*10+tw[i]*20 <15){
                flag = -1;
                break;
            }
        }
        if(flag == -1){
            cout<<"Angry Yaoge!"<<endl;
            continue;
        }

        for(int i=0;i<n;i++){
            if( !ok[i]){


            }
        }


    }
    return 0;
}
