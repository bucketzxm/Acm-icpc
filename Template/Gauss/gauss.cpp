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

typedef vector<double> vec;
typedef vector<vec> mat;
const double eps = 1e-8;
//AX=b 有无穷解时候 返回一个长度为0的数组

vec gauss(const mat& A, const vec& b)
{
    int n = A.size();
    mat B(n,vec(n+1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            B[i][j] = A[i][j];
    }
    //把b放在A的右边
    for(int i=0;i<n;i++)
    {
        B[i][n] = b[i];
    }
    //把正在处理的未知数系数的绝对值最大的式子换到第i行
    for(int i=0;i<n;i++)
    {
        int pivot = i;
        for(int j=i;j<n;j++)
        {
            if( abs(B[j][i])>abs(B[pivot][i])) pivot = j;
        }

        swap(B[i],B[pivot]);

        //无解或者无穷多解
        if( abs(B[i][i])<eps)return vec();

        //把正在处理的未知数系数变成1

        for(int j=i+1;j<=n;j++)B[i][j]/=B[i][i];

        for(int j=0;j<n;j++)
        {
            if( i!=j)
            {
                for(int k=i+1; k<=n;k++)
                {
                    B[j][k] -= B[j][i]*B[i][k];
                }
            }
        }
    }
    vec x(n);
    for(int i=0;i<n;i++)
    {
        x[i] = B[i][n];
    }
    return x;
}

int main()
{
	ios::sync_with_stdio(false);

	return 0;
}



