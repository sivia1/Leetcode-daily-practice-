class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) {
            return (nums[0]-1) * (nums[1]-1);
        }
        sort(nums.begin(), nums.end());
        return (nums[n-2]-1) * (nums[n-1]-1);
    }
};