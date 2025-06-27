class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int size = nums.size();
        int result = 0;
        int left = 1, right = *max_element(nums.begin(), nums.end());

        while(left <= right) {
            int mid = left + (right - left) / 2;
            long long sum = 0;
            for(int num : nums) {
                sum += (num-1)/mid+1;
            }

            if(sum <= threshold) { //sum is < threshold so gotta check if there's more valid answer
                result = mid;
                right = mid - 1;
                
            } else { // sum > threshold so gotta check towards left
                left = mid + 1;
            }
        }
        return result;
    }
};