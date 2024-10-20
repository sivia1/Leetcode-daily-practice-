class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minCost(n+1);
        
        minCost[0] = 0;
        minCost[1] = 0;
        
        for(int i = 2; i <= n; i++) {
            minCost[i] = min(cost[i-1] + minCost[i-1], cost[i-2] + minCost[i-2]);
        }
        return minCost[n];
    }
};