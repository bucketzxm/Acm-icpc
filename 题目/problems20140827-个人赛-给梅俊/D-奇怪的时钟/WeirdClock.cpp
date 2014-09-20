#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin 
#define cout fout 

int ttime,coin;
void calcu();
int main()
{
	while(cin>>ttime>>coin)
	{
		if(ttime==0 && coin==0)
			break;
		calcu();
	}
	return 0;
}
void calcu()
{
	long count=0,token=0;
	while(ttime!=0)
	{
		ttime=(ttime+ttime*coin)%60;
		count++;
		if(count > 10000)
		{
//			cout<<count<<endl;
			cout<<"Impossible"<<endl;
			token=1;
			break;
		}
	}
	if(token==0)
		cout<<count<<endl;
}
