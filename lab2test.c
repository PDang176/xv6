#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
	
	int PScheduler(void);

  printf(1, "\n This program tests the correctness of your lab#2\n");
  
	PScheduler();
	return 0;
}
  
    
int PScheduler(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

  int pid;
	int priority[5] = {22, 13, 18, 6, 30};
  int i,j,k;
  
  printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) systema call:\n");
  printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
  printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
  printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");
  set_prior(0);
  for (i = 0; i <  5; i++) {
		pid = fork();
		if (pid > 0 ) {
			continue;
		}
		else if ( pid == 0) {
			set_prior(priority[i]);	
			for (j=0;j<50000;j++) {
				asm("nop");	
				for(k=0;k<1000;k++) {
					asm("nop"); }
			}
			printf(1, "\n Child# %d with priority %d has finished! \n", getpid(), priority[i]);
			exit();
  	}
  	else {
			printf(2," \n Error \n");	
  	}
	}

	if(pid > 0) {
		for (i = 0; i <  5; i++) {
			wait();
		}
  	printf(1,"\n If processes with highest priority finished first then its correct \n");
	}
	
	exitS(0);		
	return 0;
}
