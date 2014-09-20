#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <fstream.h>
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin 
#define cout fout 
const MAX=30;
typedef struct List
{
	char name[MAX];
	int  No;        //当前节点编号
	int  price;     //投标价格
} List;
List array[4000];  //节点数组

int bubble(long a[MAX],int n)
{
    int i,j,k=0,temp,flag=0,cnt=1,min;	
	int *num;
	num=new int[n];
	num[0]=1;
	for (i=0; i<n-1;i++){  //冒泡法排序，将小的数下沉
		for (j=n-1; j>i;j--){
			if (a[j]<a[j-1]) {
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
		if (i>0){         //统计相同数的个数
			if(a[i]==a[i-1]){   //每次比较相邻元素的关系
				flag=1;
				cnt++;
			}
			else{
				num[k]=cnt;
				k++;
				cnt=1;
			}
		}
	}
	if ((n>1)&&(a[n-1]==a[n-2]))
		num[k]=cnt+1;
	else{
		num[k]=cnt;
		k++;
		num[k]=1;
	}
	min=num[0];
	if (flag){
		for (i=1; i<=k;i++)
			if(min>num[i]) min=num[i];
	}

	
	for (i=0; i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
	for (i=0; i<=k;i++)
		cout<<num[i]<<" ";
	cout<<":  "<<min<<endl;
				

			//for (i=1;i<=n;i++) cout<<a[i]<<" ";
			//cout<<endl;//
	
	return 0;

}

int main(){
   int T,i,k,flag,*c;
   long U,M,NodeNo,temp,a,b,j,*cc;
   cin>>T;
   for(i=0;i<T;i++){
	   cout<<"Case "<<i+1<<":"<<endl;
	   cin>>U>>M;
	   cc=new long[M];
	   
	   for(j=0;j<M;j++){
		   cin>>array[j].name>>array[j].price;
		   array[j].No=j;
		   cc[j]=array[j].price;
	   }
	   bubble(cc,M);
   }
   return 0;
}