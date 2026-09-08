#ifndef APC_H
#define APC_H

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

void insert_at_last(Dlist **head, Dlist **tail, int data);

#endif