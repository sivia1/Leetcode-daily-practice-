class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> uniqueVals;

        for(int num : nums) {
            if(num > 0) {
                uniqueVals.insert(num);
            }
        }
        return uniqueVals.size();
    }
};