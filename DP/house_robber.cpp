#include<bits/stdc++.h>
using namespace std;

// same problem as max_non_adj_sum.cpp

// optimal TC-O(n) SC-O(1)
int FindMaxSum(vector<int>&houses, int n){
    int prev=houses[0],prev2=-1,ans=houses[0];
    for(int i=1; i<n; i++){
        int rob=houses[i];
        if(i>1)rob+=prev2;
        int not_rob=prev;
        ans=max(rob,not_rob);
        prev2=prev;
        prev=ans;
    }
    return ans;
}
int main()
{
    int n; // the number of houses
    cin>>n;
    vector<int>houses(n);
    for(int i=0; i<n; i++){
        cin>>houses[i]; // money in each houses
    }
    cout<<FindMaxSum(houses,n)<<endl;

    return 0;
}