#include <bits/stdc++.h> 
using namespace std;

// problem statement:
// there is a frog on 1st step and wants to reach to the nth step of staircase
// frog can take one or two step only
// if frog jumps from ith index to jth index it will loose abs(heights[i]-heights[j]) amount of enery 
// find the minimum energy can be used by frog


// TC-O(n) SC-O(n) memoization
int jump(int ind,vector<int> &heights,int n,vector<int>&dp){
    if(ind>=n-2) return dp[ind]=abs(heights[ind]-heights[n-1]);
    if(dp[ind]!=-1)return dp[ind];
    int left=jump(ind+1,heights,n,dp)+abs(heights[ind]-heights[ind+1]);
    int right=jump(ind+2,heights,n,dp)+abs(heights[ind]-heights[ind+2]);
    return dp[ind]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    return jump(0,heights,n,dp);
}

int main(){
    int n;
    cin>>n; 
    vector<int>heights(n);
    for(int i=0; i<n; i++){
        cin>>heights[i];
    }
    cout<<frogJump(n,heights)<<endl;
    return 0;
}

// example
// 8
// 7 4 4 2 6 6 3 4 
// 7

// 6
// 4 8 3 10 4 4 
// 2