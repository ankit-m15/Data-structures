

int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        if(n==1 && m==1){
            return 1;
        }
        if(grid[n-1][m-1]==0){
            return 0;
        }
        if(n==1){
            return uniquePaths(n,m-1,grid);
        }
        if(m==1){
            return uniquePaths(n-1,m,grid);
        }
        return uniquePaths(n-1,m,grid)+uniquePaths(n,m-1,grid);
    }


#define mod 10000000009+7
class Solution {
  public:
  int mod=10000000009+7;
    int ways(int n, int m, vector<vector<int>> &grid,vector<vector<int>>&dp) {
        if(dp[n][m]!=-1) return dp[n][m];
        if(n==0 && m==0){
            return dp[n][m]=1;
        }
        if(grid[n][m]==0){
            return dp[n][m]=0;
        }
        if(n==0){
            return dp[n][m]=(int)ways(n,m-1,grid,dp)%mod;
        }
        if(m==0){
            return dp[n][m]=(int)ways(n-1,m,grid,dp)%mod;
        }
        return dp[n][m]=(int)ways(n-1,m,grid,dp)%mod+(int)ways(n,m-1,grid,dp)%mod;
    }
    int uniquePaths(int n,int m,vector<vector<int>>&grid){
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int ans=ways(n-1,m-1,grid,dp)%mod;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};

// 5 6
// 1 1 0 1 1 1
// 1 1 1 1 1 1
// 0 1 1 1 1 0
// 1 1 1 1 1 1
// 1 1 1 1 1 1

int mod=1e9+7;
int mazeObstaclesUtil(int i, int j, vector<vector<int> > &grid, vector<vector<int>> &dp) {
  if(i>0 && j>0 && grid[i][j]==0) return 0; 
  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = mazeObstaclesUtil(i-1,j,grid,dp)%mod;
  int left = mazeObstaclesUtil(i,j-1,grid,dp)%mod;
  
  return dp[i][j] = (up+left)%mod;
  
}

int uniquePaths(int n, int m, vector<vector<int> > &grid){
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return mazeObstaclesUtil(n-1,m-1,grid,dp)%mod; 
}