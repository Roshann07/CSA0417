#include <stdio.h>
int main()
{
int n, m, i, j, k;
printf("Enter the number of process-\n");
scanf("%d",&n);
printf("Enter the number of resources-\n");
scanf("%d",&m);

int alloc[n][m];
printf("Enter the values of Allocation matrix-\n");
for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)
	{
		printf("[%d][%d]=",i,j);
		scanf("%d",&alloc[i][j]);
	}
}


int max[n][m];
printf("Enter the values of Max matrix-\n");

for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)
	{
		printf("[%d][%d]=",i,j);
		scanf("%d",&max[i][j]);
	}
}

int avail[n];
printf("Enter the values of available resouces-\n");
for(i=0;i<n;i++)
{
	scanf("%d",&avail[i]);
 } 
int f[n], ans[n], ind = 0;
for (k = 0; k < n; k++) {
	f[k] = 0;
}
int need[n][m];
for (i = 0; i < n; i++) {
	for (j = 0; j < m; j++)
	need[i][j] = max[i][j] - alloc[i][j];
}
int y = 0;
for (k = 0; k < 5; k++) {
	for (i = 0; i < n; i++) {
	if (f[i] == 0) {

		int flag = 0;
		for (j = 0; j < m; j++) {
		if (need[i][j] > avail[j]){
			flag = 1;
			break;
		}
		}

		if (flag == 0) {
		ans[ind++] = i;
		for (y = 0; y < m; y++)
			avail[y] += alloc[i][y];
		f[i] = 1;
		}
	}
	}
}

int flag = 1;

for(int i = 0;i<n;i++)
{
		if(f[i]==0)
	{
		flag = 0;
		printf("The given sequence is not safe and is in deadlock");
		break;
	}
}

if(flag==1)
{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P %d ->",ans[i]);
	printf(" P &d \n",ans[n - 1]) ;
}

	return 0;
}

