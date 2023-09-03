#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int temp[100];
    i=l;
    j=m+1;
    k=l;

    while(i<=m && j<=r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    if(i>m){
        while(j<=r){
            temp[k] = arr[j];
            j++;
            k++;
        }
    }else{
        while(i<=m){
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    for(k=0 ; k<=r ; k++){
        arr[k] = temp[k];
    }

}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;


        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }

}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}

