#include<bits/stdc++.h>
using namespace std;

void print_arr(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    // function to print elements of array
}


void bubble_sort(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(arr[j-1]>arr[j]) 
            {
                swap(arr[j-1],arr[j]);
            }
        }
    }
    // time complexity : O(n*n)
}


void selection_sort(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        int min_ind=i;
        for(int j=i; j<n; j++)
        {
            if(arr[min_ind]>arr[j])
            {
                min_ind=j;
            }            
        }
        swap(arr[i],arr[min_ind]);
    }
    // time complexity : O(n*n)
}


void insertion_sort(int arr[],int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[j]>arr[i])
            {
                swap(arr[j],arr[i]);
            }            
        }
    }
    // time complexity : O(n*n)
}


// merge sort
void merge(int arr[],int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int temp_ind=l;
    int temp[100000];

    while(i<=mid && j<=r)
    {
        if(arr[i]<arr[j])
            temp[temp_ind]=arr[i++];
        else
            temp[temp_ind]=arr[j++];
        temp_ind++;
    }

    if(i>mid)
        while(j<=r)temp[temp_ind++]=arr[j++];
    else
        while(i<=mid)temp[temp_ind++]=arr[i++];
    
    for(int i=l; i<=r; i++)
        arr[i]=temp[i];
}
void merge_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    // time complexity : O(n*logn)
}


// quick sort
int partition(int arr[],int start,int end)
{
    int pivot=arr[start];
    int i=start;
    int j=end;

    while(i<j)
    {
        while(arr[i]<=pivot && i<=end-1)i++;
        while(arr[j]>pivot && j>=start)j--;

        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[start]);
    return j;
}
void quick_sort(int arr[],int start,int end)
{
    if(start<end)
    {
        int pivot=partition(arr,start,end);
        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
    }
    // best time complexity : O(n*logn)
    // worst time complexity : O(n*n)
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    //replace below funciton to check other sorting techniques
    quick_sort(arr,0,n-1); 
    print_arr(arr,n);

    return 0;
}