#include<bits/stdc++.h>
using namespace std;

// recursion method : TC-(n*m) where, m is the depth of resurion tree  SC-O(1)
int fibo(int n){
    if(n<=1) return n;
    return fibo(n-1)+fibo(n-2);
}

// memoization : TC-O(n)  SC-O(n) & stack space
int fibo2(vector<int>&dp,int n){
    if(n<=1) return n;
    if(dp[n]!=-1)return dp[n];
    return fibo(n-1)+fibo(n-2);
}
// dp : TC-O(n)  SC-O(n)
int fibo3(vector<int>dp,int n){
    dp[0]=0,dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// linear-by loops : TC-O(n) SC-O(1)
int fibo4(int n){
    int prev1=1,prev2=0,curr;
    for(int i=2; i<=n; i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}
int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<fibo(n)<<endl; 
    // cout<<fibo2(dp,n)<<endl;
    cout<<fibo3(dp,n)<<endl;
    cout<<fibo4(n)<<endl;
    return 0;
}

// fibonacci series goes like this
// 0 1 1 2 3 5 8 ...

