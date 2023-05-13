#include <stdio.h>
#include <math.h>
int main()
{
	int size,head;
	printf("Enter the number of Tracks-");
	scanf("%d",&size);

	printf("Enter the current track-");
	scanf("%d",&head);
	
	int arr[size];
    
   	printf("Enter the Tracks-");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
    }
	int seek_count = 0;
    int cur_track, distance;
   
    for(int i=0;i<size;i++)
       {
        cur_track = arr[i];
        distance = fabs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }
   
    printf("Average head movement- %d\n",(seek_count/size));
    return 0;
}
 
