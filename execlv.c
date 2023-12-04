#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(void) {
char *file = "/usr/bin/bash";
char *arg1 = "-c";
char *arg2 = "echo $ENV1 $ENV2!";
char *const env[] = {"ENV1=Hello", "ENV2=World", NULL};
printf("execle----\n");
pid_t cpid = fork();
char *file1 = "./fact";
char *file2 = "./p";
if(cpid==-1){
printf("FOrk failed");

}
else if(cpid==0){
printf("Process ID of child : %d\n",getpid());
execle(file1,file, arg1, NULL,env);
}
else{
printf("Process ID of parent : %d\n",getpid());
execle(file2,file, arg1,NULL,env);
}
printf("ENd of fork system call");
	return 0;
}
