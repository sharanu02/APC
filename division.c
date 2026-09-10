#include "apc.h"
#include <stdlib.h>
#include <stdio.h>

static void insert_at_last_div(Dlist **head, Dlist **tail, int data)
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

static int compare_lists(Dlist *head1, Dlist *head2)
{
    int count1 = 0;
    int count2 = 0;

    Dlist *temp;

    // finding length of first number
    temp = head1;

    while (temp != NULL)
    {
        count1++;
        temp = temp->next;
    }

    // finding length of second number
    temp = head2;

    while (temp != NULL)
    {
        count2++;
        temp = temp->next;
    }

    // comparing number of digits
    if (count1 > count2)
        return 1;

    if (count1 < count2)
        return -1;

    // comparing digits
    while (head1 != NULL)
    {
        if (head1->data > head2->data)
            return 1;

        if (head1->data < head2->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}

static void remove_leading_zero(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while (*head != NULL &&
           (*head)->data == 0 &&
           (*head)->next != NULL)
    {
        temp = *head;

        *head = (*head)->next;
        (*head)->prev = NULL;

        free(temp);
    }

    if (*head == NULL)
        *tail = NULL;
}

void division(Dlist *tail1, Dlist *tail2,
              Dlist **headR, Dlist **tailR)
{
    Dlist *dividend;
    Dlist *divisor;

    Dlist *remainderHead = NULL;
    Dlist *remainderTail = NULL;

    Dlist *resultHead = NULL;
    Dlist *resultTail = NULL;

    Dlist *newHead;
    Dlist *newTail;

    int quotientDigit;

    // finding first node of dividend
    dividend = tail1;

    while (dividend->prev != NULL)
    {
        dividend = dividend->prev;
    }

    // finding first node of divisor
    divisor = tail2;

    while (divisor->prev != NULL)
    {
        divisor = divisor->prev;
    }

    // checking division by zero
    if (divisor->data == 0 && divisor->next == NULL)
    {
        printf("Error: Division by zero\n");
        return;
    }

    // processing dividend from left to right
    while (dividend != NULL)
    {
        // bring down one digit
        insert_at_last_div(&remainderHead,
                           &remainderTail,
                           dividend->data);

        remove_leading_zero(&remainderHead,
                            &remainderTail);

        quotientDigit = 0;

        // subtract divisor until remainder is smaller
        while (compare_lists(remainderHead, divisor) >= 0)
        {
            newHead = NULL;
            newTail = NULL;

            subtraction(remainderTail, tail2,
                        &newHead, &newTail);

            delete_list(&remainderHead, &remainderTail);

            remainderHead = newHead;
            remainderTail = newTail;

            quotientDigit++;
        }

        // storing quotient digit
        insert_at_last_div(&resultHead,
                           &resultTail,
                           quotientDigit);

        dividend = dividend->next;
    }

    // remove extra zeros from quotient
    remove_leading_zero(&resultHead,
                        &resultTail);

    // returning result
    *headR = resultHead;
    *tailR = resultTail;

    // remainder is not needed
    delete_list(&remainderHead, &remainderTail);
}