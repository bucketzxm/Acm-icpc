#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define long long ll


class Seg{
    public:
        int *sum,*Max,*Min;
        int *addv,*setv;
        int sz;

        void build(int o,int l,int r){
            addv[o] = sum[0] = 0;
            setv[o] = -1;
            if( l == r){
                return ;
            }
            int mid = (l+r)/2;
            build(o*2,l,mid);
            build(o*2+1,mid+1,r);
        }

        void maintain(int o,int l,int r){
            sum[o] = Max[o] = Min[o] = 0;
            int lson = o*2, rson = o*2+1;
            if( r > l){
                sum[o] = sum[lson]+sum[rson]+addv[o]*(r-l+1);
                Max[o] = max( Max[lson],Max[rson])+addv[o];
                Min[o] = min( Min[lson],Min[rson])+addv[o];
            }
        }

         void pushdown(int o){

            int lson = o*2,rson = o*2+1;
            if(setv[o] != -1){
                setv[lson] = setv[rson] = setv[o];
                addv[lson] = addv[rson] = 0;
                setv[o] = -1;
            }

            if( addv[o] !=0){
                addv[lson] += addv[o];
                addv[rson] += addv[o];
                addv[o] = 0;
            }
        }

        void add(int o,int l,int r,int left,int right,int inc){
            if( left<=l && r >= right){
                addv[o] += inc;
            }else{
                int mid = (l+r)/2;
                pushdown(o);

                if( left<=M)
                    add(o*2,l,mid,left,right,inc);
                else
                    maintain(o*2,l,mid);

                if( right>M)
                    add(o*2+1,mid+1,r,left,right,inc);
                else
                    maintain(o*2+1,mid+1,r);
            }
            maintain(o,l,r);
            return;
        }



        int Set(int o,int l,int r,int left,int right,int se){

            if( l<= left && r >= right){
                setv[o] = se;
                addv[o] = 0;
            }else{
                int mid = (l+r)/2;
                pushdown(o);

                if( left<=mid) Set(o*2,l,mid,left,right,se);
                else
                    maintain(o*2,l,mid);

                if(right>mid)Set(o*2+1,mid+1,r,left,right,se);
                else
                    maintain(o*2+1,mid+1,r)

            }
            maintain(o,l,r);
            return ;
        }

        int ansSum,ansMax,ansMin;
        int query(int o,int l,int r,int left,int right,int add){

            if( setv[o] != -1){


                ansSum += (setv[o]+addv[o])*( r-l+1 );

            }

        }


}


int main(){


    return 0;
}
