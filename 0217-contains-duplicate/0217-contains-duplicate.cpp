class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //use a hashmap
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        for(auto count : freq) {
            if(count.second > 1) {
                return true;
            }
        }
        return false;
    }
};