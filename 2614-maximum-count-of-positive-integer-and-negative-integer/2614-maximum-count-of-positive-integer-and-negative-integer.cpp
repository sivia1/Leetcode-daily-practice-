class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size(), maxNeg = 0, maxPos = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0 && nums[i] != 0) {
                maxNeg++;
            }
            else if (nums[i] > 0 && nums[i] != 0) {
                maxPos++;
            }
        }
        return max(maxNeg, maxPos);
    }
};