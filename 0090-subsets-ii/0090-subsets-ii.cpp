class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        
        // CRITICAL STEP: Sort the array first
        // This ensures duplicates are adjacent so we can skip them easily
        sort(nums.begin(), nums.end());
        
        backtrack(nums, 0, curr, result);
        return result;
    }
    void backtrack (vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& result) {
        result.push_back(curr);

        for(int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i-1]) {
                continue;
            }
            
            // 3. Take: Include nums[i]
            curr.push_back(nums[i]);
            
            // 4. Recurse: Move to the next index (i + 1)
            backtrack(nums, i + 1, curr, result);
            
            // 5. Backtrack: Remove the last element (undo the choice)
            curr.pop_back();
        }
    }
};