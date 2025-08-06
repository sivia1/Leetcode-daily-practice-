class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startValue = 1;
        
        while (true) {
            int sum = startValue;
            bool valid = true;
            
            // Check if this startValue works
            for (int num : nums) {
                sum += num;
                if (sum < 1) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                return startValue;
            }
            startValue++;
        }
        
        return startValue;
    }
};