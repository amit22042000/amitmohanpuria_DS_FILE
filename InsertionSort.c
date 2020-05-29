#include<stdio.h>
int s=10;int arr[10];

void createArray()
{
    printf("Enter the values of array\n");
    for(int i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void insertionSort()
{
    for(int i=1;i<s;i++)
    {
        int j=i-1;
        int t=arr[i];
        for(;j>=0;j--)
        {
            if(arr[j]>t)
                arr[j+1]=arr[j];
            else
                break;
        }arr[j+1]=t;
    }
}
void displayArray()
{
    printf("Array is: ");
    for(int i=0;i<s;i++)
    {
        printf("%d,",arr[i]);
    }
}
void main()
{
    createArray();
    displayArray();
    insertionSort();
    displayArray();
}
