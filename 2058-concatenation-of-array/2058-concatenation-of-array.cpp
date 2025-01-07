class Solution {
public:
//tradiitonal approach
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int n2 = 2*n;
        vector<int> ans(n2);
        for(int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};