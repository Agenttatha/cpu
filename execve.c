#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
printf("execve----\n");
pid_t cpid = fork();
char *args[]={"fact",NULL};
char *args1[]={"p",NULL};
char *envp[] = {"VAR=value", NULL};
if(cpid==-1){
printf("FOrk failed");
exit(EXIT_FAILURE);
}
else if(cpid==0){
printf("Process ID of child : %d\n",getpid());
execve(args[0], args, envp);
}
else{
printf("Process ID of parent : %d\n",getpid());
execve(args1[0], args1, envp);
}
printf("End of fork system call");
}
