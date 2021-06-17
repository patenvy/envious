/*
Malhar Nimavat
ID - 202003003
Merge Sort
*/
#include <iostream>
#include <stdio.h>

using namespace std;

//number of comparisons in worst case will be m+n-1 where m is number of elements in 1st array and n is number of elements in second array
//space used in my code is n+50

void merge (int array[],int low,int mid, int high)
{
    int i=low,j=mid+1,k=low;
    int temp_array[50];

    while (i<=mid && j<=high)
    {
        if (array[i]<array[j])
        {
            temp_array[k++]=array[i++];
        }
        else
        {
            temp_array[k++]=array[j++];
        }
    }

    for ( ;i<=mid ; i++)
    {
        temp_array[k++]=array[i];
    }
    for ( ;j<=high ; j++)
    {
        temp_array[k++]=array[j];
    }

    for (i=low ; i<=high ; i++)
    {
        array[i]=temp_array[i];
    }

}

void merge_sort(int array[],int size)
{
    int passes,low,high,mid,i;
    for (passes=2 ; passes<=size ; passes=passes*2)
    {
        for (i=0 ; i+passes-1 <= size ; i=i+passes)
        {
            low=i;
            high=i+passes-1;
            mid=(low+high)/2;
            merge(array,low,mid,high);
        }
    }
    if (passes/2 < size)
    {
        merge(array,0,(passes/2)-1,size);
    }
}

int main()
{
    int x;     //declaring variable
    printf("How many elements you want to type ");
    scanf("%i",&x);  //user input
    int array[x];  //declaring array
    printf("Enter the elements\n");
    for (int i=0 ; i<x ; i++)  //loop for user input in array
    {
        scanf("%i",&array[i]);
    }
    printf("Initial list is\n");
    for (int i=0 ; i<x ; i++)  //loop for printing initial list of array
    {
        printf("%i ",array[i]);
    }
    merge_sort(array,x);  //function call
    printf("\nSorted list is\n");
    for (int t=0 ; t<x ; t++)
    {
        printf("%i ",array[t]);
    }
    return 0;
}
