#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;


struct Seg
{
    ll xmin;
    int set ;
    int lson,rson;

};
Seg tree[5*100005];

void build(int o,int l,int r){
    //cout<<o<<" "<<l<<" "<<r<<endl;
    tree[o].lson = l;
    tree[o].rson = r;
    tree[o].set = 0;
    tree[o].xmin = INT_MAX;
    if( l==r){
        return ;
    }
    int mid = (l+r)/2;
    build(o*2+1,l,mid);
    build(o*2+2,mid+1,r);
}

void update1(int o,int l,int r,int num,int set){

   // cout<<tree[o].lson<<' '<<tree[o].rson<<endl;
    if( tree[o].lson == l && tree[o].rson==r){
       //cout<<o <<" "<<l<<"  "<<r<< " "<<num<<endl;
        tree[o].xmin = num;
        tree[o].set =1;
        return;
    }

    int mid = (tree[o].lson+tree[o].rson)/2;

    if(tree[o].set){
        tree[o*2+1].set = tree[o*2+2].set = 1;
        tree[o*2+1].xmin = tree[o*2+2].xmin = tree[o].xmin;
        tree[o].set = 0;

    }
    if( l>mid ){
        update1(o*2+2,l,r,num,set);
    }else if( r<=mid){
        update1(o*2+1,l,r,num,set);
    }else{
        update1(o*2+1,l,mid,num,set);
        update1(o*2+2,mid+1,r,num,set);
    }

}

int gcd(int a,int b){
    if( b==0)return a;
    return gcd(b,a%b);
}

void update2(int o,int l,int r,int gd){

    if ( tree[o].set && tree[o].lson==l && tree[o].rson==r){
        if( tree[o].xmin > gd)
            tree[o].xmin = gcd( tree[o].xmin,gd);
        return;
    }
    if( tree[o].lson == tree[o].rson ){
            if( tree[o].xmin> gd){
                tree[o].xmin = gcd( tree[o].xmin, gd);
               // cout<<tree[o].lson<<" "<<tree[o].xmin<<" "<<gd<< ' '<<"herererere"<<endl;
            }
        return ;
    }
    int mid = (tree[o].lson+tree[o].rson)/2;

    if(tree[o].set){
        tree[o*2+1].set = tree[o*2+2].set = 1;
        tree[o*2+1].xmin = tree[o*2+2].xmin = tree[o].xmin;
        tree[o].set = 0;
    }

    if( l > mid){
        update2(o*2+2,l,r,gd);
    }else if( r<=mid){
        update2(o*2+1,l,r,gd);
    }else{
        update2(o*2+1,l,mid,gd);
        update2(o*2+2,mid+1,r,gd);
    }
}

void query(int o,int l,int r){

    if( tree[o].set == 1){
        for(int i=l;i<=r;i++){
            cout<<tree[o].xmin<<" ";
        }
        return;
    }

    if( l==r){
        cout<<tree[o].xmin<<" ";
        return;
    }
//    if(tree[o].set ){
//        tree[o*2+1].set = tree[o*2+2].set=1;
//        tree[o*2+1].xmin = tree[o*2+2].xmin = tree[o].xmin;
//    }
    int mid = (tree[o].lson+tree[o].rson)/2;
     if(tree[o].set){
        tree[o*2+1].set = tree[o*2+2].set = 1;
        tree[o*2+1].xmin = tree[o*2+2].xmin = tree[o].xmin;
        tree[o].set = 0;
    }

    if( l>mid){
        query(o*2+2,l,r);
    }else if( r<=mid){
        query(o*2+1,l,r);
    }
    else{
        query(o*2+1,l,mid);
        query(o*2+2,mid+1,r);
    }
}
int n;
int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        build(0,1,n);
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            update1(0,i+1,i+1,t,1);
        }
        int m;
       // query(0,1,n);
        //cout<<endl;
        cin>>m;

        for(int i=0;i<m;i++){
            int type , l, r, gd;
            cin>>type>>l>>r>>gd;
            if(type == 1){
                update1(0,l,r,gd,1);
            }else{
                update2(0,l,r,gd);
            }
            //cout<<type<<" "<<l<<' '<<r<<" "<<gd<<endl;
           // query(0,1,n);
            //cout<<endl;
        }
        query(0,1,n);
        cout<<endl;
    }
	return 0;
}

