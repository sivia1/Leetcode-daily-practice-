class Solution {
public:
// METHOD - 1 for consecutive elements you gotta check if(nums[i+1] ==. nums[i]+1)
//if duplicates then skip use continue;
//if in sequence i.e if nums[i] == nums[i-1]+1 then increment currLength 
//if not then reset curr length to 1 and store the previously occurring currlength to maxLength

//METHOD -2 using HashSet for Order 1 lookup.. you store the array in the set and then you traverse the set and check if is the beginning of a sequence by looking for num-1 number in the set 
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) {
            return 0;
        }
        //store all numbers in hash-set for O(1) look up
        unordered_set<int> Map(nums.begin(), nums.end());
        int maxLength = 1;

        for(int num : Map) {
            //start counting only if this number is the beginning of a sequence
            //i.e num-1 doesn't exiat in the set 
            if(Map.find(num-1) == Map.end()) {
                int currNum = num;
                int currLength = 1;

                //count consecutive numbers
                while(Map.find(currNum+1) != Map.end()) {
                    currNum++;
                    currLength++;
                }
                maxLength = max(maxLength, currLength);
            }
        }
        return maxLength;
    }
};