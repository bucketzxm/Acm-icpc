#include <iostream>
#include <algorithm>
#include <complex>

using namespace std;


int dcmp(complex<double> a, complex<double >b)
{
    double x = ( a.real()-b.real() ) * (a.real()-b.real())+(a.imag()-b.imag())*(a.imag()-b.imag());
    //cout<<a.real()<<" "<<a.imag()<<" "<<b.real()<<" "<<b.imag()<<" "<<x<<" xxxxxxxxx"<<endl;
    x = sqrt(x);
    if( fabs(x)<10e-8)return 1;
    else
        return 0;

}

int main()
{

    double a,b;
    int cse = 0;
    while(cin>>a>>b)
    {

        cout<<"Case "<<++cse<<": ";
        complex<double> z (a,b);

        complex<double> w0( 1,0);
        complex<double> w1(-1*1.0/2,sqrt(3.0)*1.0/2);
        complex<double> w2(-1*1.0/2,-sqrt(3.0)*1.0/2);

        while( !dcmp(z,w0) && !dcmp(z,w1) && !dcmp(z,w2))
        {
            z = z-(z*z*z-complex<double>(1,0))/(complex<double>(3,0)*z*z);
            //cout<<z.real()<<" "<<z.imag()<<endl;
        }
        if(dcmp(z,w0))
            cout<<"0"<<endl;
        if(dcmp(z,w1))
            cout<<"1"<<endl;
        if(dcmp(z,w2))
            cout<<"2"<<endl;
    }


    return 0;
}
