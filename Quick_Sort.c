/* 
Quick Sort
*/

#include <stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int A[],int low,int high)
{
    int pivot = A[low];
    int i = low,j = high;
    do
    {
        do{i++;}while(A[i] <= pivot);

        do{j--;}while(A[j] > pivot);

        if(i<j)
            swap(&A[i], &A[j]);
    }while(i<j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[],int low,int high)
{
    int pivot;
    if(low < high)
    {
        pivot = partition(A, low, high);
        QuickSort(A,low, pivot-1);
        QuickSort(A, pivot+1, high);
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;

    QuickSort(A,n);

    for(i=0; i<10; i++)
        printf("%d ",A[i]);

    printf("\n");
    return 0;
}