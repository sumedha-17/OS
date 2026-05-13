#include <stdio.h>

int frm[10], pg[30];
int fsize, psize;
int top = -1;
int pf = 0;

void display()
{
    int i;
    for(i = 0; i < fsize; i++)
        printf("\t%d", frm[i]);
}

int main()
{
    int i, j, flag;

    printf("Enter number of pages: ");
    scanf("%d", &psize);

    printf("Enter page reference string:\n");
    for(i = 0; i < psize; i++)
        scanf("%d", &pg[i]);

    printf("Enter frame size: ");
    scanf("%d", &fsize);

    /* initialize frames */
    for(i = 0; i < fsize; i++)
        frm[i] = -1;

    printf("\nPage | Frames");

    for(j = 0; j < psize; j++)
    {
        flag = 0;

        for(i = 0; i < fsize; i++)
        {
            if(frm[i] == pg[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            if(top == fsize - 1)
            {
                top = -1;
            }

            pf++;
            top++;
            frm[top] = pg[j];
        }

        printf("\n %d |", pg[j]);
        display();
    }

    printf("\n------------------");
    printf("\nTotal Page Faults: %d\n", pf);

    return 0;
}
