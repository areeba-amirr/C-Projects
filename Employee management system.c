#include <stdio.h>
#include <string.h>
#include <conio.h> 
#include <stdlib.h>
#define MAX_EMPLOYEES 10
#define MONTHS 12
#define BASE_SALARY_PER_DAY 3000
#define OVERTIME_PER_DAY 1000

int totalAttendance[MAX_EMPLOYEES] = {0}; // Stores total present days out of 30
Employee employees[MAX_EMPLOYEES]; // Track Data for each employee 
LeaveRecord leaveRecords[MAX_EMPLOYEES]; // Track leaves for each employee 
int salaryRecord[MAX_EMPLOYEES][MONTHS] = {0};  // Stores monthly salary for each employee
int monthlyAttendance[MAX_EMPLOYEES][MONTHS] = {0};  ///Stores monthly attendance for each employee

// Employee structure
struct Employee {
    int id;
    char name[50];
    char email[100];
    char password[20];
};
//structure to store Attendace
struct attendance{
	int empId;
	int month;
	int presentDays;
};
//structure to store leave
struct Leave {
    int employeeID;
    char leaveType[20]; // e.g., "Annual" or "Sick"
    int month;          // 1 - 12
    int count;          // Number of leave days taken in that month
};
//structure for leavetypes
struct LeaveRecord {
    int sickLeave[12];       // 12 months
    int emergencyLeave[12];
    int halfDayLeave[12];
    int totalLeavesYear;     // Sum of all leaves taken in the year
};
//Overtime Structure
struct Overtime {
    int empId;
    int month; // 1 to 12
    int hours; // Overtime hours for the month
};
//Salary record
struct salaryRecord {
    int empId;
    int month;
    int year;
    int salary;
};
//salaries(in enmployee menu)
struct Salary {
    int id;
    float monthlySalary;
};

// Function prototypes
void getMaskedPassword(char *password, int maxLen);
void loadEmployeesFromFile();
void markAttendance();
void manageLeaveRequests();
void enterOvertime();
void calculateSalary();
void viewSalary(int employeeID);
void payrollSystem();
void viewLeaveStatus(int employeeID);
void checkPerformance(int employeeID);
void payrollSystem();


