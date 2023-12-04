#include<stdio.h>
#include<signal.h>
// Handler for SIGINT, caused by
// Ctrl-C at keyboard
void handle_sigint(int sig)    // Signal Handler                         
{
    printf("Caught signal %d\n", sig);
}
int main()
{
	signal(SIGINT, handle_sigint); // Registering a Signal 
	while (1)
	{
		printf(“hello world\n”);
		sleep(1);
	}
	return 0;
}
