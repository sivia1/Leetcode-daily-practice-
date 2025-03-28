class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int currSum = 0, subarrays = 1;
        for(int num : nums) {
            if(currSum + num > maxSum) {
                subarrays++;
                currSum = num;
                if(subarrays > k) {
                    return false;
                }
            } else {
                currSum += num;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canSplit(nums, k, mid)) {
                //if mid satisfies the condition then we search for a smaller mid, 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};