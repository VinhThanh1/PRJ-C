#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int day;
    int month;
    int year;
} DateOfBirth;

typedef struct {
    char id[15];
    char name[50];
    char email[50];
    DateOfBirth dateOfBirth; 
    int gender;
    char phone[15];
    char status[10];
} User;

User users[100];
int userCount = 0;

void mainMenu();
void loginAdmin();
void adminMenu();
void addUser();
void showUsers();
void searchUser();
void loginUser();
void userMenu(User *user);
void viewAccountInfo(User *user);
void end();
int backOrExit();
void searchUserById();
void arrangeUser();
void toggleUserStatus();
int isUnique();
int errorUsers();
int notEmptyUsers();
void loadUsers();
void saveUsers();


int main() {
    loadUsers();
    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;
    while (1) {
        printf("\n*** Bank Management System ***\n");
        printf("          CHOOSE YOUR ROLE\n");
        printf("      ========================\n");
        printf("      [1] Admin\n");
        printf("      [2] User\n");
        printf("      [0] Exit the Program\n");
        printf("      ========================\n");
        printf("      Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                loginAdmin();
                break;
            case 2:
                system("cls");
                loginUser();
                break;
            case 0:
                end();
                return;
            default:
                printf("Lua Chon Khong Hop Le\n");
        }
    }
}

void loginAdmin() {
    char email[50], password[50];
    printf("\n*** Bank Management System ***\n");
    printf("               LOGIN\n");
    printf("      ========================\n");
    printf("      Email: ");
    scanf("%s", email);
    printf("      Password: ");
    scanf("%s", password);
    if (strcmp(email, "admin@gmail.com") == 0 && strcmp(password, "admin123") == 0) {
        adminMenu();
    } else {
        printf("Email hoac password khong hop le\n");
    }
}

void loginUser() {
    char email[50], phone[15];
    printf("\n*** Bank Management System ***\n");
    printf("          USER LOGIN\n");
    printf("      ========================\n");
    printf("      Email: ");
    scanf("%s", email);
    printf("      Password: ");
    scanf("%s", phone);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].email, email) == 0 && strcmp(users[i].phone, phone) == 0) {
            printf("\nWelcome %s!\n", users[i].name);
            userMenu(&users[i]);
            return;
        }
    }
    printf("Sai ten tai khoan hoac mat khau. Vui long nhap lai\n");
}

void userMenu(User *user) {
    int choice;
    while (1) {
    	printf("\n*** Bank Management System ***\n");
    	printf("      ========================\n");
        printf("*** User Menu ***\n");
        printf("      [1] View Account \n");
        printf("      [2] Deposit Money\n");
        printf("      [3] Withdraw Money\n");
        printf("      [4] Change Password\n");
        printf("      [0] Exit\n");
        printf("      ========================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	system("cls");
                viewAccountInfo(user);
                if (backOrExit()) {
                    break;
                } else {
                    exit(0);
                }
                break;
            case 2:
            	system("cls");
                printf("no function yet");
                if (backOrExit()) {
                break;
                } else {
                exit(0);
                }
                break;
            case 3:
            	system("cls");
                printf("no function yet");
                if (backOrExit()) {
                break;
                } else {
                exit(0);
                }
                break;
            case 4:
            	system("cls");
                printf("no function yet");
                 if (backOrExit()) {
                break;
                } else {
                exit(0);
                }
                break;
            case 0:
                return;
            default:
                printf("Sai ten tai khoan hoac mat khau. Vui long nhap lai\n");
        }
    }
}

void viewAccountInfo(User *user) {
    printf("\n*** Account Information ***\n");
    printf("ID: %s\n", user->id);
    printf("Name: %s\n", user->name);
    printf("Email: %s\n", user->email);
    printf("Phone: %s\n", user->phone);
    printf("Status: %s\n", user->status);
}

