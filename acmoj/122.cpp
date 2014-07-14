#include <iostream>

#include <cstring>

using namespace std;



int main()

{

   const int N = 65536;

   char str[N];

   int n, k, left, right;



   cin >> n;

   cin.getline(str, N);       //“吃掉”整数后面的换行字符

   for(k=1; k<=n; k++)

   {

      cin.getline(str, N);

      left = 0;

      right = strlen(str)-1;

      while(left < right)

      {

         if(str[left]!=str[right])

           break;

         left++;

         right--;

      }

      cout << "Case " << k << ": "

          << (left < right ? "No" : "Yes") << endl;

   }

   return 0;

}
