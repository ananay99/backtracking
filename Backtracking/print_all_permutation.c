#include<stdio.h>
#include<stdlib.h>
void print_permute(char * input,char * permute,int i)
{
    if(input[i]=='\0')
    {
        permute[i]='\0';
        printf("%s\n",permute);
    }
    else
    {
    for(int x=0;input[x]!='\0';x++)
    {
        permute[i]=input[x];
        print_permute(input,permute,i+1);
    }
    }
}
int main()
{
    char input[1000];
    char permute[1000];
    scanf("%[^\n]s",input);
    print_permute(input,permute,0);
    return 0;
}
