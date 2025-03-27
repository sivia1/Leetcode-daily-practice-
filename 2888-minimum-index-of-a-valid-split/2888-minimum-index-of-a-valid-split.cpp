class Solution {
public:
//can use boyre mooree voting algo to find the dominant element
//think like two sum
//
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int majority = nums[0], count = 0;

        for(int num : nums) {
            if(count == 0) {
                majority = num;
            }
            count += (num == majority) ? 1 : -1;
        }

        int totalCount = count_if(nums.begin(), nums.end(), [&](int num) { return num == majority; });

        int leftCount = 0;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] == majority) {
                leftCount++;
            }
            int leftSize = i+1;
            int rightSize = n - leftSize;
            int rightCount = totalCount - leftCount;

            if(leftCount * 2 > leftSize && rightCount * 2 > rightSize) {
                return i;
            }
        }
        return -1;
    }
};