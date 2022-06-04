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
bool hasCycle(struct Node *head)
{
    struct Node *f=head, *s = head;

    while (f && f->next)
    {
        f = f->next->next;
        s = s->next;
        if (f == s) return true;
    }

    return false;
}

int main()
{

    int A[] = {10, 20, 20, 30, 30, 30, 40, 50, 50};
    create(A, 9);


    printf("%d\n\n", hasCycle(first));
    Display(first);

    return 0;
}