//int totalAttendance[MAX_EMPLOYEES] = {0}; // Stores total present days out of 30
int main() {
    int portalChoice;

    do {
        printf("************************************************************************************************************************");
        printf("\n                                             EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("************************************************************************************************************************\n");
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

             printf("------------------------------------------------Welcome to Admin's Portal----------------------------------------------\n");

            while (attempts > 0) {
                printf("Enter your password: ");
                getMaskedPassword(enteredPassword, 20);

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
                    printf("\n---------------Admin Menu----------------\n");
                    printf("1) Mark Attendance\n");
                    printf("2) Manage Leave Requests\n");
                    printf("3) Calculate Salary\n");
                    printf("4) Logout\n");
                    printf("Enter your choice (1-4): ");
                    scanf("%d", &adminChoice);

                    switch (adminChoice) {
                        case 1: markAttendance(); break;
                        case 2: manageLeaveRequests(); break;
                        case 3: calculateSalary(); break;
                        case 4: printf("Logging out...\n"); break;
                        default: printf("Invalid choice!\n"); break;
                    }
                } while (adminChoice != 4);
            }
        }
        else if (portalChoice == 2) {
            int empId;
            char empPass[20];
            int attempts = 3;
            int found = 0;

            printf("---------------------------------------------Welcome to Employee's Portal----------------------------------------------\n");
            while (attempts > 0) {
            	loadEmployeesFromFile();
                printf("Enter your ID: ");
                scanf("%d", &empId);
int i;
                for ( i = 0; i < MAX_EMPLOYEES; i++) {
                    if (employees[i].id == empId) {
                        found = 1;
                        int passAttempts = 3;
                        while (passAttempts > 0) {
                            printf("Enter your password: ");
                             getMaskedPassword(empPass, 20);
                            if (strcmp(empPass, employees[i].password) == 0) {
                                int employeeChoice;
                do {
                    printf("\n------------Employee Menu-----------\n");
                    printf("1) View Salary\n");
                    printf("2) View Leave Status\n");
                    printf("3) Check Performance\n");
                    printf("4) Logout\n");
                    printf("Enter your choice (1-4): ");
                    scanf("%d", &employeeChoice);

                    switch (employeeChoice) {
                        case 1:
                           viewSalary();
                            break;
                        case 2:
                            viewLeaveStatus();
                            break;
                        case 3:
                            checkPerformance();
                            break;
                        case 4:
                           printf("Logging out...\n");
                            break;
                        default:
                            printf("Invalid choice! Please select between 1-4.\n");
                            break;
                    }
                } while (employeeChoice != 4);
                                break;
                            } else {
                                passAttempts--;
                                printf("Incorrect password! Attempts left: %d\n", passAttempts);
                                if (passAttempts == 0) {
                                    printf("Too many incorrect password attempts.\n");
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
            payrollsystem();
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
void getMaskedPassword(char *password, int maxLen){
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
void loadEmployeesFromFile() {
    FILE *fp = fopen("Employee Record.dat", "rb");
    if (fp == NULL) {
        printf("Failed to open Employee Record.dat\n");
        return;
    }

    int employeeCount = 0;
    while (fread(&employees[employeeCount], sizeof(struct Employee), 1, fp) == 1) {
        employeeCount++;
        if (employeeCount >= MAX_EMPLOYEES) break;
    }

    fclose(fp);
}
// Mark Attendence  with file handling 
void markAttendance() {
    // List of month names to display in the menu
    const char* monthNames[MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
// Total working days in each month 
    const int monthWorkingDays[MONTHS] = {
        31, 29, 31, 30, 31, 30, 
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
        loadEmployeesFromFile();
        while (1) {
            int empId;
            printf("\nEnter Employee ID to mark attendance for this month:\n");
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
                                         struct attendance att;
                        att.empId = empId;
                        att.month = monthChoice;
                        att.presentDays = presentDays;
                        // Save attendance data to the file for record keeping
                        FILE *afp = fopen("Attendance Record.dat", "ab");
                        if (afp == NULL) {
                            printf("Failed to open Attendance Record.dat\n");
                        } else {
                            fwrite(&att, sizeof(struct attendance), 1, afp);
                            fclose(afp);
                            printf("Attendance recorded for %s: %d/%d days (Saved to file).\n", 
                                   employees[i].name, presentDays, maxDays);
                        }
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
// leave management system with file handling !!
void manageLeaveRequests() {

    int empId, month, leaveCount, leaveType;
    int mainExit = 0;

    printf("[Admin] Leave Management System\n");

    while (!mainExit) {
        int choice;
        printf("\nChoose an option:\n");
        printf("1. Manage Monthly Leaves\n");
        printf("2. View Annual Leave Summary\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
if(choice<0 || choice>2){
	printf("Invalid Choice\n");
	break;
}
        if (choice == 0) {
            printf("Exiting leave management...\n");
            break;
        }
        loadEmployeesFromFile();
        printf("\nEnter Employee ID: ");
        scanf("%d", &empId);

        int empIndex = -1;
        for (int i = 0; i < MAX_EMPLOYEES; i++) {
            if (employees[i].id == empId) {
                empIndex = i;
                break;
            }
        }

        if (empIndex == -1) {
            printf("Employee not found!\n");
            continue;
        }

        if (choice == 1) {
            // ---------- Monthly Leave Management ----------
            int anotherMonth = 1;
            while (anotherMonth) {
                printf("\nEnter month number (1-12) to manage leaves (or 0 to go back): ");
                scanf("%d", &month);

                if (month == 0) break;
               if (month < 1 || month > 12) {
    printf("Invalid month!\n");
    continue;
}

// ? Simple check if already marked
if (leaveRecords[empIndex].sickLeave[month - 1] != 0 ||
    leaveRecords[empIndex].emergencyLeave[month - 1] != 0 ||
    leaveRecords[empIndex].halfDayLeave[month - 1] != 0) {

    printf(" Leave already marked for month %d!\n", month);
    continue;
}


                printf("How many leaves did %s take in month %d? ", employees[empIndex].name, month);
                scanf("%d", &leaveCount);

                if (leaveCount < 1 || leaveCount > 3) {
                    printf("Each employee is allowed only 3 leaves per month.\n");
                    continue;
                }

                int monthlySick = 0, monthlyEmergency = 0, monthlyHalf = 0;

                for (int i = 0; i < leaveCount; i++) {
                    printf("\nEnter type of leave #%d:\n", i + 1);
                    printf("1. Sick Leave\n2. Emergency Leave\n3. Half Day\nEnter choice: ");
                    scanf("%d", &leaveType);

                    switch (leaveType) {
                        case 1: monthlySick++; break;
                        case 2: monthlyEmergency++; break;
                        case 3: monthlyHalf++; break;
                        default:
                            printf("Invalid leave type! Please enter 1, 2, or 3.\n");
                            i--; break;
                    }
                }

                if (monthlySick > 1 || monthlyEmergency > 1 || monthlyHalf > 1) {
                    printf("Leave type limit exceeded! Only 1 of each type allowed per month.\n");
                    continue;
                }
                FILE *lfp = fopen("Leave.dat", "ab");  // open in append mode
if (lfp == NULL) {
    printf("Error opening Leave.dat for writing.\n");
} else {
    struct Leave leave;

    // Save sick leave (if any)
    if (monthlySick > 0) {
        strcpy(leave.leaveType, "Sick");
        leave.employeeID = empId;
        leave.month = month;
        leave.count = 1;
        fwrite(&leave, sizeof(struct Leave), 1, lfp);
    }

    // Save emergency leave (if any)
    if (monthlyEmergency > 0) {
        strcpy(leave.leaveType, "Emergency");
        leave.employeeID = empId;
        leave.month = month;
        leave.count = 1;
        fwrite(&leave, sizeof(struct Leave), 1, lfp);
    }

    // Save half-day leave (if any)
    if (monthlyHalf > 0) {
        strcpy(leave.leaveType, "Half Day");
        leave.employeeID = empId;
        leave.month = month;
        leave.count = 1;
        fwrite(&leave, sizeof(struct Leave), 1, lfp);
    }

    fclose(lfp);
}
                int totalForMonth = monthlySick + monthlyEmergency + monthlyHalf;
                int annualSoFar = leaveRecords[empIndex].totalLeavesYear;

                if (annualSoFar + totalForMonth > 36) {
                    printf("Annual leave limit exceeded! Max 36 allowed per year.\n");
                    continue;
                }

                // Update record
                leaveRecords[empIndex].sickLeave[month - 1] += monthlySick;
                leaveRecords[empIndex].emergencyLeave[month - 1] += monthlyEmergency;
                leaveRecords[empIndex].halfDayLeave[month - 1] += monthlyHalf;
                leaveRecords[empIndex].totalLeavesYear += totalForMonth;

                printf("\n Leave record updated for %s (Month: %d)\n", employees[empIndex].name, month);

                char moreMonth;
                printf("\nDo you want to manage another month for this employee? (Y/N): ");
                scanf(" %c", &moreMonth);
                if (moreMonth != 'Y' && moreMonth != 'y') {
                    anotherMonth = 0;
                }
            }

        } else if (choice == 2) {
            // ---------- Annual Summary ----------
            printf("\n Annual Leave Summary for %s (ID: %d):\n", employees[empIndex].name, employees[empIndex].id);
            printf("Month\tSick\tEmergency\tHalf Day\n");
            for (int m = 0; m < 12; m++) {
                printf("%d\t%d\t%d\t\t%d\n", m + 1,
                       leaveRecords[empIndex].sickLeave[m],
                       leaveRecords[empIndex].emergencyLeave[m],
                       leaveRecords[empIndex].halfDayLeave[m]);
            }
            printf("Total Leaves Taken This Year: %d / 36\n", leaveRecords[empIndex].totalLeavesYear);
        } else {
            printf("Invalid choice. Try again.\n");
        }

        char moreEmp;
        printf("\nDo you want to manage/view another employee? (Y/N): ");
        scanf(" %c", &moreEmp);
        if (moreEmp != 'Y' && moreEmp != 'y') {
            mainExit = 1;
        }
    }
}

void calculateSalary() {
    loadEmployeesFromFile();

    FILE *attFile = fopen("Attendance Record.dat", "rb");
    FILE *otFile = fopen("overtime.dat", "rb");
    FILE *leaveFile = fopen("Leave.dat", "rb");
    FILE *salaryFile = fopen("salaries.dat", "wb");

    if (!attFile || !otFile || !leaveFile || !salaryFile) {
        printf("Error opening one or more required files.\n");
        if (attFile) fclose(attFile);
        if (otFile) fclose(otFile);
        if (leaveFile) fclose(leaveFile);
        if (salaryFile) fclose(salaryFile);
        return;
    }

    struct attendance att;
    struct Overtime ot;
    struct Leave leave;
    struct Salary sal;

    int salaries[MAX_EMPLOYEES][MONTHS] = {0};
    int overtimeHours[MAX_EMPLOYEES][MONTHS] = {0};
    int leaveCount[MAX_EMPLOYEES][MONTHS] = {0};

    // Step 1: Load attendance
    while (fread(&att, sizeof(struct attendance), 1, attFile)) {
        for (int i = 0; i < MAX_EMPLOYEES; i++) {
            if (employees[i].id == att.empId && att.month >= 1 && att.month <= 12) {
                salaries[i][att.month - 1] = att.presentDays * BASE_SALARY_PER_DAY;
                break;
            }
        }
    }
    fclose(attFile);

    // Step 2: Load overtime
    while (fread(&ot, sizeof(struct Overtime), 1, otFile)) {
        for (int i = 0; i < MAX_EMPLOYEES; i++) {
            if (employees[i].id == ot.empId && ot.month >= 1 && ot.month <= 12) {
                overtimeHours[i][ot.month - 1] += ot.hours;
                break;
            }
        }
    }
    fclose(otFile);

    // Step 3: Load all types of leave and count
    while (fread(&leave, sizeof(struct Leave), 1, leaveFile)) {
        for (int i = 0; i < MAX_EMPLOYEES; i++) {
            if (employees[i].id == leave.employeeID && leave.month >= 1 && leave.month <= 12) {
                leaveCount[i][leave.month - 1] += leave.count;
                break;
            }
        }
    }
    fclose(leaveFile);

    // Step 4: Final Salary Calculation
    printf("\n--- Final Salary Report (Attendance + Overtime - All Leaves) ---\n");
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        int totalYearly = 0;
        int totalMonths = 0;

        for (int m = 0; m < MONTHS; m++) {
            if (salaries[i][m] > 0) {
                int base = salaries[i][m];
                int otBonus = overtimeHours[i][m] * 200;
                int leavePenalty = leaveCount[i][m] * 1000;

                int finalSalary = base + otBonus - leavePenalty;
                if (finalSalary < 0) finalSalary = 0;

                salaries[i][m] = finalSalary;
                totalYearly += finalSalary;
                totalMonths++;
            }
        }

        if (totalMonths > 0) {
            sal.id = employees[i].id;
            sal.monthlySalary = (float)totalYearly / totalMonths;
            fwrite(&sal, sizeof(struct Salary), 1, salaryFile);

            // Display
            printf("\nEmployee: %s (ID: %d)\n", employees[i].name, employees[i].id);
            for (int m = 0; m < MONTHS; m++) {
                if (salaries[i][m] > 0) {
                    printf("  Month %2d: Rs. %d\n", m + 1, salaries[i][m]);
                }
            }
            printf("  Yearly Salary: Rs. %d\n", totalYearly);
            printf("--------------------------------------------------\n");
        }
    }

    fclose(salaryFile);
}

void enterOvertime() {
    loadEmployeesFromFile();

    FILE *fp = fopen("overtime.dat", "ab");  // Open in append mode
    if (fp == NULL) {
        printf("Error: Could not open overtime.dat for writing.\n");
        return;
    }

    printf("\n--- Enter Overtime Hours for Employees ---\n");

    char moreEmployees = 'Y';
    while (moreEmployees == 'Y' || moreEmployees == 'y') {
        int empId, empIndex = -1;

        printf("\nEnter Employee ID: ");
        scanf("%d", &empId);

        // Find employee
        for (int i = 0; i < MAX_EMPLOYEES; i++) {
            if (employees[i].id == empId) {
                empIndex = i;
                break;
            }
        }

        if (empIndex == -1) {
            printf("Employee with ID %d not found!\n", empId);
        } else {
            printf("Entering overtime for %s (ID: %d)\n", employees[empIndex].name, empId);
            while (1) {
                int month;
                printf("\nEnter Month (1–12) to add overtime (0 to stop for this employee): ");
                scanf("%d", &month);

                if (month == 0) break;

                if (month < 1 || month > 12) {
                    printf("Invalid month. Try again.\n");
                    continue;
                }

                struct Overtime ot;
                ot.empId = empId;
                ot.month = month;

                printf("Enter overtime hours for month %d: ", month);
                scanf("%d", &ot.hours);

                if (ot.hours < 0) ot.hours = 0;

                fwrite(&ot, sizeof(struct Overtime), 1, fp);
                printf("Overtime saved for Month %d.\n", month);
            }
        }

        printf("\nDo you want to enter overtime for another employee? (Y/N): ");
        scanf(" %c", &moreEmployees);
    }

    fclose(fp);
}
void viewSalary(int employeeID) {
    FILE *file = fopen("salaries.dat", "rb");
    if (file == NULL) {
        printf("Error: Could not open salaries.dat\n");
        return;
    }

    struct Salary {
        int id;
        float monthlySalary;
    } sal;

    int recordCount = 0, found = 0;

    printf("\n--- Reading salaries.dat ---\n");
    while (fread(&sal, sizeof(sal), 1, file)) {
        printf("Read record: ID = %d, Monthly Salary = %.2f\n", sal.id, sal.monthlySalary);
        if (sal.id == employeeID) {
            printf("\n--- Salary Details ---\n");
            printf("Employee ID     : %d\n", sal.id);
            printf("Monthly Salary  : Rs. %.2f\n", sal.monthlySalary);
            printf("Annual Salary   : Rs. %.2f\n", sal.monthlySalary * 12);
            found = 1;
            break;
        }
        recordCount++;
    }

    fclose(file);

    if (!found) {
        printf("No salary record found for Employee ID: %d\n", employeeID);
    }
}

void viewLeaveStatus(int employeeID) {
    FILE *lfp = fopen("Leave.dat", "rb");
    if (lfp == NULL) {
        printf("No leave records found (file missing)!\n");
        return;
    }

    struct Leave leave;
    int leaveFound = 0;

    printf("\n--- Leave Details for Employee ID: %d ---\n", employeeID);
    printf("Month\tLeave Type\tCount\n");
    printf("-----\t----------\t-----\n");

    while (fread(&leave, sizeof(struct Leave), 1, lfp)) {
        if (leave.employeeID == employeeID) {
            leaveFound = 1;
            printf("%2d\t%-10s\t%d\n", leave.month, leave.leaveType, leave.count);
        }
    }

    fclose(lfp);

    if (!leaveFound) {
        printf("No leave records found for your ID.\n");
    }
}


void checkPerformance() {
    printf("[Employee] Checking performance...\n");
}

