#include <stdio.h>
void makearray(int ary[], int s)
{
    int i;

    printf("There are %d elements in the array.\n", s);

    for(i = 0; i < s; i++)
    {
        printf("Enter element no. %d: ", i+1);
        scanf("%d", &ary[i]);
    }
}
void displayarray(int ary[], int s)
{
    int i;

    printf("\nYour array:");

    for(i = 0; i < s; i++)
    {
        printf("\t%d", ary[i]);
    }

    printf("\n");
}

void linearsearch(int arr[], int s, int e)
{
    int i;

    for(i = 0; i < s; i++)
    {
        if(arr[i] == e)
        {
            printf("\nElement %d found at position %d.", e, i+1 );
            return;
        }
    }

    printf("\nElement %d not found in the array.", e);
}

void binarysearch(int ary[], int s, int e)
{
    int low = 0;
    int high = s - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(ary[mid] == e)
        {
            printf("\nElement %d found at position %d.", e, mid + 1);
            return;
        }
        else if(e < ary[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("\nElement %d not found.\n", e);
}

void displaymenu()
{
    printf("\n\n_______MENU_______");
    printf("\n1. Display Array");
    printf("\n2. Linear Search");
    printf("\n3. Binary Search");
    printf("\n4. Display Menu");
    printf("\n5. Exit");
    printf("\n___________________");
}

int main()
{
    int ary[100];
    int s;
    int option;
    int e;

    // Array is created automatically
    printf("Enter the size of your array: ");
    scanf("%d", &s);

    makearray(ary, s);
    printf("\nYour array has been stored.");

    displaymenu();

    do
    {
        printf("\nEnter option no. : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                displayarray(ary, s);
                break;

            case 2:
                printf("\nEnter desired element to search: ");
                scanf("%d", &e);

                linearsearch(ary, s, e);
                break;

            case 3:
                printf("\nEnter desired element to search: ");
                scanf("%d", &e);

                binarysearch(ary, s, e);
                break;

            case 4:
                displaymenu();
                break;

            case 5:
                printf("\nBye Bye");
                break;

            default:
                printf("\nWhat a choice!");
        }

    } while(option != 5);
    return 0;
}
