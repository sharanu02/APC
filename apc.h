#ifndef APC_H
#define APC_H

// creating node for doubly linked list
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

// functions for creating and adding nodes
void insert_at_last(Dlist **head, Dlist **tail, int data);
void create_list(char *str, Dlist **head, Dlist **tail);

// functions for addition and subtraction
// functions for arithmetic operations

void addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

void subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

void multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

void division(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

#endif