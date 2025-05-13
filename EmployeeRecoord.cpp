#include<stdio.h>
struct Employee{
    int id;
    char name[50];
    char email[100];
    char password[20];
};
void employeeRecord(){
	int totalEmployees;
	struct Employee emp;
	FILE *ptr=fopen("Employee Record.dat","ab");	
	printf("Enter total no of employees:");
	scanf("%d",&totalEmployees);
	for(int i = 0;i < totalEmployees;i++){
		printf("Id:");
		scanf("%d",&emp.id);
		printf("Name:");
		scanf("%s",&emp.name);
		printf("Email:");
		scanf("%s",&emp.email);
		printf("Password:");
		scanf("%s",&emp.password);
		 fwrite(&emp, sizeof(emp), 1, ptr); 
	}
	fclose(ptr);
	printf("Record Added Successfully\n");
	}
	void displayRecord(){
	FILE *ptr=fopen("Employee Record.dat","rb");
	if(ptr==NULL){
		printf("Error in opening file\n");
		fclose(ptr);}
			else{
			struct Employee emp;
            int index = 0;
			  printf("\nAll Student Records:\n");
    while (fread(&emp, sizeof(emp), 1, ptr) == 1) {
        printf("Index %d => Id: %d, Name: %s, Email:%s ,Password:%s\n", index, emp.id,emp.name,emp.email,emp.password );
        index++;
    }
    fclose(ptr);
}
	}

int main(){
// employeeRecord();
  displayRecord();
	return 0;
}
