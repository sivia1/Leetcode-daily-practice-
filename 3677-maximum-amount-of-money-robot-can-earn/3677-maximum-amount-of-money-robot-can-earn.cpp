class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        
        // Iterate over the number of neutralizations (0, 1, 2)
        for (int count = 0; count < 3; ++count) {
            // Traverse the grid from bottom-right to top-left
            for (int i = m - 1; i >= 0; --i) {
                for (int j = n - 1; j >= 0; --j) {
                    // Base case: Bottom-right corner
                    if (i == m - 1 && j == n - 1) {
                        dp[i][j][count] = count > 0 ? max(0, coins[i][j]) : coins[i][j];
                        continue;
                    }
                    
                    int ans = INT_MIN; // Store the maximum profit for this cell
                    
                    // Check the cell below (down movement)
                    if (i + 1 < m) {
                        ans = max(ans, coins[i][j] + dp[i + 1][j][count]); // No neutralization
                        if (count > 0) ans = max(ans, dp[i + 1][j][count - 1]); // With neutralization
                    }
                    
                    // Check the cell to the right (right movement)
                    if (j + 1 < n) {
                        ans = max(ans, coins[i][j] + dp[i][j + 1][count]); // No neutralization
                        if (count > 0) ans = max(ans, dp[i][j + 1][count - 1]); // With neutralization
                    }
                    
                    // Update dp array for the current cell
                    dp[i][j][count] = ans;
                }
            }
        }
        
        // The answer is stored at the starting cell with 2 neutralizations available
        return dp[0][0][2];
    }
};