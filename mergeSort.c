#include<stdio.h>
int s;
void merge(int arr[],int f,int m, int r)
{
    int a[r-f+1];
    for(int i=f,j=m+1,k=0;i<=m||j<=r;k++)
    {
        if(i>m)
        {
            a[k]=arr[j];
            j++;
        }
        else if(j>r)
        {
            a[k]=arr[i];
            i++;
        }
        else if(arr[i]<arr[j])
        {
            a[k]=arr[i];
            i++;
        }
        else
        {
            a[k]=arr[j];
            j++;
        }
    }
    for(int i=f;i<=r;i++)
        arr[i]=a[i-f];
}
void mergeSort(int arr[],int f,int r)
{
    if(f<r)
    {
        int m=(f+r-1)/2;
        mergeSort(arr,f,m);
        mergeSort(arr,m+1,r);
        merge(arr,f,m,r);
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
    mergeSort(arr,0,s-1);
    display(arr);
}
