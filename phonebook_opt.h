#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* small struct version */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    entry *detail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
