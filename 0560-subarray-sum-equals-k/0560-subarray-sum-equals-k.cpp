class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int>map;
        for(int i = 0; i<nums.size(); i++) {
            prefixSum+= nums[i];
            if(prefixSum == k) {
                count++;
            }
            int difference = prefixSum - k;
            if(map.find(difference) != map.end()) {
                count+=map[difference];
            }
            map[prefixSum]++;
        }
        return count;
    }
};