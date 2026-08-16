#include <stdio.h>
#include <string.h>
#include "contact.h"

int contact_count = 0;
Contact contacts[MAX_CONTACTS];

void add_contact();
void list_contacts();
void search_contact();
void delete_contact();
void save_to_file();
void load_from_file();

int main() {
    load_from_file();

    int choice;
    while(1) {
        printf("\nContact Manager\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);
        
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                list_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                save_to_file();
                break;
            case 6:
                load_from_file();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void add_contact() {
    char name[50];
    char phone[13];
    char email[50];

    printf("------Add Contact------\n");
    printf("Name: ");
    scanf_s("%s", name, sizeof(name));
    
    printf("Phone: ");
    scanf_s("%s", phone, sizeof(phone));
    
    printf("Email: ");
    scanf_s("%s", email, sizeof(email));

    // Save contact to contact list
    Contact new_contact;
    strcpy_s(new_contact.name, sizeof(new_contact.name), name);
    strcpy_s(new_contact.phone, sizeof(new_contact.phone), phone);
    strcpy_s(new_contact.email, sizeof(new_contact.email), email);
    contacts[contact_count] = new_contact;
    contact_count++;

    printf("Contact added successfully!\n");
}

void list_contacts() {
    printf("------List Contacts------\n");
    

}

void search_contact() {
    printf("------Search Contact------\n");
}

void delete_contact() {
    printf("------Delete Contact------\n");
}

void save_to_file() {
    printf("------Save to File------\n");
}

void load_from_file() {
    printf("------Load from File------\n");
}