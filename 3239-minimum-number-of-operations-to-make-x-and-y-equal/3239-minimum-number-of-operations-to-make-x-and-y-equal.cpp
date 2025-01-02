class Solution {
public:
    vector<int> dp;
    int solve(int x, int y) {
        if(x <= y) {
            return y - x;
        }
        if(dp[x] != -1) {
            return dp[x];
        }
        int res = abs(x - y);
        res = min(res, 1 + x%5 + solve(x/5, y));
        res = min(res, 1 + (5 - x%5) + solve(x/5 + 1, y));
        res = min(res, 1 + x%11 + solve(x/11, y));
        res = min(res, 1 + (11 - x%11) + solve(x/11 + 1, y));
        return dp[x] = res;
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        dp.resize(10011, -1);
        return solve(x, y);
    }
};