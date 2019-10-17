#include<stdio.h>
#include<stdlib.h>
void updateboard(char ** board,int i,int j,int n)
{
    int x=i,y=j;
    while(x>=0&&y>=0)
    {
        board[x][y]=1;
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x<n)
    {
        board[x][y]=1;
        x++;
    }
    x=i;
    y=j;
    while(y<n)
    {
        board[x][y]=1;
        y++;
    }
     x=i;
    y=j;
    while(x>=0)
    {
        board[x][y]=1;
        x--;
    }
     x=i;
    y=j;
    while(y<n&&x>=0)
    {
        board[x][y]=1;
        y++;
        x--;
    }
     x=i;
    y=j;
    while(y<n&&x<n)
    {
        board[x][y]=1;
        x++;
        y++;
    }
         x=i;
    y=j;
    while(y>=0&&x<n)
    {
        board[x][y]=1;
        x++;
        y--;
    }
    x=i;
    y=j;
    while(y>=0)
    {
        board[x][y]=1;
        y--;
    }
}
void permute(char ** board,int n,char *arr,int i,int j)
{
    int sz=n*n;
    if(i==n)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                board[x][y]=0;
            }
        }
        int chk=1;
        for(int x=0;x<sz;x++)
        {
            if(arr[x])
            {
                if(!board[x/n][x%n])
                {
                    updateboard(board,x/n,x%n,n);
                }
               else
               {
                   chk=0;
                   break;
               }
            }
        }
        if(chk)
        {
            for(int x=0;x<sz;x++)
            {
                 if(x%n==0)
               {
                   printf("\n");
               }
               if(arr[x])
               {
                   printf("q ");
               }
               else
               {
                   printf("* ");
               }

            }
            printf("\n\n");
        }
    }
    else
    {
        for(int x=j;x<sz;x++)
        {
            if(!arr[x])
            {
                arr[x]=1;
                permute(board,n,arr,i+1,x+1);
                arr[x]=0;
            }

        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    char ** board=(char**)calloc(n,sizeof(char*));
    for(int x=0;x<n;x++)
    {
        board[x]=(char*)calloc(n,sizeof(char));
    }
    char * arr=(char*)calloc(n*n,sizeof(char));
    permute(board,n,arr,0,0);
    return 0;
}
