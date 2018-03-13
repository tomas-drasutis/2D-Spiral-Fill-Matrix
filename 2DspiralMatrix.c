#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Read (int *n, int ***pntA, int *rounds);
int FirstLine (int n, int i, int j, int k, int **pntA);
int LastColumn (int n, int i, int j, int k, int **pntA);
int LastLine (int n, int i, int j, int k, int **pntA);
int FirstColumn (int n, int i, int j, int k, int **pntA);
void PrintOut (int n, int i, int j, int **pntA);

int main()
{
    int n,k,j,i;
    int **pntA;
    int rounds;
    Read (&n, &pntA, &rounds);
    k=1;
    j=0;
    for (i=0;i<rounds;i++)
    {
        k=FirstLine(n,i,j,k,pntA);
        k=LastColumn(n,i,j,k,pntA);
        k=LastLine(n,i,j,k,pntA);
        k=FirstColumn(n,i,j,k,pntA);
    }
    PrintOut(n,i,j,pntA);
    for (j=0;j<n;j++)
    {
        free((pntA)[j]);
    }
    free(pntA);
    return 0;
}
void Read (int *n, int ***pntA, int *rounds)
{   int y;
    printf("Enter size of array N: ");
    scanf("%d", &(*n));
    (*pntA)=(int**)malloc((*n)*sizeof(int*));
    for (y=0;y<(*n);y++)
    {
        (*pntA)[y]=(int*)malloc((*n)*sizeof(int));
    }
    *rounds=ceil((double)*n/2);
}
int FirstLine (int n, int i, int j, int k, int **pntA)
{
    for(j=i;j<=n-1-i;j++)
        {
            pntA[i][j]=k++;
        }
        return k;
}
int LastColumn (int n, int i, int j, int k, int **pntA)
{
    for(j=i+1;j<=n-1-i;j++)
        {
            pntA[j][n-1-i]=k++;
        }
        return k;
}
int LastLine (int n, int i, int j, int k, int **pntA)
{
    for(j=n-2-i;j>=i;j--)
        {
            pntA[n-i-1][j]=k++;

        }
        return k;
}
int FirstColumn (int n, int i, int j, int k, int **pntA)
{
    for(j=n-2-i;j>i;j--)
        {
            pntA[j][i]=k++;
        }
        return k;
}
void PrintOut (int n, int i, int j, int **pntA)
{
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%5d",pntA[i][j]);
        }
        printf("\n");
    }
}
