#include <stdio.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *headR = NULL;
    Dlist *tailR = NULL;

    // checking if correct arguments are given
    if (argc != 4)
    {
        printf("Usage: ./apc number1 operator number2\n");
        return 1;
    }

    // creating first number list
    create_list(argv[1], &head1, &tail1);

    // creating second number list
    create_list(argv[3], &head2, &tail2);

    // checking which operation user wants
    if (argv[2][0] == '+')
    {
        addition(tail1, tail2, &headR, &tailR);
    }
    else if (argv[2][0] == '-')
    {
        subtraction(tail1, tail2, &headR, &tailR);
    }
    else
    {
        printf("Invalid operator\n");
        return 1;
    }

    // printing the result
    printf("Result: ");

    Dlist *temp = headR;

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return 0;
}