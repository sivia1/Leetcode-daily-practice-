class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = max(i - k, 0); j < i; j++) {
                if(((abs(i - j)) <= k) && nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};