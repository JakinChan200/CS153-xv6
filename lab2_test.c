#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
	if (argc == 1) {
		printf(1, "Format as lab2_test #\n");
		return 0;
	}
	
	int PScheduler(void);
	int B1(void);
	// int WScheduler(void);

    printf(1, "\n This program tests the correctness of your lab#2\n");
  
	if (atoi(argv[1]) == 1) 
		PScheduler();
	else if (atoi(argv[1]) == 2)
		B1();
	// WScheduler();
	return 0;
 }
  
    
int PScheduler(void) {
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

	int pid;
	int i,j,k;
	int pr;
  
    printf(1, "\n  Step 2: Testing the priority scheduler and setPriority(int priority)) system call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31.\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10.\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0.\n");
    setPriority(0);
    for (i = 0; i < 3; i++) {
		pid = fork();
		if (pid > 0) {
			continue;
		}
		else if (pid == 0) {
			pr = 30-10*i;
			// if (i == 0) {
			// 	pr = 1;
			// }	
			// else if (i == 1) {
			// 	pr = 20;
			// }	
			// else if (i == 2) {
			// 	pr = 19;
			// }
			setPriority(pr);
			for (j=0;j<50000;j++) {
				for(k=0;k<1000;k++) {
					asm("nop");
				}
			}
			printf(1, "\n child# %d with priority %d has finished! \n",getpid(),pr/*getPriority()*/);		
			exit();
		}
		else {
			printf(2," \n Error \n");
		}
	}

	if(pid > 0) {
		for (i = 0; i < 3; i++) {
			wait();
		}
		printf(1,"\n If processes with highest priority finished first then it's correct \n");
	}

	exit();		
	return 0;
}

int B1(void) {
	int i,j,k, pr, pid;
	for (i = 0; i < 3; i++) {
		pid = fork();
		if (pid > 0) {
			continue;
		}
		else if (pid == 0) {
			pr = i*10;
			printf(1, " Started with %d.\n", pr);
			setPriority(pr);
			for (j=0;j<50000;j++) {
				for(k=0;k<1000;k++) {
					asm("nop");
				}
			}
			printf(1, "\n child# %d with priority %d has finished! \n",getpid(),getPriority());		
			exit();
		}
		else {
			printf(2," \n Error \n");
		}
	}
	if(pid > 0) {
		for (i = 0; i < 3; i++) {
			wait();
		}
		printf(1,"\n If processes end with a different priority then it's correct \n");
	}
	exit();
	return 0;
}

// int WScheduler(void) {
//   int pid;
//   int pid2;
//    setPriority(0);
 
//   pid = fork();
//   pid2 = fork();

//   if (pid > 0){
//      setPriority(25);
//      printf(1, "\n Parent process has priority %d before waiting \n", getpstat());
//      wait();
//      printf(1, "\n We are done waiting and will now exit the parent with priority %d.\n", getpstat());
//      exit();
//   }
//   else if(pid == 0){
//      setPriority(15);
//      printf(1, "\n The child process has priority %d before waiting \n", getpstat());
//      wait();
//      printf(1, "\n We are now done waiting and will exit the child process with priority %d \n", getpstat());
//      exit();
//   }
   
//   else if (pid2 > 0){
//      setPriority(7);
//      printf(1, "\n Parent process has priority %d before waiting \n", getpstat());
//      wait();
//      printf(1, "\n We are done waiting and will now exit the parent with priority %d.\n", getpstat());
//      exit();
//   }
//   else if (pid2 == 0){
//      setPriority(14);
//      printf(1, "\n The child process has priority %d before waiting \n", getpstat());
//      wait();
//      printf(1, "\n We are now done waiting and will exit the child process with priority %d \n", getpstat());
//      exit();
//   }

//   return 0;      
// }