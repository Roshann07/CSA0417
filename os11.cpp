#include <stdio.h>
int main()
{
    int x=4,y;
    printf("Enter the number of processes in each child-");
    scanf("%d",&y);
    int a[x][y];
    int s=2;
    for(int i=0;i<y;i++)
    {
    	a[0][i]=(s*(i+1)-1);
	}

    for(int i=0;i<y;i++)
    {
    	a[1][i]=s*(i+1);
	}
	int b=3,c=5;

      for(int i=0;i<y;i++)
    {
    	a[2][i]=b*(i+1);
	}

      for(int i=0;i<y;i++)
    {
    	a[3][i]=c*(i+1);
	}

      for(int i=0;i<x;i++)
    {
           for(int j=0;j<y;j++)
    {
    	printf("%d ",a[i][j]);
	}
	printf("\n");}

    return (0);
 }
