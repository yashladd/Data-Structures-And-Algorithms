#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

struct Node *recursiveMergeLists(struct Node *list1, struct Node *list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->data < list2->data) 
    {
        list1->next = recursiveMergeLists(list1->next, list2);
        return list1;
    } 
    else
    {
        list2->next = recursiveMergeLists(list1, list2->next);
        return list2;
    }
}

struct Node *mergeTwoLists(struct Node *list1, struct Node *list2)
{
    struct Node dummy = Node(), *curr;
    curr = &dummy;
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            curr->next = list1;
            curr = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            curr = list2;
            list2 = list2->next;
        }
    }

    if (list1)
        curr->next = list1;
    if (list2)
        curr->next = list2;

    return dummy.next;
}

int main()
{

    int A[] = {1, 2, 3, 4};
    int B[] = {2, 3, 6};

    create(A, 4);
    create2(B, 3);

    Display(recursiveMergeLists(first, second));

    return 0;
}