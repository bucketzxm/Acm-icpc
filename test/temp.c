#include <stdio.h>

int min(int a, int b)//在这里添加你的函数
{  if(a>b)
       return b;   //这个就是max函数的返回值，返回a的值
   else
       return a;   //这个就是max函数的返回值，返回b的值
}

int main()
{
   int a = 4,b = 6,c=0;
   c = min(a,b);//在这里写上代码,使用a,b当参数
   printf("最小值是：%d\n",c);
   return 0;
}
