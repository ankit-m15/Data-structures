class Solution{   
private:
    bool fun(int ind,int target,vector<int>arr){
        if(target==0) return true;
        if(ind==0) return arr[ind]==target;
        
        bool take,notake;
        notake=fun(ind-1,target,arr);
        if(target>=arr[ind]){
            take=fun(ind-1,target-arr[ind],arr);
        }
        return take || notake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return fun(arr.size()-1,sum,arr);
    }
};

class Solution{   
private:
    bool fun(int ind,int target,vector<int>arr,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(ind==0) return (arr[ind]==target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take,notake;
        notake=fun(ind-1,target,arr,dp);
        if(target>=arr[ind]){
            take=fun(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]= (take || notake);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        return fun(n-1,sum,arr,dp);
    }
};


class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        for(int i=0; i<n; i++){
            dp[i][0]=1;
        }
        dp[0][arr[0]]=1;
        for(int i=1; i<n; i++){
            for(int j=1; j<=sum; j++){
                if(j>=arr[i]){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n-1][sum];
    }
};