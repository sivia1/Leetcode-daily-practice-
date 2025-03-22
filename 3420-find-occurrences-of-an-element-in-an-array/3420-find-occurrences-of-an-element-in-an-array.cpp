class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> frequency;
        for(int i = 0; i < n; i++) {
            if(nums[i] == x) {
                frequency.push_back(i);
            }
        }

        vector<int> result;
        for(int k : queries) {
            if(k > 0 && k <= frequency.size()) {
                result.push_back(frequency[k-1]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};