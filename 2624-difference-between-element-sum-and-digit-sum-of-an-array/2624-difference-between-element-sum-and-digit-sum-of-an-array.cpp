class Solution {
public:
//some mistakes I made : nums[i].size() >= 1
// This is invalid because nums[i] is an int, not a string or container, so it doesn't have .size(). You don't even need this check — all integers can be broken into digits using % 10.

// You're dividing nums[i] by 10 in the loop, which modifies the original element of the vector.
    int differenceOfSum(vector<int>& nums) {
        int Elsum = 0;
        int digSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            Elsum += nums[i];
            int n = nums[i];
            
            while(n != 0) {
                int dig = n % 10;
                digSum += dig;
                n/=10;
            }
        }
        return abs(Elsum - digSum);
    }
};