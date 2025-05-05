#include<stdio.h>
#include<string.h>
int main(){
	int portalChoice;
	do{
	printf("--------------------EMPLOYEE MANAGEMENT SYSTEM-------------------------\n");
	printf("1)Admin Menu\n");
	printf("2)Employee Menu\n");
	printf("3)Payroll System\n");
	printf("4)Exit\n");
	printf("\nEnter your choice (1-4): ");
	scanf("%d",&portalChoice);
	if(portalChoice==1){
		printf("---Welcome to Admin's Portal-----\n");
		printf("Enter your password:"); 
		
		
	}
	else if(portalChoice==2){
		printf("---Welcome to Employee's Portal-----\n");
		printf("Enter your password:");
		
	}
	else if(portalChoice==3){
		printf("-------PayRoll System-------\n");
		
	}
	else if(portalChoice==4){
		printf("Exiting the program\n");
	}
} 
while(choice!=4);
	return 0;
}
