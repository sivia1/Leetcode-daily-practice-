class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int left = 0; left < n; left++) {
            int currSum = 0;
            for(int right = left; right < n; right++) {
                currSum += nums[right];
                if(currSum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};