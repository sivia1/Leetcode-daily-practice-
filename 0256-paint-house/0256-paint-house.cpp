class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        unordered_map<string, int> memo;
        return solve(0, -1, costs, n, memo);
    }

    int solve(int house, int lastColor, vector<vector<int>>& costs, int n, unordered_map<string, int>& memo) {
        if(house == n) {
            return 0;
        }

        string key = to_string(house) + "," + to_string(lastColor);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        int minCost = INT_MAX;
        for (int color = 0; color < 3; color++) {
            if (color != lastColor) {
                int cost = costs[house][color] + solve(house + 1, color, costs, n, memo);
                minCost = min(minCost, cost);
            }
        }
        
        memo[key] = minCost;
        return minCost;
    }
};