void adminMenu() {
    int choice;
    while (1) {
        printf("\n*** Bank Management System ***\n");
        printf("               Menu\n");
        printf("      ========================\n");
        printf("      [1] Add A New User\n");
        printf("      [2] Show ALL Users\n");
        printf("      [3] Search Users\n");
        printf("      [4] Lock/Unlock A User\n");
        printf("      [5] Search Users By Id\n");
        printf("      [6] Arrange\n");
        printf("      [0] Exit\n");
        printf("      ========================\n");
        printf("      Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                addUser();
                if (backOrExit()) {
                    break;
                } else {
                    exit(0);
                }
                break;
            case 2:
                system("cls");
                showUsers();
                if (backOrExit()) {
                    break;
                } else {
                    exit(0);
                }
                break;
            case 3:
                system("cls");
                searchUser();
                if (backOrExit()) {
                    break;
                } else {
                    exit(0);
                }
                break;
            case 4:
                system("cls");
                toggleUserStatus();
                if (backOrExit()) {
                    break;
                } else {
                    exit(0);
                }
                break;
            case 5:
                system("cls");
                searchUserById();
                if (backOrExit()) {
                    break;
                } else {
                    exit(0);
                }
                break;
            case 6:
                system("cls");
                arrangeUser();
                if (backOrExit()) {
                    break;
                } else {
                    exit(0);
                }
                break;
            case 0:
                end();
                return;
            default:
                printf("Lua Chon Khong Hop Le\n");
        }
    }
}

void addUser() {
    User newUser;
    fflush(stdin);
    printf("Enter ID: ");
    fgets(newUser.id, sizeof(newUser.id), stdin);
    newUser.id[strcspn(newUser.id, "\n")] = 0;
    printf("Enter name: ");
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0;
    printf("Enter email: ");
    fgets(newUser.email, sizeof(newUser.email), stdin);
    newUser.email[strcspn(newUser.email, "\n")] = 0;
    printf("Enter phone: ");
    fgets(newUser.phone, sizeof(newUser.phone), stdin);
    newUser.phone[strcspn(newUser.phone, "\n")] = 0;
    if (!notEmptyUsers(newUser.id, newUser.name, newUser.email, newUser.phone)) {
        return;
    }
    printf("Enter date of birth: \n");
        printf("  Enter the day: ");
        scanf("%d", &newUser.dateOfBirth.day);
        printf("  Enter the month: ");
        scanf("%d", &newUser.dateOfBirth.month);
        printf("  Enter the year: ");
        scanf("%d", &newUser.dateOfBirth.year);
        printf("Enter gender (0 for male, 1 for female): ");
        scanf("%d", &newUser.gender);
        getchar();
    if (errorUsers(newUser.id, newUser.name, newUser.phone) && isUnique(newUser.id, newUser.email, newUser.phone)) {
        strcpy(newUser.status, "Open");
        users[userCount++] = newUser;
        saveUsers();
        printf("Them Thanh Cong\n");
    } else {
        printf("Loi: Sai thong tin hoac bi trung. Vui long nhap lai\n");
    }
}

void showUsers() {
    if (userCount == 0) {
        printf("Khong Co Nguoi Dung\n");
        return;
    }
    printf("|===============|======================|==============================|======================|==========|\n");
    printf("|      ID       |         NAME         |             EMAIL            |         Phone        |  Status  |\n");
    printf("|===============|======================|==============================|======================|==========|\n");
    for (int i = 0; i < userCount; i++) {
        printf("| %-13s | %-20s | %-28s | %-20s | %-8s |\n", users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
    }
    printf("|---------------|----------------------|------------------------------|----------------------|----------|\n");
}

void searchUser() {
    char searchName[50];
    printf("Nhap ten can tim kiem: ");
    while (getchar() != '\n');
    scanf(" %[^\n]", searchName);
    int found = 0;
    printf("\n|===================|==========================|==============================|======================|==========|\n");
    printf("| %-17s | %-24s | %-28s | %-20s | %-8s |\n", "ID", "NAME", "EMAIL", "PHONE", "STATUS");
    printf("|===================|==========================|==============================|======================|==========|\n");
    for (int i = 0; i < userCount; i++) {
        if (strstr(users[i].name, searchName) != NULL) {
            found = 1;
            printf("| %-17s | %-24s | %-28s | %-20s | %-8s |\n",
                   users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
        }
    }
    printf("|-------------------|--------------------------|------------------------------|----------------------|----------|\n");
    if (!found) {
        printf("Khong tim thay ten ban vua nhap '%s'\n", searchName);
    }
}

void toggleUserStatus() {
    char userId[15];
    printf("Nhap ID nguoi dung de Lock/Unlock: ");
    scanf("%s", userId);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, userId) == 0) {
            printf("Nguoi dung %s dang o trang thai: %s\n", users[i].name, users[i].status);
            printf("Ban muon thay doi thanh:\n");
            printf("[1] Lock\n");
            printf("[2] Open\n");
            int choice;
            printf("Nhap lua chon: ");
            scanf("%d", &choice);

            if (choice == 1) {
                strcpy(users[i].status, "Lock");
                printf("Cap nhat trang thai thanh cong\n");
            } else if (choice == 2) {
                strcpy(users[i].status, "Open");
                printf("Cap nhat trang thai thanh cong\n");
            } else {
                printf("Lua chon khong hop le.\n");
                return;
            }
            saveUsers();
            return;
        }
    }
    printf("Khong tim thay ID ban vua nhap\n");
}

