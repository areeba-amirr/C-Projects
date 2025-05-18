#include<stdio.h>
#include<conio.h>
struct Employee{
    int id;
    char name[50];
    char email[100];
    char password[20];
};
void getMaskedPassword(char *password, int maxLen) { //password(inputted password)  maxLen(length of password array)
    int i = 0;
    char ch;
    
    while (1) {
        ch = getch(); // Read character without echoing
        
        // Enter key (end input)
        if (ch == 13) { // ASCII 13 = Enter
            break;
        }
        // Backspace
        else if (ch == 8) { // ASCII 8 = Backspace
            if (i > 0) {
                i--;
                printf("\b \b"); // Move cursor back, overwrite with space, move back again
            }
        }
        // Regular character input
        else if (i < maxLen - 1) {
            password[i++] = ch;
            printf("*");
        }
    }
    
    password[i] = '\0'; // Null-terminate string
    printf("\n");
}
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
    printf("Enter your password: ");
    getMaskedPassword(emp.password, 50);
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