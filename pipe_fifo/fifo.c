#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<sys/wait.h>

#define MSGSIZE 16

int main(){

	if ( mkfifo("myfifo",0777) == -1 ){
		printf("FIFO File exists\n");
	}

	int fd = open("myfifo",O_RDWR,0644);

	pid_t pid = fork();

	if(pid==0){
		char msg[MSGSIZE] = "Hello Parent!";
		write(fd,msg,MSGSIZE);
		close(fd);
	}

	else {
		wait(NULL);
		char rev[MSGSIZE];
		read(fd,rev,MSGSIZE);
		printf("y: %s\n",rev);
		close(fd);
	}

	return 0;
}