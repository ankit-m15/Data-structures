// we will be given one matrix of i*j.
// we have to tell the number of paths possible form (0,0) to (i-1,j-1)

// recursive solution --this will give tle
int NumberOfPath(int i, int j)
{
    if (i == 1 || j == 1)
    {
        return 1;
    }
    return NumberOfPath(i - 1, j) + NumberOfPath(i, j - 1);
}

// memoized soln -- this will take stack space
int count(int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == 0 || j == 0)
    {
        return dp[i][j] = 1;
    }
    return dp[i][j] = count(i - 1, j, dp) + count(i, j - 1, dp);
}
int NumberOfPath(int a, int b)
{
    vector<vector<int>> dp(a, vector<int>(b, -1));
    return count(a - 1, b - 1, dp);
}


// dp soln --optimal
int NumberOfPath(int a, int b)
{
    // code here
    vector<vector<int>> dp(a, vector<int>(b, -1));
    for (int i = 0; i < a; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < b; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < a; i++)
    {
        for (int j = 1; j < b; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[a - 1][b - 1];
}