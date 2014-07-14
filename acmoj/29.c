#include <stdio.h>
#include<string.h>
void jh(char *a, char *b)
{
    char x[10000];
    strcpy(x,a);
    strcpy(a,b);
    strcpy(b,x);
}
int main()
{
    int n,i;
    char a[10000],b[10000];

    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++){
        gets(a);
        gets(b);
        jh(a,b);
        printf("Case %d:\n",i);
        puts(a);
        puts(b);
        getchar();
    }
    return 0;
}

