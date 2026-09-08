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

void addition(Dlist *tail1, Dlist *tail2,
              Dlist **headR, Dlist **tailR)
{
    int carry = 0;

    // starting addition from last digit
    while (tail1 != NULL || tail2 != NULL || carry != 0)
    {
        int sum = carry;

        // adding first number digit
        if (tail1 != NULL)
        {
            sum += tail1->data;
            tail1 = tail1->prev;
        }

        // adding second number digit
        if (tail2 != NULL)
        {
            sum += tail2->data;
            tail2 = tail2->prev;
        }

        // storing last digit of sum
        insert_at_first(headR, tailR, sum % 10);

        // finding carry for next digit
        carry = sum / 10;
    }
}