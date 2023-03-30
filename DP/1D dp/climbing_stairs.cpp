#include <bits/stdc++.h>
using namespace std;

// number of ways to reach nth step if we take one step or two steps
// TC-O(n) SC-O(1)
int climbStairs(int n){
    int prev1 = 1, prev2 = 0, curr;
    for (int i = 1; i <= n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// can also be done using dp or memoization which will consume O(n) extra space 
// because we need dp arr for that

int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;

    return 0;
}