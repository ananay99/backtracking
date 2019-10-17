#include<stdio.h>
#include<stdlib.h>
void showpath(int ** board,int i,int j,int n)
{
    board[i][j]=1;
    if(i==n-1&&j==n-1)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                printf("%d ",board[x][y]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    else
    {
        if(j+1<n)
        {
            showpath(board,i,j+1,n);
        }
        if(i+1<n)
        {
            showpath(board,i+1,j,n);
        }
    }
    board[i][j]=0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int ** board=(int**)calloc(n,sizeof(int*));
    for(int x=0;x<n;x++)
    {
        board[x]=(int*)calloc(n,sizeof(int));
    }
    showpath(board,0,0,n);
    return 0;
}
