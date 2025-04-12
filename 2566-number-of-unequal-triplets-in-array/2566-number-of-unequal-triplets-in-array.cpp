class Solution {
public:
//idea : count all the ways to choose 3 different numbers and pick one index for each such that indices are strictly increasing

//fix the middle element cnt elements in the current group
// there are left elements from before cnt 
//there are right elements after cnt 

// The number of distinct triplets where:
// One element is from before group i
// One is from group i (as the middle)
// One is from after group i is-->
//left * cnt * right (one from each group)
// This formula naturally avoids duplicates, respects index order i < j < k, and ensures values are distinct.

    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        int n = nums.size();
        int res = 0;
        int left = 0;
        for(auto [val, cnt] : freq) {
            int right = n - left - cnt;
            res += left * cnt * right;
            left += cnt;
        }
        return res;
    }
};