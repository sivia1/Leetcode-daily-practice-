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
                //correct ceiling formula
                sum += (num-1)/mid+1;
            }

            if(sum <= threshold) { //sum is < threshold so gotta try smaller divisor (denominator < numerator = larger quotient)
                result = mid;
                right = mid - 1;
                
            } else { // sum > threshold so gotta check towards the right half of the array 
                left = mid + 1;
            }
        }
        return result;
    }
};