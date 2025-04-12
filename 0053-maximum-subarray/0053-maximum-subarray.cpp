class Solution {
public:
//kadane's
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum = nums[0], maxSum = nums[0];
        for(int i = 1; i < n; i++) {
            currSum = max(nums[i] + currSum, nums[i]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};