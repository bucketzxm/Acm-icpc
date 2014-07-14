#include<fstream>
#include<iostream>
#include <cstring>
using namespace std;


void daoxu(int *a,int l);
void add(int *a,int *b,int lenA,int lenB,int scale);//lenA,lenB分别为数组a，b的长度，scale为进制数，
int main()                                          //这里只是计算了八进制的加法，所以scale=8，如果需要计算其他进制的数，则只需要改变scale的值
{

 char c;
 bool t=true;
 while(t)
 {

  int i=0,j=0;
  int a[105],b[105],lenA,lenB;
  memset(a,0,105);
  memset(b,0,105);
  while(c=cin.get())
  {
   if(c==' ')break;
   a[i++]=c-48;
   cout<<a[i-1];
  }
  lenA=i;
  cout<<"+";
  while(c=cin.get())
  {
   if(c=='\n'||c==EOF)break;
   b[j++]=c-48;
   cout<<b[j-1];
  }
  lenB=j;
  cout<<"=";
  daoxu(a,i);//将数组倒序排列,以方便后面的加运算
  daoxu(b,j);
  add(a,b,lenA,lenB,8);
  cout<<'\n';
  if(c==EOF)t=false;
 }
 return 0;

}
void daoxu(int *a,int l)
{
 int temp;
 for(int i=0,j=l-1;i<=j;i++,j--)
 {
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
 }
}
void add(int *a,int *b,int lenA,int lenB,int scale)
{

 int i,j;

 if(lenA>=lenB)//数组*a的长度比*b的长度长
 {
  for(i=0;i<lenB;i++)
  {
   a[i]=a[i]+b[i];
   a[i+1]=a[i+1]+a[i]/scale;//进行相应进制的转换
   a[i]=a[i]%scale;
  }
  while(a[i]>=scale)
  {
   a[i+1]=a[i+1]+a[i]/scale;
   a[i]=a[i]%scale;
   i++;
  }
  int max=lenA>i?lenA:i;//比较lenA和i的大小，使输出格式正确
  if(max>i)
  for(int j=max-1;j>=0;j--)cout<<a[j];
  else for(int j=i;j>=0;j--)cout<<a[j];
 }
 else
 {
  for(i=0;i<lenA;i++)
  {
   b[i]=b[i]+a[i];
   b[i+1]=b[i+1]+b[i]/scale;
   b[i]=b[i]%scale;
  }
  while(b[i]>=scale)
  {
   b[i+1]=b[i+1]+b[i]/scale;
   b[i]=b[i]%scale;
   //j--;
  }
  int max=lenB>i?lenB:i;
  if(max>i)
  for(int j=max-1;j>=0;j--)cout<<b[j];
  else for(int j=i;j>=0;j--)cout<<b[j];
 }
}
