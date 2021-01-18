#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16

int main(){

/*
fd[0] is read end
fd[1] is write end
*/
int fd[2];
if(pipe(fd)==-1){
	printf("Pipe didn't work");
	exit(1);
}

pid_t pid = fork();
if(pid==0){

char *msg = "Hello Parent!";
write(fd[1],msg,MSGSIZE);
printf("Child\n");
printf("fd[0]: %d\n",fd[0]);
printf("fd[1]: %d\n", fd[1]);
close(fd[0]);
close(fd[1]);
}

else {
sleep(1);
char buf[MSGSIZE];
read(fd[0],buf,MSGSIZE);
printf("From child:\n");
printf("%s\n",buf );
printf("Parent\n");
printf("fd[0]: %d\n",fd[0]);
printf("fd[1]: %d\n", fd[1]);
close(fd[1]);
close(fd[0]);
}

return 0;
}
