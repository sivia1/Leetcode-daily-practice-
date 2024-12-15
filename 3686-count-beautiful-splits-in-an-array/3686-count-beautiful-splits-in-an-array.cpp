class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                bool nums1IsPrefixOfNums2 = (j - i >= i) && equal(nums.begin(), nums.begin() + i, nums.begin() + i);

                // Check if nums2 is a prefix of nums3
                bool nums2IsPrefixOfNums3 = 
                    (n - j >= j - i) && 
                    equal(nums.begin() + i, nums.begin() + j, nums.begin() + j);

                // If either condition is true, this is a valid split
                if (nums1IsPrefixOfNums2 || nums2IsPrefixOfNums3) {
                    count++;
                }
            }
        }
        return count;
    }
};