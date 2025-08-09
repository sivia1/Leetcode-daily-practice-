class Solution {
public:
//APPROACH :
//  Strategy:
//         1. Count existing k's in the array
//         2. For each possible value m (1-50), calculate the maximum gain
//            we can get by converting m's to k's using Kadane's algorithm
//         3. Return original count + best possible gain
    int maxFrequency(vector<int>& nums, int k) {
        int original = count(nums.begin(), nums.end(), k);
        //Try converting each possible value m to k
        int maxGain = 0;
        //We can always choose to do no operation (gain = 0)

        for(int m = 1; m <= 50; m++) {
            if(m == k) continue; // Skip k itself

            //Create transformed array for this value m
            vector<int> transformed;
            for(int num : nums) {
                if(num == m) transformed.push_back(1); //Gain -> can be converted to k
                else if (num == k) transformed.push_back(-1); //Loss ->converted to something else other than k
                else transformed.push_back(0); //No change
            }

            //Use Kadane's algorithm to find max subarray sum
            int currGain = kadane(transformed);
            maxGain = max(maxGain, currGain);
        }
        return original + maxGain;
    }

    int kadane(vector<int> arr) {
        /*
        Kadane's algorithm to find maximum sum of contiguous subarray.
        Returns 0 if all subarrays have negative sum (no operation beneficial).
        */

        int currSum = 0;
        int maxSum = 0; // We can choose empty subarray (no operation)

        for(int num : arr) {
            currSum = max(num, currSum + num); // Start new or continue
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};