#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>

int main(){
	pid_t process = fork();
	if(process<0){
		printf("Error!");
		exit(0);
	}
	else if(process==0){
		printf("Inside child\n");
		printf("pid of process is: %d\n",getpid());
		printf("pid of parent process is: %d\n",getppid());
	}
	else {
		sleep(3);
		printf("Inside parent\n");
		printf("pid of process is: %d\n",getpid());
		printf("pid of child process is: %d\n",process);
	}
	return 0;
}