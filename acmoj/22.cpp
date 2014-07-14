#include<stdio.h>
#include<math.h>
double add(double x, double y);
double sub(double x, double y);
double div(double x, double y);
double mul(double x, double y);

int dcmp(double a,double b)
{
    if(fabs(a-b)<10e-6)return 1;
    else return 0;
}
int main()
{
    double (*op[4])(double, double) = {div, mul, sub, add};
	int i,o,p,q,a[4],f,n=0;
	double b[5];
	while(scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])!=EOF)
	{
		f=0;
		for(o=0;o<4;o++)
		{
			for(p=0;p<4;p++)
			{
				for(q=0;q<4;q++)
				{
					b[0]=op[q](op[p](op[o](a[0],a[1]),a[2]),a[3]);
					if(dcmp(b[0],24))
                        { f=1;break;}
				    b[1]=op[q](op[o](a[0],op[p](a[1],a[2])),a[3]);
				    if(dcmp(b[1],24))
                        { f=1;break;}
				    b[2]=op[p](op[o](a[0],a[1]),op[q](a[2],a[3]));
				    if(dcmp(b[2],24))
                        { f=1;break;}
				    b[3]=op[o](a[0],op[q](op[p](a[1],a[2]),a[3]));
				    if(dcmp(b[3],24))
                        { f=1;break;}
				    b[4]=op[o](a[0],op[p](a[1],op[q](a[2],a[3])));if(dcmp(b[4],24)){ f=1;break;}
					if(f==1) break;
				}
			    if(f==1) break;
			}
		    if(f==1) break;
		}
		n++;
		if(f==1) printf("Case %d: Possible\n",n);
		if(f==0) printf("Case %d: Impossible!\n",n);
	}
	return 0;
}
double add(double x,double y)
{
    return x+y;
}
double sub(double x,double y)
{
	return x-y;
}
double mul(double x,double y)
{
    return x*y;
}
double div(double x, double y)
{
	return x*1.0/y;
}