void searchUserById() {
    char searchId[50];
    printf("Nhap ID can tim kiem: ");
    while (getchar() != '\n');
    scanf(" %[^\n]", searchId);
    int found = 0;
    printf("\n|===================|==========================|==============================|======================|==========|\n");
    printf("| %-17s | %-24s | %-28s | %-20s | %-8s |\n", "ID", "NAME", "EMAIL", "PHONE", "STATUS");
    printf("|===================|==========================|==============================|======================|==========|\n");
    for (int i = 0; i < userCount; i++) {
        if (strstr(users[i].id, searchId) != NULL) {
            found = 1;
            printf("| %-17s | %-24s | %-28s | %-20s | %-8s |\n",
                   users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
        }
    }
    printf("|-------------------|--------------------------|------------------------------|----------------------|----------|\n");
    if (!found) {
        printf("Khong tim thay ID ban vua nhap %s\n", searchId);
    }
}

void arrangeUser() {
    showUsers();
    if (userCount == 0) {
        printf("Danh sach de trong. Khong co gi de sap xep.\n");
        return;
    }
    int choice;
    printf("\nChon thu tu sap xep:\n");
    printf("[1] Tang dan (A-Z)\n");
    printf("[2] Giam dan (Z-A)\n");
    printf("Nhap lua chon : ");
    scanf("%d", &choice);
    if (choice != 1 && choice != 2) {
        printf("Lua chon khong hop le.\n");
        return;
    }
    for (int i = 0; i < userCount - 1; i++) {
        for (int j = i + 1; j < userCount; j++) {
            if ((choice == 1 && strcmp(users[i].name, users[j].name) > 0) || (choice == 2 && strcmp(users[i].name, users[j].name) < 0)) {
                User temp = users[i];
                users[i] = users[j];
                users[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach theo ten\n");
    showUsers();
}

// doc du lieu tu file khi bat dau chay chuong trinh
void loadUsers() {
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%s\n", users[userCount].id, users[userCount].name, users[userCount].email, users[userCount].phone, users[userCount].status) == 5) {
        userCount++;
        if (userCount >= 100) {
            break;
        }
    }

    fclose(file);
}

void saveUsers() {
    FILE *file = fopen("user.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s,%s,%s,%s,%s\n", users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
    }

    fclose(file);
}

int isUnique(char id[], char email[], char phone[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, id) == 0 || strcmp(users[i].email, email) == 0 || strcmp(users[i].phone, phone) == 0) {
            return 0;
        }
    }
    return 1;
}

int errorUsers(char id[], char name[], char phone[]) {
    if (strlen(id) < 2 || strlen(id) > 5 ||
        strlen(name) <= 3 ||
        strlen(phone) != 10) {
        printf("\nThong tin khong hop le.\n");
        return 0;
    }
    return 1;
}

int notEmptyUsers(char id[], char name[], char email[], char phone[]) {
    if (strlen(id) == 0 || strlen(name) == 0 || strlen(email) == 0 || strlen(phone) == 0) {
        printf("\nThong tin nguoi dung khong duoc de trong\n");
        return 0;
    }
    return 1;
}

int backOrExit() {
    char choice[2];
    char exit = '0';
    char back = 'b';
    printf("\nQuay lai (b) hoac Thoat(0)?: ");
    scanf("%s", choice);
    if (strcmp(choice, "b") == 0) {
        return 1;
    } else if (strcmp(choice, "0") == 0) {
        end();
        return 0;
    } else {
        printf("Lua chon khong hop le! Vui long nhap 'b' de quay lai hoac '0' de thoat.\n");
    }
}

void end() {
    printf("========== Thank You =============\n");
    printf("======== See You Soon ============\n");
    printf("\n");
    printf("------------------------------------");
    return;
}
