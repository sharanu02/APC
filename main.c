#include <stdio.h>
#include "apc.h"

int main()
{
    Dlist *head = NULL;
    Dlist *tail = NULL;

    insert_at_last(&head, &tail, 1);
    insert_at_last(&head, &tail, 2);
    insert_at_last(&head, &tail, 3);
    insert_at_last(&head, &tail, 4);
    insert_at_last(&head, &tail, 5);

    Dlist *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return 0;
}