class Solution {
public:
//for consecutive elements you gotta check if(nums[i+1] ==. nums[i]+1)
//if duplicates then skip use continue;
//if in sequence i.e if nums[i] == nums[i-1]+1 then increment currLength 
//if not then reset curr length to 1 and store the previously occurring currlength to maxLength
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int maxLength = 1;
        int currLength = 1;

        for(int i = 1; i < n; i++) {
            
            if(nums[i] == nums[i-1]) {
                continue;
            } else if(nums[i] == nums[i-1]+1) {
                currLength++;
            } else {
                maxLength = max(maxLength, currLength);
                currLength = 1;
            }
        }
        return max(maxLength, currLength);
    }
};