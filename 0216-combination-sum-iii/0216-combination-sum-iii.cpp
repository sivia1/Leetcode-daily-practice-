class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;

        solve(1, k, n, current, result);
        return result;
    }

    void solve(int num, int k, int target, vector<int>& current, vector<vector<int>>& result) {
        //base case 1 : target is met and we used exactly k numbers
        if(target == 0 && current.size() == k) {
            result.push_back(current);
            return;
        }

        // 2. FAILURE/PRUNING: 
        // - We ran out of numbers (num > 9)
        // - We exceeded the target (target < 0) - optimization
        // - We used too many numbers (current.size() == k) but target isn't 0
        if(num > 9 || target < 0 || current.size() == k) {
            return;
        }

        //Decision Tree- Pruning using Include and Exclude

        //Include
        current.push_back(num);
        solve(num+1, k, target - num, current, result);

        //backtrack
        current.pop_back();

        //Exclude
        solve(num+1, k, target, current, result);

    }
};