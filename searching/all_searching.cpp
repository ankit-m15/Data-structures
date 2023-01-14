#include<bits/stdc++.h>
using namespace std;


// function will check whether key element is present or not
// accordingly return true or false
bool iterative_linear_search(int arr[],int n,int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key)return true;
    }
    return false;
}
bool recursive_linear_search(int arr[],int ind,int size,int key)
{
    if(ind==size)return false;
    if(arr[ind]==key)return true;
    return recursive_linear_search(arr,ind+1,size,key);
}


// binary is applicable only on sorted arrays
// this function will check whether the key element is present or not iteratively
bool iterative_binary_search(int arr[],int n,int key)
{
    int low=0,high=n;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key){
            return true; // we found the element
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false; //we don't found the element
}
bool recursive_binary_search(int arr[],int low,int high,int key)
{
    // base case for recursion
    if(low>high)return false;

    int mid=low+(high-low)/2;
    if(arr[mid]==key)
        return true;
    else if(arr[mid]<key)
        return recursive_binary_search(arr,mid+1,high,key);
    else
        return recursive_binary_search(arr,low,mid-1,key);
}

// if we wants to search for index
// so, return index(i) instead of true and -1 instead of false
// and make the return-type of function int
// follow for both linear and binary search

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<iterative_linear_search(arr,n,key)<<endl;
    cout<<recursive_linear_search(arr,0,n,key)<<endl;
    cout<<iterative_binary_search(arr,n,key)<<endl;
    cout<<recursive_binary_search(arr,0,n,key)<<endl;
    
    return 0;
}