#include <stdio.h>
#include <string.h>

// Function prototypes (sab ka return type void hai)
void addEmployee();
void markAttendance();
void manageLeaveRequests();
void scheduleShifts();
void calculateSalary();
void sendNotifications();
void applyForLeave();
void viewSalary();
void viewLeaveStatus();
void enterPreferredShifts();
void viewAssignedShifts();
void checkPerformance();
void forgotPassword();

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

            char adminPassword[] = "admin123";
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
                        case 1:
                            addEmployee();
                            break;
                        case 2:
                            markAttendance();
                            break;
                        case 3:
                            manageLeaveRequests();
                            break;
                        case 4:
                            scheduleShifts();
                            break;
                        case 5:
                            calculateSalary();
                            break;
                        case 6:
                            sendNotifications();
                            break;
                        case 7:
                            printf("Logging out...\n");
                            break;
                        default:
                            printf("Invalid choice! Please select between 1-7.\n");
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
                            applyForLeave();
                            break;
                        case 2:
                            viewSalary();
                            break;
                        case 3:
                            viewLeaveStatus();
                            break;
                        case 4:
                            enterPreferredShifts();
                            break;
                        case 5:
                            viewAssignedShifts();
                            break;
                        case 6:
                            checkPerformance();
                            break;
                        case 7:
                            forgotPassword();
                            break;
                        case 8:
                            printf("Logging out...\n");
                            break;
                        default:
                            printf("Invalid choice! Please select between 1-8.\n");
                            break;
                    }
                } while (employeeChoice != 8);
            }
        } 
        else if (portalChoice == 3) {
            printf("Payroll system module not implemented yet.\n");
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

// Function definitions (abhi ke liye sirf printf statements)
void addEmployee() {
    printf("[Admin] Adding a new employee...\n");
}

void markAttendance() {
    printf("[Admin] Marking attendance...\n");
}

void manageLeaveRequests() {
    printf("[Admin] Managing leave requests...\n");
}

void scheduleShifts() {
    printf("[Admin] Scheduling shifts...\n");
}

void calculateSalary() {
    printf("[Admin] Calculating salary...\n");
}

void sendNotifications() {
    printf("[Admin] Sending notifications...\n");
}

void applyForLeave() {
    printf("[Employee] Applying for leave...\n");
}

void viewSalary() {
    printf("[Employee] Viewing salary details...\n");
}

void viewLeaveStatus() {
    printf("[Employee] Viewing leave status...\n");
}

void enterPreferredShifts() {
    printf("[Employee] Entering preferred shifts...\n");
}

void viewAssignedShifts() {
    printf("[Employee] Viewing assigned shifts...\n");
}

void checkPerformance() {
    printf("[Employee] Checking performance...\n");
}

void forgotPassword() {
    printf("[Employee] Forgot password process...\n");
}

