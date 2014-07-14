#include <iostream>
using namespace std;

int num[105][105];
int n;
void print()
{
      for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                cout<<num[i][j]<<" ";
            }
            cout<<num[i][n-1]<<endl;
        }
}
int main()
{
    int cse = 0;
    while(cin>>n)
    {
        if( cse) cout<<endl;
        cse++;
        int k=0;
        for(int i=0;i<n/2+1;i++)
        {
            for(int a=i;a<n-i;a++)
            {
                num[i][a] = ++k;
            }
            //print();
            k--;
            for(int a = i;a<n-i;a++)
            {
                num[a][n-i-1] = ++k;
            }
            k--;

            //print();
            for(int a=n-i-1;a>=i;a--)
            {
                num[n-i-1][a] = ++k;
            }
            k--;

            //print();
            for(int a=n-i-1;a>i;a--)
            {
                num[a][i] = ++k;
            }
            //k--;
        }

        print();

    }


    return 0;
}
