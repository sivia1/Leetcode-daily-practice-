class Solution {
public:
//Approach Memoization: Cache the result
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
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return recurse(nums, nums.size()-1, target, dp);
    }

//Subset Sum Code
    bool recurse(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        //base cases
        if(target == 0) return true;
        if(index <= 0) return false;

        //check if computed
        if(dp[index][target] != -1) {
            return dp[index][target];
        }
        //Don't pick
        bool notPick = recurse(nums, index-1, target, dp);

        //pick if possible
        bool pick = false;

        if(nums[index - 1] <= target) {
            pick = recurse(nums, index-1, target-nums[index-1], dp);
        }
        //store and return
        dp[index][target] = (pick || notPick) ? 1 : 0;
        return dp[index][target];
    }
};