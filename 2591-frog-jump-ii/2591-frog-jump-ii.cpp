class Solution {
public:
    int maxJump(vector<int>& stones) {
        int result = stones[1] - stones[0];
        for(int i = 1; i < stones.size()-1; i++) {
            result = max(result, stones[i+1] - stones[i-1]);
        }
        return result;
    }
};