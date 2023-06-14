#include <stdio.h>
#include<stdlib.h>
#include<sys/queue.h>
struct semaphore{
	Queue<process> q;
	int value;
};

void P(struct semaphore s)
{
	if (s.value == 1) {
		s.value = 0;
	}
	else {
		s.q.push(P);
		sleep();
	}
}

void V(Semaphore s)
{
	if (s.q is empty) {
		s.value = 1;
	}
	else {
		Process p = q.front();
		q.pop();
		wakeup(p);
	}
}
int main() {
	printf("Process is done");
	return 0;
}

