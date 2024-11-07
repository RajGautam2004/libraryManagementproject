#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Book {
    int bookID;
    char title[100];
    char author[100];
    int isIssued;  
    struct Book *next;
};


struct Book *head = NULL;


void addBook() {
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
    printf("Enter Book ID: ");
    scanf("%d", &newBook->bookID);
    printf("Enter Book Title: ");
    scanf(" %[^\n]s", newBook->title);
    printf("Enter Book Author: ");
    scanf(" %[^\n]s", newBook->author);
    newBook->isIssued = 0;
    newBook->next = head;
    head = newBook;
    printf("BOOK ADDED SUCCESSFULLY!\n");
}


void viewBooks() {
    struct Book *temp = head;
    if (temp == NULL) {
        printf("No books in the library.\n");
        return;
    }
    printf("\n%-10s %-30s %-30s %-10s\n", "Book ID", "Title", "Author", "Issued?");
    printf("\n");
    while (temp != NULL) {
        printf("%-10d %-30s %-30s %-10s\n", temp->bookID, temp->title, temp->author, (temp->isIssued ? "Yes" : "No"));
        temp = temp->next;
    }
}


void issueBook() {
    int bookID;
    printf("Enter Book ID to issue: ");
    scanf("%d", &bookID);
    struct Book *temp = head;
    while (temp != NULL) {
        if (temp->bookID == bookID) {
            if (temp->isIssued == 0) {
                temp->isIssued = 1;
                printf("BOOK ISSUED SUCCESSFULLY!\n");
                return;
            } else {
                printf("BOOK ISSUED ALREADY.\n");
                return;
            }
        }
        temp = temp->next;
    }
    printf("BOOK NOT FOUND::!\n");
}


void returnBook() {
    int bookID;
    printf("Enter Book ID to return: ");
    scanf("%d", &bookID);
    struct Book *temp = head;
    while (temp != NULL) {
        if (temp->bookID == bookID) {
            if (temp->isIssued == 1) {
                temp->isIssued = 0;
                printf("BOOK RETURNED SUCCESSFULLY::!\n");
                return;
            } else {
                printf("BOOK WAS NOT ISSUED.\n");
                return;
            }
        }
        temp = temp->next;
    }
    printf("BOOK NOT FOUND::!\n");
}


void searchBook() {
    char keyword[100];
    printf("ENTER BOOK TITLE || AUTHOR NAME TO SEARCH: ");
    scanf(" %[^\n]s", keyword);
    struct Book *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strstr(temp->title, keyword) != NULL || strstr(temp->author, keyword) != NULL) {
            printf("Book ID: %d\n", temp->bookID);
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            printf("Status: %s\n", (temp->isIssued ? "Issued" : "Available"));
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("NO BOOK FOUND TO THIS CRITERIA.\n");
    }
}


void deleteAllBooks() {
    struct Book *temp = head;
    while (temp != NULL) {
        struct Book *nextBook = temp->next;
        free(temp);
        temp = nextBook;
    }
    head = NULL;
}

int main() {
    int choice;

    while (1) {
        printf("\n :LIBRARY<->MANAGEMENT<->SYSYTEM: \n");
        printf("1. ADD BOOK:\n");
        printf("2. VIEW ALL LIST OF BOOKS:\n");
        printf("3. ISSUE BOOK:\n");
        printf("4. RETURN BOOK:\n");
        printf("5. SEARCH BOOK:\n");
        printf("6. EXIT\n");
        printf("ENTER THE USER'S CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                searchBook();
                break;
            case 6:
                deleteAllBooks();  
                printf("Exiting...\n");
                exit(0);
            default:
                printf(" choice .ERROR! Please try again.\n");
        }
    }

    return 0;
}
