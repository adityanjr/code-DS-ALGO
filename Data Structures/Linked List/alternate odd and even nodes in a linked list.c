#include <stdio.h>
#include <stdlib.h>

//Author : Swoyam S Sahoo

struct Node
{
    int data;
    struct Node *link;
};
struct Node *insert(int x, struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *temp1 = head;
        while (temp1->link != NULL)
        {
            temp1 = temp1->link;
        }
        temp1->link = temp;
    }
    return head;
}
void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
struct Node *altodev(struct Node *head)
{
    struct Node *curr, *evens, *evene, *odds, *odde;
    curr = head;
    evens = NULL;
    odds = NULL;
    while (curr != NULL) //for segregation of even and odds
    {
        if (curr->data % 2 == 0)
        {
            if (evens == NULL)
            {
                evens = curr;
                evene = evens;
            }
            else
            {
                evene->link = curr;
                evene = evene->link;
            }
        }
        else
        {
            if (odds == NULL)
            {
                odds = curr;
                odde = odds;
            }
            else
            {
                odde->link = curr;
                odde = odde->link;
            }
        }
        curr = curr->link;
    }
    struct Node *head1 = evens;
    evene->link = NULL;
    struct Node *head2 = odds;
    odde->link = NULL;
    struct Node *head3 = NULL;
    int c = 0;
    while (head1 != NULL || head2 != NULL)
    {
        if (c % 2 == 0)
        {
            head3 = insert(head2->data, head3);
            head2 = head2->link;
        }
        else
        {
            head3 = insert(head1->data, head3);
            head1 = head1->link;
        }
        c++;
    }
    printf("the linked list after arrangement is\n");
    print(head3);

    return head;
}
int main()
{
    int i, n, x;
    struct Node *head = NULL;
    printf("enter the no of elements u want 2 enter in the linked list\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(x, head);
    }
    printf("the linked list u entered is\n");
    print(head);
    head = altodev(head);
    return 0;
}
