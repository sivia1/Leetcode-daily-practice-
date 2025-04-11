class Solution {
public:
//given an array of digits 0 to 9.
//repeatedly replace the array with a new one that is one element shorter,
//each element should be the sum of two adjacent elements modulo 10
//Repeat until only one element is left, that is triangular sum

//You do n - 1 rounds if the input has n elements.

//Each round, the size of the array decreases by 1.

//Each number in the new array is (nums[i] + nums[i + 1]) % 10.

//This continues until only 1 number remains.
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }
        return nums[0];
    }
};