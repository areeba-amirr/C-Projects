#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_EMPLOYEES 20
#define MONTHS 12
#define FULL_WORKING_DAYS 30
#define DAILY_WAGE 1000  // Change this as per your wage policy

int monthlyAttendance[MAX_EMPLOYEES][MONTHS] = {0};  // place this globally

// Employee structure
typedef struct {
    int id;
    char name[50];
    char email[100];
    char password[20];
} Employee;

// Function prototypes
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

//Hardcoded data
Employee employees[MAX_EMPLOYEES] = {
    {112, "Areeba", "areebaamir826@gmail.com", "345"},
    {113, "Ali", "ali@gmail.com", "123"},
    {114, "Sara", "sara@gmail.com", "abc"},
    {115, "Ahmed", "ahmed@gmail.com", "789"},
    {116, "Fatima", "fatima@gmail.com", "fat123"},
    {117, "Usman", "usman@gmail.com", "usm456"},
    {118, "Zara", "zara@gmail.com", "zara999"},
    {119, "Bilal", "bilal@gmail.com", "bil321"},
    {120, "Hira", "hira@gmail.com", "hira88"},
    {121, "Imran", "imran@gmail.com", "imran007"},
    {122, "Asma", "asma@gmail.com", "asma123"},
    {123, "Kamran", "kamran@gmail.com", "kam999"},
    {124, "Nida", "nida@gmail.com", "nid234"},
    {125, "Tariq", "tariq@gmail.com", "tar987"},
    {126, "Hassan", "hassan@gmail.com", "has000"},
    {127, "Rabia", "rabia@gmail.com", "rab321"},
    {128, "Saad", "saad@gmail.com", "saad321"},
    {129, "Aiman", "aiman@gmail.com", "aim987"},
    {130, "Fahad", "fahad@gmail.com", "fah111"},
    {131, "Lubna", "lubna@gmail.com", "lub123"}
};
int totalAttendance[MAX_EMPLOYEES] = {0}; // Stores total present days out of 30
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
                    printf("1) Mark Attendance\n");
                    printf("2) Manage Leave Requests\n");
                    printf("3) Schedule Shifts\n");
                    printf("4) Calculate Salary\n");
                    printf("5) Send Notifications\n");
                    printf("6) Logout\n");
                    printf("Enter your choice (1-6): ");
                    scanf("%d", &adminChoice);

                    switch (adminChoice) {
                        case 1: markAttendance(); break;
                        case 2: manageLeaveRequests(); break;
                        case 3: scheduleShifts(); break;
                        case 4: calculateSalary(); break;
                        case 5: sendNotifications(); break;
                        case 6: printf("Logging out...\n"); break;
                        default: printf("Invalid choice!\n"); break;
                    }
                } while (adminChoice != 6);
            }
        }
        else if (portalChoice == 2) {
            int empId;
            char empPass[20];
            int attempts = 3;
            int found = 0;

            printf("---Welcome to Employee's Portal-----\n");
            while (attempts > 0) {
                printf("Enter your ID: ");
                scanf("%d", &empId);
int i;
                for ( i = 0; i < MAX_EMPLOYEES; i++) {
                    if (employees[i].id == empId) {
                        found = 1;
                        int passAttempts = 3;
                        while (passAttempts > 0) {
                            printf("Enter your password: ");
                            scanf("%s", empPass);
                            if (strcmp(empPass, employees[i].password) == 0) {
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
                                break;
                            } else {
                                passAttempts--;
                                printf("Incorrect password! Attempts left: %d\n", passAttempts);
                                if (passAttempts == 0) {
                                    printf("Too many incorrect password attempts.\n");
                                    char opt;
                                    printf("Forgot password? (Y/N): ");
                                    scanf(" %c", &opt);
                                    if (opt == 'Y' || opt == 'y') {
                                        forgotPassword();
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
                if (!found) {
                    attempts--;
                    printf("Invalid ID! Attempts left: %d\n", attempts);
                }
                if (found || attempts == 0) break;
            }
            if (!found && attempts == 0) {
                printf("Too many failed ID attempts. Exiting program.\n");
                exit(0);
            }
        }

        else if (portalChoice == 3) {
            printf("Payroll system module.\n");
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

// Function definitions 

void markAttendance() {
    const char* monthNames[MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    const int monthWorkingDays[MONTHS] = {
        31, 28, 31, 30, 31, 30, 
        31, 31, 30, 31, 30, 31
    };

    static int monthlyAttendance[MAX_EMPLOYEES][MONTHS] = {0};

     int monthChoice;

    while (1) {
        printf("\n--- Select Month to Mark Attendance ---\n");
        for (int i = 0; i < MONTHS; i++) {
            printf("%d) %s\n", i + 1, monthNames[i]);
        }
        printf("0) Exit to Admin Menu\n");

        printf("Enter month number (1-12, 0 to exit): ");
        scanf("%d", &monthChoice);

        if (monthChoice == 0) {
            printf("Returning to Admin Menu...\n");
            break;
        } else if (monthChoice < 1 || monthChoice > 12) {
            printf("Invalid month. Try again.\n");
            continue;
        }

        int maxDays = monthWorkingDays[monthChoice - 1];

        while (1) {
            int empId;
            printf("\nEnter Employee ID to mark attendance:\n");
            printf("(-1 to change month, 0 to exit to Admin Menu): ");
            scanf("%d", &empId);

            if (empId == 0) {
                printf("Exiting to Admin Menu...\n");
                return;
            }
            if (empId == -1) {
                printf("Changing month...\n");
                break;
            }

            int found = 0;
            for (int i = 0; i < MAX_EMPLOYEES; i++) {
                if (employees[i].id == empId) {
                    found = 1;

                    // Check if attendance already marked
                    if (monthlyAttendance[i][monthChoice - 1] > 0) {
                        printf("Attendance already marked for %s in %s.\n", 
                               employees[i].name, monthNames[monthChoice - 1]);
                        break;
                    }

                    int presentDays;
                    printf("Enter number of days %s was present in %s (0-%d): ", 
                           employees[i].name, monthNames[monthChoice - 1], maxDays);
                    scanf("%d", &presentDays);

                    if (presentDays < 0 || presentDays > maxDays) {
                        printf("Invalid input. Attendance not recorded.\n");
                    } else {
                        monthlyAttendance[i][monthChoice - 1] = presentDays;
                        printf("Attendance recorded for %s: %d/%d days.\n", 
                               employees[i].name, presentDays, maxDays);
                    }
                    break;
                }
            }

            if (!found) {
                printf("Employee ID not found. Try again.\n");
            }
        }
    }
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

