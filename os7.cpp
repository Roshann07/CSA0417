#include<stdio.h>
int main ()
{
  int nopages, nofaults, page[20], i, count = 0;
  printf("Enter no of pages references:");
  scanf("%d",&nopages);
  printf("\nEnter the page references:");
  for (i = 0; i < nopages; i++)
    {
      scanf("%d",&page[i]);
    }
  printf("\nEnter the Number of frames:");
  scanf("%d", &nofaults);
  int frame[nofaults], fcount[nofaults];
  for (i = 0; i < nofaults; i++)
    {
      frame[i] = -1;
      fcount[i] = 0;
    }
  i = 0;
  while (i < nopages)

    {
      int j = 0, flag = 0;
      while (j < nofaults)

	{
	  if (page[i] == frame[j])
	    {
	      flag = 1;
	      fcount[j] = i + 1;
	    }
	  j++;
	}
      j = 0;
      printf("\n\t***\n");
      printf("\t %d -->",page[i]);
      if (flag == 0)
	{
	  int min = 0, k = 0;
	  while (k < nofaults - 1) { if (fcount[min] > fcount[k + 1])
		min = k + 1;
	      k++;
	    }
	  frame[min] = page[i];
	  fcount[min] = i + 1;
	  count++;
	  while (j < nofaults)

	    {
	      printf("\t|%d|",frame[j]);
	      j++;
	    }
	}
      i++;
    }
  printf("\n\t***\n");
  printf("\n\t Total number of page Faults:%d",count);
  return 0;
}
