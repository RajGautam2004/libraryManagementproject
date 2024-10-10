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
    printf("Book Added Successfully!\n");
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
                printf("Book Issued Successfully!\n");
                return;
            } else {
                printf("Book is already issued.\n");
                return;
            }
        }
        temp = temp->next;
    }
    printf("Book not found!\n");
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
                printf("Book Returned Successfully!\n");
                return;
            } else {
                printf("Book was not issued.\n");
                return;
            }
        }
        temp = temp->next;
    }
    printf("Book not found!\n");
}


void searchBook() {
    char keyword[100];
    printf("Enter Book Title or Author to search: ");
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
        printf("No books found matching the search criteria.\n");
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
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Search Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
