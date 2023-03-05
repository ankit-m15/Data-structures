#include <bits/stdc++.h> 
using namespace std;

// same as the question previous question frog_jump.cpp
// but here frog is allowed to jump 1 or 2 or 3 ... or k steps

// TC-O(n*k) SC-O(n) memoization
int jump(int ind,vector<int> &heights,int n,vector<int>&dp,int k){
    if(ind>=n-2) return dp[ind]=abs(heights[ind]-heights[n-1]);
    if(dp[ind]!=1e9)return dp[ind];
    int mn=INT_MAX;
    for(int i=1; i<=k; i++){
        if(ind+i>=n)continue;
        int temp=jump(ind+i,heights,n,dp,k)+abs(heights[ind]-heights[ind+i]);
        dp[ind]=min(dp[ind],temp);
    }
    return dp[ind];
}
int frogJump(int n,int k, vector<int> &heights)
{
    vector<int>dp(n+1,1e9);
    return jump(0,heights,n,dp,k);
}

int main(){
    int n,k;
    cin>>n>>k; 
    vector<int>heights(n);
    for(int i=0; i<n; i++){
        cin>>heights[i];
    }
    cout<<frogJump(n,k,heights)<<endl;
    return 0;
}