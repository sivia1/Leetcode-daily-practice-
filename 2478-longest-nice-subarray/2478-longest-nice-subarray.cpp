class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;

        for(int i = 0; i < n; i++) {
            int mask = 0;
            for(int j = i; j < n; j++) {
                if((mask & nums[j]) != 0) {
                    break;
                }
                mask |= nums[j];
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};