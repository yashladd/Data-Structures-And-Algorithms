#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} * first;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        t->prev = last;
        last = t; 
    }
}

int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int idx, int val)
{

    if (idx < 0 || idx > Length(p)) return;

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;

    if (idx == 0)
    {
        t->data = val;
        t->next = first;
        t->prev = NULL; // same as t->prev = first->prev;
        // t->prev = first->prev;
        first->prev = t;
        first = t;
    } else {
        for (; i < idx - 1; i++)
        {
            p = p->next;
        }

        t->data = val;
        t->next = p->next;
        t->prev = p;
        if (p->next) p->next->prev = t; // p->next could be NULL
        p->next = t;
    }
}

int Delete(struct Node *p, int idx)
{
    if (idx <= 0 || idx > Length(p)) return -1;

    int x = -1, i;

    if (idx == 1)
    {
        p = first;
        x = p->data;
        first = first->next;
        free(p);
        if (first) first->prev = NULL;
    } else {
        p = first;
        for (i = 0; i < idx - 1; i++)
            p = p->next;
        x = p->data;
        p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        free(p);
    }
    return x;
    
} 


void Display (struct Node *h) 
{
    while (h)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n\n");
    
}

int main () 
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    Insert(first, 0, 100);
    Insert(first, 3, -132);
    printf("%d\n", Delete(first, 4));
    printf("%d\n", Delete(first, 1));
    Display(first);
    return 0;
}
