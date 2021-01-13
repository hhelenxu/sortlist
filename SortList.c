#include <stdio.h>
#include <stdlib.h>

//merge the two arrays together in order
void merge(int arr[], int low, int mid, int high)
{

    int lenL = mid - low + 1;
    int lenR = high - mid;
    int arrL[lenL], arrR[lenR];

    //temporary arrays
    for (int i = 0; i < lenL; i++)
        arrL[i] = arr[i + low];
    for (int i = 0; i < lenR; i++)
        arrR[i] = arr[i + mid + 1];

    int l = 0, r = 0, t = low;
    while (l < lenL || r < lenR)
    {
        if (l >= lenL)
            while (r < lenR)
                arr[t++] = arrR[r++];
        else if (r >= lenR)
            while (l < lenL)
                arr[t++] = arrL[l++];
        else if (arrL[l] <= arrR[r])
            arr[t++] = arrL[l++];
        else
            arr[t++] = arrR[r++];
    }
}

//recursively sort left and right half of arr, then merge together
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//code to test sorting
int main()
{
    int arr[] = {4, 7, 24, 18, 1, -3, 0, 37, -8};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Initial array: ");
    printArr(arr, size);
    mergeSort(arr, 0, size - 1);
    printf("Sorted array: ");
    printArr(arr, size);
    return 0;
}