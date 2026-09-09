#include <stdio.h>

void makearray(int ary[], int m)
{
    int i;
    printf("No. of elements: %d\n", m);

    for(i = 0; i < m; i++)
    {
        printf("Enter the element number %d: ", i + 1);
        scanf("%d", &ary[i]);
    }
}

void displayarray(int ary[], int m)
{
    int i;

    printf("\nYour array:");

    for(i = 0; i < m; i++)
    {
        printf("\t%d", ary[i]);
    }

    printf("\n");
}

void bubblesort(int ary[], int m)
{
    int i, j, temp;

    for(i = 0; i < m - 1; i++)
    {
        for(j = 0; j < m - i - 1; j++)
        {
            if(ary[j] > ary[j + 1])
            {
                temp = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = temp;
            }
        }
    }

    printf("\nBubble sorted array: ");

    for(i = 0; i < m; i++)
    {
        printf("%d\t", ary[i]);
    }
}

void insertsort(int ary[], int m)
{
    int i, j, temp;

    for(i = 1; i < m; i++)
    {
        temp = ary[i];
        j = i - 1;

        while(j >= 0 && ary[j] > temp)
        {
            ary[j + 1] = ary[j];
            j--;
        }

        ary[j + 1] = temp;
    }

    printf("\nInsertion sorted array: ");

    for(i = 0; i < m; i++)
    {
        printf("%d\t", ary[i]);
    }
}

void selectsort(int ary[], int m)
{
    int i, j, temp, min;

    for(i = 0; i < m - 1; i++)
    {
        min = i;

        for(j = i + 1; j < m; j++)
        {
            if(ary[j] < ary[min])
            {
                min = j;
            }
        }

        temp = ary[i];
        ary[i] = ary[min];
        ary[min] = temp;
    }

    printf("\nSelection sorted array: ");

    for(i = 0; i < m; i++)
    {
        printf("%d\t", ary[i]);
    }
}

void mergesort(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftarr[n1], rightarr[n2];

    for(i = 0; i < n1; i++)
        leftarr[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        rightarr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        if(leftarr[i] <= rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        arr[k] = leftarr[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergesortfull(int arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left + right) / 2;

        mergesortfull(arr, left, mid);
        mergesortfull(arr, mid + 1, right);

        mergesort(arr, left, mid, right);
    }
}

void quicksort(int ary[], int left, int right)
{
    int i, j, pivot, temp;

    i = left;
    j = right;
    pivot = ary[(left + right) / 2];

    while(i <= j)
    {
        while(ary[i] < pivot)
            i++;

        while(ary[j] > pivot)
            j--;

        if(i <= j)
        {
            temp = ary[i];
            ary[i] = ary[j];
            ary[j] = temp;

            i++;
            j--;
        }
    }

    if(left < j)
        quicksort(ary, left, j);

    if(i < right)
        quicksort(ary, i, right);
}

void displaymenu()
{
    printf("\n\n_______MENU_______");
    printf("\na. Display Array");
    printf("\nb. Bubble Sort");
    printf("\nc. Insertion Sort");
    printf("\nd. Selective Sort");
    printf("\ne. Merge Sort");
    printf("\nf. Quick Sort");
    printf("\ng. Display Menu");
    printf("\nh. Exit");
    printf("\n___________________");
}

int main()
{
    int ary[100];
    int m;
    char option;

    printf("Enter size of your array: ");
    scanf("%d", &m);

    makearray(ary, m);

    printf("\nYour array has been stored");

    displaymenu();

    do
    {
        printf("\nEnter option: ");
        scanf(" %c", &option);

        switch(option)
        {
            case 'a':
                displayarray(ary, m);
                break;

            case 'b':
                bubblesort(ary, m);
                break;

            case 'c':
                insertsort(ary, m);
                break;

            case 'd':
                selectsort(ary, m);
                break;

            case 'e':
                mergesortfull(ary, 0, m - 1);

                printf("\nMerge sorted array: ");

                for(int i = 0; i < m; i++)
                {
                    printf("%d\t", ary[i]);
                }
                break;

            case 'f':
                quicksort(ary, 0, m - 1);

                printf("\nQuick sorted array: ");

                for(int i = 0; i < m; i++)
                {
                    printf("%d\t", ary[i]);
                }
                break;

            case 'g':
                displaymenu();
                break;

            case 'h':
                printf("See you!");
                break;

            default:
                printf("Can't you read!?");
                break;
        }

    } while(option != 'h');

    return 0;
}
