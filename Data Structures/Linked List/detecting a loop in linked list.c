#include <stdio.h>
#include <stdlib.h>
//Author: Swoyam S Sahoo
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head;

void insert(int x)
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
}
void detectloop()
{
    int c = 0;
    struct Node *temp = head;
    struct Node *temp1 = head;
    while (temp1->link != NULL)
    {
        if (temp->link == temp1->link->link)
        {
            c = 1;
            break;
        }
        else
        {
            temp = temp->link;
            temp1 = temp1->link->link;
        }
    }
    struct Node *end = temp->link;
    struct Node *temp2 = head;
    int d = 0;
    if (c == 0)
    {
        printf("there is no loop\n");
    }
    else
    {
        printf("there is a loop\n");
        while (temp2->link != NULL)
        {
            if (temp2->link != end->link)
            {
                d++;
                temp2 = temp2->link;
                end = end->link;
            }
            else
            {
                break;
            }
        }
        printf("the %dth element is the 1st element of the loop\n", d + 2);
    }
}
void print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    int i, n, x;
    printf("enter the no of elements u want in linked list\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the %dth element in the linked list\n", i + 1);
        scanf("%d", &x);
        insert(x);
    }
    printf("the linked list u entered is\n");
    print();
    printf("enter the point where u want 2 create the loop\n");
    scanf("%d", &n);
    if (n != 0)
    {
        struct Node *temp = head;
        for (i = 0; i < n - 1; i++)
        {
            temp = temp->link;
        }
        struct Node *cur = temp;
        struct Node *temp1 = head;
        while (temp1->link != NULL)
        {
            temp1 = temp1->link;
        }
        temp1->link = cur; //loop is created
    }
    detectloop();
    return 0;
}
