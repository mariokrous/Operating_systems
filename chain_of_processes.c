#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define  N    5

int main()
{
	int i;
	int pid;

	for (i=0; i<N; i++)
	{
		pid = fork();
		
		if (pid > 0)
		{
			//inside father process
			if (i > 0)
			{
				//first-fork: main function becomes parent process
				//we want to print only child processes

				printf(" Father = %5i, Id = %5i, Child = %5i\n", getppid(), getpid(), pid);
				
			}
			wait(NULL);
				//kathe fora kanoume fork sto paidi pou dimiourgoume(sximatismos alusidas) 
				//we fork child process
				//we use break statement in parent's process in order not to fork
				break;
		}

		if (i==4)
			// last fork()
			if (pid==0)
			{
				//inside last-created child process
				printf("Father = %5i, Id = %5i, Child = -\n", getppid(), getpid() );
			}

	}

	return (0);
}
