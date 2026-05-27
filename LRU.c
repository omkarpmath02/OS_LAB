#include <stdio.h>

#define MAX 50

int search(int frames[], int capacity, int key)
{
    for(int i = 0; i < capacity; i++)
    {
        if(frames[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int pages[MAX], frames[MAX], time[MAX];
    int n, capacity;
    int faults = 0;
    int counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    for(int i = 0; i < capacity; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement:\n");

    for(int i = 0; i < n; i++)
    {
        int pos = search(frames, capacity, pages[i]);

        if(pos == -1)
        {
            int least = 0;

            for(int j = 1; j < capacity; j++)
            {
                if(time[j] < time[least])
                    least = j;
            }

            frames[least] = pages[i];
            time[least] = ++counter;
            faults++;
        }
        else
        {
            time[pos] = ++counter;
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