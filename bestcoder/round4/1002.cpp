#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iomanip>
using namespace std;
#define ll long long

int n;
double x[100];
double len[100];
int p;

bool C (double d){
   // cout<<d<<endl;
    double rec[100];

    for(int i=0;i<100;i++){
        rec[i] = -1;
    }

    rec[0] = x[0];
    x[n] = 2*10e9;
    for(int i=1;i<n;i++){

        if( rec[i] != -1)continue;

        if( rec[i-1] + d<= x[i]){
            rec[i] = x[i];
          //  cout<<"xxx1"<<endl;
        }
        else if( x[i] + d < x[i+1]){
            rec[i] = x[i]+d;
            //cout<<"xxx2"<<endl;
        }
        else if( x[i]+d == x[i+1]){
            rec[i+1] = x[i+1];
        }
        else
            return 0;


        //cout<<x[i]<<" "<<rec[i]<<endl;
    }
    return 1;

}


int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        memset(len,0,sizeof(len));
        p = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf",&x[i]);
        }

        sort(x,x+n);
        for(int i=1;i<n;i++){
            len[2*p] = x[i] - x[i-1];
            len[2*p+1] = len[2*p]/2;
            p++;
        }
        p*=2;
        sort(len,len+p);
//        reserve(len,len+p);
        int l = 0, r = p-1;
        double ans= 0;
        for(int i=p-1;i>=0;i--){
            if(C(len[i])){
                ans = len[i];
                break;
            }
        }
        printf("%.3lf\n",ans);
    }

    return 0;
}
