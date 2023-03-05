#include<bits/stdc++.h>
using namespace std;

// memo TC-O(n) SC-O(n) && stack space
int sum(int ind,vector<int>&dp,vector<int> &nums,int n){
    if(ind==n-1) return dp[ind]=nums[ind];
    if(ind>=n) return 0;

    if(dp[ind]!=-1)return dp[ind];
    int move1=sum(ind+2,dp,nums,n)+nums[ind];
    int move2=sum(ind+1,dp,nums,n);
    return dp[ind]=max(move1,move2);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n+1,-1);
    return sum(0,dp,nums,n);
}

//dp TC-O(n) SC-O(n)
int maximumNonAdjacentSum1(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    dp[0]=nums[0];
    for(int i=1; i<n; i++){
        int take=nums[i];
        if(i>1)take+=dp[i-2];
        int not_take=dp[i-1];
        dp[i]=max(take,not_take);
    }
    return dp[n-1];
}

// TC-O(n) SC-O(1)  optimal
int maximumNonAdjacentSum2(vector<int> &nums){
    int n=nums.size();
    int prev=nums[0],prev2=-1,ans;
    for(int i=1; i<n; i++){
        int take=nums[i];
        if(i>1)take+=prev2;
        int not_take=prev;
        ans=max(take,not_take);
        prev2=prev;
        prev=ans;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    // cout<< maximumNonAdjacentSum(nums)<<endl;
    // cout<< maximumNonAdjacentSum1(nums)<<endl;
    cout<< maximumNonAdjacentSum2(nums)<<endl;
    
    return 0;
}