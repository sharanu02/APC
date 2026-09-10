#include "apc.h"
#include <stdlib.h>

static void insert_at_first(Dlist **head, Dlist **tail, int data)
{
    // creating new node
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
        return;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)
    {
        *tail = new;
    }
    else
    {
        (*head)->prev = new;
    }

    *head = new;
}

void subtraction(Dlist *tail1, Dlist *tail2,
                 Dlist **headR, Dlist **tailR)
{
    int borrow = 0;

    // starting subtraction from last digit
    while (tail1 != NULL)
    {
        int difference = tail1->data - borrow;

        // subtracting second number digit
        if (tail2 != NULL)
        {
            difference -= tail2->data;
            tail2 = tail2->prev;
        }

        // checking if borrow is needed
        if (difference < 0)
        {
            difference += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        // storing result digit
        insert_at_first(headR, tailR, difference);

        tail1 = tail1->prev;
    }

    // removing extra zero from starting
    while (*headR != NULL &&
           (*headR)->data == 0 &&
           (*headR)->next != NULL)
    {
        Dlist *temp = *headR;

        *headR = (*headR)->next;
        (*headR)->prev = NULL;

        free(temp);
    }
}
