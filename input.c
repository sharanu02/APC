#include "apc.h"
#include <stdlib.h>

void insert_at_last(Dlist **head, Dlist **tail, int data)
{
    // creating new node
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
        return;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    // if list is empty then new node is head and tail
    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        // connecting new node with last node
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
    }
}

void create_list(char *str, Dlist **head, Dlist **tail)
{
    int i = 0;

    // taking each digit from number
    while (str[i] != '\0')
    {
        insert_at_last(head, tail, str[i] - '0');
        i++;
    }
}