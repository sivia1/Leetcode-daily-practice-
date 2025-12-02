class Solution {
public:
//Try ALL possible combination. you have to try diff fill ways to fill empty slots based on nums.size()
//DECISION - TREE to free suppose _, _, _. fill one by one.
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        solve(nums, temp, visited, ans);
        return ans;
    }

    void solve(vector<int>& nums, vector<int>& temp, vector<bool>& visited, vector<vector<int>>& ans) {
        //base case
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(!visited[i]) {
                visited[i] = true; //Mark it used

                temp.push_back(nums[i]); //add it to current permutation

                //call the function recursively to fill the next slot
                solve(nums, temp, visited, ans);

                // UNDO 
                temp.pop_back(); // Remove the last number
                visited[i] = false; // // Mark it as unused so it can be picked in other branches
            }
        }
    }
};