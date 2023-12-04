#include<stdio.h>
#include<signal.h>
#include<unistd.h>
// Handler for SIGINT, caused by
// Ctrl-C at keyboard
void handle_sigchild(int sig)    // Signal Handler                         
{
    printf("Inside child signal %d \n", sig);
    //signal(SIGINT,SIG_DFL); //De registering Signal 
    
}
int main()
{
	signal(SIGCHLD, handle_sigchild); // Registering a Signal 
	int p=fork();
	if(p==0)
	{
	  printf("Inside Child process \n");
	  //
	  printf("End of child Process \n");
	  }
	  else if(p>=0)
	  {
	    printf("Inside parent process \n");
	    wait();
	    printf("End of parent process \n");
	   } 
	
	
	return 0;
}
