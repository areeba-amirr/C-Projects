#include <stdio.h>
#include <string.h>

int main() {
    int portalChoice;

    do {
        printf("\n--------------------EMPLOYEE MANAGEMENT SYSTEM-------------------------\n");
        printf("1) Admin Menu\n");
        printf("2) Employee Menu\n");
        printf("3) Payroll System\n");
        printf("4) Exit\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &portalChoice);

        if (portalChoice == 1) {

            char adminPassword[] = "admin123"; // Yhn password hardcode kia h admin portal access krny ky  liye !!
            char enteredPassword[20];
            int attempts = 3, success = 0;

            printf("---Welcome to Admin's Portal-----\n");

            while (attempts > 0) {
                printf("Enter your password: ");
                scanf("%s", enteredPassword);

                if (strcmp(enteredPassword, adminPassword) == 0) {
                    success = 1;
                    break;
                } else {
                    attempts--;
                    printf("Incorrect password! Attempts left: %d\n", attempts);
                    if (attempts == 0) {
                        printf("Too many failed attempts. Returning to main menu.\n");
                    }
                }
            }

            if (success) {
                int adminChoice;
                do {
                    printf("\n---Admin Menu---\n");
                    printf("1) Add Employee\n");
                    printf("2) Mark Attendance\n");
                    printf("3) Manage Leave Requests\n");
                    printf("4) Schedule Shifts\n");
                    printf("5) Calculate Salary\n");
                    printf("6) Send Notifications\n");
                    printf("7) Logout\n");
                    printf("Enter your choice (1-7): ");
                    scanf("%d", &adminChoice);

                    switch (adminChoice) {
                        // spaces chordiye hn bd mn discuss krk add krdeingy !
                        case 1:
                            
                            break;
                        case 2:
                            
                            break;
                        case 3:
                           
                            break;
                        case 4:
                           
                            break;
                        case 5:
                            
                            break;
                        case 6:
                            
                            break;
                        case 7:
                          
                            break;
                        default:
                            
                            break;
                    }
                } while (adminChoice != 7);
            }
        } 
        else if (portalChoice == 2) {
         
            char employeePassword[] = "employee123";
            char enteredPassword[20];
            int attempts = 3, success = 0;

            printf("---Welcome to Employee's Portal-----\n");

            while (attempts > 0) {
                printf("Enter your password: ");
                scanf("%s", enteredPassword);

                if (strcmp(enteredPassword, employeePassword) == 0) {
                    success = 1;
                    break;
                } else {
                    attempts--;
                    printf("Incorrect password! Attempts left: %d\n", attempts);
                    if (attempts == 0) {
                        printf("Too many failed attempts. Returning to main menu.\n");
                    }
                }
            }
            if (success) {
                int employeeChoice;
                do {
                    printf("\n---Employee Menu---\n");
                    printf("1) Apply for Leave\n");
                    printf("2) View Salary\n");
                    printf("3) View Leave Status\n");
                    printf("4) Enter Preferred Shifts\n");
                    printf("5) View Assigned Shifts\n");
                    printf("6) Check Performance\n");
                    printf("7) Forgot Password\n");
                    printf("8) Logout\n");
                    printf("Enter your choice (1-8): ");
                    scanf("%d", &employeeChoice);

                    switch (employeeChoice) {
                        case 1:
                        
                            break;
                        case 2:
                          
                            break;
                        case 3:
                            
                            break;
                        case 4:
                           
                            break;
                        case 5:
                           
                            break;
                        case 6:
                         
                            break;
                        case 7:
                          
                            break;
                        case 8:
                    
                            break;
                        default:
                            
                            break;
                    }
                } while (employeeChoice != 8);
            }
        } 
        else if (portalChoice == 3) {
           
        } 
        else if (portalChoice == 4) {
            printf("Exiting the program.\n");
        } 
        else {
            printf("Invalid Choice! Please enter a choice between (1-4)\n");
        }

    } while (portalChoice != 4);

    return 0;
}
