class Solution {
    //dp bottom up. Also we need to know the 3 sets of numbers for the 4th number, so maintain an array of 3 numbers
public:
    int tribonacci(int n) {
        if(n < 3) {
            return n > 0 ? 1 : 0;
        }
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};