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

struct Node *recReverse(struct Node* head) {
    if (!head || !(head->next)) {
        return head;
    }
    struct Node * newHead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}



struct Node* reverse(struct Node *head)
{
    struct Node *prev = NULL , *curr = head;

    while (curr) {
        struct Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{

    int A[] = {1,2,3,4};
    create(A, 4);


    Display(recReverse( first));

    return 0;
}