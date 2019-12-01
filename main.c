#include <stdio.h>
#include "myBank.h"

int main(){
	
	int counter =0;		//last free account number. to keep track for the next new openAccount func
    	char func = 'a';	
    	printf("Enter Transaction Type1: \n");
    	scanf("	%c", &func);
    	while (func!= 'E') {
        	switch (func) {
            	case 'O':{
                	openAccount(counter++);
                	break;
		}	
            	case 'B':{
                	checkBalance();
                	break;
		}
            	case 'D':{
                	depositing();
                	break;
		}
            	case 'W':{
                	withrawal();
                	break;
		}
            	case 'C':{
                	closeAccount();
                	break;
		}
            	case 'I':{
                	interest();
                	break;
		}
            	case 'P':{
                	printAllOpen();
                	break;
		}
            	case 'E':{
                	exitallprogram();
                	break;
		}
            	default:
                	printf(" ");
        }
        printf("Enter Transaction Type: \n");
        scanf("	%c", &func);
    }
	return 0;
}
