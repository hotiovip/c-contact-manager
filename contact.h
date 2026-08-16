#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 1000

typedef struct {
    char name[50];
    char phone[13]; // Format: (+49)0123456789
    char email[50];
} Contact;

#endif