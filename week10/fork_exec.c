#include<stdio.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t pid = fork();
	int wstatus;
	if(pid==0){
		printf("Child process\n");
		char *arg[] = {"/bin/ls", "-l", NULL};
		execv(arg[0],arg);
	}
	else{
		wait(&wstatus);
		printf("Parent process\n");
		printf("Child process exited with status: %d",WEXITSTATUS(wstatus));
	}
	return 0;
}