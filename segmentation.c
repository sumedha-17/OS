#include <stdio.h>
#include <stdlib.h>

struct list
{
    int seg;
    int base;
    int limit;
    struct list *next;
} *p = NULL;

void insert(struct list *q, int base, int limit, int seg)
{
    struct list *temp;

    if (p == NULL)
    {
        p = (struct list *)malloc(sizeof(struct list));
        p->seg = seg;
        p->base = base;
        p->limit = limit;
        p->next = NULL;
    }
    else
    {
        while (q->next != NULL)
        {
            q = q->next;
        }

        temp = (struct list *)malloc(sizeof(struct list));
        temp->seg = seg;
        temp->base = base;
        temp->limit = limit;
        temp->next = NULL;

        q->next = temp;
    }
}

int find(struct list *q, int seg)
{
    while (q != NULL)
    {
        if (q->seg == seg)
            return q->limit;
        q = q->next;
    }
    return -1;
}

int search(struct list *q, int seg)
{
    while (q != NULL)
    {
        if (q->seg == seg)
            return q->base;
        q = q->next;
    }
    return -1;
}

int main()
{
    int seg, offset, limit, base, c, s, physical;

    printf("Enter segment table\n");
    printf("Enter -1 as segment value for termination\n");

    do
    {
        printf("Enter segment number: ");
        scanf("%d", &seg);

        if (seg != -1)
        {
            printf("Enter base value: ");
            scanf("%d", &base);

            printf("Enter limit value: ");
            scanf("%d", &limit);

            insert(p, base, limit, seg);
        }
    } while (seg != -1);

    printf("Enter segmentation number: ");
    scanf("%d", &seg);

    printf("Enter offset: ");
    scanf("%d", &offset);

    c = find(p, seg);
    s = search(p, seg);

    if (c == -1 || s == -1)
    {
        printf("Segment not found\n");
    }
    else if (offset < c)
    {
        physical = s + offset;
        printf("Address in physical memory: %d\n", physical);
    }
    else
    {
        printf("Error: Offset exceeds limit\n");
    }

    return 0;
}
