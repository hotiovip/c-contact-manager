#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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
        printf("5. Exit\n");
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
                save_to_file(); // Save before closing
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void add_contact() {
    char name[50];
    char phone[15];
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
    
    for(int i = 0; i < contact_count; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("-------------------------\n");
    }
}

void search_contact() {
    char search_name[50];

    printf("------Search Contact------\n");
    printf("Enter name to search: ");
    scanf_s("%s", search_name, sizeof(search_name));
    
    bool found = false;
    for(int i = 0; i < contact_count; i++) {
        if(strcmp(contacts[i].name, search_name) == 0) {
            found = true;

            printf("-------------------------\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
        }
    }
    printf("-------------------------\n");

    if (!found) {
        printf("Contact not found!\n");
    }
}

void delete_contact() {
    char delete_name[50];

    printf("------Delete Contact------\n");
    printf("Enter name to delete: ");
    scanf_s("%s", delete_name, sizeof(delete_name));

    bool found = false;
    for(int i = 0; i < contact_count; i++) {
        if(strcmp(contacts[i].name, delete_name) == 0) {
            found = true;

            printf("-------------------------\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("-------------------------\n");

            char confirm;
            printf("Are you sure you want to delete this contact? (y/n): ");
            scanf_s(" %c", &confirm, 1);
            if(confirm != 'y' && confirm != 'Y') {
                printf("Deletion cancelled.\n");
                return;
            }
            else {
                // Shift contacts to remove the deleted contact
                for(int j = i; j < contact_count - 1; j++) {
                    contacts[j] = contacts[j + 1];
                }
                contact_count--;
                printf("Contact deleted successfully!\n");
                break;
            }
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void save_to_file() {
    FILE *file;
    errno_t err = fopen_s(&file, "contacts.dat", "wb");
    
    if (err != 0 || file == NULL) {
        printf("Error: Could not save file!\n");
        return;
    }
    
    fwrite(&contact_count, sizeof(int), 1, file);
    fwrite(contacts, sizeof(Contact), contact_count, file);
    
    fclose(file);
    printf("Contacts saved successfully!\n");
}

void load_from_file() {
    FILE *file;
    errno_t err = fopen_s(&file, "contacts.dat", "rb");
    
    if (err != 0 || file == NULL) {
        // File doesn't exist yet - that's ok!
        return;
    }
    
    fread(&contact_count, sizeof(int), 1, file);
    fread(contacts, sizeof(Contact), contact_count, file);
    
    fclose(file);
    printf("Loaded %d contacts.\n", contact_count);
}