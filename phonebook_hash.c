#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#include "phonebook_hash.h"

entry* HashTable[Hash_Table_Size];

/* hash version */

static inline int hash(char lastname[])
{
     int letnumber;
     int val=0;
     for(int i=0;i<(sizeof(lastname)/sizeof(lastname[0]));i++)
     {
           letnumber = lastname[i];
           val += letnumber;
      }

      return val%Hash_Table_Size;
}

entry *findName(char lastname[], entry *pHead)
{
    pHead = HashTable[hash(lastname)];

    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    int tablenumber = hash(lastName);
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    if(HashTable[tablenumber] != NULL)
    {
          HashTable[tablenumber]->pNext = e;
	  e->pNext = NULL;
          strcpy(e->lastName, lastName);
          HashTable[tablenumber]->pNext = e;
     }
     else
     {
	  e->pNext = NULL;
          strcpy(e->lastName, lastName);
          HashTable[tablenumber] = e;
      } 
      free(e->pNext);

    return e;
}
