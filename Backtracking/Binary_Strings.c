#include<stdio.h>
#include<stdlib.h>
void print_bstring(char * ar,int i,int n)
{
    if(i==n)
    {
        printf("%s\n",ar);
    }
    else
    {
      ar[i]='0';
      print_bstring(ar,i+1,n);
      ar[i]='1';
      print_bstring(ar,i+1,n);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    char * ar=(char*)malloc(sizeof(char)*n+1);
    ar[n]='\0';
    print_bstring(ar,0,n);
    return 0;
}
