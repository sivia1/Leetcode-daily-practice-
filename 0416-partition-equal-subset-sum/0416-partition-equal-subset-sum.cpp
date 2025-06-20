class Solution {
public:
//Approach Tabulation (1D dp): Space Optimized
    bool canPartition(vector<int>& nums) {
        //if the sum of array is even, then only the subset can be equally divided. If sum not even return false
        // pattern if sum is even, target = sum/2 and problem is reduced to subset sum problem, do it in Recursion, Memoization, Tabulation, Space Optimized
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) {
            return false;
        }
        int target = sum/2;
        vector<bool> dp(sum+1, false);

        for(int i = 0; i <= n; i++) {
            dp[0] = true;
        }
        //process each number
        for(int num : nums) {
            //traverse right to left to avoid using updated values
            for(int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j-num];
            }
            
        }
        return dp[target];
    }
};