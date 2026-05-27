#include <stdio.h>

#define MAX 50

int search(int frames[], int capacity, int key)
{
    for(int i = 0; i < capacity; i++)
    {
        if(frames[i] == key)
            return 1;
    }

    return 0;
}

int main()
{
    int pages[MAX], frames[MAX];
    int n, capacity;
    int faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    for(int i = 0; i < capacity; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement:\n");

    for(int i = 0; i < n; i++)
    {
        if(!search(frames, capacity, pages[i]))
        {
            int pos = -1;

            for(int j = 0; j < capacity; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
            {
                int farthest = -1;

                for(int j = 0; j < capacity; j++)
                {
                    int k;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                            break;
                    }

                    if(k > farthest)
                    {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        printf("Page %d -> ", pages[i]);

        for(int j = 0; j < capacity; j++)
        {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}