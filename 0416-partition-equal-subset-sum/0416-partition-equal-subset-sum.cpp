class Solution {
public:
//Approach Tabulation (2D dp): bool matrix of size [n+1][sum+1]; dp[n+1][sum+1]
    bool canPartition(vector<int>& nums) {
        //if the sum of array is even, then only the subset can be equally divided. If sum not even return false
        // pattern if sum is even, target = sum/2 and problem is reduced to subset sum problem, do it in Recursion, Memoization, Tabulation, Space Optimized
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) {
            return false;
        }
        sum % 2 == 0;
        int target = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                //don't pick the element
                dp[i][j] = dp[i-1][j];

                //pick if possible, previous element is < sum
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][target];
    }
};