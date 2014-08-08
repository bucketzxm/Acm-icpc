#include <iostream>
using namespace std;

#define MAXN 1005
int r,c;
int loop[MAXN][MAXN], left[MAXN][MAXN],down[MAXN][MAXN];
int main(){

    while(cin>>r>>c){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int k=0;k<3;k++){
                    cin>>loop[i][j]>>left[i][j]>>down[i][j];
                }
            }

        }



    }

    return 0;
}
