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

static void insert_at_last_mul(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
        return;

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail == NULL)
    {
        *head = new;
    }
    else
    {
        (*tail)->next = new;
    }

    *tail = new;
}

static void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;
}

static void multiply_digit(Dlist *tail1, int digit,
                           Dlist **headR, Dlist **tailR)
{
    int carry = 0;

    // multiplying first number by one digit
    while (tail1 != NULL)
    {
        int product = tail1->data * digit + carry;

        insert_at_first(headR, tailR, product % 10);

        carry = product / 10;

        tail1 = tail1->prev;
    }

    // storing remaining carry
    if (carry != 0)
    {
        insert_at_first(headR, tailR, carry);
    }
}

void multiplication(Dlist *tail1, Dlist *tail2,
                    Dlist **headR, Dlist **tailR)
{
    Dlist *resultHead = NULL;
    Dlist *resultTail = NULL;

    Dlist *partialHead;
    Dlist *partialTail;

    Dlist *newResultHead;
    Dlist *newResultTail;

    int position = 0;

    // initial result = 0
    insert_at_last_mul(&resultHead, &resultTail, 0);

    // starting from last digit of second number
    while (tail2 != NULL)
    {
        partialHead = NULL;
        partialTail = NULL;

        // multiply first number by current digit
        multiply_digit(tail1, tail2->data,
                       &partialHead, &partialTail);

        // adding zeros according to position
        for (int i = 0; i < position; i++)
        {
            insert_at_last_mul(&partialHead, &partialTail, 0);
        }

        // adding partial product to result
        newResultHead = NULL;
        newResultTail = NULL;

        addition(resultTail, partialTail,
                 &newResultHead, &newResultTail);

        // deleting old lists
        delete_list(&resultHead, &resultTail);
        delete_list(&partialHead, &partialTail);

        // new result becomes current result
        resultHead = newResultHead;
        resultTail = newResultTail;

        tail2 = tail2->prev;
        position++;
    }

    // returning final result
    *headR = resultHead;
    *tailR = resultTail;
}