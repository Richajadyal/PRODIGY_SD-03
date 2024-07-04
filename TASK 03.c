#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

void addContact(Contact *contacts, int *numContacts) {
    printf("Enter name: ");
    scanf("%s", 

contacts[*numContacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*numContacts].phone);
    printf("Enter email address: ");
    scanf("%s", contacts[*numContacts].email);
    (*numContacts)++;
}

void viewContacts(Contact *contacts, int numContacts) {
    printf("Contact List:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s, Phone: %s, Email: %s\n",
               contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}



void editContact(Contact *contacts, int numContacts) {
    int index;
    printf("Enter index of contact to edit (0-%d): ", numContacts - 1);
    scanf("%d", &index);
    if (index >= 0 && index < numContacts) {
        printf("Enter new name: ");
        scanf("%s", contacts[index].name);
        printf("Enter new phone number: ");
        scanf("%s", contacts[index].phone);
        printf("Enter new email address: ");
        scanf("%s", contacts[index].email);
    } else {
        printf("Invalid index.\n");
    }
}

void deleteContact(Contact *contacts, int *numContacts) {
    int index;
    printf("Enter index of contact to delete (0-%d): ", *numContacts - 1);
    scanf("%d", &index);
    if (index >= 0 && index < *numContacts) {
        for (int i = index; i < *numContacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*numContacts)--;
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
    Contact contacts[100];
    int numContacts = 0;
    int choice;


    while (1) {
        printf("Contact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                viewContacts(contacts, numContacts);
                break;

            case 3:
                editContact(contacts, numContacts);
                break;
            case 4:
                deleteContact(contacts, &numContacts);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
