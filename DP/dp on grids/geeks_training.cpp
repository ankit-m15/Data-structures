// here we have to perform one of the 3 activities for n,
// for every activity some points will be given 
// our task is gain maximum points after n days

// recursive solution -gives TLE
int maxp(int day, int last, vector<vector<int>> &points){
    if (day == 0){
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++){
            if (i != last)
            {
                maxi = max(maxi, points[day][i]);
            }
        }
        return maxi;
    }
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++){
        if (i != last){
            maxi = max(maxi, points[day][i] + maxp(day - 1, i, points));
        }
    }
    return maxi;
}
int maximumPoints(vector<vector<int>> &points, int n){
    return fun(n - 1, -1, points);
}


// memoized soln -- this will take stack space
int fun(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if (dp[day][last] != -1)
        return dp[day][last];
    if (day == 0){
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[day][i]);
            }
        }
        return dp[day][last] = maxi;
    }
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++){
        if (i != last){
            maxi = max(maxi, points[day][i] + fun(day - 1, i, points, dp));
        }
    }
    return dp[day][last] = maxi;
}
int maximumPoints(vector<vector<int>> &points, int n){
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return fun(n - 1, 3, points, dp);
}


// dp soln --optimal
int maximumPoints(vector<vector<int>> &points, int n){
    for (int i = 1; i < n; i++){
        points[i][0] += max(points[i - 1][1], points[i - 1][2]);
        points[i][1] += max(points[i - 1][0], points[i - 1][2]);
        points[i][2] += max(points[i - 1][0], points[i - 1][1]);
    }
    return max(points[n - 1][0], max(points[n - 1][1], points[n - 1][2]));
}