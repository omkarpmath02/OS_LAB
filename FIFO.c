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
    int front = 0;
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

    printf("\nFIFO Page Replacement:\n");

    for(int i = 0; i < n; i++)
    {
        if(!search(frames, capacity, pages[i]))
        {
            frames[front] = pages[i];
            front = (front + 1) % capacity;
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