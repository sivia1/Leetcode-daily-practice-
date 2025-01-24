class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int coin : coins) {
            for(int x = coin; x <= amount; x++) {
                if(dp[x - coin] != INT_MAX) {
                    dp[x] = min(dp[x], 1+dp[x-coin]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};