class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int min = INT_MAX;

        for(auto i : nums) {
            if(abs(i) < abs(min)) {
                min = i;
            }
            if(abs(i) == abs(min)) {
                min = max(i, min);
            }
        }
        return min;
    }
};