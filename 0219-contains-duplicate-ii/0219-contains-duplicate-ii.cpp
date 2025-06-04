class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> seen;
        for(int i = 0; i < nums.size(); i++) {
            if(seen.count(nums[i]) == 1) {
                return true;
            }
            seen.insert(nums[i]);
            if(seen.size() > k) {
                seen.erase(nums[i-k]);
            }
        }
        return false;
    }
};