#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
printf("execlp----\n");
pid_t cpid = fork();
char *file1 = "fact";
char *file2 = "p";
char *arg1 = "Hello world!";

if(cpid==-1){
printf("FOrk failed");

}
else if(cpid==0){
printf("Process ID of child : %d\n",getpid());
execl(file1, arg1, NULL);
}
else{
printf("Process ID of parent : %d\n",getpid());
execl(file2, arg1,NULL);
}
printf("ENd of fork system call");
}
