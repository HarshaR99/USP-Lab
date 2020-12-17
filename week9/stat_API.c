#include <stdio.h> 
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include<time.h>
#include<unistd.h>

void permissions(struct stat fileStat){
	printf("File Permissions: \n");
	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
}

void attributes(struct stat stats){
	struct tm dt;
	printf("\nFIle attributes\n");
	printf("\nFile size: \t %ld", stats.st_size);	
	printf("\nNumber of Links: \t%ld", stats.st_nlink);
	printf("\nFile inode Number: \t%ld",stats.st_ino);		
	dt = *(gmtime(&stats.st_ctime));
	printf("\nFile Created On: \t%d-%d-%d\t%d:%d:%d", dt.tm_mday,dt.tm_mon,dt.tm_year + 1900, dt.tm_hour, dt.tm_min, dt.tm_sec);	
	dt = *(gmtime(&stats.st_mtime));
	printf("\nFile Last Modified On: \t%d-%d-%d\t%d:%d:%d\n", dt.tm_mday,dt.tm_mon,dt.tm_year + 1900, dt.tm_hour, dt.tm_min, dt.tm_sec);
	printf("The file %s a symbolic link\n", (S_ISLNK(stats.st_mode)) ? "is" : "is not");
	printf("The file %s a regular file\n", (S_ISREG(stats.st_mode)) ? "is" : "is not");	
}

int main(){
	char path[20];
	struct stat buf,lbuf; // does not work if declared as pointer eg. *buf is used
	printf("Enter the File Path: ");
	scanf("%s", path );
	
	int status_stat = stat(path,&buf);
	
	if (status_stat==0){
		permissions(buf);
		attributes(buf);
	}
	else{
		printf("Error!\n");
		printf("status :%d\n", status_stat);
		exit(0);
	}

	

	return 0;
}