//
//  main.c
//  1-1
//
//  Created by Kyle.Yang on 14-7-3.
//  Copyright (c) 2014Äê Kyle.Yang. All rights reserved.
//

#include <stdio.h>
double exp(double x0);
double exp1(double x0);
double power(double x0,int n);
double fact(int n);
int main(void)
{
    double x0;
    int cse = 0;
    while(scanf("%lf",&x0)!=EOF){
            if(cse)printf("\n");
                cse++;
            printf("e1(%.3f) = %.5f\n",x0,exp1(x0));
            printf("e2(%.3f) = %.5f\n",x0,exp(x0));
    }
    return 0;
}
double exp(double x0)
{
    double sum2=1,y0;
    int n=1;
    y0=x0;
    while(y0>=0.000001||-y0>=0.000001){
        sum2=sum2+y0;
        n++;
        y0=power(x0,n)/fact(n);
    }
    return sum2;
}
double power(double x0,int n)
{
    double sum2=1;
    int i;
    for(i=1;i<=n;i++){
        sum2=sum2*x0;
    }
    return sum2;
}
double fact(int n)
{
    double result=1;
    int i;

    if(n==0)
        result=1;
    else{
        for(i=1;i<=n;i++){
            result=result*i;
        }
    }
    return result;
}
double exp1(double x0)
{
    double sum2=1;
    int n=1;
    for(n=1;n<=19;n++){
        sum2=sum2+power(x0,n)/fact(n);
    }
    return sum2;
}
