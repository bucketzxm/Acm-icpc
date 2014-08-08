#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

string tex;

int main()
{
    freopen("in","r",stdin);


    while(cin>>tex){
        cout<<tex<<endl;
        int len = tex.length();
        if( tex[0]==")" || tex[len-1]=="(")
        {
            cout<<"None"<<endl;
            continue;
        }

        string one (tex);
        string two (tex);


        if( one[0] =="?"){ one[0] = "("; two[0] = "("}
        if( one[len-1]=="?"){ one[len-1] = ")"; two[0]=")"}

        int ok = 0;
        int left = 0;
        for(int i=0;i<len;i++){
            if( one[i] == "("){
                left++;
            }else{
                if( left ==0)
                    left ++;
                else
                    left --;
            }
        }
        if( left == 0)ok++;

    }


    return 0;
}
