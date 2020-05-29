#include<stdio.h>
int s;
void selectionSort(int arr[])
{
    for(int i=0;i<s-1;i++)
    {
        int smallestPos=i;
        for(int j=i+1;j<s;j++)
        {
            if(arr[j]<arr[smallestPos])
                smallestPos=j;
        }
        int t=arr[smallestPos];
        arr[smallestPos]=arr[i];
        arr[i]=t;
    }
}
void display(int arr[])
{
    for(int i=0;i<s;i++)
    {
        printf("%d,",arr[i]);
    }printf("\n");
}
void main()
{
    printf("Enter the size of the array:");
    scanf("%d",&s);
    int arr[s];
    for(int i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    display(arr);
    selectionSort(arr);
    display(arr);
}
